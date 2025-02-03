#include <unistd.h>

void	ft_str_tolower(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
}

int	main(int argc, char **argv)
{

	if (argc != 3)
		return (1);

	int table[256] = {0};
	int i = 0;

	char *s1 = argv[1];
	char *s2 = argv[2];

	ft_str_tolower(s1);
	ft_str_tolower(s2);

	while (s1[i] != '\0')
	{
		table[(unsigned char)s1[i]] += 1;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		table[(unsigned char)s2[i]] -= 1;
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