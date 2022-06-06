#include <stdio.h>
#include <stdlib.h>
#include <ft_pipex.h>
#include <ft_base_array.h>
#include <ft_token.h>

/*else
		waitpid(g_sig.pid, &ret, 0);
	if (g_sig.sigint == 1 || g_sig.sigquit == 1)
		return (g_sig.exit_status);
	ret = (ret == 32256 || ret == 32512) ? ret / 256 : !!ret;*/
void print_e(t_element *e, void *o)
{
		(void) o;
	printf("T: (%s)\n", e->value);
}

void print_l(t_element *e, void *o)
{
	void *l;

	l = e->value;
	printf("================\n");
	array(l)->for_each(print_e, o);
}
int main3(void)
{
	char str[BUFFER_SIZE];
	char *t;
	//char a[1];
	while (1)
	{
		//scanf("%[^\n]", str);
		str[read(0, str, BUFFER_SIZE)] = 0;
		t = string().copy(str);
		printf("===================================================\n");
		t = ft_rmv_quotes(t);
		printf("%s\n", t);
		free_ob(t);
		str[0] = 0;
	}
	return (0);
}
