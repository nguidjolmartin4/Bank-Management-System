# Bank Management Systems in C

## Thanks for visiting this gtihub repo🙏

Okay so this is the beginning of a long story so, I will be brief 🧐!. The purpose of this program is offer users a lil account management system for an imaginary bank.

And this is the interface of your bank

    +---------------+-------------+---------------+
    |               |  Main Menu  |               |
    +---------------+-------------+---------------+
    |       1 . Deposit Money                     |
    |       2 . Withdraw Money                    |
    |       3 . Transfer Money                    |
    |       4 . Account Details                   |
    |       5 . Transaction Details               |
    |       6 . Exit                              |
    +---------------------------------------------+

        Enter your choice : 

And in this readme file, I'm going to walk you through the code I made so have fun 😁📝!

### Header Files 📝

Down below are all the header files i used to complete the program.

    #include<time.h>    
    #include<stdio.h>
    #include<conio.h>
    #include<stdlib.h>

The `time.h` header file helped me to use the time(), ctime() functions which basically permitted me to get the current date🗓 and time🕓 of the system during the transactions🤑💸

You can see them in action at these level

    void deposit_money() {

        time_t tm;
        time(&tm);

        FILE *ptr = fopen("Account.txt", "a");

        printf("+--------------------------+\n");
        printf("|     DEPOSITING MONEY     |\n");
        printf("+--------------------------+\n");
        printf("Enter the amount : ");
        scanf("%d", &dip_amt);

        amt += dip_amt;

        printf("Money Deposited Successfully\n");
        printf("Current Balance : %d XAF", amt);
        fprintf(ptr, "\n---------------------------------------\n");
        fprintf(ptr, "%d XAF has been deposited to your account successfully!\n", dip_amt);
        fprintf(ptr, "Date and time of transaction : %s", ctime(&tm));
        printf("\nPress a any key to continue ...");
        getch();
    }

Now about the `stdio.h` (Standard Input Output) header file actually gives us the possibility to use function like `printf()`, `scanf()` and all the light ...😏😏.

The `conio.h` header file give us access to functions like `getch()`. Actually it's the only function from the `conio.h` header file I used in the program so I won't mention the other ones 🥲🥲🥲.

Now talking the about the `stdlib.h` (Standard Library) header file it gives us access to function like `system()`, `exit()` and many more ...😏😏.

You can see them in action down below

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

What `system("cls")`; actually is, it clear's the terminal for the user for more visibility of the program and the `exit(0)` function actually exit's out the program with a return value. A `O` return value means everything was successful✅✅✅ mean while a `1` return value means there was and error❌❌❌ while running the program.

### The Function `f(x)`

Down below are the functions i used allthrough the program.

    void menu();
    void deposit_money();
    void withdraw_money();
    void transfer_money();
    void account_details();
    void transaction_details();
    void last_details();

Actually I won't through explaining all the functions 1 by 1 but i have the opportunity to record my screen, I will explain my code thoroughtly Okay🙏🥲...

`Please the Account.txt file contains all the transaction made with account`

Thank's for getting through this Markdown file!🙏🥲.
It's your favourite coder #ng_dev

Follow me on :

Instagram : <https://www.instagram.com/nguidjol_martin/>
GitHub    : <https://github.com/nguidjolmartin4>
Email     : <nguidjolmartin4@gmail.com>
Whatsapp  : <https://whatsapp.com/channel/0029VaDrn2V4o7qH1cMCOc1X>
