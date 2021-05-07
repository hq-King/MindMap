#include"save.h"
#include"common.h"
#include "file.h"
#include "popup.h"
#include "USER.h"
#include "history.h"
#include "LIGANDCO.h"
#include "compare.h"
/*************************************************************
函数名：void DrawSave()
参数：编号
返回值：无
函数功能：绘制保存界面
**************************************************************/
void DrawSave()
{
	int x=250,y=190;
	//大脑图案
	setbkcolor(WHITE);
    clrmous(MouseX,MouseY);
	setcolor(GREEN);
	setlinestyle(SOLID_LINE,0,3);
	moveto(x,y);       
	lineto(x,y-10);
	lineto(x+10,y-10);
	lineto(x+10,y-20);
	lineto(x+20,y-20);
	lineto(x+20,y-30);
	lineto(x+30,y-30);
	lineto(x+30,y-40);
	lineto(x+40,y-40);
	lineto(x+40,y-50);
	lineto(x+50,y-50);
	lineto(x+50,y-60);
	lineto(x+100,y-60);
	lineto(x+100,y-50);
	lineto(x+110,y-50);
	lineto(x+110,y-40);
	lineto(x+120,y-40);
	lineto(x+120,y-20);
	lineto(x+130,y-20);
	lineto(x+130,y-10);
	lineto(x+140,y-10);
	lineto(x+140,y+10);
	lineto(x+130,y+10);
	lineto(x+130,y+20);
	lineto(x+120,y+20);
	lineto(x+120,y+30);
	lineto(x+110,y+30);
	lineto(x+110,y+50);
	lineto(x+100,y+50);
	lineto(x+100,y+60);
	lineto(x+70,y+60);
	lineto(x+70,y+70);
	moveto(x+60,y+70);
	lineto(x+60,y+50);
	lineto(x+90,y+50);
	lineto(x+90,y+40);
	lineto(x+80,y+40);
	moveto(x+100,y+40);
	lineto(x+100,y+30);
	lineto(x+30,y+30);
	lineto(x+30,y+20);
	lineto(x+20,y+20);
	lineto(x+20,y+10);
	lineto(x+10,y+10);
	lineto(x+10,y);
	lineto(x,y);
	line(x+70,y-50,x+80,y-50);
	line(x+90,y-50,x+100,y-50);
	line(x+40,y-40,x+50,y-40);
	line(x+60,y-40,x+90,y-40);
	line(x+30,y-30,x+40,y-30);
	line(x+50,y-30,x+100,y-30);
	line(x+20,y-20,x+40,y-20);
	line(x+50,y-20,x+70,y-20);
	line(x+80,y-20,x+110,y-20);
	line(x+10,y-10,x+30,y-10);
	line(x+40,y-10,x+60,y-10);
	line(x+80,y-10,x+90,y-10);
	line(x+100,y-10,x+120,y-10);
	line(x+30,y,x+40,y);
	line(x+50,y,x+60,y);
	line(x+70,y,x+80,y);
	line(x+90,y,x+110,y);
	line(x+120,y,x+130,y);
	line(x+20,y+10,x+30,y+10);
	line(x+50,y+10,x+60,y+10);
	line(x+70,y+10,x+90,y+10);
	line(x+100,y+10,x+110,y+10);
	line(x+30,y+20,x+40,y+20);
	line(x+50,y+20,x+70,y+20);
	line(x+80,y+20,x+90,y+20);
	line(x+100,y+20,x+110,y+20);
	line(x+20,y-10,x+20,y);
	line(x+30,y-10,x+30,y);
	line(x+40,y-20,x+40,y-10);
	line(x+40,y+10,x+40,y+20);
	line(x+50,y-30,x+50,y-20);
	line(x+50,y-10,x+50,y);
	line(x+50,y+20,x+50,y+30);
	line(x+60,y-50,x+60,y-40);
	line(x+60,y+10,x+60,y+20);
	line(x+70,y-20,x+70,y-10);
	line(x+70,y,x+70,y+10);
	line(x+80,y-60,x+80,y-50);
	line(x+80,y-20,x+80,y);
	line(x+80,y+20,x+80,y+40);
	line(x+90,y-40,x+90,y-30);
	line(x+90,y,x+90,y+20);
	line(x+100,y-50,x+100,y-40);
	line(x+100,y-30,x+100,y-20);
	line(x+100,y-10,x+100,y);
	line(x+110,y-30,x+110,y-20);
	line(x+110,y,x+110,y+10);
	line(x+110,y+20,x+110,y+30);
	line(x+120,y,x+120,y+30);    


	
	puthz(160, 10, "保存您的头脑风暴", 32, 42, YELLOW);
	setfillstyle(1, GREEN);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(LIGHTGRAY);
	bar(190, 435, 190+80, 435+25);
	rectangle(190, 435, 190+80, 435+25);
	puthz(209,440,"确认",16,28,WHITE);
	
	bar(370, 435, 370+80, 435+25);
	rectangle(370, 435, 370+80, 435+25);
	puthz(389, 440, "取消", 16, 28, WHITE);
	
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);	
	setcolor(GREEN);
	setfillstyle(1, WHITE);
	puthz(100, 335+3, "请输入要保存的文件名", 24, 25, BLUE);
	puthz(100, 370+3, "请输入要收藏的文件名", 24, 25, BLUE);
	bar(360, 335, 555, 335+30);
	rectangle(360, 335, 555, 335+30);
	bar(360, 375, 555, 375+30);
	rectangle(360, 375, 555, 375+30);
	
	puthz(566, 335+6, "小于七位", 16, 16, BLUE); 
	puthz(566, 375+6, "小于七位", 16, 16, BLUE); 


}

