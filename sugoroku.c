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
  puts( "�������낭��\n"
        "30�}�X��ɃS�[��������܂��B\n"
        "1,2,3�̂R�̖ڂ������ʂȃT�C�R��10���A�D���Ȑ������U���ċ��i�߂܂��B\n"
        "�҂�����オ��Ɏ~�܂�ΏI���ł��B�ڂ̐���������΁A�]�����ڂ̐������߂�܂��B\n"
        "----------------------------------------------\n");
  int rand( void );
  srand( (unsigned int)time(NULL) );

  do {
    DEBUG_PRINTF("time: %ld\n", time(0));
    puts( "��_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |�オ��I\n");
    do {
      printf("�c��%d�}�X�ł��B�T�C�R���̐��́H",30-position);
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
      printf("�o���ڂ̍��v %u\n", move);

      position += move;
      if (position > 30){
        position = 30 -(position-30);
      } else {

      }

      for (i=0; i<position; i++) {
        printf("- ");
      }
      printf("��");
      for (; i<30; i++) {
        printf("- ");
      }
      printf("|�オ��I\n");

      count++;
    } while(position != 30);

    printf("���߂łƂ��I�I %d��ڂŏオ��ł�",count);

    do {
      puts("������x���܂����H�i1=Yes; 0=No!�j");
      scanf("%d",&continue_yn);
      DEBUG_PRINTF("continue_yn: %d\n", continue_yn);
    } while (continue_yn != 1 && continue_yn != 0);
  } while(continue_yn != 0);

  return 0;
}