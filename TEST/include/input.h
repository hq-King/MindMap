#ifndef _INPUT_H_
#define _INPUT_H_

int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color);
//汉字输入法
int input_method(int x,int y,char *str,int value,char *py) ;
//汉字输入法调入
char *itostr(int a,char *s);
//数字标号
void pyFrm(int x1,int y1,int x2,int y2);
// /输入法小框
int xouttextxy(int x,int y,char *s,int color);
//字符输入法
void hz_int(int x1,int y1,int x2,int y2,char *s,int color);
//汉字字符换行显示

#endif
