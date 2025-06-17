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
	char **arr;
	int i = 0;
	int j = 0;
	int k = 0;

	arr = malloc (sizeof(char *) * 1000);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n')
			i++;
		if (str[i])
		{
			k = 0;
			arr[j] = malloc (sizeof(char) * 1000);
			while (str[i] && str[i] != '\v' && str[i] != ' ')
			{
				arr[j][k++] = str[i++];
			}
			arr[j++][k] = '\0';
		}
	}
	arr[j] = NULL;
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