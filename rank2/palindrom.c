int ft_strlen(char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return (i);
}
int palindrom(char *s)
{
    int i = 0;
    int j = ft_strlen(s) - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return (0);
        i++;
        j--;
    }
    return(1);
}
int main (int argc, char **argv)
{
    if (argc != 2)
        return (1);
    if (!palindrom(argv[1]))
        return (1);
    return (0);
}