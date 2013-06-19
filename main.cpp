#include "mainwindow.h"
#include <QApplication>
#include <assert.h>
#include "chnt.h"

int main(int argc, char *argv[])
{
    CHNT hnt;

    assert(hnt.YiDongTa(0,2));

    assert(hnt.YiDongTa(0,1));

    assert(hnt.YiDongTa(2,1));

    assert(hnt.YiDongTa(0,2));

    assert(hnt.YiDongTa(1,0));

    assert(hnt.YiDongTa(1,2));

    assert(hnt.YiDongTa(0,2));


    hnt.InitTa();//从空倒空
    assert(!hnt.YiDongTa(1,2));


    hnt.InitTa();//从高倒空
    assert(hnt.YiDongTa(0,1));


    hnt.InitTa();//从空祷告
    assert(!hnt.YiDongTa(1,0));


    hnt.InitTa();//从高到低
    assert(hnt.YiDongTa(0,2));
    assert(hnt.YiDongTa(0,1));
    assert(hnt.YiDongTa(2,1));

    hnt.InitTa();//从低到高
    assert(hnt.YiDongTa(0,2));
    assert(!hnt.YiDongTa(0,2));

    //return 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
