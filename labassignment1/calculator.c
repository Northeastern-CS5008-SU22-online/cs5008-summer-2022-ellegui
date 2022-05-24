// Zixian Gui
// gui.zi@northeastern.edu

#include <stdio.h>

int main()
{
    int a,b,c, choice;

    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d", &choice);
    
    printf("Enter a and b values");
    scanf("%d %d", &a, &b);
    
    switch (choice) {
        case 1:
            c = a + b;
            printf("Sum = %d\n", c);
            break;

        case 2:
            c = a - b;
            printf("Subtraction = %d\n", c);
            break;

        case 3:
            c = a * b;
            printf("Product = %d\n", c);
            break;
        
        case 4:
            c = a / b;
            printf("Division = %d\n", c);
            break;
        
        default:
            printf("Invalid choice input\n");
            break;
    }
        
    return 0;
}
