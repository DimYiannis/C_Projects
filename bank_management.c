#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    char name[50];
    char pass[50];
    int isLoggedIn;
};

void createacc(struct Account *accounts) {

    char name[50];
    char pass[50];

    printf("Please insert your name: \n");
    scanf("%s", accounts->name);
    printf("\n Please create your password: \n");
    scanf("%s", accounts->pass);
    printf("\n Your new account has been created!");
    printf("\nProceed to login... \n");

}

void login(struct Account *accounts, int numAccounts) {
  char name[50];
  char pass[50];
  int i;

  printf("Enter your name: ");
  scanf("%s", name);
  printf("Enter your password: ");
  scanf("%s", pass);

    for (i=0; i<numAccounts; i++)
    {
        if (strcmp(accounts[i].name, name)== 0 &&
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