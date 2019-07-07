#include <stdio.h>

char *reverse(char *);

void main(int argc, char *argv[]) {

char *p;
   printf("count --> %d\n", argc);
 p = argc > 1 ? argv[1] : "";

 if( argc > 1)   p = argv[1];
else p = "";

  //引数チェック
//  if (argc>1) {
    if (*argv[1] == '\0') {
        printf("No characters in argument %s\n",argv[1]);
        return;
//    }
    printf("Input --> %s\n", argv[1]);
  }
  else {
      printf("No argument\n");
  }

  printf("Output --> %s\n", reverse(p));

}

char *reverse(char *str) {
  char temp;
  char *first = str, *last = str;

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
  return str;
}

