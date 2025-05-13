/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:50:33 by williamguer       #+#    #+#             */
/*   Updated: 2025/05/12 18:50:04 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_cd(char **str) // Prototypage qui sera changer par la suite. SECURE A FAIRE
{
    char *path;
    int ret;
	size_t limit;

    limit = 255;
    if (str[1] == NULL || ft_strncmp(str[1], "~", 1) == 0)
    {
        path = getenv("HOME");
        if (path == NULL)
            return (1);
    }
    else
        path = str[1];
    if (ft_strlen(path) > limit)
    {
        printf("cd: %s: File too long\n", path);
        return (1);
    }
    ret = chdir(path);
    if (ret == -1)
    {
        perror("cd");
        return (1);
    }
    return (0);
}
