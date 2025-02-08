#include <unistd.h>

int main(int argc, char **argv)
{
    char *str = argv[1];
    int i = 0;
    if (argc != 2)
        return(write(1, "\n", 1));
	while (str[i])
	{
		int count = str[i] - 'a' + 1;
		while (count > 0)
		{
			write(1, &str[i], 1);
			count--;
		}
		i++;
	}
    write(1, "\n", 1);
    return(0);
}