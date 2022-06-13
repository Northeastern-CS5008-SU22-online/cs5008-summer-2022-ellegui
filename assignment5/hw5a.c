// name: Zixian Gui
// email: gui.zi@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95  // 95 printing characters x20-x7E


// return random character
char randChar() {
  // 0 -> x20 -> ' '
  // 1 -> x21 -> '!'
  // ,,,
  // 94 -> x7E -> '~'
  // see https://ascii.cl
  return ((char)((rand() % RAND_RANGE) + 0x20));
}


// return location mid way between left and right
int midPoint(int left, int right){
  // note integer division always returns an integer
  return( left + (right-left)/2 );
}


// min of two integers
int findMin(int a, int b){
  if (a<=b) {return a;} else {return b;}
}


// merge two sorted sub arrays
void mergeIt(
	   char* data,
	   int leftStart,
	   int leftStop,
	   int rightStart,
	   int rightStop) {

  // ADD YOUR CODE HERE
  // calculate the length of the left and right portions of the array
  int left_len = leftStop - leftStart + 1;
  int right_len = rightStop - rightStart + 1;

  // create temporary arrays to store these portions
  int temp_left[left_len];
  int temp_right[right_len];
  
  // used as index/counter variables for the 3 arrays: data[], temp_left, temp_right
  int i, j, k;
  
  // copy the left portion into the temp_left array
  for (i = 0; i < left_len; i++) {
    temp_left[i] = data[leftStart + i];
  }

  // copy the right portion into the temp_right array
  for (int i = 0; i < right_len; i++) {
    temp_right[i] = data[rightStart + i];
  }

  // i move through temp_left, j move through temp_right, and k move through the data array
  // add element from temp_left[] to data[] if temp_left[i] is less than temp_right[j]
  // or if j reaches the end of temp_right
  for (i = 0, j = 0, k = leftStart; k <= rightStop; k++) {
    if ((i < left_len) && 
        (findMin(temp_left[i] + 0, temp_right[j] + 0) == temp_left[i] + 0) || j >= right_len) {
      data[k] = temp_left[i];
      i++;
    }
  // add element from temp_right[] to data[] if temp_left[i] is larger than temp_right[j]
    else {
      data[k] = temp_right[j];
      j++;
    }
  }  
  return;
}


// break data array up into halves until down to single elements
// then merge them
void msort(char* data, int left, int right) {

  if (left >= right) {
    // base case of 1 element
    return;
  } else {
    // sort left half
    msort(data, left, midPoint(left,right));

    // sort right half
    msort(data, midPoint(left,right)+1, right);

    // merge left and right halves
    mergeIt(
	    data,
	    left, midPoint(left,right),
	    midPoint(left,right)+1, right
	    );
  }
  return;
}


int main(){

  char source[LIMIT]; // array to hold input data values

  int i;             // loop variable
  int j;             // loop variable
  int smallest;      // current smallest element

  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize source array with random character
  for (i=0; i<LIMIT; i++) {
    source[i] = randChar();
  }

  //print out source array in rows of 20 elments
  printf("Source array:\n");
  for (i=0; i < ((LIMIT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < LIMIT) {
	      printf("%c ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // do the sorthing
  msort(source, 0, LIMIT-1);


  //print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i=0; i < ((LIMIT/10)+1); i++) {
    for (j=0; j<10; j++) {
      if (i*10+j < LIMIT) {
	      printf("%c ",source[i*10+j]);
      }
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
