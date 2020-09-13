#include"QIPAN.h"
#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <ctime> 
#include <cstdlib> 
using namespace std;

int main()
{
    srand(time(NULL));
    QIPAN A, B;    //定义对象A，B
    A.fuzhi();     //初始化并生成棋盘
    A.qizi2();
    A.shengcheng();
    cout << "双击空格键开始游戏" << endl;            //开始游戏
    cout << "请输入你想移动的棋子起始坐标与目的坐标" << endl;
    char xx = _getch();

    while (xx = _getch()) {     //按任意键后激活游戏
        cin >> B.a >> B.b >> B.c >> B.d;   //输入起始坐标与终止坐标
        B.AA();               //移动棋子
        if (B.A == 0) {
            cout << "错误!该位置无棋子！" << endl;
            continue;
        }
        if (B.Z != 0) {
            cout << "错误!请重新移动至无棋子处！" << endl;
            continue;
        }
        if (B.a > 9 || B.b > 9 || B.c > 9 || B.d > 9) {
            cout << "请在棋盘范围内移动棋子！" << endl;
            continue;
        }
        
        B.lujing1(B.b, B.a);
        B.lujing2();
        if (qipan1[B.d][B.c] == 1) {
            qipan[B.d][B.c] = B.A;
            qipan[B.b][B.a] = 0;
        }
        else {
            cout << "错误！无可用路径用于移动棋子！" << endl;
            continue;
        }
        for (int h = 1; h < 10; h++) {          
            for (int l = 1; l < 10; l++) {
                qipan1[h][l] = 0;
            }
        }
        B.f();         //计数并消除满足条件的相连棋子
        B.qizi();      //随机生成三个棋子

        QIPAN C, D, E; //定义对象C，D，E
        C.c = B.I;     //判断新生成的棋子1是否满足消除条件但不计分
        C.d = B.J;
        C.f();

        D.c = B.M;     //判断新生成的棋子2是否满足消除条件但不计分
        D.d = B.N;
        D.f();

        E.c = B.P;     //判断新生成的棋子3是否满足消除条件但不计分
        E.d = B.Q;
        E.f();

        system("cls"); //消除旧棋盘
        B.shengcheng();//生成移动后新棋盘
        cout << "请按空格键后输入你想移动的棋子起始坐标与目的坐标" << endl;
        B.score();     //输出得分
        B.over();      //判断游戏是否结束
        B.guiyi();     //将四个计数数据归一
        C.guiyi();
        D.guiyi();
        E.guiyi();
    }
    return 0;
}

