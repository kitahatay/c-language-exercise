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

// range�͈̔͂ŋ[�������𓾂�B
int get_random(int min, int max){
  return (rand() % (max-min)) + 1;
}

// �����ɑΉ�����g�����v�̃J�[�h��\������B
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
  puts( "-- ���̃v���O�����͖������ł��B --\n"
        "�ŏ��ɂP���J�[�h���o�܂�����|���������߂Ă��������B\n"
        "���ɏo��J�[�h���O�̃J�[�h�Ɠ������傫����΁A���Ȃ��̏����ł��B\n"
        "�|�������߂�܂�����A�����邩�ǂ��������߂Ă��������B�����ď��ĂΊ|�����͂Q�{�ɂȂ�܂��B�ȍ~�A�S�{�A�W�{�Ɩ߂邨���������܂��B�������A������Ƃ���܂ł̏����� �Ȃ��Ȃ�܂��B\n"
        "�������������Ȃ��Ĕj�Y���邩�A$1000�𒴂���ƃQ�[���I���ł��B\n"
        "----------------------------------------------\n"
        "�Q�[�����J�n���܂��B");
  int rand( void );
  srand( (unsigned int)time(NULL) );

  // do {
  DEBUG_PRINTF("time: %ld\n", time(0));
  printf( "��������$%d�ł��B\n",possession);

  do {
   
    if (multiplier==1){

      printf("�ŏ��̃J�[�h�ł��B\n");
      card1 =get_random(1, 13);
      show_card(card1);
      printf("������q���܂����H($1�`$%d)",possession);
      fgets(buf, sizeof(buf), stdin);
      sscanf(buf, "%d",&bet);
      possession -= bet; 
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
      do {
        printf("�{����%d�{�B�����܂����H�i1=Yes; 0=No!�j", multiplier<<1);
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
        printf( "��������$%d�ł��B\n",possession);
        multiplier = 1;
      }
      DEBUG_PRINTF("bet: %d\n", bet);
    } else {
      // possession -= bet;
      printf("���Ȃ��̕����B��������$%d�ł��B\n",possession);
      multiplier = 1;
    }

    DEBUG_PRINTF("multiplier: %d\n", multiplier);
    
  } while(possession > 0 && possession<=1000);
  if (possession >= 1000)
      printf("���߂łƂ��I�I ���Ȃ��͑�x���ł��B\n");
  else
      printf("�c�O�ł����B�j�Y�ł��B\n");
      
  return 0;
}