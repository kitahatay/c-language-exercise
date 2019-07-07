//引数の文字列を反転させて出力する。

#include <stdio.h>

char *reverse(char *);

void main(int argc, char *argv[]) {

    char *p;
    printf("count --> %d\n", argc);
    p = argc > 1 ? argv[1] : "";
    printf("Input --> %s\n", argv[1]);
    printf("Output --> %s\n", reverse(p));

}

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

