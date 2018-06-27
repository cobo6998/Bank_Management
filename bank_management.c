#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void menu();


void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close(void)
{
    printf("\n\n\n\nThis C Project is developed by Bochoris and Anesti!");
}

void menu(void)
{
    int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    
    system("cls");
    switch(choice)
    {
            case 1:new_acc();
            break;
            case 2:edit();
            break;
            case 3:transact();
            break;
            case 4:see();
            break;
            case 5:erase();
            break;
            case 6:view_list();
            break;
            case 7:close();
            break;
    }
}
    
int main()
    
{
    char pass[16], password[16]="anesti_bochoris";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nCorrect Password!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
