//
// Created by Kiko on 2022/11/3.
//

#include "Warehouse.h"


void Cin(Depot *&L){
    cout << "\n\n\n"
            "\t\t--------------------------------------------------------" << endl;
    cout << "\t\t\t\t请输入商品名称:" << endl << "\t\t\t\t";
    cin >> L->goods.sName;
    cout << "\t\t\t\t请输入商品数量(单位：件):" << endl << "\t\t\t\t";
    cin >> L->goods.iNumber;
    cout << "\t\t\t\t请输入商品单价(单位：元/件)" << endl << "\t\t\t\t";
    cin >> L->goods.dUnitPrice;
    system("cls");
}

void Dispaly(Depot *L){
    system("cls");
    Goods e;
    cout << "\n\n\n"
            "\t\t------------------------------------------------------" << endl;
    for( int i = 1; i <= Total(L); ++i ){
        GetGoods(L, i, e);
        Output(e);
    }
    cout << "\t\t------------------------------------------------------" << endl;
}

void Output(Goods x){
    printf("\t\t   商品名称：%-5s  数量：%3d件    单价：%4.2f 元/件\n", x.sName.c_str(), x.iNumber, x.dUnitPrice);
}

void Init(Depot *&L){
    L = new Depot;
    L->next = nullptr;
}

bool IsEmpty(Depot *L){
    return L->next == nullptr;
}

void Destroy(Depot *&L){
    Depot *p;
    while( L ){
        p = L;
        L = L->next;
        delete p;
    }
}

void Clear_(Depot *&L){
    Depot *p = L->next;
    Depot *q = nullptr;
    while( p ){
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;
}

int Total(Depot *L){
    Depot *p = L->next;
    int i = 0;
    while( p ){
        p = p->next;
        ++i;
    }
    return i;
}

Depot *GetGoods(Depot *L, int i, Goods &e){
    Depot *p = L->next;
    int j = 1;
    while( p && j < i ){
        p = p->next;
        ++j;
    }
    e = p->goods;
    return p;
}

int LocateGoods(Depot *L, string s){
    Depot *p = L->next;
    int i = 1;
    while( p && p->goods.sName != s ){
        p = p->next;
        ++i;
    }
    if( p ) return i;
    else return -1;
}

void Insert(Depot *&L, int i){
    Depot *p = L;
    int j = 0;
    while( p && j < i - 1 ){
        p = p->next;
        ++j;
    }
    if( !p || j > i - 1 ) return;
    Depot *s = new Depot;
    Cin(s);
    s->next = p->next;
    p->next = s;
}

void Delete_(Depot *&L, int i){
    Depot *q, *p;
    p = L;
    int j = 0;
    while( p && j < i - 1 ){
        p = p->next;
        ++j;
    }
    q = p->next;
    p->next = q->next;
    delete q;
}

void Input(Depot *&L, int n){
    Depot *p = nullptr;
    for( int i = 0; i < n; ++i ){
        p = new Depot;
        Cin(p);
        p->next = L->next;
        L->next = p;
    }
}

void Union(Depot *&La, Depot *&Lb){
    Depot *p = Lb->next, *s = nullptr;
    while( p != NULL ){
        s = new Depot;
        s->goods = p->goods;
        s->next = La->next;
        La->next = s;
        p = p->next;
    }
}