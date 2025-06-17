#include <stdlib.h>
#include <stdio.h>

int count(int start, int end)
{
	int i = 1;

	while (start != end)
	{
		if (start < end)
			end--;
		else 
			end++;
		i++;
	}
	return (i);

}

int *ft_range(int start, int end)
{
	int size;
	int *arr;
	int i = 0;
	arr = malloc(sizeof(char) * count(start, end));
	while (start != end)
	{
		arr[i] = start;
		i++;
		if (start < end)
			start++;
		else 
			start--;
		i++;
	}
	arr[i] = end;
	return (arr);
}