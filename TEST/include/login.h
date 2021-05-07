#ifndef  _LOGIN_H__
#define  _LOGIN_H__
#include "USER.h"

//登录界面的功能选择
void Userslogin_func(int *func,USER*u, struct mpdata *mp,int * judge) ;
//登录界面的绘制
void draw_login(void) ;
//用来判断登录信息是否输入完全和正确
int login_complete(char* u, char* p);
//判断用户名与密码是否匹配
int login(char* name, char*password);
#endif