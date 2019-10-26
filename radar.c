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
  puts( "�����[�_�[��\n"
        "�^�[�Q�b�g�Ƃ��� 0�`100 �̂����P�̐����ݒ肳��܂��B�T������ʒu�Ɣ͈͂���͂��ă^�[�Q�b�g�������Ă��������B\n"
        "�^�[�Q�b�g�ƒT���ʒu�̍����T���͈͈ȉ��ł���΃q�b�g�ł��B�T���͈͂��傫����΁A�͂���ł��B\n"
        "�T���ʒu�ƃ^�[�Q�b�g����v����ΐ����ł��B\n"
        "----------------------------------------------\n"
        "�Q�[�����J�n���܂��B\n");
  int rand( void );
  srand( (unsigned int)time(NULL) );

  do {
    DEBUG_PRINTF("time: %ld\n", time(0));
    target = rand();
    DEBUG_PRINTF("target: %u\n", target);

    // DEBUG_PRINTF("%d %u %u\n",INT_MIN, target, RAND_MAX);
    target = (unsigned int)(target*99)/RAND_MAX;
    DEBUG_PRINTF("target: %u\n", target);

    puts( "�^�[�Q�b�g���ݒ肳��܂����B\n"
          "�ʒu�́H");
    scanf("%d",&direction);
    DEBUG_PRINTF("direction: %d\n", direction);
    // direction = getchar(); 

    puts( "\n�͈͂́H");     
    scanf("%d",&range);
    DEBUG_PRINTF("range: %d\n", range);
    // ran_char = getchar();
    // DEBUG_PRINTF("range: %u\n", range);

    if ((target <= (direction + range)) && (target >= (direction - range))){
      puts( "\n�q�b�g���܂����B");
    } else {
      puts( "\n�͂���܂����B");  
    }
    do {
      puts("������x���܂����H�i1=Yes; 0=No!�j");
      scanf("%d",&continue_yn);
      DEBUG_PRINTF("continue_yn: %d\n", continue_yn);
    } while (continue_yn != 1 && continue_yn != 0);
  } while(continue_yn != 0);

  return 0;
}