#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include  "gen.h"      


*gen *createA()
{
	FILE *fp=fopen("genealogy.txt","r");
	gen * head,* s,* r;
	head=(gen*)malloc(sizeof(gen));
	r=head;
    while (fscanf(fp,"%d %s %d",&s->Num, s->peoplename, &s->Quantity)!=EOF)
	{
		 
        if(head == NULL)
        {   
            head = s;
        }
        else
            r->next = s;
        r = s;
        s = (gen *)malloc(sizeof(gen));
        r->next = NULL;
	}
	fclose(fp);
	return head;
}
//创建单链表 1（管理员） 
*/ 

Fam *createB()
{
    FILE *fd = fopen("genealogy.txt","r");
    Fam *head, *s, *r;
    head = NULL;
    r = NULL;
    s = (Fam *)malloc(sizeof(Fam));
    	while(fscanf(fd,"%d %s %s %d %d %s %f %s",&s->num,s->name,s->birthplace,&s->birthdate,&s->deathdate,s->sex,&s->height,s->work)!=EOF)
    {   
        if(head == NULL)
        {   
            head = s;
        }
        else
            r->next =s;
        r = s;
        s = (Fam *)malloc(sizeof(Fam));
        r->next = NULL;
    }
    fclose(fd);
    return head;
}//单链表2的创建（家族成员） 






int welcome()
{
	int n;
	char input[4]={'\0'};
	printf("\n---------家谱管理系统---------\n");
	printf("\n");
	printf("\n");
    printf("=           欢迎              =");
    printf("\n");
    printf("\n----------请问你是家族成员吗(yes or no)？--------\n");
    printf("\n");
    printf("---------------------");
    gets(input);
	if(strcmp(input,"yes")==0)	
	         return 1;
	else 
	         return 0; 
 } //欢迎界面 
 
 
 int  check(char *name,char *pwd)
 {
 	int u=0;
 	if(strcmp(name,"root")==0&&strcmp(pwd,"123456")==0)
 	{
 		u=1;
 		return 1;
	 }
	 return 0;
 }
 //账号密码匹配；
 
 
  int  login()
{
    system("cls");
    int i, m, n=0;
    char user[20] = {'\0'};
    char passwd[20] = {'\0'};
    char aa[20]={' ','U','s','e','r',' ','N','a','m','e',':'};//输出账号登陆
	char bb[20]={' ','P','a','s','s','w','o','r','d',':'};
    while(1)
    {
        printf("\n");
        for(i=0;i<12;i++)
        {
            printf("%c",aa[i]);
            Sleep(50);
        }
        //printf(" User Name:");
        gets(user);//输入账号
        for(i=0;i<10;i++)
        {
            printf("%c",bb[i]);
            Sleep(50);
        }
	    gets(passwd);
        m = check(user,passwd);
        if(m==1)
            return m;
        else 
        {
            n++;
            printf("Incorrect please try again!\n");
            if(n==3)
            {
                return 0;
            }
        }
    }



}//登陆界面

 
 void function1()
{
	printf("\n-------家谱管理系统-------\n");
	printf("\n");
	printf("=============================");
	printf("=        主菜单        =");
	printf("=============================");
	printf("\n");
	printf("          请根据需要选择操作\n");
	printf("\n");
	printf("          选择需要查询的方式\n");
	printf("          (0)输入0退出该系统\n");
    printf("          (1) 录入家族成员基本信息\n");
    printf("          (2) 打印家族成员基本信息\n");
    printf("          (3) 修改家族成员基本信息\n");
    printf("          (4) 删除家族成员基本信息\n");
    printf("          (5) 查询家族成员基本信息\n");
	 
 } 

//管理员主菜单


void function2()
{
  	printf("\n-------家谱管理系统-------\n");
	printf("\n");
	printf("=============================");
	printf("=        主菜单        ="); 
	printf("=============================");
	printf("\n");
	printf("          请根据需要选择操作\n");
	printf("\n");
	printf("          选择需要查询的方式\n");
	printf("          (0)输入0退出该系统\n");
    printf("          (1) 录入家族成员基本信息\n");
    printf("          (2) 查询家族成员基本信息\n");
 } //家族成员菜单 


