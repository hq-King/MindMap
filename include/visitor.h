#ifndef  _VISITOR_H__
#define  _VISITOR_H__
#include"mpfunc.h"
//绘制游客界面
void Draw_Visitor(struct mpdata *mp);
//游客界面调用
void Visitor_Func(int state, int *func, struct mpdata *mp);

#endif