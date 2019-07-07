#include <stdio.h>

char *reverse(char *);

void main() {
  
  char str[] = "abcdefg";

  printf("Input --> %s\n", str);
  
  reverse(str);
  printf("Output --> %s\n", str);

}

char *reverse(char *str) {
  //int i=0, j=0;
  char temp;
  char *first = str, *last = str;
  // char tmpt[100];

  while( *(last+1) != '\0') {
    last++;
  }

  while(first < last){
    temp = *first;
    *first = *last;
    *last = temp;
    
    first++;
    last--;

  }
 
  // while(str[i]) {
  //   // printf("%c", str[i]);
  //   tmpt[i]=str[i];
  //   i++;
  // }

  // while(i) {
  //   i--;
  //   str[j]=tmpt[i];
  //   j++;
  // }
  
}

