#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <ctime> 
#include <cstdlib> 
using namespace std;
int II;
int qipan1[15][15];
int qipan[15][15];      //ȫ�ֶ�ά����
class QIPAN {           //������QIPAN
private:
    int shuiping;       //����˽�����ݳ�Ա
    int shuzhi;
    int xie1;
    int xie2;

public:
    int a, b, c, d, A, S = 0;        //���干�����ݳ�Ա
    int I = 0, J = 0, P = 0, Q = 0, M = 0, N = 0, C, D, E, F, G, H, K, L, Z;
    friend istream& operator>>(istream&, QIPAN&);        //�������������
    QIPAN(int shui = 1, int shu = 1, int x1 = 1, int x2 = 1) :shuiping(shui), shuzhi(shu), xie1(x1), xie2(x2) {}    //��ʼ��˽�����ݳ�Ա
    void fuzhi();                   //���̸�ֵ����
    void shengcheng();              //�������ɺ���
    void panduan(int i, int j);     //�ظ������жϺ���
    void AA();                      //ȡֵ����ʼλ�ã�
    void guiyi();                   //˽�����ݳ�Ա��һ
    void qizi();                    //����������Ӻ���
    void qizi2();
    void score();                   //�Ʒֺ���
    void jishu1();                  //�����������˸�����
    void jishu2();
    void jishu3();
    void jishu4();
    void jishu5();
    void jishu6();
    void jishu7();
    void jishu8();
    void xiaochu1();                //��������
    void xiaochu2();
    void xiaochu3();
    void xiaochu4();
    void over();                    //�ж���Ϸ��������
    void f();                       //������������������
    void lujing1(int q, int w);
    void lujing2();
};


istream& operator>>(istream& input, QIPAN& x)   //�������������
{
    char e, f, g;
    while (1)
    {
        input >> x.a >> e >> x.b >> f >> x.c >> g >> x.d;     //��ȡ��������
        break;
    }
    return input;
}

void QIPAN::AA()                  //������ʼλ��ֵ
{
    A = qipan[b][a];
    Z = qipan[d][c];
    
}
void QIPAN::lujing1(int q,int w)
{
    if (qipan[q - 1][w] == 0)
        qipan1[q - 1][w] = 1;
    if (qipan[q + 1][w] == 0)
        qipan1[q + 1][w] = 1;
    if (qipan[q ][w+1] == 0)
        qipan1[q][w + 1] = 1;
    if (qipan[q ][w -1] == 0)
        qipan1[q][w - 1] = 1;
}
void QIPAN::lujing2()
{
    QIPAN a;
    for(int H=1;H<=100;H++)
    {
        for (int h = 1; h < 10; h++) {          
            for (int l = 1; l < 10; l++) {
                if (qipan1[h][l] == 1)
                    a.lujing1(h, l);
            }
        }
    }
    
}
void QIPAN::fuzhi()                //Ϊ���̸�ֵ
{
    for (int h = 1; h < 10; h++) {          //�������̳�ʼֵ
        for (int l = 1; l < 10; l++) {
            qipan[h][l] = 0;
        }
    }
    for (int m = 1; m < 10; m++) {          //��������
        qipan[m][0] = m;
    }
    for (int n = 1; n < 10; n++) {
        qipan[0][n] = n;
    }
    qipan[0][0] = 1;
}

void QIPAN::shengcheng()                     //��������
{
    for (int h = 0; h < 10; h++) {
        for (int l = 0; l < 10; l++) {
            switch (qipan[h][l]) {
            case 0:cout << "0 ";
                break;
            case 1:cout << "1 ";
                break;
            case 2:cout << "2 ";
                break;
            case 3:cout << "3 ";
                break;
            case 4:cout << "4 ";
                break;
            case 5:cout << "5 ";
                break;
            case 6:cout << "6 ";
                break;
            case 7:cout << "7 ";
                break;
            case 8:cout << "8 ";
                break;
            case 9:cout << "9 ";
                break;

            }
        }
        cout << endl;
    }
}

void QIPAN::panduan(int i, int j)        //�ж������������Ƿ��ظ�
{

    if (qipan[i][j] == 0) {
        qipan[i][j] = (rand() % 7 + 1);   //�������
    }
    else {

        i = (rand() % 10);
        j = (rand() % 10);
        panduan(i, j);
    }
}

void QIPAN::qizi()              //���������������
{
    if (shuzhi < 5 && shuiping < 5 && xie1 < 5 && xie2 < 5) {

        
        I = (rand() % 10);
        J = (rand() % 10);
        P = (rand() % 10);
        Q = (rand() % 10);
        M = (rand() % 10);
        N = (rand() % 10);

        QIPAN B;
        B.panduan(I, J);        //ȷ�������ɵ��������Ӵ�������
        B.panduan(P, Q);
        B.panduan(M, N);
    }

}
void QIPAN::qizi2()
{
    srand(time(NULL));
    I = (rand() % 10);
    J = (rand() % 10);
    P = (rand() % 10);
    Q = (rand() % 10);
    M = (rand() % 10);
    N = (rand() % 10);
    C = (rand() % 10);
    H = (rand() % 10);
    D = (rand() % 10);
    E = (rand() % 10);
    F = (rand() % 10);
    G = (rand() % 10);
    K = (rand() % 10);
    L = (rand() % 10);
    QIPAN B;
    B.panduan(I, J);        //ȷ�������ɵ��������Ӵ�������
    B.panduan(P, Q);
    B.panduan(M, N);
    B.panduan(C, D);        //ȷ�������ɵ��������Ӵ�������
    B.panduan(E, F);
    B.panduan(G, H);
    B.panduan(K, L);
}
void QIPAN::score()            //�Ʒ�
{
    if (shuiping >= 5 || shuzhi >= 5 || xie1 >= 5 || xie2 >= 5)
        S += 2;
    if (shuiping >= 5)
        S += (shuiping - 1) * 2;
    if (shuzhi >= 5)
        S += (shuzhi - 1) * 2;
    if (xie1 >= 5)
        S += (xie1 - 1) * 2;
    if (xie2 >= 5)
        S += (xie2 - 1) * 2;
    cout << "���ĵ÷�Ϊ��" << S << endl;
}

