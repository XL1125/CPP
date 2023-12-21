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
    string m_sName;     //�ֿ���
    Depot *m_L;         //�ֿ�ͷָ��
public:
    static int ms_Num ;


public:
    int INPUT();                                   //����
    int ISEMPTY();                                 //���ֿ��Ƿ�Ϊ��
    int TOTAL();                                   //������Ʒ�������
    int GETGOODS();                                //��Ų�����Ʒ
    int LOCATEGOODS();                             //���Ʋ�����Ʒ
    int INSERT();                                  //��iλ�ò�����Ʒ
    int DELETE_();                                 //ɾ��iλ����Ʒ
    int UNION();                                   //���ֿ�Lb�ϲ���La
    int DISPALYGOODS();                            //չʾȫ����Ʒ
    int CLEAR();                                   //���ֿ��ÿ�
    int DESTROY();                            //���ٲֿ�
    int DESTROY(WH *wh);
public:
    static int INIT();                              //��ʼ���ֿ�
    static void DISPALYWh();                        //չʾȫ����

};

extern WH *g_Warehouse;

#endif
