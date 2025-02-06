#include <unistd.h>

// int		ft_atoi(char *str)
// {
// 	int n = 0;

// 	while (*str != '\0')
// 	{
// 		n = n * 10;
// 		n = n + *str - '0';
// 		++str;
// 	}
// 	return (n);
// }

// void	print_hex(int n)
// {
// 	char hex_digits[] = "0123456789abcdef";

// 	if (n >= 16)
// 		print_hex(n / 16);
// 	write(1, &hex_digits[n % 16], 1);
// }

// int		main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		print_hex(ft_atoi(argv[1]));

// 	write(1, "\n", 1);
// }
int atoi(char *s)
{
	int i;
	int nbr;
	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		nbr = nbr * 10;
		nbr = nbr + s[i] - '0';
		i++;
	}
	return(nbr);
}

int print_hex(int nbr)
{
	char HEX[] = "0123456789abcdef";

	if (nbr <= 16)
		print_hex(nbr / 16);
	write(1, &HEX[nbr % 16], 1);
	return (nbr)
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1), 0);
	print_hex(ft_atoi(argv[1]));
	return (0);
}