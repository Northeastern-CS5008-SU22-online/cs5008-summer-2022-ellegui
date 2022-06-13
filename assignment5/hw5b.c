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
  return ((char)((rand() % RAND_RANGE)+0x20));
}


// return the value of a char unless it is lower case
// in which case return the upper case of the character
char upperChar(char c){
  if ((c<'a') || (c>'z')){
    return(c);
  } else {
    // if you forget the displacement of lower to upper case
    // just let the computer figure it out for you!
    return(c-('a'-'A'));
  }
}

// convert chars from "a - z" to "A - Z" and compare 
bool lessEqual(char first, char second) {
  if (first >= 97 && first <= 122){
    first = first - 32;
  }
  if (second >= 97 && second <= 122){
    second = second - 32;
  }
  if (first <= second) {
    return true;
  }
  else {
    return false;
  }
}

// convert chars from "a - z" to "A - Z" and compare
bool largerThan(char first, char second) {
  if (first >= 97 && first <= 122){
    first = first - 32;
  }
  if (second >= 97 && second <= 122){
    second = second - 32;
  }
  if (first > second) {
    return true;
  }
  else {
    return false;
  }
}

// pick pivot and then sort small and big parts 
void quicky(char* data, int left, int right) {

  // ADD YOUR CODE HERE
  int i, j, pivot, temp;
  // let pivot = left index, i move from left to right, j is the opposite
  if (left < right) {
    pivot = left;
    i = left;
    j = right;

    while (i < j) {
      while (lessEqual(data[i], data[pivot]) && i < right) {
        i++;
      }
      while (largerThan(data[j], data[pivot])) {
        j--;
      }

      // swap data[i] and data[j]
      if(i < j) {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
    
    // swap data[pivot] and data[j]
    temp = data[pivot];
    data[pivot] = data[j];
    data[j] = temp;

    // apply quicksort to the left side subarray
    quicky(data, left, j - 1);

    // apply quicksort to the right side subarray
    quicky(data, j + 1, right);
  }
  return;
}


int main() {

  char source[LIMIT]; // array to hold input data values

  int i;             // loop variable
  int j;             // loop variable


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

  // do the sorting
  quicky(source, 0, LIMIT-1);

  
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
