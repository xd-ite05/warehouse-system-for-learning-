#include"stdio.h"
#include "stdlib.h"
#include <string.h>
struct data

{
    int amount; // ����
    char name[20]; // ����
    int num; // ��� 
    char  nature[15];//����   �Ķ� 
    char remarks[50];//��ע   �Ķ� 
    float  price; //�۸� �Ķ� 
}food[100];

int S=0; //������

//��⺯��
int wokao=0;
void input()
{
    
    char c;
    while(1)
    {
        system("cls");
        printf(" ��Ʒ%d\n",++S);
        printf("��������Ʒ���:");
        scanf("%d",&food[wokao].num);
        printf("��������Ʒ����:");
        scanf("%s",food[wokao].name);
        
        printf("��������Ʒ���ԣ�15����ĸ���ڣ�:");//�Ķ� 
        scanf("%s",food[wokao].nature); 
        printf("��������Ʒ�۸�:");
        scanf("%f",&food[wokao].price);
        printf("��������Ʒ����:");
        scanf("%d",&food[wokao].amount);
        printf("��������Ʒ��ע(50����ĸ����):");//�Ķ� 
        scanf("%s",food[wokao].remarks);
		 
        printf("�Ƿ�������(Y/N):");
        scanf(" %c",&c);
        wokao++;
        if(c=='N'||c=='n') break;
    }
}

//���⺯��

void output()
{
    int a,b,c,i,j=0;
    char _nature[10];  //�Ķ� 
    char d;
    char _name[20];
    while(1)
    {
        system("cls");
        printf("\t\t1������ų���\n");
        printf("\t\t2�������Ƴ���\n");
        printf("\t\t3�������Գ���\n");  //�Ķ� 
        printf("\t\t0������\n");
        printf("\t\t��ѡ��");
        scanf("%d",&a);
        if(a==1)
        {
            printf("�������������ı��:");
            scanf("%d",&b);
            printf("\n");
            
            for(i=0;i<S;i++)
            {
                if(b==food[i].num) j=i;
            }
            if(food[j].amount>0)
            {
                printf("�������������");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("���ﲻ��\n");
                else
                {
                    food[j].amount-=c;
                    printf("���%d����ɹ�����!\n����ʣ��%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("�˻���Ϊ��\n");
            }
        }
        if(a==2)
        {
            printf("������������������:");
            scanf("%s",_name); 
            printf("\n");
            for(i=0;i<S;i++)
            {
if(strcmp(food[i].name,_name)==0) j=i;
            }
            if(food[j].amount>0)
            {
                printf("�������������");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("���ﲻ��\n");
                else
                {
                    food[j].amount-=c;
                    printf("���%d����ɹ�����!\n����ʣ��%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("�˻���Ϊ��\n");
            }
        }
         if(a==3)//�Ķ� 
        {
            printf("������������������:");
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
                printf("�������������");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("���ﲻ��\n");
                else
                {
                    food[j].amount-=c;
                    printf("���%d����ɹ�����!\n����ʣ��%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("�˻���Ϊ��\n");
            }
        }
        else if(a==0) break;
        printf("�Ƿ��������(Y/N):");
        scanf(" %c",&d);
        if(d=='N'||d=='n') break;
    }
}

//�����������

void current()
{
    int a;
    system("cls");
    printf("\t\t1���������\n");
    printf("\t\t2���������\n");
    printf("\t\t0������\n");
    printf("\t\t��ѡ��");
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

//���Һ���

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
    	flag=0;//�Ķ� 
        system("cls");
        printf("\t\t1������Ų���\n");
        printf("\t\t2�������Ʋ���\n");
        printf("\t\t3�������Բ���\n");
        printf("\t\t0������\n");
        printf("\t\t��ѡ��");
        scanf("%d",&a);
        if(a==1)
        {
            printf("��������Ҫ��ѯ����ı��:");
            scanf("%d",&b);
            printf("\n");
            for(i=0;i<S;i++)
            {
                if(b==food[i].num) break;
            }
            if(i<=S)
                printf("��ţ�%d\n���ƣ�%s\n������%d\n",food[i].num,food[i].name,food[i].amount);
            else
                printf("δ�ҵ��˱��\n");
            printf("�Ƿ��������(Y/N): ");
            scanf(" %c",&c);
            if(c=='N'||c=='n') break;
        }
        else if(a==2)
        {
            printf("��������Ҫ��ѯ���������:");
            scanf("%s",_name);
            printf("\n");
            for(i=0;i<S;i++)
            {
                if(strcmp(_name,food[i].name)==0) break;
            }
            if(i<=S)
                printf("��ţ�%d\n���ƣ�%s\n������%d\n",food[i].num,food[i].name,food[i].amount);
            else
                printf("δ�ҵ�������\n");
            printf("�Ƿ��������(Y/N): ");
            scanf(" %c",&c);
            if(c=='N'||c=='n') break;
        }
        else if(a==3)  //�Ķ� 
		{
            printf("��������Ҫ��ѯ���������:");
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
				printf("��ţ�%d\n���ƣ�%s\n���ԣ�%s\n",food[i].num,food[i].name,food[i].nature);
                printf("�۸�%d\n������%d\n��ע��%s\n",food[i].price,food[i].amount,food[i].remarks);
                flag=1;
                printf("****************************\n");
            	}
            	
        	}
            if(flag==0) 
            printf("δ�ҵ������ԵĻ���\n");
            else;
            printf("�Ƿ��������(Y/N): ");
            scanf(" %c",&c);
            if(c=='N'||c=='n') break;
        } 
        else if(a==0) break;
        
    }
    
}

//��ʾ����

void show()
{
    int i;
    char c;
    system("cls");
    printf("\t\t���\t\t ����\t\t ����\t\t �۸�\t\t  ����\t\t  ��ע\n");
    for(i=0; i<S; i++)
    {
    	
        printf("\t\t%-16d %-16s %-16s",food[i].num,food[i].name,food[i].nature);
        printf("%-16d %-16d %-16s",food[i].price,food[i].amount,food[i].remarks);
		//printf("\t%d\t%s\t%d",food[i].num,food[i].name,food[i].amount);
		printf("\n"); 
        
    }
    printf("\n\n");
    printf("���س������أ�");
    c=getchar();
    c=getchar();
}

char file[20]; //�ļ�����ȫ�ֱ���

//���ļ�

void Open()
{
    FILE *fp;
    int i;
    char c;
    system("cls");
    printf("����򿪵��ļ�����\n");
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
        printf("�ļ���ȡ����\n");
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
            printf("�ļ���ȡ����\n");
        }
    }
    fclose(fp);
    printf("�ļ��򿪳ɹ���\n\n");
    printf("���س������أ�");
    c=getchar();
    c=getchar();
}

