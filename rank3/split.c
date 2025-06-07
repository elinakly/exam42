/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:56:25 by eklymova          #+#    #+#             */
/*   Updated: 2025/06/07 20:41:18 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "stdio.h"
#include "stdlib.h"

char    **ft_split(char *str)
{
	int i =0;
	int k =0;
	int j =0;
	char **arr;

	arr = malloc(sizeof(char*) * 1000);
	if (!arr)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\v' || str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			j = 0;
			arr[k] = malloc(sizeof(char) * 1000);
			while (str[i] && str[i] != '\n' && str[i] != '\v' && str[i] != ' ' && str[i] != '\t')
				arr[k][j++] = str[i++];
			arr[k++][j] = '\0';
		}
	}
	arr[k] = NULL;
	return (arr);
}
int main (void)
{
	char *str = "lSYpQqxBa6rCnTVZj DTwcgbPZVM3r1fFA liD6QB9vAWeSCh Y8o37pws5UtkW9 LoTjisK ZJK0a bhUriDB vemWN9 lbvEj5roD oOp sdVSAHRF13 R1YvglnyZzukb siC XR9 MgpTZrQKeE kmDPJ2yIORB 1eSipK2YPj bvOERn 0O1uiVRYEbg4Sy7a";
	int i = 0;
	char **splity = ft_split(str);
	while (splity[i])
	{
	printf("%s\n", splity[i++]);
	}
	return 0;
}