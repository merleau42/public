Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>


#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

void	epurstr(char *s)
{
	int len = ft_strlen(s);

	while (len && ft_isblank(s[len - 1]))
		--len;
	while (len && ft_isblank(*s) && *s++)
		--len;
	while (len--)
	{
		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))
			write(1, s, 1);
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		epurstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
