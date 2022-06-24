#include <ft_minishell.h>

int	main4()
{
	char	*str;
	str = readline("write: ");
	printf("===================================================\n");
	printf("result: %i\n", ft_handle_brackets(str, 30));
	free(str);
	rl_clear_history();
	return (0);
}
