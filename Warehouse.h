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

void Init(Depot *&L);                              //初始化仓库
void Input(Depot *&L, int n);                      //头插法建库
void Destroy(Depot *&L);                           //销毁仓库
void Clear_(Depot *&L);                              //将仓库置空
bool IsEmpty(Depot *L);                            //检测仓库是否为空
int Total(Depot *L);                               //计算商品种类个数
Depot *GetGoods(Depot *L, int i,Goods &e);          //序号查找商品
int LocateGoods(Depot *L, string s);                  //名称查找商品
void Insert(Depot *&L, int i);              //在i位置插入商品
void Delete_(Depot *&L, int i);                     //删除i位置商品
void Union(Depot *&La, Depot *&Lb);                //将仓库Lb合并到La
void Dispaly(Depot *L);                             //展示全部商品
void Output(Goods x);                             //输出字符串
void Cin(Depot *&L);

#endif
