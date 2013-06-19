#include "chnt.h"
#include <string.h>

#include <QtDebug>

const int CHNT::m_CengShu = 9;
CHNT::CHNT()
{
    m_ShiJiCengShu = 3;
    this->InitTa();
}

void CHNT::InitTa()
{
    memset(m_Ta_1,0,sizeof(m_Ta_1));
    memset(m_Ta_2,0,sizeof(m_Ta_2));
    memset(m_Ta_3,0,sizeof(m_Ta_3));
    for(int i=0;i<m_ShiJiCengShu;i++)
    {
        m_Ta_1[i] = m_ShiJiCengShu-i;
    }
}

int CHNT::TaDingCeng(int* Ta)
{
    if(Ta[0]==0)
        return 0;
    int i=0;
    for(;i<m_ShiJiCengShu && Ta[i]!=0;i++)
    {
    }
    return i-1;
}
int CHNT::CongTa(int* congTa)
{
    return this->TaDingCeng(congTa);
}

int CHNT::DaoTa(int* daoTa)
{
    return this->TaDingCeng(daoTa);
}

bool CHNT::YiDongTa(int cong,int dao)
{
    print();

    if( cong == dao )
    {
        return false;
    }
    int* ta[] = {(int*)m_Ta_1,(int*)m_Ta_2,(int*)m_Ta_3};
    int congCeng = TaDingCeng(ta[cong]);
    int daoCeng = TaDingCeng(ta[dao]);
    int congDing = ta[cong][congCeng];
    int daoDing = ta[dao][daoCeng];
    if( congDing == 0 )
    {
        return false;
    }
    if( congDing > daoDing && daoDing != 0 )
    {
        return false;
    }
    if(ta[dao][daoCeng]== 0)
    {
        ta[dao][daoCeng] = ta[cong][congCeng];
    }
    else
    {
        ta[dao][daoCeng+1] = ta[cong][congCeng];
    }

    ta[cong][congCeng] = 0;

    return true;
}
/*
{

    switch (congTa)
    {
    case 1:
    {
        int it = CongTa(m_Ta_1);
        int temp = m_Ta_1[it];
        if(temp == 0)
            return false;
        switch (daoTa)
        {
        case 1:
        {
            return false;
        }
        case 2:
        {
            m_Ta_1[it] = m_Ta_2[DaoTa(m_Ta_2)];
            m_Ta_2[DaoTa(m_Ta_2)] = temp;
            return true;
        }
        case 3:
        {
            m_Ta_1[it] = m_Ta_3[DaoTa(m_Ta_3)];
            m_Ta_3[DaoTa(m_Ta_3)] = temp;
            return true;
        }
        }
    }
    case 2:
    {
        int it = CongTa(m_Ta_2);
        int temp = m_Ta_2[it];
        if(temp == 0)
            return false;
        switch (daoTa)
        {
        case 1:
        {
            m_Ta_2[it] = m_Ta_1[DaoTa(m_Ta_1)];
            m_Ta_1[DaoTa(m_Ta_1)] = temp;
            return true;
        }
        case 2:
        {
            return false;
        }
        case 3:
        {
            m_Ta_2[it] = m_Ta_3[DaoTa(m_Ta_3)];
            m_Ta_3[DaoTa(m_Ta_3)] = temp;
            return true;
        }
        }
    }
    case 3:
    {
        int it = CongTa(m_Ta_3);
        int temp = m_Ta_3[it];
        if(temp == 0)
            return false;
        switch (daoTa)
        {
        case 1:
        {
            m_Ta_3[it] = m_Ta_1[DaoTa(m_Ta_1)];
            m_Ta_1[DaoTa(m_Ta_1)] = temp;
            return true;
        }
        case 2:
        {
            if(temp >)
            m_Ta_3[it] = m_Ta_2[DaoTa(m_Ta_2)];
            m_Ta_2[DaoTa(m_Ta_2)] = temp;
            return true;
        }
        case 3:
        {
            return false;
        }
        }
    }
    }
    return false;
}*/

bool CHNT::ShiFouGuoGuan()
{
    for(int i=0;i<m_ShiJiCengShu;i++)
    {
        if(m_Ta_3[i] != m_ShiJiCengShu - i)
            return false;
    }
    return true;
}

int CHNT::Is0(int mougeta,int dijiceng)
{
    int* p[] = {(int*)m_Ta_1,(int*)m_Ta_2,(int*)m_Ta_3};
    //qDebug()<<p[mougeta][dijiceng]<<" "<<mougeta<<"  "<<dijiceng<<"\n";

    return p[mougeta][dijiceng];
}

void CHNT::print()
{
    int* p[] = {(int*)m_Ta_1,(int*)m_Ta_2,(int*)m_Ta_3};
    for(int i =0;i<3;i++)
    {
        QString sz;
        for(int j = 0; j < 9; j++ )
        {
            sz += QString().setNum( p[i][j] );
            sz += " ";
        }
        qDebug()<<sz;
    }
     qDebug()<<"\n";
}

void CHNT::GoToXiaYiJi()
{
    SetXiaYiJi();
}

void CHNT::SetXiaYiJi()
{
    m_ShiJiCengShu ++;
    if(m_ShiJiCengShu > 9)
        m_ShiJiCengShu = 3;
    InitTa();
}
