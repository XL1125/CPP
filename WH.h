//
// Created by Kiko on 2022/11/4.
//

#ifndef WAREHOUSE_H_WH_H
#define WAREHOUSE_H_WH_H

#include <iostream>
#include "Warehouse.h"

using namespace std;

class WH{
public:
    int m_ID;
    string m_sName;     //仓库名
    Depot *m_L;         //仓库头指针
public:
    static int ms_Num ;


public:
    int INPUT();                                   //建库
    int ISEMPTY();                                 //检测仓库是否为空
    int TOTAL();                                   //计算商品种类个数
    int GETGOODS();                                //序号查找商品
    int LOCATEGOODS();                             //名称查找商品
    int INSERT();                                  //在i位置插入商品
    int DELETE_();                                 //删除i位置商品
    int UNION();                                   //将仓库Lb合并到La
    int DISPALYGOODS();                            //展示全部商品
    int CLEAR();                                   //将仓库置空
    int DESTROY();                            //销毁仓库
    int DESTROY(WH *wh);
public:
    static int INIT();                              //初始化仓库
    static void DISPALYWh();                        //展示全部库

};

extern WH *g_Warehouse;

#endif
