#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc != 3)
	{	
		write(1, "\n", 1);
		return (0);
	}
	int i = 0;
	int j = 0;

	char *str1 = argv[1];
	char *str2 = argv[2];
	while (str2[i])
	{
		if (str2[i] == str1[j])
			j++;
		if (str1[j] == '\0')
		{
			write(1, "1\n", 2);
			return (0);
		}
		i++;
	}
	write(1, "0\n", 2);
	return (0);
}