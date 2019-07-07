#include <stdio.h>

void main(int argc, char *argv[])
{
/*
	printf("Hello World\n");
	printf("%d\n",argc);
*/
	char work[10];
	int i;

	for(i=1;i<argc;i++) {
		printf("%s",argv[i]);
		printf(" ");
	}
	// work[10] = 'a';
	printf("\n");
}

