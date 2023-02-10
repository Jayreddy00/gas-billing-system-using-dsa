#include<stdio.h>
#include<stdlib.h>
struct Node{
	char name[100];
	char hmno[100];
	char street[100];
	char village[100];
	char town[100];
	char feedback[1000];
	int fb;
	long serno;
	long mno;
	int cylinder;
	struct Node *prev;
	struct Node *next; 
};
struct Node *start;
struct Node *temp,*newnode,*ptr;
int i,h;
	long a=0;
void bill();
void newenrol();
void terminate();
void feedback();
void viewfeedback();
void create();
void connections();
void employee();
void main()
{
	int id,ch;
	system("cls");
	printf("\n 1.NEW CONNECTION ENROLLMENT");
	printf("\n 2.TERMINATE CURRENT CONNECTION");
	printf("\n 3.BOOK A CYLINDER");
	printf("\n 4.FEEDBACK");
	printf("\n 5.EMPLOYEE");
	printf("\n 6.EXIT");
	while(1){
		printf("\n Make your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				newenrol();
				break;
			case 2:
				terminate();
				break;
			case 3:
				bill();
				break;
			case 4:
				feedback();
				break;
			case 5:
				printf("\nPLEASE ENTER YOUR EMPLOYEE ID:");
				scanf("%d",&id);
				if(id==1||id==2){
				employee();
				}
				else if(id==3||id==4){
				employee();
				}
				else{
					printf("\nERROR! INVALID EMLOYEE ID");
				}
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\n Invalid choice");
				break;
		}
}
}
void create()
{
	int total,index,item,id;
	if(start==NULL)
	{	
		printf("\n Enter no.of connections:");
		scanf("%d",&total);
		if(total<=0)
		{
		printf("\n Total no.of connections need to be Positive");
		}
		else
		{
			temp = (struct Node*)malloc(sizeof(struct Node));
			printf("\n Enter the person details:");
			printf("\n NAME:");
			scanf("%s",temp->name);
			printf("\n MOBILE NUMBER:");
			scanf("%ld",&temp->mno);
			printf("\n HOUSE NO:");
			scanf("%s",temp->hmno);
			printf("\n STREET:");
			scanf("%s",temp->street);
			printf("\n VILLAGE:");
			scanf("%s",temp->village);
			printf("\n TOWN:");
			scanf("%s",temp->town);
			temp->fb=0;
			temp->cylinder=0;
			temp->serno=a;
			temp->prev=NULL;
			temp->next=NULL;
			start = temp;
			temp->serno=temp->serno+1;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\n SERVICE NO (SERNO):%ld",temp->serno);
			a++;
			for(index=2;index<=total;index++)
			{
				newnode = (struct Node*)malloc(sizeof(struct Node));
			newnode->serno=a;
			printf("\n Enter the person details:");
			printf("\n NAME:");
			scanf("%s",newnode->name);
			printf("\n MOBILE NUMBER:");
			scanf("%ld",&newnode->mno);
			printf("\n HOUSE NO:");
			scanf("%s",newnode->hmno);
			printf("\n STREET:");
			scanf("%s",newnode->street);
			printf("\n VILLAGE:");
			scanf("%s",newnode->village);
			printf("\n TOWN:");
			scanf("%s",newnode->town);
			newnode->fb=0;
			newnode->cylinder=0;
				newnode->next = NULL;
				newnode->prev=temp;
				temp->next = newnode;
				temp=newnode;
			newnode->serno=newnode->serno+1;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\n SERVICE NO (SERNO):%ld",newnode->serno);
			a++;
			}
		}
	}
	else
	{
		printf("\n CONNECTIONS ALREADY REGISTERED");
	}
}
void bill()
{
	struct Node *temp;
	long us;
	
	int n,h,k;
	float bill;
	if(start==NULL)
	{
	  printf("\n error! no enrolled connections");	
	}
	else
	{
		printf("ENTER YOUR SERVICE NUMBER:");
		scanf("%ld",&us);
		temp=start;
		while(temp!=NULL)
		{
			if(us==temp->serno){
				printf("\n ENTER THE NO.OF CYLINDERS REQUIRED");
				scanf("%d",&n);
				printf("\n ENTER 1 TO CONFIRM BOOKING ");
				scanf("%d",&k);
				if(k==1){
				temp->cylinder=temp->cylinder+n;
				bill=n*1124;
				printf("\n BOOKING SUCCESSFULL");
				for(i=0;i<7;i++){
				printf(".\t");
				sleep(1);
			}
			system("cls");
				printf("	       BHARAT GAS					");
				printf("\n----------------------------------");
					printf("\nSERVICE NO      :%ld",temp->serno);
				printf("\nNAME      :%s",temp->name);
				printf("\nH.NO      :%s",temp->hmno);
				printf("\nADDRESS   :%s,",temp->street);
				printf("\n           %s,",temp->village);
				printf("\n           %s",temp->town);
				printf("\nMOBILE NO :%ld",temp->mno);
				printf("\n----------------------------------");
				printf("\nNO.OF CYLINDERS    :%d",temp->cylinder);
				printf("\nBASE RATE          :%d",720*n);
				printf("\nCENTRAL GST        :%d",18*n);
				printf("\nSTATE GST          :%d",18*n);
				printf("\nTOTAL BILL		 :%d",720*n+18*n+18*n);
				printf("\n----------------------------------");
			}	
			temp=temp->next;
		}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		main();
	}
	}
}
}
void newenrol()
{
	newnode=(struct Node *)malloc(sizeof(struct Node));
        	newnode->serno=a;
		printf("\n PLEASE FILL THE FOLLOWING DETAILS FOR NEW CONNECTION:");
	    	printf("\n NAME:");
			scanf("\n");
	   	    scanf("%[^\n]%*c",newnode->name);
			printf(" MOBILE NUMBER:");
			scanf("%ld",&newnode->mno);
			printf(" HOUSE NO:");
			scanf("%s",newnode->hmno);
			printf(" STREET:");
			scanf("\n");
	   	    scanf("%[^\n]%*c",newnode->street);
			printf(" VILLAGE:");
			scanf("\n");
	   	    scanf("%[^\n]%*c",newnode->village);
			printf(" TOWN:");
			scanf("\n");
	   	    scanf("%[^\n]%*c",newnode->town);
			newnode->fb=0;
			newnode->cylinder=0;
		newnode->next=NULL;
		newnode->prev=NULL;
	if(start==NULL){
	start=newnode;
	newnode->serno=newnode->serno+1;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\nSERVICE NO (SERNO)       :%ld",newnode->serno);
			a++;
		}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
			newnode->serno=newnode->serno+1;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\nSERVICE NO (SERNO)       :%ld",newnode->serno);
			a++;
	}
}
void terminate()
{
	int loc=1,count=1,i=0,h,a;
	long us;
	system("cls");
	if(start==NULL)
	{
	  printf("\n error! no enrolled connections");
	}
	else
	{
		printf("ENTER YOUR SERVICE NUMBER:");
		scanf("%ld",&us);
		temp=start;
		while(temp!=NULL)
		{
 			i++;
			temp=temp->next;
		}
		temp=start;
	while(temp!=NULL)
		{
			if(us==temp->serno){
				break;
			}
 			loc++;
			temp=temp->next;
		}
		if(loc==1){
		if(start->next==NULL)
		{
				printf("\n1.CONIFIRM DELETE\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
			printf("\n THE CONECTION WITH SERVICE NO %ld IS DELETED",start->serno);
			start=NULL;
		}
		}
		else{
				printf("\n1.CONFIRM DELETE\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
		temp=start;
		printf("\n THE CONECTION WITH  SERVICE NO %ld IS DELETED",start->serno);
		start = temp->next;
		start = start->next;
		start->prev=NULL;
	    free(temp);	
	    }
		}
		}
		else if(loc==i&&loc!=1){
				printf("\n1.CONFIRM DELETE\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
		temp=start;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		printf("\n THE CONECTION WITH SERVICE NO %ld IS DELETED",temp->serno);
		free(temp);
	    }
		}
		else{
			temp=start;
		   while(temp!=NULL&&count!=loc)
		    {
			   ptr=temp;
			    temp=temp->next;
			    count++;
		    }
		    if(temp==NULL)
		    {
		    	printf("\n NO CONNECTION IS PRESENT");
			}
			else
			{	
			    printf("\n1.CONFIRM DELETE\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
				ptr->next=temp->next;
				printf("\n THE CONECTION WITH SERVICE NO %d IS DELETED",temp->serno);
				free(temp);
			}
			}
		}
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		main();
	}
}
void feedback()
{
		long us;
	system("cls");
	printf("\n ENTER YOUR SERVICE NO:");
	scanf("%ld",&us);
	temp=start;
	while(temp!=NULL){
	if(us==temp->serno){
	printf("ENTER YOUR FEEDBACK:");
    scanf("\n");
	scanf("%[^\n]%*c", temp->feedback);
	temp->fb=1;
	printf("\nTHANK YOU FOR YOUR FEEDBACK");
		}
		temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		main();
	}
}
void employee(){
	int ch;
		system("cls");
		printf("\n1.VIEW CONNECTIONS");
		printf("\n2.VIEW FEEDBACKS");
		printf("\n3.MAIN MENU");
		while(1){
			printf("\n enter your choice:");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					connections();
					break;
				case 2:
					viewfeedback();
					break;
				case 3:
					main();
					break;
			    case 9:
					create();
					break;
				default:printf("\n INVALID CHOICE");
			}
		}
}
void connections(){
	int i=1;
	float bill;
	temp=start;
	system("cls");
	printf("\n S.NO    NAME          SERNO     NO.OF CYLINDERS    BILL AMOUNT         SUBSIDY AMOUNT ");
	while(temp!=NULL){
	printf("\n %d      %s         %ld        %d             %d              %d",i,temp->name,temp->serno,temp->cylinder,1124*temp->cylinder,450*temp->cylinder);
    temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		employee();
	}
}
void viewfeedback(){
	temp=start;
	system("cls");
	while(temp!=NULL){
		if(temp->fb==1){
			printf("\nSERNO: %ld\n FEEDBACK: %s",temp->serno,temp->feedback);
		}
		temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		employee();
	}
}