/*************************************************************
函数名：void SaveFunc(int *func,USER *u,struct mpdata *mp,int statue)
参数：界面跳转参数,用户结构体指针,思维导图结构体指针,版式判断参数
返回值：无
函数功能：保存界面调用
**************************************************************/

void SaveFunc(int *func,USER *u,struct mpdata *mp,int statue)
{
	File allfile[FILEMAX];
	File cfile[FILEMAX];
	char filename[20];
	int fun = 0;
	int l=0;
	int state=0;
	int j;
	int i;
	int o=0;
	//初始化保存文件和上传文件
	for(i=0;i<FILEMAX;i++)
		{
			memset(&allfile[i],'\0',sizeof(File));
		}
	for(i=0;i<FILEMAX;i++)
		{
			memset(&cfile[i],'\0',sizeof(File));
		}
	DrawSave();


	if(u->history != 0)
	{
		Output_Filemenu(allfile, u->user);
	}
	//导出已保存文件
	
	if(u->num!=0)
	{
		Output_CFilemenu(cfile, u->user);
	}
	//导出已经上传的文件
	

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//确认按钮
		if(MouseX > 190 && MouseY>435 && MouseX < 190+80 && MouseY <435+25 )

		{
			if ( mouse_press(190, 435, 190+80, 435+25) == 2)
			//未点击
			{
				MouseS = 1;
				continue;
			}

			if( mouse_press(190, 435, 190+80, 435+25) == 1)
			//点击
			{
				clrmous(MouseX, MouseY);
				fun = Examine_Filename(u, allfile, filename);
				if(fun == 1 || fun ==3)
				{
					if(state==1)
					{
						u->history ++;
						Insert_filemenu(allfile, filename, u->format, u->history);
						Input_data(u->user,mp);
						Input_history(u->user,u->history);
						Input_format(u->user, u->format);
						Input_filemenu(allfile, u->user);
						Input_filedata(u->user,mp,filename);
						puthz(260,412,"保存成功",24,30,BLUE);
						delay(1500);
						cover_save(260, 412,WHITE);
						state = 0;
						clrmous(MouseX,MouseY);
						cleardevice();
						*func = 4;
						return;
					}
				}
				if(fun == 2 && state ==1)
				//保存
				{
					puthz(260,412,"文件存在",24,30,BLUE);
					delay(1500);
					cover_save(260, 412,WHITE);
					state = 0;
					clrmous(MouseX,MouseY);
					cleardevice();
					*func = 4;
					return;
				}
				//上传文件不存在
				if(fun != 2 && state==2)
				{
					puthz(260,412,"无此文件",24,30,BLUE);
					delay(1500);
					cover_save(260, 412,WHITE);
					state = 0;
					clrmous(MouseX,MouseY);
					cleardevice();
					*func = 4;
					return;
				}
				//首次上传
				if(fun == 2 && state ==2 && u->num == 0)
				//上传
				{
					u->num++;
					Insert_filemenu(cfile, filename, j, u->num);
					Input_num(u->user,u->num);
					Input_Cfilemenu(cfile, u->user);																
					state = 0;
					puthz(260,412,"上传成功",24,30,BLUE);
					delay(1500);
					cover_save(260, 412,WHITE);
					clrmous(MouseX,MouseY);
					cleardevice();
					*func = 4;
					return;
				}

				//非首次上传
				if(fun == 2 && state ==2 && u->num != 0)
				//上传
				{
					for(o=0;o<u->num;o++)
					{
						if(strcmp(filename,cfile[o].name)==0)
						//判断是否已经上传过
						{
							l=1;
							break;
						}
						else
						{
							continue;
						}
					}
				
					if(l !=1 )
					{					
						u->num++;
						Insert_filemenu(cfile, filename, j, u->num);
						Input_num(u->user,u->num);
						Input_Cfilemenu(cfile, u->user);																
						state = 0;
						puthz(260,412,"上传成功",24,30,BLUE);
						delay(1500);
						cover_save(260, 412,WHITE);		
						clrmous(MouseX,MouseY);
						cleardevice();	
						*func = 4;
						return;
					}

					if(l == 1)
					{
						puthz(260,412,"已经上传",24,30,BLUE);	
						delay(1500);
						cover_save(260, 412,WHITE);
						clrmous(MouseX,MouseY);
						cleardevice();
						*func = 4;
						return;
					}
				}

			}
		}

		if(MouseX > 370 && MouseY>435 && MouseX < 450 && MouseY <435+25 )

		{
			if ( mouse_press(370, 435, 370+80, 435+25) == 2)
			//未点击
			{
				MouseS = 1;
				continue;
			}

			if( mouse_press(370, 435, 370+80, 435+25) == 1)
			//点击
			{
				if(statue == 1)
				{
					clrmous(MouseX, MouseY);
					cleardevice();
					*func = 8;
					return;

				}

				if(statue == 2)
				{
					clrmous(MouseX, MouseY);
					cleardevice();
					*func = 9;
					return;

				}
			}
		}

		if(mouse_press(360, 335, 555, 335+30)==1)
		{
			clrmous(MouseX, MouseY);
			cover_save(480, 310,WHITE);
			Light_Compare(360, 335, 555, 335+30,BLUE,WHITE);
			filename[0]='\0';
			EnterFileName(filename,360,335,7,WHITE);
			state=1;
			continue;
		}

		if(mouse_press(360, 375, 555, 375+30)==1)
		{
			clrmous(MouseX, MouseY);
			cover_save(480, 310,WHITE);
			Light_Compare(360, 375, 555, 375+30,BLUE,WHITE);
			filename[0]='\0';
			EnterFileName(filename,360,375,7,WHITE);
			j=getfileformat(u->user,filename);
			state=2;
			continue;
			
		}

        if(MouseS != 0)
        {
            MouseS = 0;
            continue;
        }



    }
}


