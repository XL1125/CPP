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
    cout << "\t\t              1. �� �� �� �� ��" << endl;
    cout << "\t\t              2. �� �� �� �� " << endl;
    cout << "\t\t              3. �� �� �� �� " << endl;
    cout << "\t\t              4. �� �� �� �� " << endl;
    cout << "\t\t-------------------------------------------" << endl;

}

void ShowFun(){
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t              0. �� �� �� Ʒ �� �� �� " << endl;
    cout << "\t\t              1. ��  ��  ��  ��  �� " << endl;
    cout << "\t\t              2. չ ʾ ȫ �� �� Ʒ " << endl;
    cout << "\t\t              3. �� Ʒ �� �� �� �� " << endl;
    cout << "\t\t              4. �� �� �� �� �� Ʒ " << endl;
    cout << "\t\t              5. �� �� �� �� �� Ʒ " << endl;
    cout << "\t\t              6. ��  ��  ��  Ʒ " << endl;
    cout << "\t\t              7. ɾ  ��  ��  Ʒ " << endl;
    cout << "\t\t              8. ��  ��  ��  �� " << endl;
    cout << "\t\t              9. ��  ��  ��  �� " << endl;
    cout << "\t\t            ESC. �� �� �� �� �� �� " << endl;
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
                cout << "��Чѡ��" << endl;
                system("pause");
                break;
        }
    }
}

void Menu2(){
    system("cls");
    ShowFun();
    switch( getch()){
        case '0'://�� �� �� Ʒ
            system("cls");
            Function(&WH::INPUT);
            break;
        case '1':{//��  ��  ��  ��  ��
            system("cls");
            Function(&WH::ISEMPTY);
            break;
        }
        case '2'://չ ʾ ȫ �� �� Ʒ
            system("cls");
            Function(&WH::DISPALYGOODS);
            break;
        case '3'://�� Ʒ �� �� �� ��
            system("cls");
            Function(&WH::TOTAL);
            break;
        case '4'://�� �� �� �� �� Ʒ
            system("cls");
            Function(&WH::GETGOODS);
            break;
        case '5'://�� �� �� �� �� Ʒ
            system("cls");
            Function(&WH::LOCATEGOODS);
            break;
        case '6'://��  ��  ��  Ʒ
            system("cls");
            Function(&WH::INSERT);
            break;
        case '7'://ɾ  ��  ��  Ʒ
            system("cls");
            Function(&WH::DELETE_);
            break;
        case '8'://��  ��  ��  ��
            system("cls");
            Function(&WH::CLEAR);
            break;
        case '9'://��  ��  ��  ��
            system("cls");
            Function(&WH::DESTROY);
            break;
        case 27:
            system("cls");
            Menu1();
        default:
            cout << "��Ч" << endl;
            break;
    }

}

//succeed
void suc(){
    system("cls");
    cout << "���ڷ����ϼ��˵�........" << endl;
    Sleep(600);

}

WH *Choose(){
    int i = 0;
    system("cls");
    WH::DISPALYWh();
    cout << "��ѡ����Ҫ�����Ĳֿ�(����0�����ϼ��˵�)��" << endl;
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
