#include"stdio.h"
#include "stdlib.h"
#include <string.h>
struct data

{
    int amount; // ����
    char name[20]; // ����
    int num; // ���
    char nature[15];//����
    char remarks[50];//��ע
    float price; //�۸�
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
        printf(" Ԫ����Ʒ%d\n",++S);
        printf("������Ԫ����Ʒ���:");
        scanf("%d",&food[wokao].num);
        printf("������Ԫ����Ʒ����:");
        scanf("%s",food[wokao].name);
        
        printf("������Ԫ����Ʒ���ԣ�15����ĸ���ڣ�:");//
        scanf("%s",food[wokao].nature);
        printf("������Ԫ����Ʒ�۸�:");
        scanf("%f",&food[wokao].price);
        printf("������Ԫ����Ʒ����:");
        scanf("%d",&food[wokao].amount);
        printf("������Ԫ����Ʒ��ע(50����ĸ����):");//
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
    char _nature[10];  //
    char d;
    char _name[20];
    while(1)
    {
        system("cls");
        printf("\t\t1����Ԫ����ų���\n");
        printf("\t\t2����Ԫ�����Ƴ���\n");
        printf("\t\t3����Ԫ�����Գ���\n");  //
        printf("\t\t0������\n");
        printf("\t\t��ѡ��");
        scanf("%d",&a);
        if(a==1)
        {
            printf("���������Ԫ���ı��:");
            scanf("%d",&b);
            printf("\n");
            
            for(i=0;i<S;i++)
            {
                if(b==food[i].num) j=i;
            }
            if(food[j].amount>0)
            {
                printf("������Ԫ����������");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("Ԫ�����ﲻ��\n");
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
                printf("������Ԫ����������");
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
        if(a==3)//
        {
            printf("���������Ԫ��������:");
            scanf("%s",_nature);
            printf("\n");
            
            for(i=0;i<S;i++)
            {
                if(strcmp(_nature,food[i].nature)==0)
 j=i;
            }
            if(food[j].amount>0)
            {
                printf("������Ԫ����������");
                scanf("%d",&c);
                if(c>food[j].amount)
                    printf("���ﲻ��\n");
                else
                {
 food[j].amount-=c;
                    printf("���%dԪ���ɹ�����!\n����ʣ��%d\n",food[j].num,food[j].amount);
                }
            }
            else
            {
                printf("��Ԫ��Ϊ��\n");
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
    printf("\t\t1��Ԫ�����\n");
    printf("\t\t2��Ԫ������\n");
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
    char _beizhu[50]; 
    int item[100];
    int flag=0;
    
    while(1)
    {
        for(i=0;i<S;i++)
 item[i]=0;
 flag=0;
        system("cls");
        printf("\t\t1����Ԫ����Ų���\n");
        printf("\t\t2����Ԫ�����Ʋ���\n");
        printf("\t\t3����Ԫ�����Բ���\n");
        printf("\t\t4����Ԫ����ע����\n");
        printf("\t\t0������\n");
        printf("\t\t��ѡ��");
        scanf("%d",&a);
        if(a==1)
        {
            printf("��������Ҫ��ѯԪ���ı��:");
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
            printf("��������Ҫ��ѯԪ��������:");
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
        else if(a==3)
        {
            printf("��������Ҫ��ѯԪ��������:");
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
                    printf("�۸�%.2f\n������%d\n��ע��%s\n",food[i].price,food[i].amount,food[i].remarks);
 flag=1;
                    printf("****************************\n");
                }
                
            }
            }
			else if(a==4)
        {
            printf("��������Ҫ��ѯԪ���ı�ע:");
            scanf("%s",_beizhu);
            printf("\n");
            for(i=0;i<S;i++)
            {
                if(strcmp(_beizhu,food[i].remarks)==0)
 item[i]=1;
            }
            for(i=0;i<S;i++)
            {
                
                if((item[i]==1)&&(i<=S))
                {
                    printf("****************************\n");
                    printf("��ţ�%d\n���ƣ�%s\n���ԣ�%s\n",food[i].num,food[i].name,food[i].nature);
                    printf("�۸�%.2f\n������%d\n��ע��%s\n",food[i].price,food[i].amount,food[i].remarks);
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
    printf("\t\t���\t\t ����\t\t ����\t\t �۸�\t\t ����\t\t ��ע\n");
    for(i=0; i<S; i++)
    {
        
        printf("\t\t%-16d %-16s %-16s",food[i].num,food[i].name,food[i].nature);
        printf("%16.2f %16d %16s",food[i].price,food[i].amount,food[i].remarks);
        
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
    printf("1�����棨���иò���ǰ�����ȴ��ļ���\n");
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
void tongji()
{
    int qqq=0;
    system("CLS");
    printf("������ͳ�ƵĹ��ܣ�\n");
    printf("1 ����Ԫ�������ܼ�ֵ\n");
    printf("2 :ÿ�³���Ԫ�����ܼ�ֵ\n");
    printf("3 :����Ԫ������������\n");
    scanf("%d",&qqq);
    printf("\n");
    printf("\n");
    if(qqq==1)
    {float zongjiazhi=0;
        for(int i=0;i<S;i++)zongjiazhi+=food[i].amount*food[i].price;
        printf("�ܼ�ֵΪ%.2f\n",zongjiazhi);
        printf("���س������أ�");
        getchar();
        getchar();
    }
    else if(qqq==2)
    {
        
        printf("\n");
        float zongjiazhi=0;
        for(int i=0;i<S;i++)
        {   int shuliang=0;
            printf("�������ϸ���%s��Ʒ��������",food[i].name);
            scanf("%d",&shuliang);
            
 zongjiazhi+=shuliang*food[i].price;
        }
        for(int i=0;i<S;i++)zongjiazhi-=food[i].amount*food[i].price;
        printf("\n");
        printf("����Ԫ�������ܼ�ֵ%.2f\n",zongjiazhi);
        printf("���س������أ�");
        getchar();
        getchar();
    }
    else if(qqq==3)
    {
        printf("�������ϸ��¸���Ԫ���������������\n");
        printf("\n");
        int xiaohaoliang[100];
        for(int i=0;i<S;i++)
        {   int shuliang=0;
            printf("������%s��Ʒ��������",food[i].name);
            scanf("%d",&shuliang);
            
 shuliang-=food[i].num;
 xiaohaoliang[i]=shuliang;
            
        }
        printf("\n");printf("\n");printf("\n");printf("\n");
        for(int i=0;i<S;i++)
        {
            printf("%s������Ϊ%d\n",food[i].name,xiaohaoliang[i]);
        }
        printf("\n");
        printf("���س������أ�");
        getchar();
        getchar();
        
    }
}

int main()
{
    int a;
    ///���˵�
    while(1)
    {
        system("CLS");
        
        printf("\t\t\t\t* * * * * * * * * * * * *\n");
        printf("\t\t\t\t* 1��Ԫ���������� * \n");
        printf("\t\t\t\t* 2������Ԫ���� * \n");
        printf("\t\t\t\t* 3����ʾԪ���ֿ�� * \n");
        printf("\t\t\t\t* 4��������ļ� * \n");
        printf("\t\t\t\t* 5�����ļ� * \n");
        printf("\t\t\t\t* 6��ͳ�� * \n");
        printf("\t\t\t\t* 0���˳� * \n");
        printf("\t\t\t\t* * * * * * * * * * * * * \n");
        printf("\t\t\t\t��ѡ��");
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


