#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct flags
{
	int minus;
	int zero;
	int star;
	int dot;
} flag;

int main()
{
	char *i = "123";

	printf("%s",i);
	printf("end");

	int j = 123;

	printf("\n%d", j);
	
		

	return (0);
}