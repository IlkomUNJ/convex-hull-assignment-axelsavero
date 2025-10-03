#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include <algorithm>
#include <QVector>

// --- Fungsi Bantu ---

/**
 * @brief Menentukan orientasi tiga titik (p, q, r).
 * @return > 0 jika r di kiri garis pq (belokan kiri / counter-clockwise)
 * @return < 0 jika r di kanan garis pq (belokan kanan / clockwise)
 * @return 0 jika p, q, dan r segaris (collinear)
 */
long long orientationTest(QPoint p, QPoint q, QPoint r) {
    return (long long)(q.x() - p.x()) * (long long)(r.y() - p.y()) -
           (long long)(q.y() - p.y()) * (long long)(r.x() - p.x());
}

// --- Algoritma SLOWCONVEXHULL ---

QVector<QPoint> slowConvexHull(const QVector<QPoint>& points, long long& iterations) {
    iterations = 0;
    int n = points.size();
    if (n < 3) return {};

    QVector<QPair<QPoint, QPoint>> hullEdges;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            bool isValidEdge = true;
            for (int k = 0; k < n; ++k) {
                iterations++;
                if (k == i || k == j) continue;

                if (orientationTest(points[i], points[j], points[k]) > 0) {
                    isValidEdge = false;
                    break;
                }
            }

            if (isValidEdge) {
                hullEdges.append({points[i], points[j]});
            }
        }
    }

    QVector<QPoint> hull;
    if (hullEdges.isEmpty()) return {};

    QPair<QPoint, QPoint> currentEdge = hullEdges.first();
    hull.append(currentEdge.first);
    hull.append(currentEdge.second);

    while (hull.first() != hull.last()) {
        bool foundNext = false;
        for (const auto& edge : hullEdges) {
            if (edge.first == hull.last()) {
                hull.append(edge.second);
                foundNext = true;
                break;
            }
        }
        if (!foundNext) break;
    }
    hull.pop_back();

    return hull;
}


// --- Algoritma Incremental CONVEXHULL ---

QVector<QPoint> fastConvexHull(QVector<QPoint>& points, long long& iterations) {
    iterations = 0;
    int n = points.size();
    if (n <= 2) return points;

    std::sort(points.begin(), points.end(), [](const QPoint& a, const QPoint& b) {
        return a.x() < b.x() || (a.x() == b.x() && a.y() < b.y());
    });

    QVector<QPoint> upperHull, lowerHull;

    for (const QPoint& p : points) {
        while (upperHull.size() >= 2) {
            iterations++;
            if (orientationTest(upperHull[upperHull.size()-2], upperHull.last(), p) >= 0) {
                upperHull.pop_back();
            } else {
                break;
            }
        }
        upperHull.push_back(p);
    }

    for (int i = n - 1; i >= 0; --i) {
        const QPoint& p = points[i];
        while (lowerHull.size() >= 2) {
            iterations++;
            // Sama, cek belokan kanan
            if (orientationTest(lowerHull[lowerHull.size()-2], lowerHull.last(), p) >= 0) {
                lowerHull.pop_back();
            } else {
                break;
            }
        }
        lowerHull.push_back(p);
    }

    lowerHull.pop_front();
    lowerHull.pop_back();

    QVector<QPoint> hull = upperHull;
    hull.append(lowerHull);

    return hull;
}

// ===================================================================
// IMPLEMENTASI KELAS MAINWINDOW
// ===================================================================

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generatePointsButton_clicked()
{
    m_points.clear();
    int width = ui->canvasWidget->width() - 20;
    int height = ui->canvasWidget->height() - 20;

    for (int i = 0; i < 150; ++i) {
        int x = QRandomGenerator::global()->bounded(10, width);
        int y = QRandomGenerator::global()->bounded(10, height);
        m_points.append(QPoint(x, y));
    }

    ui->canvasWidget->setPoints(m_points);
}

void MainWindow::on_slowHullButton_clicked()
{
    if (m_points.isEmpty()) return;

    long long iter = 0;
    QVector<QPoint> hull = slowConvexHull(m_points, iter);

    ui->canvasWidget->setHull(hull, iter, "Slow Hull");
}

void MainWindow::on_fastHullButton_clicked()
{
    if (m_points.isEmpty()) return;

    long long iter = 0;
    QVector<QPoint> pointsCopy = m_points;
    QVector<QPoint> hull = fastConvexHull(pointsCopy, iter);

    ui->canvasWidget->setHull(hull, iter, "Fast Hull");
}
