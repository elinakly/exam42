#include <stdlib.h>
#include <stdio.h>

int count(int start, int end)
{
    int count = 1;
    while (start != end)
    {
        count++;
        if (start < end)
            start++;
        else
            start--;
    }
    return (count);
}

int *ft_range(int start, int end)
{
    int size = count(start, end);
    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        return (0);
    int i = 0;
    while (start != end)
    {
        arr[i] = start;
        i++;
        if (start < end)
            start++;
        else
            start--;
    }
    arr[i] = end;
    return (arr);
}