/*************************************************************
函数名：void Input_history(char *u, int n)  
参数：用户名,个数
返回值：无
函数功能：更新历史
**************************************************************/
void Input_history(char *u, int n)    
{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	 //打开用户数据库
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
		//exit(1);
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	
	if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c6");
			delay(2000);
			//exit(1);
		}
	
	for(i = 0; i < num; i++)
	{
		
		fseek(fp, i*sizeof(USER), SEEK_SET);
		fread(p, sizeof(USER), 1, fp);
		fseek(fp, i*sizeof(USER), SEEK_SET);   
		 //重新定位，解决fwrite无法写入的问题
		if(strcmp(p->user, u) == 0)
		{
			p->history = n;
			fwrite(p, sizeof(USER), 1, fp);
		
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				//exit(1);
			}
			return;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
	//printf("wrong");
	//exit(1);
}

/*************************************************************
函数名：void Input_format(char *u, int n)  
参数：用户名,个数
返回值：无
函数功能：更新版式
**************************************************************/
void Input_format(char *u, int n) 
{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat","rb+")) == NULL) 
	//打开用户数据库
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	
	if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c7");
			delay(2000);
			exit(1);
		}
	
	for(i = 0; i < num; i++)
	{
		
		fseek(fp, i*sizeof(USER), SEEK_SET);
		fread(p, sizeof(USER), 1, fp);
		fseek(fp, i*sizeof(USER), SEEK_SET);    
		//重新定位，解决fwrite无法写入的问题
		if(strcmp(p->user, u) == 0)
		{
			p->format = n;
			fwrite(p, sizeof(USER), 1, fp);
		
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				exit(1);
			}
			return;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
函数名：void Input_num(char *u, int n)  
参数：用户名,个数
返回值：无
函数功能：更新上传文件数
**************************************************************/
void Input_num(char *u, int n)    
{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat", "rb+")) == NULL)
	 //打开用户数据库
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
		//exit(1);
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	
	if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c6");
			delay(2000);
			//exit(1);
		}
	
	for(i = 0; i < num; i++)
	{
		
		fseek(fp, i*sizeof(USER), SEEK_SET);
		fread(p, sizeof(USER), 1, fp);
		fseek(fp, i*sizeof(USER), SEEK_SET);   
		 //重新定位，解决fwrite无法写入的问题
		if(strcmp(p->user, u) == 0)
		{
			p->num = n;
			fwrite(p, sizeof(USER), 1, fp);
		
			if(p != NULL)
			{
				free(p);
				p = NULL;
			}
			if(fclose(fp) != 0)
			{
				printf("\n cannot close UserData.dat");
				delay(2000);
				//exit(1);
			}
			return;
		}
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close UserData.dat");
		delay(2000);
		exit(1);
	}
	//printf("wrong");
	//exit(1);
}

