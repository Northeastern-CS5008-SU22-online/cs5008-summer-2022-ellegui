//Zixian Gui
//gui.zi@northeastern.edu
//To perform insertion sort of integers stored in a file and display the output and store it in another file.

#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp;
    int arr[10], temp;
    int count = 0, i, j; /*count will have the total number of elements in the array*/

    /*read the file*/
    fp = fopen("Input.txt","r");
    if(fp == NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }

    //insert your code here
    while (fscanf(fp, "%d", &arr[i])!= EOF) {
        printf("%d\n", arr[i]);
        i++;
        count++;
        if (count >= 10) {
            break;
        }
    }

    // Insertion Sort
    for (i = 1; i < count; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }    
    
   // to store the output in another file
   fp = fopen("sorted.txt", "w");
   for (i = 0; i < count; i++) {
       fprintf(fp, "%d\n", arr[i]);
       printf("%d\n", arr[i]);
   } 
    fclose(fp);
    return 0;
}
