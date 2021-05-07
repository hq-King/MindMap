#include"common.h"
#include"mouse.h"
#include"USER.h"
#include "file.h"
#include"menufunc.h"
#include"mpfunc.h"
#include "compare.h"

/*************************************************************
函数名：void inputfilename(char *site, int x1, int y1, int x2, int y2)
参数：字符串数组，输入范围坐标
返回值：无
函数功能：文件名输入函数
**************************************************************/
void EnterFileName(char*id, int x1, int y1, int charnum, int color)
//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RED);
	settextstyle(SMALL_FONT, HORIZ_DIR, 6);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	//光标
	while(bioskey(1))
	{
		k = bioskey(0);
		//按键
	}
	while (1)
	{
	
		t = bioskey(0); 
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
				//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20); 
					//遮盖光标
					outtextxy(x1 + 8 + i * 18, y1+5, id + i);
					//输出t字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)
				//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);
					//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 20);
					//遮盖文字
					i--;//减少一个字符?
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);
				//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);
					//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 20);
					//遮盖文字
					i--;
					//减少一个字符
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
					//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 20);//遮盖光标  
				break;
			}
		}
	}
}

/*************************************************************
函数名：int Check_SameFile(char *newname, File *allfile, int n)  
参数：文件名 , 文件结构体指针,个数
返回值：0，1
函数功能：检查文件是否重名
**************************************************************/
int Check_SameFile(char *newname, File *allfile, int n)  
 //检查文件是否重名
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(allfile[i].name, newname) == 0)
			return 1;
	}
	return 0;
}

/*************************************************************
函数名：int Examine_Filename(USER *u, File *allfile, char *newname)     
参数：用户结构体指针, 文件结构体指针,文件名
返回值：0，1
函数功能：检查文件情况
**************************************************************/
int Examine_Filename(USER *u, File *allfile, char *newname)   
//检查文件名情况
{ 
	while(1)
	{	
		if(Judge_Filename(newname, 480, 310) == 1)
		{
			if(u->history == 0)
			{
				return 1; 
				//无历史 
			}
			
			if(Check_SameFile(newname, allfile, u->history) == 1)
			{
				return 2; 
				//重名 
			}
			else
			{
				if(u->history == 10)
				{
					puthz(480, 315, "达最大文件数",16, 17, RED);
					break; 
				}
				else
				{
					return 3;
					//有历史不重名 
				}
			}
		}
		else
			break;
	}
	return 0; 
}

/*************************************************************
函数名：int Judge_Filename(char *name, int x, int y)
参数：文件名,坐标位置
返回值：0，1
函数功能：检查文件情况
**************************************************************/
int Judge_Filename(char *name, int x, int y)
{
	if(strlen(name) > 6)
	{
		puthz(x,y,"文件名应小于七位",16,17,RED);
		return 0;
	}
	if(strlen(name) == 0)
	{
		puthz(x,y,"文件名不能为空",16,17,RED);
		return 0;
	}
	else if((strlen(name) <= 6 ) && (strlen(name) != 6 ))
	{
		return 1;
	}
	return 0;
}

/*************************************************************
函数名：void createfolder(char *name) 
参数：文件名
返回值：无
函数功能：创建用户文件夹
**************************************************************/
void createfolder(char *name) 
 //创建用户文件夹
{
	char path[50]= {".\\file\\"};
	strcat(path, name);
	mkdir(path);
	//创建空目录
}

/*************************************************************
函数名：void Insert_filemenu(File *allfile, char *filename, int format, int n)  
参数：文件结构体指针,文件名,文件版式信息,个数
返回值：无
函数功能：插入文件并且排序
**************************************************************/
void Insert_filemenu(File *allfile, char *filename, int format, int n)  

