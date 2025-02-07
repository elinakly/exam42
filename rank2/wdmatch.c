#include <unistd.h>

char *putstr(char *s)
{
    int i = 0;
    while(s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return(s);
}
int main(int ac, char **av)
{
    char *s1 = av[1];
    char *s2 = av[2];
    if (ac != 3)
        return(write(1, "\n", 1), 0);
    int i = 0;
    int j = 0;
    while(s1[i] != '\0' && s2[j] != '\0')
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    if (s1[i] == '\0')
        putstr(s1);
    write(1, "\n", 1);
    return(0);
}