#ifndef _HISTORY_H_
#define _HISTORY_H_
#include "USER.h"
#include "file.h"
#include "compare.h"
void DrawHistory();
//绘制历史界面
void History_Func(int *func,USER *u,struct mpdata *mp,int statue,struct comparedata *CMP);
//调用历史功能
void Printfilemenu_History(File *allfile, int n);   //鎵撳嵃鏂囦欢鐩?褰?
//打印文件目录
int getfileformat(char *username, char *filename);
//得到指定文件版式
#endif