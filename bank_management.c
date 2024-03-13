#include <stdio.h>
#include <stdlib.h>


void createacc() {

    char name[50];
    char pass[50];

    printf("Please insert your name");

}



int main()
{
    int choice;

    while (1)
    {
        printf("Welcome to westealyourmoney bank!\n");
        printf(" please choose one of the following options to proceed.\n");
        printf("In order to create an account press: 1 \n");
        printf("In order to login tou your account press: 2 \n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            createacc();
        }
        else if (choice == 2)
        {
            login();
        }
        else
        {
            printf("Invalid choice please choose again");
        }

    }

    return 0;
}