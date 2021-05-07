#ifndef  _USER_H__
#define  _USER_H__

typedef struct userinfo
{
	char user[15];           //6-12位，用户名
	char tel[15];             //11位，电话号码
	char password[15];       //6-12位，密码
	int history ;      		//用户文件历史 0或1
	int format;				//版式模块
	int num;
}USER;	
//封装用户信息




#endif