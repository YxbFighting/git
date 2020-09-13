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
int qipan[15][15];      //全局二维数组
class QIPAN {           //定义类QIPAN
private:
    int shuiping;       //定义私有数据成员
    int shuzhi;
    int xie1;
    int xie2;

public:
    int a, b, c, d, A, S = 0;        //定义共有数据成员
    int I = 0, J = 0, P = 0, Q = 0, M = 0, N = 0, C, D, E, F, G, H, K, L, Z;
    friend istream& operator>>(istream&, QIPAN&);        //输入运算符重载
    QIPAN(int shui = 1, int shu = 1, int x1 = 1, int x2 = 1) :shuiping(shui), shuzhi(shu), xie1(x1), xie2(x2) {}    //初始化私有数据成员
    void fuzhi();                   //棋盘赋值函数
    void shengcheng();              //棋盘生成函数
    void panduan(int i, int j);     //重复棋子判断函数
    void AA();                      //取值（初始位置）
    void guiyi();                   //私有数据成员归一
    void qizi();                    //随机生成棋子函数
    void qizi2();
    void score();                   //计分函数
    void jishu1();                  //计数函数（八个方向）
    void jishu2();
    void jishu3();
    void jishu4();
    void jishu5();
    void jishu6();
    void jishu7();
    void jishu8();
    void xiaochu1();                //消除函数
    void xiaochu2();
    void xiaochu3();
    void xiaochu4();
    void over();                    //判断游戏结束函数
    void f();                       //计数函数与消除函数
    void lujing1(int q, int w);
    void lujing2();
};


istream& operator>>(istream& input, QIPAN& x)   //重载输入运算符
{
    char e, f, g;
    while (1)
    {
        input >> x.a >> e >> x.b >> f >> x.c >> g >> x.d;     //读取输入坐标
        break;
    }
    return input;
}

void QIPAN::AA()                  //保存起始位置值
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
void QIPAN::fuzhi()                //为棋盘赋值
{
    for (int h = 1; h < 10; h++) {          //遍历棋盘初始值
        for (int l = 1; l < 10; l++) {
            qipan[h][l] = 0;
        }
    }
    for (int m = 1; m < 10; m++) {          //棋盘坐标
        qipan[m][0] = m;
    }
    for (int n = 1; n < 10; n++) {
        qipan[0][n] = n;
    }
    qipan[0][0] = 1;
}

void QIPAN::shengcheng()                     //生成棋盘
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

void QIPAN::panduan(int i, int j)        //判断新生成棋子是否重复
{

    if (qipan[i][j] == 0) {
        qipan[i][j] = (rand() % 7 + 1);   //随机生成
    }
    else {

        i = (rand() % 10);
        j = (rand() % 10);
        panduan(i, j);
    }
}

void QIPAN::qizi()              //随机生成三个坐标
{
    if (shuzhi < 5 && shuiping < 5 && xie1 < 5 && xie2 < 5) {

        
        I = (rand() % 10);
        J = (rand() % 10);
        P = (rand() % 10);
        Q = (rand() % 10);
        M = (rand() % 10);
        N = (rand() % 10);

        QIPAN B;
        B.panduan(I, J);        //确保新生成的三个棋子处无棋子
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
    B.panduan(I, J);        //确保新生成的三个棋子处无棋子
    B.panduan(P, Q);
    B.panduan(M, N);
    B.panduan(C, D);        //确保新生成的三个棋子处无棋子
    B.panduan(E, F);
    B.panduan(G, H);
    B.panduan(K, L);
}
void QIPAN::score()            //计分
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
    cout << "您的得分为：" << S << endl;
}

void QIPAN::over()          //棋盘布满棋子游戏结束
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

void QIPAN::guiyi()          //将计分数恢复初始值
{
    shuiping = 1;
    shuzhi = 1;
    xie1 = 1;
    xie2 = 1;
}



void QIPAN::jishu1()          //计数函数
{

    if (d >= 2) {     //确保不更改棋盘坐标
        for (int i = 1; i <= d - 1; i++) //向上 
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
    for (int i = 1; i <= 8; i++) //向下 
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
        for (int i = 1; i <= c - 1; i++) //向左 
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

    for (int i = 1; i <= 8; i++) //向右 
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
        for (int i = 1; i <= c - 1; i++) //向左下 
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
        for (int i = 1; i <= d - 1; i++) //向右上 
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
    for (int i = 1; i <= 6; i++) //向右下 
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
        for (int i = 1; i <= t - 1; i++) //向左上 
        {
            if (qipan[d - i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                xie2++;
            else
                break;
        }
    }

}

void QIPAN::xiaochu1()          //棋子消除函数
{
    if (shuiping >= 5) {        //计数函数累计到可消除值


        if (c >= 2)
        {
            for (int i = 1; i <= c - 1; i++) //左 
            {
                if (qipan[d][c - i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d][c - i] = 0;
                else
                    break;
            }
        }
        for (int i = 1; i <= 8; i++) //右 
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
            for (int i = 1; i <= d - 1; i++) //上 
            {
                if (qipan[d - i][c] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d - i][c] = 0;
                else
                    break;
            }
        }
        for (int i = 1; i <= 8; i++) //下 
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
            for (int i = 1; i <= c - 1; i++) //左下 
            {
                if (qipan[d + i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d + i][c - i] = 0;
                else
                    break;
            }
        }
        if (d >= 2)
        {
            for (int i = 1; i <= d - 1; i++) //右上 
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

        for (int i = 1; i <= 6; i++) //右下 
        {
            if (qipan[d + i][c + i] == qipan[d][c] && qipan[d][c] != 0)
                qipan[d + i][c + i] = 0;
            else
                break;
        }
        int t = (c > d ? d : c);
        if (t >= 2)
        {
            for (int i = 1; i <= t - 1; i++) //左上 
            {
                if (qipan[d - i][c - i] == qipan[d][c] && qipan[d][c] != 0)
                    qipan[d - i][c - i] = 0;
                else
                    break;
            }
        }
        
    }
}

void QIPAN::f() {         //整合计数函数与消除函数以简化main（）函数
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

