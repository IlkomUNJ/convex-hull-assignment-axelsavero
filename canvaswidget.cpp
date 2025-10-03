#include "canvaswidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPolygonF>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget(parent), m_iterations(0)
{
}

void CanvasWidget::setPoints(const QVector<QPoint>& points)
{
    m_points = points;
    m_hull.clear();
    m_iterations = 0;
    m_algoName = "";
    update();
}

void CanvasWidget::setHull(const QVector<QPoint>& hull, long long iterations, const QString& algoName)
{
    m_hull = hull;
    m_iterations = iterations;
    m_algoName = algoName;
    update();
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    painter.fillRect(rect(), Qt::white);


    painter.setBrush(Qt::blue);
    painter.setPen(Qt::NoPen);
    for (const QPoint& p : m_points) {
        painter.drawEllipse(p, 3, 3);
    }


    if (!m_hull.isEmpty()) {
        painter.setPen(QPen(Qt::red, 2));
        painter.setBrush(Qt::NoBrush);

        QPolygonF hullPolygon;
        for(const QPoint& p : m_hull) {
            hullPolygon << p;
        }

        if (!m_hull.isEmpty()) {
            hullPolygon << m_hull.first();
        }
        painter.drawPolyline(hullPolygon);
    }


    if (m_iterations > 0) {
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        QString text = QString("%1: %2 iterations").arg(m_algoName).arg(m_iterations);
        painter.drawText(10, 25, text);
    }
}
