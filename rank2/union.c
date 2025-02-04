#include <unistd.h>

void ft_union(char *s1, char *s2)
{
    int table[256] = {0};

    int i = 0;
    while (s1[i] != '\0')
    {
        if (table[s1[i]] == 0)
        {
            table[s1[i]] = 1;
            write(1, &s1[i], 1);
        }
        i++;
    }
    i = 0;
    while (s2[i] != '\0')
    {
        if (table[s2[i]] == 0)
        {
            table[s2[i]] = 1;
            write(1, &s2[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}