void QIPAN::over()          //���̲���������Ϸ����
{
    int number = 0;
    for (int h = 1; h <= 9; h++) {
        for (int l = 1; l <= 9; l++) {
            if (qipan[h][l] != 0)
                number++;
        }
    }
    if (number == 81) {
        cout << "GAME OVER" << endl;
        system("pause");
    }

}

void QIPAN::guiyi()          //���Ʒ����ָ���ʼֵ
{
    shuiping = 1;
    shuzhi = 1;
    xie1 = 1;
    xie2 = 1;
}



void QIPAN::jishu1()          //��������
{

    if (d >= 2) {     //ȷ����������������
        for (int i = 1; i <= d - 1; i++) //���� 
        {
            if (qipan[d - i][c] == qipan[d][c] && qipan[d][c] != 0)
                shuzhi++;
            else
                break;
        }
    }
}

void QIPAN::jishu2()
{
    for (int i = 1; i <= 8; i++) //���� 
    {
        if (qipan[d + i][c] == qipan[d][c] && qipan[d][c] != 0)
            shuzhi++;
        else
            break;
    }
}

void QIPAN::jishu3()
{
    if (c >= 2)
    {
        for (int i = 1; i <= c - 1; i++) //���� 
        {
            if (qipan[d][c - i] == qipan[d][c] && qipan[d][c] != 0)
                shuiping++;
            else
                break;
        }
    }

}

void QIPAN::jishu4()
{

    for (int i = 1; i <= 8; i++) //���� 
    {
        if (qipan[d][c + i] == qipan[d][c] && qipan[d][c] != 0)
            shuiping++;
        else
            break;
    }
}

void QIPAN::jishu5()
{
    if (c >= 2) {
        for (int i = 1; i <= c - 1; i++) //������ 
        {
            if (qipan[d + i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                xie1++;
            else
                break;
        }
    }

}

void QIPAN::jishu6()
{
    if (d >= 2)
    {
        for (int i = 1; i <= d - 1; i++) //������ 
        {
            if (qipan[d - i][c + i] == qipan[d][c] && qipan[d][c] != 0)
                xie1++;
            else
                break;
        }
    }

}

void QIPAN::jishu7()
{
    for (int i = 1; i <= 6; i++) //������ 
    {
        if (qipan[d + i][c + i] == qipan[d][c] && qipan[d][c] != 0)
            xie2++;
        else
            break;
    }
}

void QIPAN::jishu8()
{
    int t = (c > d ? d : c);
    if (t >= 2)
    {
        for (int i = 1; i <= t - 1; i++) //������ 
        {
            if (qipan[d - i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                xie2++;
            else
                break;
        }
    }

}

void QIPAN::xiaochu1()          //������������
{
    if (shuiping >= 5) {        //���������ۼƵ�������ֵ


        if (c >= 2)
        {
            for (int i = 1; i <= c - 1; i++) //�� 
            {
                if (qipan[d][c - i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d][c - i] = 0;
                else
                    break;
            }
        }
        for (int i = 1; i <= 8; i++) //�� 
        {
            if (qipan[d][c + i] == qipan[d][c] && qipan[d][c] != 0)
                qipan[d][c + i] = 0;
            else
                break;
        }
        
    }
}

void QIPAN::xiaochu2()
{
    if (shuzhi >= 5) {

        if (d >= 2) {
            for (int i = 1; i <= d - 1; i++) //�� 
            {
                if (qipan[d - i][c] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d - i][c] = 0;
                else
                    break;
            }
        }
        for (int i = 1; i <= 8; i++) //�� 
        {
            if (qipan[d + i][c] == qipan[d][c] && qipan[d][c] != 0)
                qipan[d + i][c] = 0;
            else
                break;
        }
        
    }
}

void QIPAN::xiaochu3()
{
    if (xie1 >= 5) {

        if (c >= 2) {
            for (int i = 1; i <= c - 1; i++) //���� 
            {
                if (qipan[d + i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d + i][c - i] = 0;
                else
                    break;
            }
        }
        if (d >= 2)
        {
            for (int i = 1; i <= d - 1; i++) //���� 
            {
                if (qipan[d - i][c + i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d - i][c + i] = 0;
                else
                    break;
            }
        }
        
    }
}

void QIPAN::xiaochu4()
{
    if (xie2 >= 5) {

        for (int i = 1; i <= 6; i++) //���� 
        {
            if (qipan[d + i][c + i] == qipan[d][c] && qipan[d][c] != 0)
                qipan[d + i][c + i] = 0;
            else
                break;
        }
        int t = (c > d ? d : c);
        if (t >= 2)
        {
            for (int i = 1; i <= t - 1; i++) //���� 
            {
                if (qipan[d - i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d - i][c - i] = 0;
                else
                    break;
            }
        }
        
    }
}

void QIPAN::f() {         //���ϼ������������������Լ�main��������
    jishu1();
    jishu2();
    jishu3();
    jishu4();
    jishu5();
    jishu6();
    jishu7();
    jishu8();
    xiaochu1();
    xiaochu2();
    xiaochu3();
    xiaochu4();
    if (shuiping >= 5 || shuzhi >= 5 || xie1 >= 5 || xie2 >= 5)
        qipan[d][c] = 0;
}

