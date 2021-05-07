#ifndef _SELECT_H__
#define _SELECT_H__
#include "USER.h"
//选择调用
void select(int *func, struct mpdata *mp,int *statue,USER *u,int judge,int *tate);
//高亮
void Light_Select(int n);
//恢复高亮
void Recover_Select(int n);
#endif
