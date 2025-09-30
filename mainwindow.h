#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_generatePointsButton_clicked();
    void on_slowHullButton_clicked();
    void on_fastHullButton_clicked();

private:
    Ui::MainWindow *ui;


    QVector<QPoint> m_points;
};
#endif // MAINWINDOW_H
