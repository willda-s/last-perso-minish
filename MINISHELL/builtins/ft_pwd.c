/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:54:49 by willda-s          #+#    #+#             */
/*   Updated: 2025/05/12 18:55:15 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_pwd(void) //Pour le moment prototyper en void(void) <------- Surement a changer !
{
	char *buff = getcwd(NULL, 0);
	if (buff == NULL)
		perror("pwd");
	printf("%s\n", buff);
	free (buff);
}

//marche mais la remonter d'erreur n'est pas faite !
//pwd marche meme si env est vide. il faudra stocker le pwd dans une variable d'environnement.