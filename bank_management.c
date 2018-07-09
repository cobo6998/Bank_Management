#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int main_exit;

void menu();

struct date
{
    int month,day,year;
};

struct
{
    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add,upd,check,rem,transaction;


float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}
    
//The function foredelay() used for import a delay. This achieved by a loop
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
    printf("\nEnter the amount to deposit:€");
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
//Print a message with the developers before exit
void close(void)
{
    printf("\n\n\n\nThis C Project is developed by Bochoris and Anesti!");
}

void transact(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==transaction.acc_no)
        {
            test=1;
            if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if (choice==1)
            {
                printf("Enter the amount you want to deposit:€ ");
                scanf("%f",&transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
             else
             {
                 printf("Enter the amount you want to withdraw:€ ");
                 scanf("%f",&transaction.amt);
                 add.amt-=transaction.amt;
                 fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                 printf("\n\nWithdrawn successfully!");
             }
        }
        else
        {
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test!=1)
    {
        printf("\n\nRecord not found!!");
        transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==0)
            transact();
        else if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }
}
        
    
 


void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }
}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("Enter the account number:");
        scanf("%d",&check.acc_no);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {
                system("cls");
                test=1;
                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:€ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                {
                    time=1.0;
                    rate=9;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                {
                    time=2.0;
                    rate=11;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                {
                    time=3.0;
                    rate=13;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                }
                else if(strcmpi(add.acc_type,"saving")==0)
                {
                    time=(1.0/12.0);
                    rate=8;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d of every month",intrst,add.deposit.day);
                }
                else if(strcmpi(add.acc_type,"current")==0)
                {
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    else if (choice==2)
    {
        printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {
                system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                {
                    time=1.0;
                    rate=9;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                {
                    time=2.0;
                    rate=11;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                {
                    time=3.0;
                    rate=13;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                }
                else if(strcmpi(add.acc_type,"saving")==0)
                {
                    time=(1.0/12.0);
                    rate=8;
                    intrst=interest(time,add.amt,rate);
                    printf("\n\nYou will get €.%.2f as interest on %d of every month",intrst,add.deposit.day);
                }
                else if(strcmpi(add.acc_type,"current")==0)
                {
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }
    fclose(ptr);
    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
        else
        {
            printf("\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
        }
        if (main_exit==1)
        {
            system("cls");
            menu();
        }
        else
        {
            system("cls");
            close();
        }
    }
        
        
                    


/* The menu() function provides the initial menu for the program after a success login
It has 7 choices which are leading in relative actions*/
void menu(void)
{
    int choice;
    //Clear the screen
    system("cls");
    //Set the font color blue
    system("color 0");
    //Print the Headline of the menu
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    
    system("cls");
    //Depending with the choice it calls the relative function 
    switch(choice)
    {
            case 1:
            new_acc();
            break;
            case 2:
            edit();
            break;
            case 3:
            transact();
            break;
            case 4:
            see();
            break;
            case 5:
            erase();
            break;
            case 6:
            view_list();
            break;
            case 7:
            close();
            break;
            default:
            printf("\nInvalid! Try again...");
            fordelay(1000000000);
            system("cls");
            menu();
    }
}

//Start of the main program    
int main()    
{
    //for greek characters
    system("chcp 1253>nul");
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
