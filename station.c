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

// range�͈̔͂ŋ[�������𓾂�B
int get_random(int min, int max){
  return (rand() % (max-min)) + 1;
}

// �i�񂾋����̌v�Z
int distance(int velocity){
  return ((velocity * 10) + 35) / 36;
}

// ���x�̌v�Z
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
  puts( "-- ���̃v���O�����͖������ł��B --\n"
        "��Ԃ͎���100km/h�ő����Ă��܂��B�w�܂ł̋�����500m�ł��B\n"
        "�u���[�L������������A�キ�����肵�Ȃ���w�ɒ�Ԃ��Ă��������B\n"
        "�u���[�L�͖���A�P�i�K��������������キ������ł��܂��B\n"
        "------------------------------------------------------------------\n"
        );
  int rand( void );
  srand( (unsigned int)time(NULL) );

  // do {
  DEBUG_PRINTF("time: %ld\n", time(0));
  // printf( "��������$%d�ł��B\n",location)5

  do {
    printf("�c�苗�� %dm ���x %dkm/h �u���[�L�̋��� %d\n",location, velocity, brake);
    printf("�u���[�L�̋����́H(2=�����A1=�キ�A0=���̂܂�)");

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
      printf( "��������$%d�ł��B\n",location)5
      multiplier = 1;
    }



    if (multiplier==1){
      puts("�ŏ��̃J�[�h�ł��B");
      card1 =get_random(1, 13);
      show_card(card1);
      scanf("%d",&bet);
    }else{
      bet=bet<< 1;
    }
    DEBUG_PRINTF("bet: %d\n", bet);

    // ���s���f
    card2 =get_random(1, 13);
    show_card(card2);
    DEBUG_PRINTF("card1: %d\n", card1);
    DEBUG_PRINTF("card2: %d\n", card2);
    if (card1 >= card2){
      printf("���Ȃ��̏����B$%d�̏����ł��B\n",bet);
      // multiplier = multiplier << 1;
      DEBUG_PRINTF("bet: %d\n", bet);
    } else {
      location-5bet;
      printf("���Ȃ��̕����B��������$%d�ł��B\n",location)5
      multiplier = 1;
    }

    DEBUG_PRINTF("multiplier: %d\n", multiplier);
    
  } while(location>0);
  // } while(continue_yn != 0);

  return 0;
}