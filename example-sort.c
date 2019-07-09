#include <stdio.h>

char *reverse(char *);
char *sort(char *);

void main(int argc, char *argv[]) {

    char *p;
    //printf("count --> %d\n", argc);
    p = argc > 1 ? argv[1] : "";
    printf("Input --> %s\n", argv[1]);
    //printf("Output --> %s\n", reverse(p));
    printf("Output --> %s\n", sort(p)); //reverseと同じ引数なので、反転に注意
}

//引数の文字列を文字コード順に並べ替える。
char *sort(char *str) {
    int i,j;
    unsigned char tmp;

    for(j=1; str[j]; j++) {    
      for(i=1; str[i]; i++) {
        if(str[i-1] > str[i]) {
          tmp = str[i-1];
          str[i-1] = str[i];
          str[i] = tmp;
        }
      }
    }
    return str;
}

//引数の文字列を反転させる。
char *reverse(char *str) {
//    printf("size --> %ld\n", sizeof(str));
//   if (*str) {
    char temp;
    char *first = str, *last = str;

    while( *last != '\0') {last++;}
    if (str != last) last--;

    // }
    // for(; *last != '\0'; last++);
    printf("*first --> %lx\n", (long)first);
    printf("*last --> %c\n", *last);
    
    while(first < last){

        temp = *first;
        *first = *last;
        *last = temp;
        //printf("temp --> %c\n", temp);    
        first++;
        last--;
    }

//   }
  return str;
}

