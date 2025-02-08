#include <unistd.h>

char *to_lower(char *s)
{
    int i = 0;

    while(s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        i++;
    }
    return(s);
}

int main(int argc, char **argv)
{
    int i = 1;
    int j;
    int flag = 0;
    int a = 0;
    if (argc == 1)
        return(write(1, "\n", 1), 0);
    while(argv[i])
    {   
        to_lower(argv[i]);
        i++;
    }
    i = 1;

    while(argv[i])
    {
        j = 0; 
   
        while (argv[i][j] != '\0')
        {   
            while (argv[i][j] == ' ' || argv[i][j] == '\v' || argv[i][j] == '\t')
            {
                write(1, &argv[i][j], 1);
                j++;
                flag = 0;
            }

            if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') && flag == 0)
            {
                argv[i][j] -= 32;
                write(1, &argv[i][j], 1);
                flag = 1;
            }
            else if (argv[i][j] == '\0')
            {
                a = 1;
                write(1, "\n", 1);
                break ;
            }               
            else
            {
                write(1, &argv[i][j], 1);
                flag = 1;
            }
            j++;           
        }
        i++;
    }
    if (!a)
        write(1, "\n", 1);
    return (0);
}