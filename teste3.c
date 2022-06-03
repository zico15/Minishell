#include <stdio.h>
#include <stdlib.h>

/*else
		waitpid(g_sig.pid, &ret, 0);
	if (g_sig.sigint == 1 || g_sig.sigquit == 1)
		return (g_sig.exit_status);
	ret = (ret == 32256 || ret == 32512) ? ret / 256 : !!ret;*/

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
