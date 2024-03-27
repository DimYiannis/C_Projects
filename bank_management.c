#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    char name[50];
    char pass[50];
    int isLoggedIn;
    double balance;
};

struct Money
{
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

void createacc(struct Account *accounts)
{

    char name[50];
    char pass[50];

    printf("Please insert your name: \n");
    scanf("%s", accounts->name);
    printf("\n Please create your password: \n");
    scanf("%s", accounts->pass);
    printf("\n Your new account has been created!");
    printf("\nProceed to login... \n");
}

void login(struct Account *accounts, int numAccounts)
{
    char name[50];
    char pass[50];
    int i;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%s", pass);

    for (i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].name, name) == 0 &&
            strcmp(accounts[i].pass, pass) == 0)
        {
            accounts[i].isLoggedIn = 1;
            printf("\nWelcome, %s! You are now logged in.\n", name);
            return;
        }
    }
    // If no matching account found
    printf("\nInvalid username or password. Please try again.\n");
}

void transfer(struct Account *accounts, int numAccounts)
{
    char sender_name[50];
    char receiver_name[50];
    double amount;
    int i, sender_index = -1, receiver_index = -1;

    // Find the index of the logged-in user (sender)
    for (i = 0; i < numAccounts; i++)
    {
        if (accounts[i].isLoggedIn)
        {
            sender_index = i;
            break;
        }
    }

    printf("Enter receiver's name: ");
    scanf("%s", receiver_name);

    // Find receiver's account
    for (i = 0; i < numAccounts; i++)
    {
        if (strcmp(accounts[i].name, receiver_name) == 0)
        {
            receiver_index = i;
            break;
        }
    }

    if (receiver_index == -1)
    {
        printf("Receiver's account not found.\n");
        return;
    }

    // input amount to transfer
    printf("enter amount to transfer:  ");
    scanf("%lf", &amount);

    // check if sender has sufficient balance
    if (accounts[sender_index].balance < amount)
    {
        printf("insufficient balance in the sender's account. \n");
        return;
    }

    // perform the transfer
    accounts[sender_index].balance -= amount;
    accounts[receiver_index].balance += amount;

    printf("transfer successful. New balance for sender %s: %.2lf \n", accounts[sender_index].name, accounts[sender_index].balance);
    printf("New balance for receiver %s: %.2lf \n", accounts[receiver_index].name, accounts[receiver_index].balance);
}

void account(struct Account *accounts, int numAccounts, int sender_index)
{
    int choice;

    printf("\n If you wish to transfer money to your account press 3");
    printf("\n If you wish to check your account's money amount press 4");
    printf("\n If you wish to logout press 5");
    scanf("%d", &choice);

    switch (choice)
    {
    case 3:
        transfer(accounts, numAccounts);
        break;
    case 4:
        printf("Your current balance: %.2lf\n", accounts[sender_index].balance);
        break;
    case 5:
        accounts[sender_index].isLoggedIn = 0;
        printf("You have been logged out.\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}


int main()
{
    int choice;
    struct Account accounts[100];

    while (1)
    {
        printf("\n Welcome to westealyourmoney bank!\n");
        printf("\nPlease choose one of the following options to proceed.\n");
        printf("In order to create an account press: 1 \n");
        printf("In order to login tou your account press: 2 \n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            createacc(accounts);
            login(accounts, 100);
        }
        else if (choice == 2)
        {
            login(accounts, 100);
        }
        else
        {
            printf("Invalid choice please choose again");
        }
    }

    return 0;
}