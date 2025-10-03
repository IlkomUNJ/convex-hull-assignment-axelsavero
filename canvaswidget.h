#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QString>

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = nullptr);

    void setPoints(const QVector<QPoint>& points);
    void setHull(const QVector<QPoint>& hull, long long iterations, const QString& algoName);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<QPoint> m_points;
    QVector<QPoint> m_hull;
    long long m_iterations;
    QString m_algoName;
};

#endif
