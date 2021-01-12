#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct person{
  char name[30];
  char address[100];
  char father_name[30];
  char mother_name[30];
  long int phone_no[10];
  char sex[8];
  char mail[100];
  char citizen_no[15];

  };
  void menu();
  void got();
  void back();
  void start();
  void addrecord();
  void modifyrecord();
  void deleterecord();
  void listrecord();
  void searchrecord();

int main()

{
    system("color 3f");
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
    printf("**********WELCOME TO PHONEBOOK**********\t\t\n\n");
    printf("\t\tMENU\n");
    printf("1.Add New \t2.List \t\t3.Exit \n4.Modify \t5.Search \t6.Delete");
    switch(getch()){
case '1':
    addrecord();
    break;
case '2':
    listrecord();
    break;
case '3':
    exit(0);
    break;
case '4':
    modifyrecord();
    break;
case '5':
    searchrecord();
    break;
case '6':
    deleterecord();
    break;
default:
    system("cls");
    printf("Enter input between 1 to 6 only\n");
    printf("Enter the input\n");
    getch();
menu();
    }
}
void addrecord(){
system("cls");
FILE *f;
struct person p;
f=fopen("project","ab+");
printf("Enter name:\n");
got(p.name);
printf("\nEnter the address:\n");
got(p.address);
printf("\nEnter Father's name:\n");
got(p.father_name);
printf("\nEnter Mother's name:\n");
got(p.mother_name);
printf("\nEnter phone number:\n");
got(p.phone_no);
printf("\nEnter sex:\n");
got(p.sex);
printf("\nEnter E-mail ID:\n");
got(p.mail);
printf("\nEnter Citizen Number:\n");
got(p.citizen_no);
fwrite(&p,sizeof(p),1,f);

fflush(stdin);
printf("Record Saved\n");
fclose(f);

printf("Enter any key");
getch();
system("cls");
menu();
}

void listrecord(){
struct person p;
FILE *f;
f=fopen("project","rb");
if (f==NULL)
{
    printf("\nError in Listing!\n");
exit(1);
}
while(fread(&p,sizeof(p),1,f)==1){
        printf("\nHERE IS THE LIST OF THE CONTACTS IN YOUR DEVICE!\n");
    printf("\nName: %s\n Address: %s\n Father's Name: %s\n Mother's Name: %s\n Phone Number: %ld\n Sex: %s\n E-mail ID: %s\n Citizen Number: %s\n",p.name,p.address,p.father_name,p.mother_name,p.phone_no,p.sex,p.mail,p.citizen_no);
getch();
system("cls");
}
fclose(f);

printf("Enter any key");
getch();
system("cls");
menu();
}

void searchrecord()
{
struct person p;
char name[50];
FILE *f;
f=fopen("project","rb");
if (f==NULL)
{
    printf("Error in Opening\a\a\a\n");
exit(1);
}
printf("\nEnter the name to search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1){
        if(strcmp(p.name,name)==0){
            printf("\nDetailed Information about %s",name);

    printf("\nName: %s\n Address: %s\n Father's Name: %s\n Mother's Name: %s\n Phone Number: %ld\n Sex: %s\n E-mail ID: %s\n Citizen Number: %s\n",p.name,p.address,p.father_name,p.mother_name,p.phone_no,p.sex,p.mail,p.citizen_no);
getch();
system("cls");
}
else
    printf("File not found\n");
}

fclose(f);

printf("Enter any key");
getch();
system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
    int flag;
    char name[50];
    f=fopen("project","rb");
    if(f==NULL)
        {

            printf("DATA NOT FOUND!!!");

        }
    else
    {
        ft=fopen("temp","wb+");
        if(ft==NULL)

            printf("File opening error");
        else

        {


        printf("\nEnter the name to delete:");
        got(name);

        fflush(stdin);
        while(fread(&p,sizeof(p),1,f)==1)
        {
            if(strcmp(p.name,name)!=0)
                fwrite(&p,sizeof(p),1,ft);
            if(strcmp(p.name,name)==0)
                flag=1;
        }
    fclose(f);
    fclose(ft);
    if(flag!=1)
    {
        printf("\nNO SUCH CONTACT FOUND!!");
        remove("temp.txt");
    }
        else
        {
            remove("project");
            rename("temp.txt","project");
            printf("CONTACT DELETED!");

        }
    }
}
 printf("\n Enter any key");

     getch();
    system("cls");
menu();
}
void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
    char  name[50];
    f=fopen("project","rb+");
    if(f==NULL)
        {

            printf("CONTACT'S DATA NOT ADDED YET.");
            exit(1);


        }
    else
    {
        system("cls");
        printf("\nENTER CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter the Name:");
                    got(s.name);
                    printf("\nEnter the Address:");
                    got(s.address);
                    printf("\nEnter Father's name:");
                    got(s.father_name);
                    printf("\nEnter Mother's name:");
                    got(s.mother_name);
                    printf("\nEnter Phone number:");
                    scanf("%ld",&s.phone_no);
                    printf("\nEnter sex:");
                    got(s.sex);
                    printf("\nEnter E-mail ID:");
                    got(s.mail);
                    printf("\nEnter citizen no\n");
                    got(s.citizen_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n YOUR DATA HAS BEEN MODIFIED SUCCESSFULLY!!!");

            }
            else
            {
                    printf("\nDATA NOT FOUND!!");

            }
            fclose(f);
    }
     printf("\n Enter any key");
     getch();
    system("cls");
    menu();

}

void got(char *name)
{

   int i=0,j;
    char g,ch;
    do
    {
        g=getch();
                if(g!=8&&g!=13)
                {
                    *(name+i)=g;
                        putch(g);
                        i++;
                }
                if(g==8)
                {
                    if(i>0)
                    {
                        i--;
                    }

                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(g!=13);
      *(name+i)='\0';
}




