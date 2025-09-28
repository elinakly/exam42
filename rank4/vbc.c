#include "vbc.h"

void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
    exit(1);
}

int ft_product(char **s)
{
    int a = ft_factor(s);
    while (**s == '*')
    {
        (*s)++;
        a *= ft_factor(s);
    }
    return a;
}

int ft_sum(char **s)
{
    int sum = ft_product(s);
    while (**s == '+')
    {
        (*s)++;
       sum += ft_product(s);
    }
    return sum;
}

int ft_factor(char **s)
{
    if (isdigit(**s))
        return *(*s)++ - '0';
    if (**s == '(')
    {
        (*s)++;
        int n = ft_sum(s);
        if (**s != ')')
            unexpected(**s);
        (*s)++;
        return n;
    }
    if (**s == '\0')
        unexpected(0);
    unexpected(**s);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    char *s = argv[1];
    int res = ft_sum(&s);
    if (*s != '\0')
        unexpected(*s);

    printf("%d\n", res);
    return 0;
}
