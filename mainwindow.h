#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "chnt.h"
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_currentIndexChanged(int index);

private:
    CHNT m_Hnt;
    QRect ta[3][9];
    QRect oldRect;
    QString m_jiShi;
    int m_buShu;
    int m_JiShi_miao;
    int m_JiShi_fen;
    int m_JiShi_shi;
    int cong;
    int dao;
    int timerID;
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void InitRect();
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