/*************************************************************
函数名：void Input_Cfilemenu(File *allfile, char *u)  
参数：文件结构体指针,用户名
返回值：无
函数功能:存入文件目录
**************************************************************/
void Input_Cfilemenu(File *allfile, char *u)  
 //存入文件目录
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"n_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "wb+")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		exit(1);
	}
	
	for(i=0; i<FILEMAX; i++)
	{
		fwrite(&allfile[i], sizeof(File), 1, fp);
	}
	if(fclose(fp) != 0)
	{
		printf("\n cannot close mfile");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
函数名：void Output_CFilemenu(File *allfile, char *u)   
参数：文件结构体指针,用户名
返回值：无
函数功能：导出文件目录
**************************************************************/
void Output_CFilemenu(File *allfile, char *u)   
//导出文件目录
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"n_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "rb")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<FILEMAX; i++)
	{
		fread(&allfile[i], sizeof(File), 1, fp);
	}
	
	if(fclose(fp) != 0)
	{
		printf("\n cannot close mfile");
		delay(2000);
		exit(1);
	}

}
/*************************************************************
函数名：int int check_cfile(USER *u,char *filename)
参数：文件结构体指针,用户名
返回值：无
函数功能：检查上传文件是否已经上传过
**************************************************************/
int check_cfile(USER *u,char *filename)
{
	FILE *fp;

	File allfile[FILEMAX];
	int i;
	int num;
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u->user);
	strcat(mpath,fenge);
	strcat(mpath,"n_");
	strcat(mpath,u->user);
	strcat(mpath,".dat");
	if((fp = fopen(mpath, "rb+")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		exit(1);
	}
	num=ftell(fp)/sizeof(FILE);
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<num; i++)
	{
		fread(&allfile[i], sizeof(File), 1, fp);
	}
	for(i=0;i<num;i++)
	{
		if(strcmp(filename,allfile[i].name)==0)
		{
			if(fclose(fp) != 0)
			{
			printf("\n cannot close mfile");
			delay(2000);
			exit(1);
			}
			return 1;
		}
		
	}
	if(fclose(fp) != 0)
			{
			printf("\n cannot close mfile");
			delay(2000);
			exit(1);
			}
		
	return 2;
	
}



