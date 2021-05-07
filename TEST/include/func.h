#ifndef  _FUNC_H__
#define  _FUNC_H__

void inputadmin(char* id, int x1, int y1, int charnum, int color);
//输入账号框功能
void inputpassword(char* id, int x1, int y1, int charnum, int color);
//输入密码框功能
void panduan(char* s, int* jud, int x, int y,int color);
//s判断是否输入
int Search_S_user(char * name,int z);
//判断是否重复
int judge_name(char* s, int x, int y);
//判断用户名是否大于6位且小于12位
int judge_ispasswordsame(char* s1, char* s2, int x, int y);
//判断密码是否大于6位小于12位
int judge_tel(char* s, int x, int y,int z);
//判断电话号码是否符合格式

#endif