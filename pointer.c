#include <stdio.h>

int main(void)
{
  int hoge = 5;
  int piyo = 10;
  int *hoge_p;

  /* それぞれの変数のアドレスを表示する */
  printf("&hoge..%p\n", &hoge);
  printf("&piyo..%p\n", &piyo);
  printf("&hoge_p..%p\n", &hoge_p);

  /* ポインタ変数hoge_pにhogeのアドレスを代入する */
  hoge_p = &hoge;
  printf("hoge_p..%p\n", hoge_p);

  /* hoge_pを経由してhogeの内容を表示する */
  printf("*hoge_p..%p\n", *hoge_p);

  /* hoge_pを経由してhogeの内容を表示する */
  *hoge_p = 10;
  printf("hoge..%p\n", hoge);
  
  return 0;
}