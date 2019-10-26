#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ヘッダファイルに分けた方が良いかも
// #define DEBUG
#if defined(DEBUG)
  #define DEBUG_PRINTF(fmt,...) printf( "Debugging: %s [Line:%d] " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define DEBUG_PRINTF(fmt,...)
#endif

char *reverse(char *);
char *sort(char *);
void twobyte();
void comp_double(double, double);
char *ternary_operator(char *);

// #AA c言語でやってはいけないこと
// https://clown.hatenablog.jp/entry/20111025/ng_programmer

// #BB gets( )とscanf( )の問題点の解決
// http://www1.cts.ne.jp/~clab/hsample/IO/IO16.html

int main(int argc, char *argv[]) {

  // printf("Input --> %s\n", argv[1]);

  char *r; //使わない変数を残しておく
  char *input_string ;
  input_string = NULL ;
  
  // やってはいけないこと：全角スペースを使う
  twobyte();

  // やってはいけないこと：浮動小数を等値比較
  comp_double(1.0, 1.0);
  
  // 引数が無い場合は標準入力を要求する
  // switch ()
  if (!argv[1]) {

  }else{
    // 引数が必要な処理
    input_string = (char *)malloc( strlen( argv[1] )+1);
    strcpy( input_string , argv[1] );
    DEBUG_PRINTF( "第一引数 [%s]\n" , input_string ) ;


    // input_string = argc > 1 ? argv[1] : ""; //三項演算子
    // やってはいけないこと：三項演算子の数行に渡る多重ネスト
    printf("三項演算の返り値 --> %s\n", ternary_operator(input_string));


    printf("引数の文字列を反転 --> %s\n", reverse(input_string));
    
    strcpy( input_string , argv[1] );
    // fprintf( stderr , "input_string [%s]\n" , input_string ) ;
    printf("引数の文字列を文字コード順に並べ替え --> %s\n", sort(input_string));

    free( input_string );
  
  }  
  return 0;
}

// やってはいけないこと：三項演算子の数行に渡る多重ネスト
char *ternary_operator(char *input_string){
  DEBUG_PRINTF("input_string [%c]\n", *input_string);
  DEBUG_PRINTF("input_string check [%d]\n", (*input_string > 'a'));
  
  // char *str = input_string ? *input_string > 'a' ? "A": strlen(input_string ) > 2 ? "B": "C": "D";
  // 上の行と下のネストは同じ意味
  char *str = input_string ?
                *input_string > 'a' ?
                  "A":
                  strlen(input_string ) > 3 ?
                    "B":
                    "C":
                "D"; /* ここはdead codeのはず */
  
  return str;
}

// やってはいけないこと：浮動小数を等値比較
void comp_double(double comp1 , double comp2){
  for (int i = 0; i < 2; i++) {
    if (comp1 == comp2){
      puts( "同じ数値") ;
    } else {
      printf( "異なる数値\n") ;
    }
    comp1 -= 0.1, comp2 += 0.1;
    comp1 += 0.2;
  }

  comp1 /= 2.00, comp1 *= 2;
  if (comp1 == comp2){
    printf( "同じ数値\n") ;
  } else {
    printf( "異なる数値\n") ;
  }
}


void twobyte() {

  // やってはいけないこと：全角スペースを使う
  printf("全角スペース-->\"　\"<--を表\示する\n");
    /*
    MinGWMinGWのgccコンパイラは、文字列がsift-jisの場合特定の文字列を正しく認識しません。
    この場合「表」の２バイト目は「0x5C」、つまり\なため、
    次の「示」の１バイト目の「0x8E」(これの８進数表記が 216)が
    不明なエスケープシーケンスだと判断してしまい、
    unknown escape sequence: ‘\216’というワーニングを出します。
    */
  // 次の行はコンパイルエラーになる
  // printf(　"\n");

}

//引数の文字列を文字コード順に並べ替える。
char *sort(char *str) {
  // printf("%p\n", str);
  char tmp;
  long las;
  char *str1 =str , *str2=str;
  
  #ifdef DEBUG
    // 入力した各文字の文字コードを表示
    for (; strlen(str );str++){
      printf("%c = %X\n", *str, *str);
    }
    str=str1;
  #endif
 
  
  // printf("%p\n", str1);

  while(*str1) {
  // printf("str1 %c\n", *str1);
    while(*str2) {
  // printf("str2 %c\n", *str2);
      if(*str1 > *str2) {
        tmp = *str1;
        *str1 = *str2;
        *str2 = tmp;
      }
      str2++;
    }

    str1++;
    str2=str1+1;
  }
  // printf("%p\n", str2);

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
  // printf("*first --> %lx\n", (long)first);
  // printf("*last --> %c\n", *last);
  
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
