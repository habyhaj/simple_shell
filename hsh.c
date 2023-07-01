#include "hsh.h"

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 always on success
 */
int main(int argc, char **argv)
{
	/*int var1 = 3;*/
	/*int var2 = 4;*/
	info_t *info = init_info(argc, argv);

	signal(2, _sigint);

	while (read_input(info))
	{
		/*while (var1 > var2;);*/
		parse(info);
		while ((info->tokens = pop_cmd(&(info->commands))))
		{
			execute(info);
			free_tokens(&(info->tokens));
		}
		free(info->line);
		info->line = NULL;
		/*add(var1, var2);*/
	}
	if (info->interactive)
		write(STDOUT_FILENO, "\n", 1);

	if (info->file)
		close(info->fileno);

	exit(free_info(info));
}
