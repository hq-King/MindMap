#ifndef  _FILE_H__
#define  _FILE_H__
#include "USER.h"
#define FILEMAX 10


typedef struct file
{
	char name[8];		
	int format;			
	char filetime[30];	
}File;


typedef struct Zfile
{
	char user[20];
	char name[8];		
	int format;			
	char filetime[30];	
}ZFile;

struct ZSdata {
	char user[20];
	char filename[20];
	char filetime[30];
	int history;
	int format;	
};
//
void SORT_filemenu(File *allfile, int format, int n);
//从指定文件导出数据
void Output_File(char *u ,struct mpdata *mp,char * filename) ;
//存入文件
void Input_data(char *u , struct mpdata *mp);
//存入文件
void Input_filedata( char *u , struct mpdata *mp,char *filename)  ;
//获取当前时间
void Get_filetime(char *filetime)  ; 
//检查文件情况
int Judge_Filename(char *name, int x, int y);
//检查文件是否重名
int Check_SameFile(char *newname, File* allfile, int n);
//检查文件情况
int Examine_Filename(USER *u, File* allfile, char *newname);  
//创建用户文件夹
void Createfolder(char *name);
//插入文件并且排序
void Insert_filemenu(File *allfile, char *filename, int format, int n)  ;
//
void Insert_Cfilemenu(ZFile *allfile, char *filename, int format, int n, char*user)  ;
//
void Drawpoint(int x, int y) ;
//导出文件目录
void Output_Filemenu(File *allfile, char *u) ;
//存入文件目录
void Input_filemenu(File *allfile, char *u)  ; 
//打印文件目录
void Print_Filemenu(File *allfile, int n)  ; 
//文件名输入函数
void EnterFileName(char*id, int x1, int y1, int charnum, int color);
//导出文件
void Outputdata(char *u ,struct mpdata *mp)   ;
//将数据库中用户信息导入指针
int Copy_infor_User(USER *user);
//把用户注册信息写入文件
void inputtofile(char* name, char* tel, char* password);
//删除文件数据
void Delete_filedata(char *u, char *filename) ; 
//删除文件目录里的信息
void Delete_filename(File *allfile, char *filename, int n)  ; 
//
int Change_format(char *filename, File *allfile, int n);
//
void Change_filemenu(File *allfile, char *filename, int format)  ;
//从指定文件导出数据
void Output_Cfile(char *u ,struct comparedata *mp,char * filename)   ;
#endif