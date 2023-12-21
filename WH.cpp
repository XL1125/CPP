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
                cout << "\t\t\t\t请输入第" << j + 1 << "个仓库的名字：" << endl << "\t\t\t\t";
                cin >> g_Warehouse[j].m_sName;
                g_Warehouse[j].m_ID = j + 1;
                Init(g_Warehouse[j].m_L);
            }
            system("cls");
            cout << "\n\n\n"
                    "\t\t-----------------------------------------------------" << endl;
            cout << "\t\t\t\t\t输入完毕" << endl;
            cout << "\t\t-----------------------------------------------------" << endl;
            s_IsTwice = true;
            Sleep(1000);
            system("cls");
            return 0;
        }
        else{
            cout << "\n\n\n"
                    "\t\t-------------------------------------------" << endl;
            cout << "\t\t\t\t您要创建几个仓库？" << endl << "\t\t\t\t";
            cin >> ms_Num;

            if( ms_Num > 0 ){
                g_Warehouse = new WH[ms_Num];
                s_IsCreate = true;
                system("cls");
                cout << "\n\n\n"
                        "\t\t----------------------------------------------" << endl;
                cout << "\n\t\t\t\t成功创建" << ms_Num << "个仓库" << endl;
                cout << "\n\t\t----------------------------------------------" << endl;
                Sleep(1000);
                system("cls");
                return 0;
            }
            else{
                cin.clear();
                cin.sync();
                cout << "\n\t\t\t\t非法数值" << endl;
                Sleep(1000);
                system("cls");
                return -1;
            }
        }
    }
    else{
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t你已经成功创建了仓库" << endl;
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
    cout << "\t\t\t\t需要添加多少个商品？" << endl << "\t\t\t\t";
    int x{0};
    cin >> x;
    cout << "\t\t-------------------------------------------" << endl;
    Sleep(1000);
    system("cls");
    Input(m_L, x);
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t添加成功" << endl;
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
    cout << "\t\t\t\t是否销毁此仓库：" << m_sName << endl;
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
    cout << "\t\t\t\t是否清空此仓库：" << m_sName << endl;
    cout << "\t\t\t\t1.YES       2.NO" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    if( getch() == '1' ){
        Clear_(m_L);
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;
        cout << "正在清空此仓库，请稍等........" << endl;
        Sleep(1200);
        cout << "清空完毕。" << endl;
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

        cout << "\t\t\t\t此仓库没有任何商品。" << endl;

        cout << "\t\t-------------------------------------------" << endl;
    }
    else{
        cout << "\n\n\n"
                "\t\t-------------------------------------------" << endl;
        cout << "\t\t\t\t此仓库有商品。" << endl;
        cout << "\t\t-------------------------------------------" << endl;
    }
    return 0;
}

int WH::TOTAL(){
    system("cls");
    cout << "\n\n\n"
            "\t\t-------------------------------------------" << endl;
    cout << "\t\t\t\t" << m_sName << "库中一共有" << Total(m_L) << "种商品" << endl;
    cout << "\t\t-------------------------------------------" << endl;
    return 0;
}

int WH::GETGOODS(){
    system("cls");
    int i;
    Goods e;
    cout << "\n\n\n"
            "\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t\t请输入商品序号：" << endl << "\t\t\t\t";
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
    cout << "\t\t\t\t请输入商品名称：" << endl << "\t\t\t\t";
    cin >> name;
    int i = LocateGoods(m_L, name);
    cout << "\t\t\t\t此商品的序号为：" << i << endl;
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
    cout << "\t\t\t\t需要在第几个位置插入商品？" << endl << "\t\t\t\t";
    cin >> i;
    system("cls");
    Insert(m_L, i);
    cout << "\n"
            "\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t插入成功" << endl;
    cout << "\t\t-------------------------------------------------" << endl;
    return 0;
}

int WH::DELETE_(){
    int i;
    cout << "需要删除第几个位置的商品？" << endl;
    cin >> i;
    Delete_(m_L, i);
    cout << "\n"
            "\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t删除成功" << endl;
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
        cout << "\t\t\t\t仓库为空，没有东西" << endl;
        cout << "\t\t-------------------------------------------------------" << endl;
        return -1;
    }
    else
        Dispaly(m_L);
    return 0;
}

