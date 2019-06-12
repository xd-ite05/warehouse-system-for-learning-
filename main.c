//
//  1.c
//  一样一样
//
//  Created by 王潞东 on 2019/6/12.
//  Copyright © 2019 王潞东. All rights reserved.
//

#include"stdio.h"
#include "stdlib.h"
#include <string.h>
struct data

{
    int amount; // 数量
    char name[20]; // 名称
    int num; // 编号
    char  nature[15];//属性
    char remarks[50];//备注
    float  price; //价格
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
        printf(" 元件物品%d\n",++S);
        printf("请输入元件物品编号:");
        scanf("%d",&food[wokao].num);
        printf("请输入元件物品名称:");
        scanf("%s",food[wokao].name);
        
        printf("请输入元件物品属性（15个字母以内）:");//
        scanf("%s",food[wokao].nature);
        printf("请输入元件物品价格:");
        scanf("%f",&food[wokao].price);
        printf("请输入元件物品数量:");
        scanf("%d",&food[wokao].amount);
        printf("请输入元件物品备注(50个字母以内):");//
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
    char _nature[10];  //
    char d;
    char _name[20];
    while(1)
    {
        system("cls");
        printf("\t\t1、按元件编号出库\n");
        printf("\t\t2、按元件名称出库\n");
        printf("\t\t3、按元件属性出库\n");  //
        printf("\t\t0、返回\n");
        printf("\t\t请选择：");
        scanf("%d",&a);
        if(a==1)
        {
            printf("请输入出货元件的编号:");
            scanf("%d",&b);
            printf("\n");
            
            for(i=0;i<S;i++)
            {
                if(b==food[i].num) j=i;
            }
            if(food[j].amount>0)
            {
                printf("请输入元件出货量：");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("元件货物不足\n");
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
                printf("请输入元件出货量：");
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
        if(a==3)//
        {
            printf("请输入出货元件的属性:");
            scanf("%s",_nature);
            printf("\n");
            
            for(i=0;i<S;i++)
            {
                if(strcmp(_nature,food[i].nature)==0)
                    j=i;
            }
            if(food[j].amount>0)
            {
                printf("请输入元件出货量：");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("货物不足\n");
                else
                {
                    food[j].amount-=c;
                    printf("编号%d元件成功出货!\n货物剩余%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("此元件为零\n");
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
    printf("\t\t1、元件入库\n");
    printf("\t\t2、元件出库\n");
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
        flag=0;
        system("cls");
        printf("\t\t1、按元件编号查找\n");
        printf("\t\t2、按元件名称查找\n");
        printf("\t\t3、按元件属性查找\n");
        printf("\t\t0、返回\n");
        printf("\t\t请选择：");
        scanf("%d",&a);
        if(a==1)
        {
            printf("请输入需要查询元件的编号:");
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
            printf("请输入需要查询元件的名称:");
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
        else if(a==3)
        {
            printf("请输入需要查询元件的属性:");
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
                    printf("价格：%.2f\n数量：%d\n备注：%s\n",food[i].price,food[i].amount,food[i].remarks);
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
        printf("%16.2f %16d %16s",food[i].price,food[i].amount,food[i].remarks);
        
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
    printf("1、储存（进行该操作前请您先打开文件）\n");
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
void tongji()
{
    int qqq=0;
    system("CLS");
    printf("输入你统计的功能：\n");
    printf("1 ：库元器件的总价值\n");
    printf("2 :每月出库元件的总价值\n");
    printf("3 :各类元件的月消耗量\n");
    scanf("%d",&qqq);
    printf("\n");
    printf("\n");
    if(qqq==1)
    {float  zongjiazhi=0;
        for(int i=0;i<S;i++)zongjiazhi+=food[i].amount*food[i].price;
        printf("总价值为%.2f\n",zongjiazhi);
        printf("按回车键返回！");
        getchar();
        getchar();
    }
    else if(qqq==2)
    {
        
        printf("\n");
        float zongjiazhi=0;
        for(int i=0;i<S;i++)
        {   int shuliang=0;
            printf("请输入上个月%s物品的数量：",food[i].name);
            scanf("%d",&shuliang);
            
            zongjiazhi+=shuliang*food[i].price;
        }
        for(int i=0;i<S;i++)zongjiazhi-=food[i].amount*food[i].price;
        printf("\n");
        printf("出库元器件的总价值%.2f\n",zongjiazhi);
        printf("按回车键返回！");
        getchar();
        getchar();
    }
    else if(qqq==3)
    {
        printf("请输入上个月各类元器件的入库数量：\n");
        printf("\n");
        int xiaohaoliang[100];
        for(int i=0;i<S;i++)
        {   int shuliang=0;
            printf("请输入%s物品的数量：",food[i].name);
            scanf("%d",&shuliang);
            
            shuliang-=food[i].num;
            xiaohaoliang[i]=shuliang;
            
        }
        printf("\n");printf("\n");printf("\n");printf("\n");
        for(int i=0;i<S;i++)
        {
            printf("%s消耗量为%d\n",food[i].name,xiaohaoliang[i]);
        }
        printf("\n");
        printf("按回车键返回！");
        getchar();
        getchar();
        
    }
}
int main()
{
    int a;
    ///主菜单
    while(1)
    {
        system("CLS");
        
        printf("\t\t\t\t* * * * * * * * * * * * *\n");
        printf("\t\t\t\t* 1、元件出库和入库        * \n");
        printf("\t\t\t\t* 2、查找元件表           * \n");
        printf("\t\t\t\t* 3、显示元件仓库表        * \n");
        printf("\t\t\t\t* 4、输出到文件           * \n");
        printf("\t\t\t\t* 5、打开文件             * \n");
        printf("\t\t\t\t* 6、统计                * \n");
        printf("\t\t\t\t* 0、退出                * \n");
        printf("\t\t\t\t* * * * * * * * * * * * * \n");
        printf("\t\t\t\t请选择：");
        scanf("%d",&a);
        switch(a)
        {
            case 1: current();break;
            case 2: search();break;
            case 3: show();break;
            case 4: save();break;
            case 5: Open();break;
            case 6: tongji();break;
            case 0: exit(0);
        }
    }
    return 0;
}
