//
// Created by Kiko on 2022/11/4.
//

#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "Warehouse.h"
#include "WH.h"

int Function(int (WH::*fun)());

void ShowMain(){
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t              1. 创 建 新 仓 库" << endl;
    cout << "\t\t              2. 查 看 仓 库 " << endl;
    cout << "\t\t              3. 操 作 仓 库 " << endl;
    cout << "\t\t              4. 退 出 程 序 " << endl;
    cout << "\t\t-------------------------------------------" << endl;

}

void ShowFun(){
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t              0. 添 加 商 品 至 仓 库 " << endl;
    cout << "\t\t              1. 空  仓  库  检  测 " << endl;
    cout << "\t\t              2. 展 示 全 部 商 品 " << endl;
    cout << "\t\t              3. 商 品 种 类 个 数 " << endl;
    cout << "\t\t              4. 序 号 查 找 商 品 " << endl;
    cout << "\t\t              5. 名 称 查 找 商 品 " << endl;
    cout << "\t\t              6. 插  入  商  品 " << endl;
    cout << "\t\t              7. 删  除  商  品 " << endl;
    cout << "\t\t              8. 清  空  仓  库 " << endl;
    cout << "\t\t              9. 销  毁  仓  库 " << endl;
    cout << "\t\t            ESC. 返 回 上 级 菜 单 " << endl;
    cout << "\t\t-------------------------------------------" << endl;

}

void ShowWh(){
    WH::DISPALYWh();
}

void Menu1(){
    while( 1 ){
        system("cls");
        ShowMain();
        switch( getch()){
            case '1':{
                system("cls");
                int i = 0, j = 0;
                while( i < 2 && j == 0 ){
                    j = WH::INIT();
                    ++i;
                }
                break;
            }
            case '2':
                system("cls");
                WH::DISPALYWh();
                system("pause");
                break;
            case '3':
                system("cls");
                Menu2();
                break;
            case '4':
                exit(0);
            default:
                cout << "无效选择" << endl;
                system("pause");
                break;
        }
    }
}

void Menu2(){
    system("cls");
    ShowFun();
    switch( getch()){
        case '0'://添 加 商 品
            system("cls");
            Function(&WH::INPUT);
            break;
        case '1':{//空  仓  库  检  测
            system("cls");
            Function(&WH::ISEMPTY);
            break;
        }
        case '2'://展 示 全 部 商 品
            system("cls");
            Function(&WH::DISPALYGOODS);
            break;
        case '3'://商 品 种 类 个 数
            system("cls");
            Function(&WH::TOTAL);
            break;
        case '4'://序 号 查 找 商 品
            system("cls");
            Function(&WH::GETGOODS);
            break;
        case '5'://名 称 查 找 商 品
            system("cls");
            Function(&WH::LOCATEGOODS);
            break;
        case '6'://插  入  商  品
            system("cls");
            Function(&WH::INSERT);
            break;
        case '7'://删  除  商  品
            system("cls");
            Function(&WH::DELETE_);
            break;
        case '8'://清  空  仓  库
            system("cls");
            Function(&WH::CLEAR);
            break;
        case '9'://销  毁  仓  库
            system("cls");
            Function(&WH::DESTROY);
            break;
        case 27:
            system("cls");
            Menu1();
        default:
            cout << "无效" << endl;
            break;
    }

}

//succeed
void suc(){
    system("cls");
    cout << "正在返回上级菜单........" << endl;
    Sleep(600);

}

WH *Choose(){
    int i = 0;
    system("cls");
    WH::DISPALYWh();
    cout << "请选择需要操作的仓库(输入0返回上级菜单)：" << endl;
    cin >> i;
    if( i < 0 || i > WH::ms_Num )
        Choose();
    else if(i == 0)
        Menu2();
    else
        return &g_Warehouse[i - 1];
}

int Function(int (WH::*fun)()){
    WH *e = Choose();
    (e->*fun)();
    system("pause");
    suc();
    Menu2();
    return 0;
}
