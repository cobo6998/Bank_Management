#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void menu();


void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()
{
    int choice;
    FILE *ptr;
    
    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
    
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    
    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
        test++;
    }
    fclose(view);
    if (test==0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }
    
    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
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

//Start of the main program    
int main()    
{
    //define two variables for credentials 
    char pass[16], password[16]="anesti_bochoris";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    //check of password
    if (strcmp(pass,password)==0)
        /*In case of correct password, the program prints a message in the screen
        and then run 6 times the fordelay() function and prints 6 '.'. Then it clears the 
        screen and calls the function menu().*/
        {printf("\n\nCorrect Password!\nLOADING");
        for(i=0;i<=6;i++)
        {
            //Call the function fordelay()
            fordelay(100000000);
            printf(".");
        }
            //Clear the screen
            system("cls");
            //Call the function menu()
            menu();
        }
    else
        /*In case of incorrect password, the program prints a message in the screen
    Then prompt to type 1 for another try or 0 for exit.*/
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                /* In case 1 has been typed it clears the screen 
        and calls the function menu().*/
                    {
                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                /* In case 0 has been typed it clears the screen 
        and calls the function close().*/
                    {
                    system("cls");
                    close();}
            else
                 /* In case any other character have been typed it prints a message, 
        calls the function fordelay(), clears the screen and loop at the prompt for
        1 or 0 choice. */
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