{
	int i,j;
	int k;
	File temp;
	//得到最新的文件信息
	strcpy(allfile[n-1].name, filename);
	allfile[n-1].format = format;
	//获取文件创建时间
	Get_filetime(allfile[n-1].filetime);
	k = strlen(allfile[n-1].filetime);
	allfile[n-1].filetime[k-1] = '\0';
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			//排序
			if(strcmp(allfile[j].name,allfile[j+1].name) > 0)
			{
				temp = allfile[j];
				allfile[j] = allfile[j+1];
				allfile[j+1] = temp;
			}
		}
	}
}

/*************************************************************
函数名：void Input_filemenu(File *allfile, char *u)  
参数：文件结构体指针,用户名
返回值：无
函数功能：存入文件目录
**************************************************************/
void Input_filemenu(File *allfile, char *u)  
 
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"m_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "wb+")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
		
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

void Drawpoint(int x, int y)  
//画点
{
	setfillstyle(1,WHITE);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(BLUE);
	circle(x,y,2);
}

/*************************************************************
函数名：void Output_Filemenu(File *allfile, char *u)   
参数：文件结构体指针,用户名
返回值：无
函数功能：导出文件目录
**************************************************************/
void Output_Filemenu(File *allfile, char *u)   
//导出文件目录
{
	int i;
	FILE *fp;
	
	char mpath[25]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(mpath,u);
	strcat(mpath,fenge);
	strcat(mpath,"m_");
	strcat(mpath,u);
	strcat(mpath,".dat");

	if((fp = fopen(mpath, "rb")) == NULL)
	{
		printf("can not open mfile");
		delay(2000);
	
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
函数名：void printt_Filemenu(File *allfile, char *u)   
参数：文件结构体指针,用户名
返回值：无
函数功能：打印文件目录
**************************************************************/
void Print_Filemenu(File *allfile, int n)   //打印文件目录
{
	int i;
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	//以五为界限，分左右两块
	if(n<=5)
	{
		for(i=0;i<n;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//画点
			Drawpoint(90, 100+10+40*i);
			//输出文件名
			outtextxy(105, 100+40*i, allfile[i].name);
			//输出版式
			switch(allfile[i].format)
			{
				case 1:
					puthz(90+165, 100+5+40*i,"版式一",16,17,BLUE);
					break;
				case 2:
					puthz(90+165, 100+5+40*i,"版式二",16,17,BLUE);
					break;
				case 3:
					puthz(90+165, 100+5+40*i,"对比",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(105+10, 100+25+40*i, allfile[i].filetime);
		}
	}
	else if(n>5)
	{
		for(i=0;i<5;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//画点
			Drawpoint(90, 100+10+40*i);
			//输出文件名
			outtextxy(105, 100+40*i, allfile[i].name);
			//输出版式
			switch(allfile[i].format)
			{
				case 1:
					puthz(90+165, 100+5+40*i,"版式一",16,17,BLUE);
					break;
				case 2:
					puthz(90+165, 100+5+40*i,"版式二",16,17,BLUE);
					break;
				case 3:
					puthz(90+165, 100+5+40*i,"版式三",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(105+10, 100+25+40*i, allfile[i].filetime);
		}
		for(i=5;i<n;i++)
		{
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			Drawpoint(330, 100+10+40*(i-5));
			outtextxy(345, 100+40*(i-5), allfile[i].name);
			switch(allfile[i].format)
			{
				case 1:
					puthz(330+165, 100+5+40*(i-5),"版式一",16,17,BLUE);
					break;
				case 2:
					puthz(330+165, 100+5+40*(i-5),"版式二",16,17,BLUE);
					break;
				case 3:
					puthz(330+165, 100+5+40*(i-5),"版式三",16,17,BLUE);
					break;
			}
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(345+10, 100+25+40*(i-5), allfile[i].filetime);
		}
	}
}
/*************************************************************
函数名：void Get_filetime(char *filetime)    
参数：文件名
返回值：无
函数功能：获取当前时间
**************************************************************/
void Get_filetime(char *filetime)   
//获取当前时间
{
	time_t timer;
	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	strcpy(filetime, asctime(tblock));
}

/*************************************************************
函数名：void Input_filedata( char *u , struct mpdata *mp,char *filename)   
参数：用户名,结构体指针,文件名
返回值：无
函数功能：存入文件
**************************************************************/
void Input_filedata( char *u , struct mpdata *mp,char *filename)   
 //将用户思维导图数据传入文件
{
	int i,j;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	if((fp = fopen(copath, "wb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
		for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fwrite(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fwrite(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fwrite(&mp->amoofson[i],2,1,fp);
	}

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"wb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		
	}
		fwrite(&mp->amooflevel,2,1,fp);
		fwrite(&mp->amoofline,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}


/*************************************************************
函数名：void Input_data(char *u , struct mpdata *mp)  
参数：用户名,结构体指针
返回值：无
函数功能：存入文件
**************************************************************/
void Input_data(char *u , struct mpdata *mp)
{
	int i,j;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,u);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,u);
	strcat(fpath,".dat");
	if((fp = fopen(copath, "wb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fwrite(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fwrite(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fwrite(&mp->amoofson[i],2,1,fp);
	}
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"wb")) == NULL)
	{
		printf("can not open datafile");
		delay(2000);
	
	}
		fwrite(&mp->amooflevel,2,1,fp);
		fwrite(&mp->amoofline,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
函数名：void Outputdata(char *u ,struct mpdata *mp)   
参数：用户名,结构体指针
返回值：无
函数功能：导出文件
**************************************************************/
void Outputdata(char *u ,struct mpdata *mp)   
//将用户思维导图数据从文件中传出
{
	int i=0,j=0;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,u);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,u);
	strcat(fpath,".dat");
	
	if((fp = fopen(copath, "rb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fread(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fread(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fread(&mp->amoofson[i],2,1,fp);
	}
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"rb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
	
	}

	fread(&mp->amooflevel,2,1,fp);
	fread(&mp->amoofline,2,1,fp);

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}



/*********************************************
函数名:void inputtofile(char* name, char* tel, char* password)
功能：把用户注册信息写入文件
参数:name,id,code
返回值:1/0
***********************************************/
void inputtofile(char* name, char* tel, char* password)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen(".\\USERS\\userdata.dat", "wb+" )) == NULL)
	//建立数据库
	{
		printf("cannot open file userdata.txt");
		delay(3000);
	
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
	
	}
	memset(u,'\0',sizeof(USER));
	strcpy(u->user, name);
	strcpy(u->tel, tel);
	strcpy(u->password, password);
	fseek(fp, 0, SEEK_END);
	//跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);
	//把用户信息写入
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}

/*************************************************************
函数名：int Copy_infor_User(USER *user)  
参数：用户指针
返回值：0,1
函数功能：将数据库中用户信息导入指针
**************************************************************/
int Copy_infor_User(USER *user)    

{
	int i;
	int num;
	FILE *fp;
	USER *p = NULL;
	if((fp = fopen(".\\USERS\\userdata.dat","rb")) == NULL) //打开用户数据库
	{
		printf("File UserData.dat cannot be open");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_END);
	num = ftell(fp) / sizeof(USER);
	//计算用户个数
	for(i = 0; i < num; i++)
	{
		if((p = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("not enough memory for userfunc.c8");
			delay(2000);
			
		}
		fseek(fp, i*sizeof(USER), SEEK_SET);
		//把用户信息读入指针
		fread(p, sizeof(USER), 1, fp);
		if(strcmp(p->user, user->user) == 0)
		{
			memset(user, '\0', sizeof(USER)); 
			 //重置
			strcpy(user->user,p->user);
			strcpy(user->password,p->password);
			strcpy(user->tel,p->tel);
			user->history = p->history;
			user->format = p->format;
			user->num = p->num;
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
			return 1;
		}
		if (p != NULL)
		{
			free(p);
			p = NULL;
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
	return 0;
}



/*************************************************************
函数名：void Delete_filedata(char *u, char *filename)  
参数：用户名,文件名
返回值：无
函数功能：删除文件数据
**************************************************************/
void Delete_filedata(char *u, char *filename)  
 //删除文件数据
{
	char copath[50]= {".\\file\\"};
	char fpath[50]=  {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	
	if(remove(copath) == -1)
	//删除文件数据
	{
		printf("can not delete");
		delay(2000);
		
	}
		
	if(remove(fpath) == -1)
	//删除文件数据
	{
		printf("can not delete");
		delay(2000);
		
	}
}

/*************************************************************
函数名：void Delete_filename(File *allfile, char *filename, int n)    
参数：文件结构体指针,文件名,个数
返回值：无
函数功能：删除文件目录里的信息
**************************************************************/
void Delete_filename(File *allfile, char *filename, int n)   
//删除文件目录中的文件信息
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(strcmp(allfile[i].name, filename) == 0)
			break;
	}
	if(i==n-1)
	{
		memset(&allfile[i],'\0',sizeof(File));
		return;
	}
	else
	{
		for(j=i ; j<n-1 ; j++)
		{
			allfile[j] = allfile[j+1];
		}
		memset(&allfile[n-1],'\0',sizeof(File));
		return;
	}
}




/*************************************************************
函数名：void Output_File(char *u ,struct mpdata *mp,char * filename)     
参数：用户名，结构体指针,文件名
返回值：无
函数功能：从指定文件导出数据
**************************************************************/

void Output_File(char *u ,struct mpdata *mp,char * filename)   
//将指定思维导图数据从文件中传出
{
	int i=0,j=0;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	
	
	if((fp = fopen(copath, "rb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0;i<5;i++)
	{
		for(j=0; j<6; j++)
		{
			fread(&mp->text[i][j],sizeof(struct bardata),1,fp);
		}
	}

	for(i=0; i< 40; i++)
	{
		fread(&mp->connect[i],sizeof(struct linedata),1,fp);
	}
	
	for(i=0;i<5;i++)
	{
		fread(&mp->amoofson[i],2,1,fp);
	}
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"rb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		
	}

	fread(&mp->amooflevel,2,1,fp);
	fread(&mp->amoofline,2,1,fp);

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
}

/*************************************************************
函数名：void Output_CFile(char *u ,struct mpdata *mp,char * filename)     
参数：用户名，结构体指针,文件名
返回值：无
函数功能：从指定文件导出数据
**************************************************************/
void Output_Cfile(char *u ,struct comparedata *CMP,char * filename)
//将指定思维导图数据从文件中传出
{
	int i=0,j=0;
	FILE *fp;
	char copath[50]= {".\\file\\"};
	char fpath[50]= {".\\file\\"};
	char fenge[5]={"\\"};
	
	strcat(copath,u);
	strcat(copath,fenge);
	strcat(copath,"draw_");
	strcat(copath,filename);
	strcat(copath,".dat");
	strcat(fpath,u);
	strcat(fpath,fenge);
	strcat(fpath,"data_");
	strcat(fpath,filename);
	strcat(fpath,".dat");
	
	
	if((fp = fopen(copath, "rb")) == NULL)
	{
		printf("can not open drawfile");
		delay(2000);
	
	}
	fseek(fp, 0, SEEK_SET);
    fread((*CMP).theme,2*18*sizeof(char),1,fp);
	fread((*CMP).similar,6*20*sizeof(char),1,fp);
	fread((*CMP).differ1,6*20*sizeof(char),1,fp);
    fread((*CMP).differ2,6*20*sizeof(char),1,fp);
    

	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
	
	if((fp = fopen(fpath,"rb")) == NULL)
	{
		printf("can not open ffile");
		delay(2000);
		exit(1);
	}
		fread(&(*CMP).si_num,2,1,fp);
		fread(&(*CMP).dif1_num,2,1,fp);
        fread(&(*CMP).dif2_num,2,1,fp);
	if(fclose(fp) != 0)
	{
		printf("can not close");
		delay(2000);
		exit(1);
	}
    fclose(fp);
}