void showpeople(Fam *L) 
 {
 	system("cls");                                          //清屏操作 
    Fam *r = L;
    printf("姓名\t\t出生地\t出生日期\t死亡日期\t性别\t身高\t职业\t");
    while (r!=NULL)
    {
        printf("%s %s %d %d %s %f %s",r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
        r = r->next;
    }
    system("pause");      //冻结屏幕，便于观察屏幕的执行结果 
 }  //打印家谱 
 
 
 
 //添加成员
 
 	
*void addpeople(Fam *L)
{
     Fam *r = L;
     Fam *s = NULL;
     int Quantity;
    char name[MAXSIZE] = {'\0'};
    printf("请输入成员姓名和人数：");
    scanf("%s %d",name,&Quantity);
    FILE *fd = fopen("genealogy.txt","a+");
    while (r!=NULL)
    {
        s = r;
        r = r->next;
    }
    r->Num = s->Num + 1;
    strcpy(r->peoplename,name);
    r->Quantity = Quantity;
    r->next = NULL;
    fprintf(fd,"%d %s %d\n",r->num,&r->name,r->Quantity);
    printf("添加成功！\n");
    fclose(fd);
    system("pause");
}     //       //   添加成员 */

 	
 	
void change(Fam *L)
{
    showpeople(L);
    Fam *r = L;
    char name[MAXSIZE] = {'\0'};
    int num, quantity;
    printf("请输入成员编号：");
    scanf("%d",&num);
    while (r->num!=num)
    {
        r = r->next;
    }
    printf("%-10d %-20s \n",r->num, r->name);
    printf("请输入要修改的成员信息：");
    scanf("%s %s %d %d %s %f %s",r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
    printf("修改成功！\n");
    system("pause");
}//更改成员信息
 	
 	
 /*void deletepeople(Fam *S)
{
    Fam *r = S;
    char name[30];
    scanf("%s",name); 
    if(strcmp(name,r->name)==0)
    	r = r->next;
    else 
    {
	   	while (r!=NULL)
	    {
	        if(strcmp(name,r->name)==0)
	        {
	            
	        }
	        r = r->next;
	    }
	}
    
}       ////删除成员 */
	
 	
 	
 	
 void searchpeople(Fam *S)
{
    Fam *r = S;
    char name[MAXSIZE] = {'\0'};
    printf("请输入要查询成员的姓名：");
    scanf("%s",name);
    while (r!=NULL)
    {
        if(strcmp(name,r->name)==0)
        {
            printf("该成员基本信息为：");
            printf("%s %s %d %d %s %f %s",r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
        }
        r = r->next;
    }
    system("pause");
    
}//查询某成员信息 
	
 	
 	void finall(Fam*L)
{
    FILE *fd = fopen("genealogy.txt","w");
    Fam *r = (Fam *)malloc(sizeof(Fam));
    r = L;
    while (r!=NULL)
    {
        fprintf(fd,"%d %s %s %d %d %s %f %s",&r->num,r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
        r = r->next;
    }
    fclose(fd);
}//文件处理
 	
 	
 	
 	
 	
 	
 	
 int main()
{
    Fam *L = NULL;
    int shell, judge;
    char choice = '*';
    L = createB();
    shell = welcome();
    if (shell==1)   
    {
        judge = login();
        if (judge==1)
        {
            while (choice!='0')
            {
                system("cls");
                function1();
                printf("请选择选项：");
                choice = getchar();
                switch (choice-'0')
                {
                    case 1:
                        //addpeople(L);
                        break;
                    case 2:
                        showpeople(L);
                        break;
                    case 3:
                        change(L);
                        break;
                    case 4:
                        //deletepeople(L);
                        break;
                    case 5:
                        searchpeople(L);
                    default:
                        break;
                }
            }
    }
        else
        {
            while (choice!='0')
            {
                system("cls");
                function2();
                printf("请选择选项：");
                choice = getchar();
                switch (choice-'0')
                {
                    case 1:
                        showpeople(L);
                        break;
                    case 2:
                        searchpeople(L);
                        break;
                    default:
                        break;
                }
            }
            
        }
           
    }
    else
    {
        while (choice!='0')
        {
            system("cls");
            function2();
            printf("请选择选项：");
            choice = getchar();
            switch (choice-'0')
            {
                case 1:
                    showpeople(L);
                    break;
                case 2:
                    searchpeople(L);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



