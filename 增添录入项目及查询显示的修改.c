#include"stdio.h"
#include "stdlib.h"
#include <string.h>
struct data

{
    int amount; // 数量
    char name[20]; // 名称
    int num; // 编号 
    char  nature[15];//属性   改动 
    char remarks[50];//备注   改动 
    float  price; //价格 改动 
}food[100];

int S=0; //货物数

//入库函数
int wokao=0;
void input()
{
    
    char c;
    while(1)
    {
        system("cls");
        printf(" 物品%d\n",++S);
        printf("请输入物品编号:");
        scanf("%d",&food[wokao].num);
        printf("请输入物品名称:");
        scanf("%s",food[wokao].name);
        
        printf("请输入物品属性（15个字母以内）:");//改动 
        scanf("%s",food[wokao].nature); 
        printf("请输入物品价格:");
        scanf("%f",&food[wokao].price);
        printf("请输入物品数量:");
        scanf("%d",&food[wokao].amount);
        printf("请输入物品备注(50个字母以内):");//改动 
        scanf("%s",food[wokao].remarks);
		 
        printf("是否继续入库(Y/N):");
        scanf(" %c",&c);
        wokao++;
        if(c=='N'||c=='n') break;
    }
}

//出库函数

void output()
{
    int a,b,c,i,j=0;
    char _nature[10];  //改动 
    char d;
    char _name[20];
    while(1)
    {
        system("cls");
        printf("\t\t1、按编号出库\n");
        printf("\t\t2、按名称出库\n");
        printf("\t\t3、按属性出库\n");  //改动 
        printf("\t\t0、返回\n");
        printf("\t\t请选择：");
        scanf("%d",&a);
        if(a==1)
        {
            printf("请输入出货货物的编号:");
            scanf("%d",&b);
            printf("\n");
            
            for(i=0;i<S;i++)
            {
                if(b==food[i].num) j=i;
            }
            if(food[j].amount>0)
            {
                printf("请输入出货量：");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("货物不足\n");
                else
                {
                    food[j].amount-=c;
                    printf("编号%d货物成功出货!\n货物剩余%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("此货物为零\n");
            }
        }
        if(a==2)
        {
            printf("请输入出货货物的名称:");
            scanf("%s",_name); 
            printf("\n");
            for(i=0;i<S;i++)
            {
if(strcmp(food[i].name,_name)==0) j=i;
            }
            if(food[j].amount>0)
            {
                printf("请输入出货量：");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("货物不足\n");
                else
                {
                    food[j].amount-=c;
                    printf("编号%d货物成功出货!\n货物剩余%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("此货物为零\n");
            }
        }
         if(a==3)//改动 
        {
            printf("请输入出货货物的属性:");
            scanf("%s",&_nature); 
            printf("\n");
            
            for(i=0;i<S;i++)
            {
            	if(strcmp(_nature,food[i].nature)==0)
				j=i;//for(j=0;j<15;j++)
                //if(_nature[j]==food[i].nature[i]) j=i;
            }
            if(food[j].amount>0)
            {
                printf("请输入出货量：");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("货物不足\n");
                else
                {
                    food[j].amount-=c;
                    printf("编号%d货物成功出货!\n货物剩余%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("此货物为零\n");
            }
        }
        else if(a==0) break;
        printf("是否继续出库(Y/N):");
        scanf(" %c",&d);
        if(d=='N'||d=='n') break;
    }
}

//货物出库和入库

void current()
{
    int a;
    system("cls");
    printf("\t\t1、货物入库\n");
    printf("\t\t2、货物出库\n");
    printf("\t\t0、返回\n");
    printf("\t\t请选择：");
    scanf("%d",&a);
    if(a==1)
    {
        input();
    }
    else if(a==2)
    {
        output();
    }
}

//查找函数

void search()
{
    int i,a,b;
    char c;
    char _name[20];
    char _nature[10];
    int item[100];
    int flag=0;
    
    while(1)
    {
    	for(i=0;i<S;i++)
    	item[i]=0;
    	flag=0;//改动 
        system("cls");
        printf("\t\t1、按编号查找\n");
        printf("\t\t2、按名称查找\n");
        printf("\t\t3、按属性查找\n");
        printf("\t\t0、返回\n");
        printf("\t\t请选择：");
        scanf("%d",&a);
        if(a==1)
        {
            printf("请输入需要查询货物的编号:");
            scanf("%d",&b);
            printf("\n");
            for(i=0;i<S;i++)
            {
                if(b==food[i].num) break;
            }
            if(i<=S)
                printf("编号：%d\n名称：%s\n数量：%d\n",food[i].num,food[i].name,food[i].amount);
            else
                printf("未找到此编号\n");
            printf("是否继续查找(Y/N): ");
            scanf(" %c",&c);
            if(c=='N'||c=='n') break;
        }
        else if(a==2)
        {
            printf("请输入需要查询货物的名称:");
            scanf("%s",_name);
            printf("\n");
            for(i=0;i<S;i++)
            {
                if(strcmp(_name,food[i].name)==0) break;
            }
            if(i<=S)
                printf("编号：%d\n名称：%s\n数量：%d\n",food[i].num,food[i].name,food[i].amount);
            else
                printf("未找到此名称\n");
            printf("是否继续查找(Y/N): ");
            scanf(" %c",&c);
            if(c=='N'||c=='n') break;
        }
        else if(a==3)  //改动 
		{
            printf("请输入需要查询货物的属性:");
            scanf("%s",_nature);
            printf("\n");
            for(i=0;i<S;i++)
            {
                if(strcmp(_nature,food[i].nature)==0) 
				 item[i]=1;
            }
            for(i=0;i<S;i++)
            {
			
            if((item[i]==1)&&(i<=S))
                {
                printf("****************************\n");
				printf("编号：%d\n名称：%s\n属性：%s\n",food[i].num,food[i].name,food[i].nature);
                printf("价格：%d\n数量：%d\n备注：%s\n",food[i].price,food[i].amount,food[i].remarks);
                flag=1;
                printf("****************************\n");
            	}
            	
        	}
            if(flag==0) 
            printf("未找到此属性的货物\n");
            else;
            printf("是否继续查找(Y/N): ");
            scanf(" %c",&c);
            if(c=='N'||c=='n') break;
        } 
        else if(a==0) break;
        
    }
    
}

//显示函数

void show()
{
    int i;
    char c;
    system("cls");
    printf("\t\t编号\t\t 名称\t\t 属性\t\t 价格\t\t  数量\t\t  备注\n");
    for(i=0; i<S; i++)
    {
    	
        printf("\t\t%-16d %-16s %-16s",food[i].num,food[i].name,food[i].nature);
        printf("%-16d %-16d %-16s",food[i].price,food[i].amount,food[i].remarks);
		//printf("\t%d\t%s\t%d",food[i].num,food[i].name,food[i].amount);
		printf("\n"); 
        
    }
    printf("\n\n");
    printf("按回车键返回！");
    c=getchar();
    c=getchar();
}

char file[20]; //文件名，全局变量

//打开文件

void Open()
{
    FILE *fp;
    int i;
    char c;
    system("cls");
    printf("输入打开的文件名：\n");
    scanf("%s",file);
    if((fp=fopen(file,"rb"))==NULL)
    {
        printf("cannot open infile\n");
    }
    if(fread(&S,sizeof(int),1,fp)!=1)
    {
        if(feof(fp))
        {
            fclose(fp);
            return ;
        }
        printf("文件读取错误！\n");
    }
    for(i=0;i<S;i++)
    {
        if(fread(&food[i],sizeof(struct data),1,fp)!=1)
        {
            if(feof(fp))
            {
                fclose(fp);
                return ;
            }
            printf("文件读取错误！\n");
        }
    }
    fclose(fp);
    printf("文件打开成功！\n\n");
    printf("按回车键返回！");
    c=getchar();
    c=getchar();
}

//输出到文件

void save()
{
    FILE *fp;
    int i,a;
    char c;
    system("cls");
    printf("1、储存\n");
    printf("2、另存为\n");
    printf("0、返回\n");
    printf("请选择：");
    scanf("%d",&a);
    if(a==1)
    {
        if((fp=fopen(file,"wb"))==NULL)
        {
            printf("cannot open file\n");
        }
        if(fwrite(&S,sizeof(int),1,fp)!=1)
        {
            printf("写入文件错误！\n");
        }
        for(i=0;i<S;i++)
        {
            if(fwrite(&food[i],sizeof(struct data),1,fp)!=1)
            {
                printf("写入文件错误！\n");
            }
        }
        fclose(fp);
        printf("保存成功！\n\n");
        printf("按回车键返回！");
        c=getchar();
        c=getchar();
    }
    else if(a==2)
    {
        printf("\n文件名：");
        scanf("%s",file);
        if((fp=fopen(file,"wb"))==NULL)
        {
            printf("cannot open file\n");
        }
        if(fwrite(&S,sizeof(int),1,fp)!=1)
        {
            printf("写入文件错误！\n");
        }
        for(i=0;i<=S;i++)
        {
            if(fwrite(&food[i],sizeof(struct data),1,fp)!=1)
            {
                printf("写入文件错误！\n");
            }
        }
        fclose(fp);
        printf("保存成功！\n\n");
        printf("按回车键返回！");
        c=getchar();
        c=getchar();
    }
}

int main()
{
    int a;
    ///主菜单
    while(1)
    {
        system("CLS");
       
        printf("\t\t\t\t* * * * * * * * * * * * * * * * \n");
        printf("\t\t\t\t* 1、货物出库和入库 * \n");
        printf("\t\t\t\t* 2、查找货物表 * \n");
        printf("\t\t\t\t* 3、显示仓库货物表 * \n");
        printf("\t\t\t\t* 4、输出到文件 * \n");
        printf("\t\t\t\t* 5、打开文件 * \n");
        printf("\t\t\t\t* 0、退出 * \n");
        printf("\t\t\t\t* * * * * * * * * * * * * * * * \n");
        printf("\t\t\t\t请选择：");
        scanf("%d",&a);
        switch(a)
        {
            case 1: current();break;
            case 2: search();break;
            case 3: show();break;
            case 4: save();break;
            case 5: Open();break;
            case 0: exit(0);
        }
    }
    return 0;
}

 
