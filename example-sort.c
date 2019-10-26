#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �w�b�_�t�@�C���ɕ����������ǂ�����
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

// #AA c����ł���Ă͂����Ȃ�����
// https://clown.hatenablog.jp/entry/20111025/ng_programmer

// #BB gets( )��scanf( )�̖��_�̉���
// http://www1.cts.ne.jp/~clab/hsample/IO/IO16.html

int main(int argc, char *argv[]) {

  // printf("Input --> %s\n", argv[1]);

  char *r; //�g��Ȃ��ϐ����c���Ă���
  char *input_string ;
  input_string = NULL ;
  
  // ����Ă͂����Ȃ����ƁF�S�p�X�y�[�X���g��
  twobyte();

  // ����Ă͂����Ȃ����ƁF���������𓙒l��r
  comp_double(1.0, 1.0);
  
  // �����������ꍇ�͕W�����͂�v������
  // switch ()
  if (!argv[1]) {

  }else{
    // �������K�v�ȏ���
    input_string = (char *)malloc( strlen( argv[1] )+1);
    strcpy( input_string , argv[1] );
    DEBUG_PRINTF( "������ [%s]\n" , input_string ) ;


    // input_string = argc > 1 ? argv[1] : ""; //�O�����Z�q
    // ����Ă͂����Ȃ����ƁF�O�����Z�q�̐��s�ɓn�鑽�d�l�X�g
    printf("�O�����Z�̕Ԃ�l --> %s\n", ternary_operator(input_string));


    printf("�����̕�����𔽓] --> %s\n", reverse(input_string));
    
    strcpy( input_string , argv[1] );
    // fprintf( stderr , "input_string [%s]\n" , input_string ) ;
    printf("�����̕�����𕶎��R�[�h���ɕ��בւ� --> %s\n", sort(input_string));

    free( input_string );
  
  }  
  return 0;
}

// ����Ă͂����Ȃ����ƁF�O�����Z�q�̐��s�ɓn�鑽�d�l�X�g
char *ternary_operator(char *input_string){
  DEBUG_PRINTF("input_string [%c]\n", *input_string);
  DEBUG_PRINTF("input_string check [%d]\n", (*input_string > 'a'));
  
  // char *str = input_string ? *input_string > 'a' ? "A": strlen(input_string ) > 2 ? "B": "C": "D";
  // ��̍s�Ɖ��̃l�X�g�͓����Ӗ�
  char *str = input_string ?
                *input_string > 'a' ?
                  "A":
                  strlen(input_string ) > 3 ?
                    "B":
                    "C":
                "D"; /* ������dead code�̂͂� */
  
  return str;
}

// ����Ă͂����Ȃ����ƁF���������𓙒l��r
void comp_double(double comp1 , double comp2){
  for (int i = 0; i < 2; i++) {
    if (comp1 == comp2){
      puts( "�������l") ;
    } else {
      printf( "�قȂ鐔�l\n") ;
    }
    comp1 -= 0.1, comp2 += 0.1;
    comp1 += 0.2;
  }

  comp1 /= 2.00, comp1 *= 2;
  if (comp1 == comp2){
    printf( "�������l\n") ;
  } else {
    printf( "�قȂ鐔�l\n") ;
  }
}


void twobyte() {

  // ����Ă͂����Ȃ����ƁF�S�p�X�y�[�X���g��
  printf("�S�p�X�y�[�X-->\"�@\"<--��\\������\n");
    /*
    MinGWMinGW��gcc�R���p�C���́A������sift-jis�̏ꍇ����̕�����𐳂����F�����܂���B
    ���̏ꍇ�u�\�v�̂Q�o�C�g�ڂ́u0x5C�v�A�܂�\�Ȃ��߁A
    ���́u���v�̂P�o�C�g�ڂ́u0x8E�v(����̂W�i���\�L�� 216)��
    �s���ȃG�X�P�[�v�V�[�P���X���Ɣ��f���Ă��܂��A
    unknown escape sequence: �e\216�f�Ƃ������[�j���O���o���܂��B
    */
  // ���̍s�̓R���p�C���G���[�ɂȂ�
  // printf(�@"\n");

}

//�����̕�����𕶎��R�[�h���ɕ��בւ���B
char *sort(char *str) {
  // printf("%p\n", str);
  char tmp;
  long las;
  char *str1 =str , *str2=str;
  
  #ifdef DEBUG
    // ���͂����e�����̕����R�[�h��\��
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

//�����̕�����𔽓]������B
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
