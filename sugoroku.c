// http://kitako.tokyo/lib/CTask.aspx
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DEBUG
#if defined(DEBUG)
  #define DEBUG_PRINTF(fmt,...) printf( "Debugging: %s [Line:%d] " fmt, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
  #define DEBUG_PRINTF(fmt,...)
#endif

int main(){
  int i;
  int position=0;
  int ndice;
  unsigned int dice[10];
  unsigned char move ;
  int count = 0;

  char continue_yn;
  puts( "▲すごろく▼\n"
        "30マス先にゴールがあります。\n"
        "1,2,3の３つの目を持つ特別なサイコロ10個を、好きな数だけ振って駒を進めます。\n"
        "ぴったり上がりに止まれば終わりです。目の数が多ければ、余った目の数だけ戻ります。\n"
        "----------------------------------------------\n");
  int rand( void );
  srand( (unsigned int)time(NULL) );

  do {
    DEBUG_PRINTF("time: %ld\n", time(0));
    puts( "▲_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |上がり！\n");
    do {
      printf("残り%dマスです。サイコロの数は？",30-position);
      scanf("%d",&ndice);
      DEBUG_PRINTF("ndice: %d\n", ndice);
      // ndice = getchar(); 
      move=0;
      for (i=0; i<ndice; i++) {
        dice[i]=1+(int)(rand()*(3-1+1.0)/(1+RAND_MAX));
        DEBUG_PRINTF("dice[%d]: %u ",i,dice[i]);
        move += dice[i];
      }
      DEBUG_PRINTF("\n");
      printf("出た目の合計 %u\n", move);

      position += move;
      if (position > 30){
        position = 30 -(position-30);
      } else {

      }

      for (i=0; i<position; i++) {
        printf("- ");
      }
      printf("▲");
      for (; i<30; i++) {
        printf("- ");
      }
      printf("|上がり！\n");

      count++;
    } while(position != 30);

    printf("おめでとう！！ %d回目で上がりです",count);

    do {
      puts("もう一度やりますか？（1=Yes; 0=No!）");
      scanf("%d",&continue_yn);
      DEBUG_PRINTF("continue_yn: %d\n", continue_yn);
    } while (continue_yn != 1 && continue_yn != 0);
  } while(continue_yn != 0);

  return 0;
}