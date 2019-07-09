#include <stdio.h>

char *reverse(char *);
char *sort(char *);

void main(int argc, char *argv[]) {

    char *p;
    //printf("count --> %d\n", argc);
    p = argc > 1 ? argv[1] : "";
    printf("Input --> %s\n", argv[1]);
    printf("Output1 --> %s\n", reverse(p));
    printf("Output2 --> %s\n", sort(p)); //reverseと同じ引数なので、反転に注意
}

//引数の文字列を文字コード順に並べ替える。
char *sort(char *str) {
    // int i,j,k;
    // unsigned char tmp;

    // for(i=0; str[i]; i++) {
    //   for(j=0; str[j]; j++) {
    //     if(str[j] > str[j+1]) {
    //       tmp = str[j];
    //       str[j] = str[j+1];
    //       str[j+1] = tmp;
          
    //     }
    //   }
    // }
///////////////    
    char tmp;
    char *str1 = str, *str2 = str;

    // while( *last != '\0') {last++;}
    // if (str != last) last--;
    while(*str1){
      do {
        str2++;
        if(*str1 > *str2) {
          tmp = *str1;
          *str1 = *str2;
          *str2 = tmp;
        }
      } while(*str2);
      str1++;
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

