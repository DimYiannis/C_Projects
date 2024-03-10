#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library
{
    char book_name[20];
    char author[20];
    int pages;
    float price;
};

int main()
{

    struct library lib[100];

    char ar_nm[30], bk_nm[30];

    // Keep the track of the number of books available in the library
    int i, input = 0, count = 0;

    while (input != 5)
    {
        printf("\n\n********######"
               "WELCOME TO E-LIBRARY "
               "#####********\n");
        printf("\n\n1. Add book information\n2. Display "
               "book information\n");
        printf("3. List all books of "
               "given author\n");
        printf(
            "4. List the count of books in the library\n");
        printf("5. Exit");

        // Enter the book details
        printf("\n\nEnter one of "
               "the above: ");
        scanf("%d", &input);

        switch (input)
        {

            // add book
        case 1:
            if (count < 100)
            {
                printf("Enter book name = ");
                scanf("%s", lib[count].book_name);

                printf("Enter author name = ");
                scanf("%s", lib[count].author);

                printf("Enter pages = ");
                scanf("%d", &lib[count].pages);

                printf("Enter price = ");
                scanf("%f", &lib[count].price);
                count++;
            }
            else
            {
                printf("Library is full. Cannot add more books.\n");
            }
            break;

        // Print book information
        case 2:
            printf("you have entered the following information \n");

            for (i = 0; i < count; i++)
            {
                printf("book name = %s \n", lib[i].book_name);

                printf("\t author name =  %s \n", lib[i].author);

                printf("\t pages = %d \n", lib[i].pages);

                printf("\t price = %f \n", lib[i].price);
            }
            break;

        // take the author name as input
        case 3:
            printf("Enter author name : ");
            scanf("%s", ar_nm);
            for (i = 0; i < count; i++)
            {
                if (strcmp(ar_nm, lib[i].author) == 0)
                    printf("%s %s %d %f \n",
                           lib[i].book_name,
                           lib[i].author,
                           lib[i].pages,
                           lib[i].price);
            }
            break;

        // print total count
        case 4:
            printf("\n No of books in library: %d", count);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}