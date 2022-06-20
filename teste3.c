#include <stdio.h>
#include <stdlib.h>
#include "headers/ft_minishell.h"
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

//scanf("%[^\n]", str);

int main3(void)
{
	char *str;
	void	*lst;
	void	*cmd;
	str = readline("write: ");
	printf("===================================================\n");
	lst = token(str);
	free(str);
	// lst = ft_divide_quotes(string().copy(str));
	int	i = -1;
	while (++i < array(lst)->size)
	{
		// printf("(%s)\n", array(lst)->get(i));
		cmd = array(lst)->get(i);
		int j = -1;
		while (++j < array(cmd)->size)
		{
			printf("(%s)\n", array(cmd)->get(j));
		}
		printf("===============\n");
	}
	array(lst)->for_each(set_fun_destroy_token, NULL);
	array(lst)->destroy();
	rl_clear_history();
	return (0);
}
// ls | wc > t.txt || < t.txt wc
