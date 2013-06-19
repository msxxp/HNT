#ifndef CHNT_H
#define CHNT_H

class CHNT
{
private:
    int m_Ta_1[9];
    int m_Ta_2[9];
    int m_Ta_3[9];
    static const int m_CengShu;
    int m_ShiJiCengShu;
public:
    CHNT();

    void print();

    void GoToXiaYiJi();

    void InitTa();
    int CongTa(int* congTa);
    int DaoTa(int *daoTa);
    int TaDingCeng(int* Ta);
    bool YiDongTa(int cong,int dao);
    bool ShiFouGuoGuan();
    int Is0(int mougeta,int dijiceng);
    void SetXiaYiJi();
};

#endif // CHNT_H
