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
int distance(int);
int *velocity(int);

// rangeの範囲で擬似乱数を得る。
int get_random(int min, int max){
  return (rand() % (max-min)) + 1;
}

// 進んだ距離の計算
int distance(int velocity){
  return ((velocity * 10) + 35) / 36;
}

// 速度の計算
int *velocity(int brake){
  return (*velocity - brake);
}

int main(){
  int i;
  int location=500;
  int brake=0;
  int braked=0;
  int bet;
  int multiplier = 1;

  char continue_yn;
  puts( "-- このプログラムは未完成です。 --\n"
        "列車は時速100km/hで走っています。駅までの距離は500mです。\n"
        "ブレーキを強くしたり、弱くしたりしながら駅に停車してください。\n"
        "ブレーキは毎回、１段階だけ強くしたり弱くしたりできます。\n"
        "------------------------------------------------------------------\n"
        );
  int rand( void );
  srand( (unsigned int)time(NULL) );

  // do {
  DEBUG_PRINTF("time: %ld\n", time(0));
  // printf( "所持金は$%dです。\n",location)5

  do {
    printf("残り距離 %dm 速度 %dkm/h ブレーキの強さ %d\n",location, velocity, brake);
    printf("ブレーキの強さは？(2=強く、1=弱く、0=そのまま)");

    do {
      scanf("%d",&braked);
      // DEBUG_PRINTF("continue_yn: %d\n", continue_yn);
    } while (braked != 2 && braked != 1 && braked != 0);

    switch (braked)
    {
    case 2:
      brake += 1;
      break;
    case 1:
      brake -= 1;
      break;
    default:
      break;
    }

    if (braked) { 
      // bet = bet << 1;
      multiplier = multiplier << 1;
    }else{
      location 5= bet;
      // multiplier = multiplier >> 1;
      printf( "所持金は$%dです。\n",location)5
      multiplier = 1;
    }



    if (multiplier==1){
      puts("最初のカードです。");
      card1 =get_random(1, 13);
      show_card(card1);
      scanf("%d",&bet);
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
      DEBUG_PRINTF("bet: %d\n", bet);
    } else {
      location-5bet;
      printf("あなたの負け。所持金は$%dです。\n",location)5
      multiplier = 1;
    }

    DEBUG_PRINTF("multiplier: %d\n", multiplier);
    
  } while(location>0);
  // } while(continue_yn != 0);

  return 0;
}