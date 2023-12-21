//
// Created by Kiko on 2022/11/4.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "WH.h"
#include "Warehouse.h"

WH *g_Warehouse = nullptr;
int WH::ms_Num = 0;
static bool s_IsCreate = false;
static bool s_IsTwice = false;

int WH::INIT(){
    if( !s_IsTwice ){
        if( s_IsCreate ){
            cout << "\n\n\n"
                    "\t\t-----------------------------------------------------" << endl;
            for( int j = 0; j < ms_Num; ++j ){
                cout << "\t\t\t\t�������" << j + 1 << "���ֿ�����֣�" << endl << "\t\t\t\t";
                cin >> g_Warehouse[j].m_sName;
                g_Warehouse[j].m_ID = j + 1;
                Init(g_Warehouse[j].m_L);
            }
            system("cls");
            cout << "\n\n\n"
                    "\t\t-----------------------------------------------------" << endl;
            cout << "\t\t\t\t\t�������" << endl;
            cout << "\t\t-----------------------------------------------------" << endl;
            s_IsTwice = true;
            Sleep(1000);
            system("cls");
            return 0;
        }
        else{
            cout << "\n\n\n"
                    "\t\t-------------------------------------------" << endl;
            cout << "\t\t\t\t��Ҫ���������ֿ⣿" << endl << "\t\t\t\t";
            cin >> ms_Num;

            if( ms_Num > 0 ){
                g_Warehouse = new WH[ms_Num];
                s_IsCreate = true;
                system("cls");
                cout << "\n\n\n"
                        "\t\t----------------------------------------------" << endl;
                cout << "\n\t\t\t\t�ɹ�����" << ms_Num << "���ֿ�" << endl;
                cout << "\n\t\t----------------------------------------------" << endl;
                Sleep(1000);
                system("cls");
                return 0;
            }
            else{
                cin.clear();
                cin.sync();
                cout << "\n\t\t\t\t�Ƿ���ֵ" << endl;
                Sleep(1000);
                system("cls");
                return -1;
            }
        }
    }
    else{
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t���Ѿ��ɹ������˲ֿ�" << endl;
        cout << "\t\t-------------------------------------------" << endl;
        system("pause");
        return 1;
    }
}

void WH::DISPALYWh(){

    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;

    for( int i = 0; i < ms_Num; ++i ){
        cout << "\t\t      " << g_Warehouse[i].m_ID << "." + g_Warehouse[i].m_sName;
        if((i + 1) % 2 == 0 )
            cout << endl;
    }
    cout << "\n\t\t-------------------------------------------" << endl;

}

int WH::INPUT(){
    system("cls");
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t��Ҫ��Ӷ��ٸ���Ʒ��" << endl << "\t\t\t\t";
    int x{0};
    cin >> x;
    cout << "\t\t-------------------------------------------" << endl;
    Sleep(1000);
    system("cls");
    Input(m_L, x);
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t��ӳɹ�" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    Sleep(1000);
    return 0;
}

int WH::DESTROY(WH *wh){
    int i(m_ID);
    WH *p = &(wh[i - 1]);
    for( ; p < &(wh[ms_Num - 1]); ++p ){
        (p + 1)->m_ID--;
        *p = *(p + 1);
    }
    ms_Num--;
    return 0;
}

int WH::DESTROY(){
    system("cls");
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t�Ƿ����ٴ˲ֿ⣺" << m_sName << endl;
    cout << "\t\t\t\t1.YES       2.NO" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    if( getch() == '1' ){
        Destroy(m_L);
        DESTROY(g_Warehouse);
        return 0;
    }
    else{

        return -1;
    }
}

int WH::CLEAR(){
    system("cls");
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t�Ƿ���մ˲ֿ⣺" << m_sName << endl;
    cout << "\t\t\t\t1.YES       2.NO" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    if( getch() == '1' ){
        Clear_(m_L);
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;
        cout << "������մ˲ֿ⣬���Ե�........" << endl;
        Sleep(1200);
        cout << "�����ϡ�" << endl;
        cout << "\t\t-------------------------------------------" << endl;
        Sleep(200);
        return 0;
    }
    else{
        return -1;
    }
}

int WH::ISEMPTY(){
    system("cls");
    if( IsEmpty(m_L)){
        system("cls");
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;

        cout << "\t\t\t\t�˲ֿ�û���κ���Ʒ��" << endl;

        cout << "\t\t-------------------------------------------" << endl;
    }
    else{
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t�˲ֿ�����Ʒ��" << endl;
        cout << "\t\t-------------------------------------------" << endl;
    }
    return 0;
}

int WH::TOTAL(){
    system("cls");
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t" << m_sName << "����һ����" << Total(m_L) << "����Ʒ" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    return 0;
}

int WH::GETGOODS(){
    system("cls");
    int i;
    Goods e;
    cout << "\n\n\n"
            "\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t\t��������Ʒ��ţ�" << endl << "\t\t\t\t";
    cin >> i;
    GetGoods(m_L, i, e);
    cout << "\n"
            "\t\t-------------------------------------------------------" << endl;
    Output(e);
    cout << "\t\t-------------------------------------------------------" << endl;
    return 0;
}

int WH::LOCATEGOODS(){
    system("cls");
    string name;
    Goods e;
    cout << "\n\n\n"
            "\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t\t��������Ʒ���ƣ�" << endl << "\t\t\t\t";
    cin >> name;
    int i = LocateGoods(m_L, name);
    cout << "\t\t\t\t����Ʒ�����Ϊ��" << i << endl;
    GetGoods(m_L, i, e);
    cout << "\n"
            "\t\t-------------------------------------------------------" << endl;
    Output(e);
    cout << "\t\t-------------------------------------------------------" << endl;
    return 0;
}

int WH::INSERT(){
    system("cls");
    int i;
    Depot *p;
    Goods e;
    cout << "\n\n\n"
            "\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t\t��Ҫ�ڵڼ���λ�ò�����Ʒ��" << endl << "\t\t\t\t";
    cin >> i;
    system("cls");
    Insert(m_L, i);
    cout << "\n"
            "\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t����ɹ�" << endl;
    cout << "\t\t-------------------------------------------------" << endl;
    return 0;
}

int WH::DELETE_(){
    int i;
    cout << "��Ҫɾ���ڼ���λ�õ���Ʒ��" << endl;
    cin >> i;
    Delete_(m_L, i);
    cout << "\n"
            "\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\tɾ���ɹ�" << endl;
    cout << "\t\t-------------------------------------------------" << endl;
    return 0;
}

int WH::UNION(){

    return 0;
}

int WH::DISPALYGOODS(){
    system("cls");
    if( IsEmpty(m_L)){
        cout << "\n\n\n"
                "\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t\t�ֿ�Ϊ�գ�û�ж���" << endl;
        cout << "\t\t-------------------------------------------------------" << endl;
        return -1;
    }
    else
        Dispaly(m_L);
    return 0;
}

