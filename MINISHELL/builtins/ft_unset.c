/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:44:05 by williamguer       #+#    #+#             */
/*   Updated: 2025/05/12 18:55:08 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_unset(char **str, char **env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str[1] == NULL)
        return (0);
    while (str[++i])
    {
        if (ft_strchr(str[i], '=') == NULL)
        {
            while (env[j])
            {
                if (ft_strncmp(env[j], str[i], ft_strlen(str[i])) == 0)
                    break ;
                j++;
            }
            if (env[j])
                free(env[j]);
            env[j] = NULL;
        }
    }
    return (0);
}
