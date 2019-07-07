#include <stdio.h>

void main() {
  
  char str[] = "abcdefg";
  char *reverse( char * );

  printf("Input --> %s\n", str);
  
  reverse(str);
  printf("Output --> %s\n", str);

}

char *reverse( char *str ) {
  int i=0, j=0;
  char tmpt[100];

  while(str[i]) {
    // printf("%c", str[i]);
    tmpt[i]=str[i];
    i++;
  }

  while(i) {
    i--;
    str[j]=tmpt[i];
    j++;
  }
  
}

