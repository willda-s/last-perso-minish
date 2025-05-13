/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:27:01 by willda-s          #+#    #+#             */
/*   Updated: 2025/05/12 18:43:06 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t count_tab(char **str)
{
	size_t i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

int ft_echo(char **str)
{
	int i;
	int n;
	int count;

	i = 1;
	n = 0;
	count = count_tab(str);
	if (count > 1 && ft_strncmp(str[1], "-n", 2) == 0)
	{
		n = 1;
		i++;
	}
	while (str[i])
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	if (n == 0)
		printf("\n");
	return (0);
}
