
void main() {
  printf("Hello World\n");
  printf(" World");
  unsigned char astr[];

  unsigned char *Sreverse(unsigned char *, unsigned char *), astr;
  
  printf("%s", Sreverse(astr));
  return 0;
}

unsigned char *Sreverse(unsigned char *s, unsigned char *t) {
  unsigned *pp;
  pp=t;

  while(*s++);
  for(t=0; *t++=*s--;);
  return pp;
}