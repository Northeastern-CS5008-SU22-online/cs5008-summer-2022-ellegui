// name: Zixian Gui
// email: gui.zi@northeastern.edu

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]) {
    int i = 0;
    int slow = 0;
    int fast;
    
    //insert your code here

    while (slow < n){
        fast = slow;

        while (fast < n && arr[fast] == arr[slow]) {
            fast++;
        }
        res[i++] = arr[slow];
        
        if(fast - slow > 1) {
            int diff = fast - slow;
            char count[100];
            sprintf(count, "%d", diff);
            for (int j = 0; j < strlen(count); j++){
                res[i++] = count[j];
            }
        }
        slow = fast;
    }
    printf("Input: %s\n", arr);
    printf("Output: %s\n", res);
    return i; 
}
 

int main() {
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
