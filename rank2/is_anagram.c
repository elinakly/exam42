#include <unistd.h>

char *ft_tolower(char *s)
{
	int i = 0;

	while(s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <- 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}

int is_anagram(char *a, char *b)
{
	int table[256] = {0};
	int i = 0;

	while (a[i] != '\0')
	{
		table[a[i]] += 1;
		i++;
	}
	i = 0;
	while (b[i] != '\0')
	{
		table[b[i]] -= 1;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (table[i] != 0)
			return(1);
		i++;
	}
	return(0);
}
int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	char *s1 = ft_tolower(argv[1]);
	char *s2 = ft_tolower(argv[2]);
	if (is_anagram(s1, s2))
		return(1);
	return (0);
}