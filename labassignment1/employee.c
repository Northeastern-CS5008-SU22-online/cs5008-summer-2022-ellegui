/*C Program to read and print the employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/

typedef struct employee {
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];
}employee_t;

/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
    for (int i = 0; i < n; i++){
        printf("\nEnter the employeeID, Name, designation and Department of Employee %d:\n", (i + 1));
        employee_t e;
        scanf("%d", &e.empId);
        scanf("%s", e.Name);
        scanf("%s", e.Designation);
        scanf("%s", e.Dept);
        s[i] = e;
    }
}

/* Function to print the employee details*/
void display(int n, employee_t* s)
{
    for (int i = 0; i < n; i++){
        printf("\nThe details of Employee %d:\n", (i + 1));
        printf("empId: %d\n", s[i].empId);
        printf("Name: %s\n", s[i].Name);
        printf("designation: %s\n", s[i].Designation);
        printf("Dept: %s\n", s[i].Dept);
    }
}

/*----------Main Program--------*/
int main()
{
    int number;
    
    printf("Enter the number of employees: ");
    scanf("%d", &number);

    employee_t s[number];
    readData(number, &s);
    display(number, &s);

    return 0;
}