//
// Created by Kiko on 2022/11/3.
//

#ifndef W_H_MANAGESYSTEM_WAREHOUSE_H
#define W_H_MANAGESYSTEM_WAREHOUSE_H

#include <iostream>

using namespace std;
struct Depot;
struct Goods{
    string sName;
    int iNumber;
    double dUnitPrice;
};

struct Depot{
    Goods goods;
    Depot *next;
};

void Init(Depot *&L);                              //��ʼ���ֿ�
void Input(Depot *&L, int n);                      //ͷ�巨����
void Destroy(Depot *&L);                           //���ٲֿ�
void Clear_(Depot *&L);                              //���ֿ��ÿ�
bool IsEmpty(Depot *L);                            //���ֿ��Ƿ�Ϊ��
int Total(Depot *L);                               //������Ʒ�������
Depot *GetGoods(Depot *L, int i,Goods &e);          //��Ų�����Ʒ
int LocateGoods(Depot *L, string s);                  //���Ʋ�����Ʒ
void Insert(Depot *&L, int i);              //��iλ�ò�����Ʒ
void Delete_(Depot *&L, int i);                     //ɾ��iλ����Ʒ
void Union(Depot *&La, Depot *&Lb);                //���ֿ�Lb�ϲ���La
void Dispaly(Depot *L);                             //չʾȫ����Ʒ
void Output(Goods x);                             //����ַ���
void Cin(Depot *&L);

#endif
