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
	scanf("%[^\n]", str);
	// printf("===================================================\n");
	// printf("%s\n", str);
	// int	i = -1;
	// while (str[++i])
	// 	printf("%i", is_quotes(str, i));
	// printf("\n");
	// printf("===================================================\n");
	// ft_divide_cmd(str);
	void *tk;
	tk = ft_divide_cmds(ft_divide_quotes(str));
	printf("size: %i\n",array(tk)->size);
	array(tk)->for_each(print_l, 0);
	return (0);
}
