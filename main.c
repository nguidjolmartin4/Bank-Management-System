#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char name[20];
int deposit_amt, withdraw_amt, transfer_amt;
int amt = 10000, account_num;
int account_num_a, account_num_b;

void menu();
void deposit_money();
void withdraw_money();
void transfer_money();
void account_details();
void transaction_details();
void last_details();

int main() {

    int choice;

    printf("Enter your name : ");
    gets(name);

    printf("Enter your account no. : ");
    scanf("%d", &account_num);

    while (1) {
        menu();

        printf("\n\tEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls"); 
                deposit_money();
                break;
            case 2:
                system("cls"); 
                withdraw_money();
                break;
            case 3:
                system("cls"); 
                transfer_money();
                break;
            case 4:
                system("cls"); 
                account_details();
                break;
            case 5:
                system("cls"); 
                transaction_details();
                break;
            case 6:
                system("cls"); 
                last_details();
                exit(0);

            default: printf("Invalid Choice");
        }
    }

    return 0;
}

void menu() {
    system("cls");
    printf("\n+---------------+-------------+---------------+\n");
    printf("|               |  Main Menu  |               |\n");
    printf("+---------------+-------------+---------------+\n");
    printf("|       1 . Deposit Money                     |\n");
    printf("|       2 . Withdraw Money                    |\n");
    printf("|       3 . Transfer Money                    |\n");
    printf("|       4 . Account Details                   |\n");
    printf("|       5 . Transaction Details               |\n");
    printf("|       6 . Exit                              |\n");
    printf("+---------------------------------------------+\n");
}

void deposit_money() {

    time_t tm;
    time(&tm);

    FILE *ptr = fopen("Account.txt", "a");

    printf("+--------------------------+\n");
    printf("|     DEPOSITING MONEY     |\n");
    printf("+--------------------------+\n");
    printf("Enter the amount : ");
    scanf("%d", &deposit_amt);

    amt += deposit_amt;

    printf("Money Deposited Successfully\n");
    printf("Current Balance : %d XAF", amt);
    fprintf(ptr, "\n---------------------------------------\n");
    fprintf(ptr, "%d XAF has been deposited to your account successfully!\n", deposit_amt);
    fprintf(ptr, "Date and time of transaction : %s", ctime(&tm));
    printf("\nPress a any key to continue ...");
    getch();
}

void withdraw_money() {

    time_t tm;
    time(&tm);

    FILE *ptr = fopen("Account.txt", "a");

    printf("+------------------------+\n");
    printf("|     WITHDRAW MONEY     |\n");
    printf("+------------------------+\n");
    printf("Enter the amount : ");
    scanf("%d", &withdraw_amt);

    amt -= withdraw_amt;

    printf("Money Withdrawn Successfully\n");
    printf("Current Balance : %d XAF\n", amt);
    fprintf(ptr, "---------------------------------------\n");
    fprintf(ptr, "%d XAF has been withdrawn from your account successfully!\n", withdraw_amt);
    fprintf(ptr, "Date and time of transaction : %s", ctime(&tm));
    printf("\nPress a any key to continue ...");
    getch();
};

void transfer_money() {

    time_t tm;
    time(&tm);

    FILE *ptr = fopen("Account.txt", "a");

    printf("+----------------------------+\n");
    printf("|     TRANSFERRING MONEY     |\n");
    printf("+----------------------------+\n");
    printf("Enter the amount : ");
    scanf("%d", &transfer_amt);

    if (amt < transfer_amt) {
        printf("Your Balance is insufficient !");
    } else {
        printf("Enter the account no. of the receiver\n=> ");
        scanf("%d", &account_num_a);
        
        printf("Re-enter the account no. of the receiver\n=> ");
        scanf("%d", &account_num_b);

        if (account_num_a != account_num_b) {
            printf("The two account no. doesn't match!");
        } else {
            amt -= transfer_amt;
            printf("Money Transferred Successfully !\n");
            printf("Current Balance : %d\n", amt);
            fprintf(ptr, "---------------------------------------\n");
            fprintf(ptr, "%d XAF has been transferred from your account to %d successfully!\n", transfer_amt, account_num_a);
            fprintf(ptr, "Date and time of transaction : %s", ctime(&tm));
            printf("\nPress a any key to continue ...\n");
            getch();
        }  
    }

};

void account_details() {

    printf("+------------------------------------\n");
    printf("|       ACCOUNT DETAILS\n");
    printf("+---------------+--------------------\n");
    printf("| Name          | %s\n", name);
    printf("| Account No.   | %d\n", account_num);
    printf("| Total Balance | %d\n", amt);
    printf("+---------------+--------------------\n");
    printf("\nPress any key to continue...");
    getch();
};

void transaction_details() {
    
    FILE *ptr;
    ptr = fopen("Account.txt", "r");

    char c = fgetc(ptr);

    if (c == EOF) {
        printf("No Recent Transactions\n");
    } else {
        printf("Transaction Details\n");
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }

    printf("\nPress any key to continue...");
    getch();
};

void last_details() {

    printf("+----------------+----------------+\n");
    printf("| Name           | %s\n", name);
    printf("| Account Number | %d\n", account_num);
    printf("| Amount         | %d\n", amt);
    printf("+----------------+----------------+\n");
    printf("\nPress any key to continue...");
    getch();    
};