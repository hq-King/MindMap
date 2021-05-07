#ifndef _SAVE_H_
#define _SAVE_H_
#include "user.h"
#define FILEMAXNUM 100
#include "file.h"
//绘制保存界面
void DrawSave();
//保存界面调用
void SaveFunc(int *func,USER *u,struct mpdata *mp,int statue);
//更新历史
void Input_history(char *u, int n) ;
//更新版式
void Input_format(char *u, int n) ;
//更新上传文件数
void Input_num(char *u, int n) ; 
//存入文件目录
void Input_Cfilemenu(File *allfile, char *u)  ;
//导出文件目录
void Output_CFilemenu(File *allfile, char *u)   ;
//检查上传文件是否已经上传过
int check_cfile(USER *u,char *filename);
#endif