#include <stdio.h>

char *to_upper(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}

int ft_strlen(char *s)
{
    int i = 0;

    while(s[i] != '\0')
    {
        i++;
    }
    return (i);
}

int main(int argc, char *argv[])
{
    int i;

    i = 0;
    if (argc != 3)
        return (1);
    char *s1 = to_upper(argv[1]);
    char *s2 = to_upper(argv[2]);
    int len = ft_strlen (s1);
    int len2 = ft_strlen (s2);
    if (len != len2)
        return (1);
    while (s1[i] != '\0')
    {
        int j = 0;
        while (s2[j] != '\0')
        {   
            if (s1[i] == s2[j])
            {
                len--;
                break;
            }
            j++;
        }
        i++;
    }
    if (len == 0)
        return (0);
    return (1);
}