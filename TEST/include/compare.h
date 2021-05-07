#ifndef  _COMPARE_H__
#define  _COMPARE_H__
#include "user.h"
//绘制对比模式
void draw_input_compare();
//对比功能调用
void comparefunc(int *func,USER *u,struct comparedata *CMP ,int tate);
//点亮文本框
void Light_Compare(int x, int y, int x1, int y1, int color1, int color2);
//绘制对比模式
void DRAW(int *func ,struct comparedata *CMP);
//存入文件
void Input_Cfiledata( char *u, char theme[][18],char similar[][20],char differ1[][20]
                    ,char differ2[][20],int si_num,int dif1_num,int dif2_num,char *filename);   

struct comparedata
{
    char theme[2][18];  
	char differ1[6][20];
    char differ2[6][20];
    char similar[6][20];
    int si_num;
	int dif1_num;
    int dif2_num;  
};

#endif
