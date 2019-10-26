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

int get_random(int,int);
void show_card(int);

// rangeの範囲で擬似乱数を得る。
int get_random(int min, int max){
  return (rand() % (max-min)) + 1;
}

// 数字に対応するトランプのカードを表示する。
void show_card(int num){
  switch (num)
  {
  case 1: 
    printf("|A|\n");
    break;
  case 11: 
    printf("|J|\n");
    break;
  case 12: 
    printf("|Q|\n");
    break;
  case 13: 
    printf("|K|\n");
    break;
  default:
    printf("|%d|\n",num);
    break;
  }
  return;
}

int main(){
  int i;
  int possession=100;
  int card1=0;
  int card2=0;
  int bet;
  int multiplier = 1;
  char buf[256];

  char continue_yn;
  puts( "-- このプログラムは未完成です。 --\n"
        "最初に１枚カードが出ますから掛け金を決めてください。\n"
        "次に出るカードが前のカードと同じか大きければ、あなたの勝ちです。\n"
        "掛け金が戻りますから、続けるかどうかを決めてください。続けて勝てば掛け金は２倍になります。以降、４倍、８倍と戻るお金が増えます。ただし、負けるとそれまでの勝ちは なくなります。\n"
        "所持金が無くなって破産するか、$1000を超えるとゲーム終了です。\n"
        "----------------------------------------------\n"
        "ゲームを開始します。");
  int rand( void );
  srand( (unsigned int)time(NULL) );

  // do {
  DEBUG_PRINTF("time: %ld\n", time(0));
  printf( "所持金は$%dです。\n",possession);

  do {
   
    if (multiplier==1){

      printf("最初のカードです。\n");
      card1 =get_random(1, 13);
      show_card(card1);
      printf("いくら賭けますか？($1～$%d)",possession);
      fgets(buf, sizeof(buf), stdin);
      sscanf(buf, "%d",&bet);
      possession -= bet; 
    }else{
      bet=bet<< 1;
    }
    DEBUG_PRINTF("bet: %d\n", bet);

    // 勝敗判断
    card2 =get_random(1, 13);
    show_card(card2);
    DEBUG_PRINTF("card1: %d\n", card1);
    DEBUG_PRINTF("card2: %d\n", card2);
    if (card1 >= card2){
      printf("あなたの勝ち。$%dの勝ちです。\n",bet);
      // multiplier = multiplier << 1;
      do {
        printf("倍率は%d倍。続けますか？（1=Yes; 0=No!）", multiplier<<1);
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%d",&continue_yn);
        DEBUG_PRINTF("continue_yn: %d\n", continue_yn);
      } while (continue_yn != 1 && continue_yn != 0);
      if (continue_yn) { 
        // bet = bet << 1;
        multiplier = multiplier << 1;
      }else{
        possession += bet;
        // multiplier = multiplier >> 1;
        printf( "所持金は$%dです。\n",possession);
        multiplier = 1;
      }
      DEBUG_PRINTF("bet: %d\n", bet);
    } else {
      // possession -= bet;
      printf("あなたの負け。所持金は$%dです。\n",possession);
      multiplier = 1;
    }

    DEBUG_PRINTF("multiplier: %d\n", multiplier);
    
  } while(possession > 0 && possession<=1000);
  if (possession >= 1000)
      printf("おめでとう！！ あなたは大富豪です。\n");
  else
      printf("残念でした。破産です。\n");
      
  return 0;
}