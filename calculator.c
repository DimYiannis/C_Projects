#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    double a, b;
    while (1)
    {
        printf("Enter an operator (+, -, *, /), \n"
               "if want to exit press x: ");
        scanf("%c", &ch);

        // to exit
        if (ch == 'x')
            exit(0);
        printf("Enter two first and second operand: ");
        scanf("%lf %lf", &a, &b);

        // using switch case we will differentiate
        // operations based on different operator
        switch (ch)
        {

        // for addition
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
            break;

        // for subtraction
        case '-':
            printf("%.1lf - %.1lf= %.1lf\n", a, b, a - b);
            break;

        // for multiplication
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
            break;

            // For Division
        case '/':
            printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
            break;

            // If operator doesn't match any case constant
        default:
            printf("Error! please write a valid operator\n");
        }

        printf("\n");
    }
}