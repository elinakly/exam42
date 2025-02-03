#include <unistd.h>

char *ft_tolower(char *s)
{
	int i = 0;

	while(s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <- 'z')
		{
			s[i] -= 32;
		}
		i++;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	char *s1, *s2;
	int i = 0;
	if (argc != 3)
		return (1);
	char table[256] = {0}; 
	s1 = ft_tolower(argv[1]);
	s2 = ft_tolower(argv[2]);

	while (s1[i] != '\0')
	{
		table[s1[i]] += 1;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		table[s2[i]] -= 1;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (table[i] != 0)
			return (1);
		i++;
	}
	return (0);
}