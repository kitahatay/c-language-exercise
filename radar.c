// http://kitako.tokyo/lib/CTask.aspx
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// #define DEBUG
#if defined(DEBUG)
  #define DEBUG_PRINTF(fmt,...) printf( "Debugging: %s [Line:%d] " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define DEBUG_PRINTF(fmt,...)
#endif

int main(){
  int direction;
  int range;
  unsigned int target ;
  unsigned char dir_char ;
  unsigned char ran_char ;
  char continue_yn;
  puts( "☆レーダー☆\n"
        "ターゲットとして 0～100 のうち１つの数が設定されます。探索する位置と範囲を入力してターゲットを見つけてください。\n"
        "ターゲットと探索位置の差が探索範囲以下であればヒットです。探索範囲より大きければ、はずれです。\n"
        "探索位置とターゲットが一致すれば正解です。\n"
        "----------------------------------------------\n"
        "ゲームを開始します。\n");
  int rand( void );
  srand( (unsigned int)time(NULL) );

  do {
    DEBUG_PRINTF("time: %ld\n", time(0));
    target = rand();
    DEBUG_PRINTF("target: %u\n", target);

    // DEBUG_PRINTF("%d %u %u\n",INT_MIN, target, RAND_MAX);
    target = (unsigned int)(target*99)/RAND_MAX;
    DEBUG_PRINTF("target: %u\n", target);

    puts( "ターゲットが設定されました。\n"
          "位置は？");
    scanf("%d",&direction);
    DEBUG_PRINTF("direction: %d\n", direction);
    // direction = getchar(); 

    puts( "\n範囲は？");     
    scanf("%d",&range);
    DEBUG_PRINTF("range: %d\n", range);
    // ran_char = getchar();
    // DEBUG_PRINTF("range: %u\n", range);

    if ((target <= (direction + range)) && (target >= (direction - range))){
      puts( "\nヒットしました。");
    } else {
      puts( "\nはずれました。");  
    }
    do {
      puts("もう一度やりますか？（1=Yes; 0=No!）");
      scanf("%d",&continue_yn);
      DEBUG_PRINTF("continue_yn: %d\n", continue_yn);
    } while (continue_yn != 1 && continue_yn != 0);
  } while(continue_yn != 0);

  return 0;
}