#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QtDebug>
#include <assert.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerID = startTimer(1000);
    oldRect = this->geometry();
    InitRect();
    cong = 0;
    dao = 0;
    m_JiShi_miao = 0;
    m_JiShi_fen = 0;
    m_JiShi_shi = 0;
    m_buShu = 0;
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    cong = 0;
    dao = 0;
    QRect cRect = this->geometry();
    int x = cRect.width()/3;
    if(event->button() == Qt::LeftButton)
    {
        QPoint pot;
        pot = event->pos();
        int temp = pot.x()/x;

        if ( temp >= 0 && temp <3 )
        {
            cong = temp;
        }
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QRect cRect = this->geometry();
    int x = cRect.width()/3;

    QPoint pot;
    pot = event->pos();
    int temp = pot.x()/x;

    if ( temp >= 0 && temp <3 )
    {
        dao = temp;
        if(m_Hnt.YiDongTa(cong,dao))
        {
            m_buShu ++;
        }
        cong = 0;
        dao = 0;
    }
    if(m_Hnt.ShiFouGuoGuan())
    {
        m_Hnt.GoToXiaYiJi();
        m_JiShi_miao = 0;
        m_JiShi_fen = 0;
        m_JiShi_shi = 0;
        m_buShu = 0;
    }
    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_Hnt.SetXiaYiJi();
    m_JiShi_miao = 0;
    m_JiShi_fen = 0;
    m_JiShi_shi = 0;
    m_buShu = 0;
     this->update();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QRect cRect = this->geometry();

    if(cRect != oldRect)
    {
        InitRect();
    }
    int h = cRect.height();
    int y = h/14;

    QPainter pnt(this);
    pnt.drawText(QRect(cRect.width()/3,cRect.height()-cRect.height()/12,cRect.width()-cRect.width()/3,cRect.height()),m_jiShi);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<9;j++)
        {
            int temp = m_Hnt.Is0(i,j);
            if(temp!=0)
            {
                ta[i][9-temp].setTop(h-(j+3)*y);
                ta[i][9-temp].setBottom(h-(j+2)*y);
                assert( ta[i][j].left() < ta[i][j].right() );
                pnt.fillRect(ta[i][9-temp],QBrush(Qt::darkYellow));
            }
        }
    }
}

void MainWindow::InitRect()
{
    QRect cRect = this->geometry();

    int zuixiaozhi = 30;
    int w = cRect.width()/3;
    int x_1 = w/2;
    int x_2 = x_1/9;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<9;j++)
        {
            ta[i][j].setLeft(w*i+x_2+j*x_2);
            ta[i][j].setRight(w*i+w-x_2-j*x_2);
        }
    }
}


void MainWindow::timerEvent(QTimerEvent *event)
{
    m_jiShi = "";
    if(event->timerId() == timerID)
    {
        if(m_JiShi_shi<10)
        {
            m_jiShi += "0";
        }
        m_jiShi += QString().setNum(m_JiShi_shi);
        m_jiShi += ":";
        if(m_JiShi_fen<10)
        {
            m_jiShi += "0";
        }
        m_jiShi += QString().setNum(m_JiShi_fen);
        m_jiShi += ":";
        if(m_JiShi_miao<10)
        {
            m_jiShi += "0";
        }
        m_jiShi += QString().setNum(m_JiShi_miao);
        m_JiShi_miao++;
        if( m_JiShi_miao == 60 )
        {
            m_JiShi_miao = 0;
            m_JiShi_fen++;
            if(m_JiShi_fen == 60)
            {
                m_JiShi_fen = 0;
                m_JiShi_shi++;
                if(m_JiShi_shi == 24)
                {
                    m_JiShi_shi = 0;
                }
            }
        }
    }
    m_jiShi += "当前步数:";
    m_jiShi += QString().setNum(m_buShu);
    this->update();
}
#include <QDesktopWidget>
void MainWindow::on_comboBox_activated(int index)
{

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QDesktopWidget* DeskTop = QApplication::desktop();
    const QRect screen = DeskTop->availableGeometry();
    QRect tempRect;
    QString sz = ui->comboBox->currentText();
    QStringList wh = sz.split('X');
    if ( wh.size() < 2 ) return;
    int w = wh[0].trimmed().toInt();
    int h = wh[1].trimmed().toInt();
    if ( w < 200 || h < 100 )
    {
        w = 800;
        h = 600;
    }
    tempRect.setRect( screen.width()/2 - w / 2,screen.height()/2 - h / 2,w,h);
    if( tempRect.left() < 0 ) tempRect.setLeft(0);
    if( tempRect.top() < 0 ) tempRect.setTop(0);
    if( tempRect.right() > screen.right()) tempRect.setRight(screen.right());
    if( tempRect.bottom() > screen.bottom()) tempRect.setBottom(screen.bottom());
    this->setGeometry(tempRect);
    QRect rc = this->geometry();
    this->update();
}
