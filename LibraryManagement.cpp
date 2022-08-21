#include<stdio.h>
#include<string.h>
void Issue_Book(struct Book bk[],int size);
void Deposit_Book(struct Book bk[],int size);
void Add_Book(struct Book bk[],int size);
void Delete_Book(struct Book bk[],int size);
struct Book
{
   int b_id;
   char b_name[100];
   char b_author[100];
   int b_qty;
};
int main()
{  int n;
   int size;
   printf("Enter the no of books");
   scanf("%d",&size);
   struct Book bk[size];
    do{
       printf("----LIBRARY MANAGEMENT SYSTEM----\n");
       printf("----1.ISSUE BOOK------\n");
       printf("----2.DEPOSIT BOOK----\n");
       printf("----3.ADD BOOK--------\n");
       printf("----4.DELETE BOOK-----\n");
       printf("----5.EXIT------------\n");
       printf("Enter your option");
       scanf("%d",&n);
       switch (n)
       {
         case 1: Issue_Book(bk,size);
                 break;
       case 2:   Deposit_Book(bk,size);
                 break;
       case 3:  Add_Book(bk,size);
                break;

       case 4: Delete_Book(bk,size);
               break;

       }
    }while(n!=5);
    return 0;
}
void Issue_Book(struct Book bk[],int size)
{
                int id;
                 printf("The following books are available\n");
                  for(int i=0;i<size;i++)
                { printf("%d  \t %s \t %s \t %d \n",bk[i].b_id,bk[i].b_name,bk[i].b_author,bk[i].b_qty);}
                  printf("Enter book id for issue");
                  scanf("%d",&id);
                  for(int i=0;i<size;i++)
                  {
                    if(bk[i].b_id==id)
                    {
                        if(bk[i].b_qty>0)
                        {
                           bk[i].b_qty--;
                           break;
                        }
                        else{
                            printf("Sorry ! book not available\n");
                            break;
                        }
                    }
                  }  
}
void Deposit_Book(struct Book bk[],int size)
{
                 char name[100];
                 printf("Enter the book name");
                 fgets(name,25,stdin);
                 for(int i=0;i<size;i++)
                 {
                    if(strcmp(bk[i].b_name,name))
                    {
                        bk[i].b_qty++;
                        printf("Book has been deposited\n");
                        break;
                    }
                 }
}
void Add_Book(struct Book bk[],int size)
{
                 int id,qty;
                 char name[100],author[100];
                size++;
                printf("To add book\n");
                printf("Enter book id");
                scanf("%d",&id);
                bk[size-1].b_id=id;
                printf("Enter book name");
                scanf("%s",&name);
                strcpy(bk[size-1].b_name,name);
                printf("Enter author name");
                scanf("%s",&author);
                strcpy(bk[size-1].b_author,author);
                printf("Enter book quantity");
                scanf("%d",&qty);
                bk[size-1].b_qty=qty; 
}
void Delete_Book(struct Book bk[],int size)
{
    int id;
               printf("Enter the book id ");
               scanf("%d",&id);
               for(int i=0;i<size;i++)
               {
                if(id==bk[i].b_id)
                {
                    for(int j=i;j<size;j++)
                    {
                         bk[i]=bk[i+1];
                    }
                    break;
                }
               }
}