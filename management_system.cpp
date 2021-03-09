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
//���������� 1������Ա�� 
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
}//������2�Ĵ����������Ա�� 






int welcome()
{
	int n;
	char input[4]={'\0'};
	printf("\n---------���׹���ϵͳ---------\n");
	printf("\n");
	printf("\n");
    printf("=           ��ӭ              =");
    printf("\n");
    printf("\n----------�������Ǽ����Ա��(yes or no)��--------\n");
    printf("\n");
    printf("---------------------");
    gets(input);
	if(strcmp(input,"yes")==0)	
	         return 1;
	else 
	         return 0; 
 } //��ӭ���� 
 
 
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
 //�˺�����ƥ�䣻
 
 
  int  login()
{
    system("cls");
    int i, m, n=0;
    char user[20] = {'\0'};
    char passwd[20] = {'\0'};
    char aa[20]={' ','U','s','e','r',' ','N','a','m','e',':'};//����˺ŵ�½
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
        gets(user);//�����˺�
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



}//��½����

 
 void function1()
{
	printf("\n-------���׹���ϵͳ-------\n");
	printf("\n");
	printf("=============================");
	printf("=        ���˵�        =");
	printf("=============================");
	printf("\n");
	printf("          �������Ҫѡ�����\n");
	printf("\n");
	printf("          ѡ����Ҫ��ѯ�ķ�ʽ\n");
	printf("          (0)����0�˳���ϵͳ\n");
    printf("          (1) ¼������Ա������Ϣ\n");
    printf("          (2) ��ӡ�����Ա������Ϣ\n");
    printf("          (3) �޸ļ����Ա������Ϣ\n");
    printf("          (4) ɾ�������Ա������Ϣ\n");
    printf("          (5) ��ѯ�����Ա������Ϣ\n");
	 
 } 

//����Ա���˵�


void function2()
{
  	printf("\n-------���׹���ϵͳ-------\n");
	printf("\n");
	printf("=============================");
	printf("=        ���˵�        ="); 
	printf("=============================");
	printf("\n");
	printf("          �������Ҫѡ�����\n");
	printf("\n");
	printf("          ѡ����Ҫ��ѯ�ķ�ʽ\n");
	printf("          (0)����0�˳���ϵͳ\n");
    printf("          (1) ¼������Ա������Ϣ\n");
    printf("          (2) ��ѯ�����Ա������Ϣ\n");
 } //�����Ա�˵� 


void showpeople(Fam *L) 
 {
 	system("cls");                                          //�������� 
    Fam *r = L;
    printf("����\t\t������\t��������\t��������\t�Ա�\t���\tְҵ\t");
    while (r!=NULL)
    {
        printf("%s %s %d %d %s %f %s",r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
        r = r->next;
    }
    system("pause");      //������Ļ�����ڹ۲���Ļ��ִ�н�� 
 }  //��ӡ���� 
 
 
 
 //��ӳ�Ա
 
 	
*void addpeople(Fam *L)
{
     Fam *r = L;
     Fam *s = NULL;
     int Quantity;
    char name[MAXSIZE] = {'\0'};
    printf("�������Ա������������");
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
    printf("��ӳɹ���\n");
    fclose(fd);
    system("pause");
}     //       //   ��ӳ�Ա */

 	
 	
void change(Fam *L)
{
    showpeople(L);
    Fam *r = L;
    char name[MAXSIZE] = {'\0'};
    int num, quantity;
    printf("�������Ա��ţ�");
    scanf("%d",&num);
    while (r->num!=num)
    {
        r = r->next;
    }
    printf("%-10d %-20s \n",r->num, r->name);
    printf("������Ҫ�޸ĵĳ�Ա��Ϣ��");
    scanf("%s %s %d %d %s %f %s",r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
    printf("�޸ĳɹ���\n");
    system("pause");
}//���ĳ�Ա��Ϣ
 	
 	
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
    
}       ////ɾ����Ա */
	
 	
 	
 	
 void searchpeople(Fam *S)
{
    Fam *r = S;
    char name[MAXSIZE] = {'\0'};
    printf("������Ҫ��ѯ��Ա��������");
    scanf("%s",name);
    while (r!=NULL)
    {
        if(strcmp(name,r->name)==0)
        {
            printf("�ó�Ա������ϢΪ��");
            printf("%s %s %d %d %s %f %s",r->name,r->birthplace,&r->birthdate,&r->deathdate,r->sex,&r->height,r->work);
        }
        r = r->next;
    }
    system("pause");
    
}//��ѯĳ��Ա��Ϣ 
	
 	
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
}//�ļ�����
 	
 	
 	
 	
 	
 	
 	
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
                printf("��ѡ��ѡ�");
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
                printf("��ѡ��ѡ�");
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
            printf("��ѡ��ѡ�");
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