//������ļ�

void save()
{
    FILE *fp;
    int i,a;
    char c;
    system("cls");
    printf("1������\n");
    printf("2�����Ϊ\n");
    printf("0������\n");
    printf("��ѡ��");
    scanf("%d",&a);
    if(a==1)
    {
        if((fp=fopen(file,"wb"))==NULL)
        {
            printf("cannot open file\n");
        }
        if(fwrite(&S,sizeof(int),1,fp)!=1)
        {
            printf("д���ļ�����\n");
        }
        for(i=0;i<S;i++)
        {
            if(fwrite(&food[i],sizeof(struct data),1,fp)!=1)
            {
                printf("д���ļ�����\n");
            }
        }
        fclose(fp);
        printf("����ɹ���\n\n");
        printf("���س������أ�");
        c=getchar();
        c=getchar();
    }
    else if(a==2)
    {
        printf("\n�ļ�����");
        scanf("%s",file);
        if((fp=fopen(file,"wb"))==NULL)
        {
            printf("cannot open file\n");
        }
        if(fwrite(&S,sizeof(int),1,fp)!=1)
        {
            printf("д���ļ�����\n");
        }
        for(i=0;i<=S;i++)
        {
            if(fwrite(&food[i],sizeof(struct data),1,fp)!=1)
            {
                printf("д���ļ�����\n");
            }
        }
        fclose(fp);
        printf("����ɹ���\n\n");
        printf("���س������أ�");
        c=getchar();
        c=getchar();
    }
}

int main()
{
    int a;
    ///���˵�
    while(1)
    {
        system("CLS");
       
        printf("\t\t\t\t* * * * * * * * * * * * * * * * \n");
        printf("\t\t\t\t* 1������������� * \n");
        printf("\t\t\t\t* 2�����һ���� * \n");
        printf("\t\t\t\t* 3����ʾ�ֿ����� * \n");
        printf("\t\t\t\t* 4��������ļ� * \n");
        printf("\t\t\t\t* 5�����ļ� * \n");
        printf("\t\t\t\t* 0���˳� * \n");
        printf("\t\t\t\t* * * * * * * * * * * * * * * * \n");
        printf("\t\t\t\t��ѡ��");
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

 
