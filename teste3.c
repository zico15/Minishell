#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	
	while (i < 10000)
	{
			printf("T: %i\n", i++);
	}
	printf("FIMM: %i\n", i++);
	exit(0);
}
