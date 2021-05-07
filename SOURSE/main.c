#include"common.h"
#include"forget.h"
#include"login.h"
#include"register.h"
#include"drawmenu.h"
#include"USER.h"
#include"mouse.h"
#include"save.h"
#include"history.h"
#include"help.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "visitor.h"
#include "compare.h"
#include "communit.h"
#include"outline.h"

/*************************************************************
函数名：main()
参数：无
返回值：无
函数功能：创建数据结构,初始化图形界面,跳转页面
**************************************************************/	
void main()
{		
    int func=0;
    int statue = 0;
    int tate=3;
    int gm,gd;
    int judge=0;
    int MY,MX,BUTTON;
    //创建程序所需要的数据结构
    struct mpdata mp;
    struct mpdata visitor;
    struct comparedata CMP; 
    COM zs;
    USER u;
	gm=VGA;
    gd=VGAHI;
    memset(&u,'\0',sizeof(USER));
    initgraph(&gm,&gd,".\\BORLANDC\\BGI");
    mouseinit();
    welcome();
    //跳转页面
    while(1)
    {
        switch(func)
        {

            //登陆页面
		    case 0:
            Userslogin_func(&func,&u,&visitor,&judge);
            break;

            //注册页面
			case 1:
			zhuce_func(&func);
			break;
			
            //找回密码页面
			case 2:
			forget_func(&func);
			break;
			
            //选择思维导图版式页面
			case 3:
            select(&func,&mp,&statue,&u,judge,&tate);		
            break;
            
            //保存页面
            case 4:
			SaveFunc(&func,&u,&mp,statue);
            break;

            //历史页面
            case 5:
            History_Func(&func,&u,&mp,statue,&CMP);
            break;

            //帮助页面
			case 6:
            Help_Func(&func,statue);
            break;

            //关于页面
            case 7:
            About_func(&func,statue);
            break;

            //版式1的主界面
            case 8:
			menu_func(1,&func,&mp,&u);
			break;

            //版式2的主界面
            case 9:
            menu_func(2,&func,&mp,&u);
            break;

            //游客访问的主界面
            case 10 :
            Visitor_Func(1,&func,&visitor);
            break;

            //对比模式的主界面
            case 11:
			comparefunc(&func,&u,&CMP,tate);
            break;
            
            //社区的主界面
            case 12:
            Community_func(&func,&u,&mp,&CMP);
            break;

            //
            case 13:
            DRAW(&func,&CMP);
            break;

            //版式1的大纲模式
            case 14:
            outline_func(1, &func, mp);
            break;

            //版式2的大纲模式
            case 15:
            outline_func(2, &func, mp);
            break;
        }
    }
    getch();
	closegraph();
}


