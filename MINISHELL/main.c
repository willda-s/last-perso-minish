/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:56:52 by willda-s          #+#    #+#             */
/*   Updated: 2025/05/12 17:38:27 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void free_tab(char **str)
{
	while(*str && str)
	free(*str++);
	free(*str);
}
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *input;
	char **str;
	
	while(1)
	{
		input = readline("> ");
		if (*input)
			add_history(input);
		str = ft_split(input, ' ');
		if (ft_strncmp(str[0], "env", ft_strlen(str[0])) == 0)
		ft_env(env);
		else if (ft_strncmp(str[0], "pwd", ft_strlen(str[0])) == 0)
		ft_pwd();
		else if (ft_strncmp(str[0], "exit", ft_strlen(str[0])) == 0)
		{
			errno = ft_exit(str);
			if (errno != -12)//a verifier car leak readline
			{
				free(input);
				free_tab(str);
				rl_clear_history();
				return (errno);
			}
		}
		else if (ft_strncmp(str[0], "echo", ft_strlen(str[0])) == 0)
			ft_echo(str);
		free(input);
	}
	free_tab(str);
	
}

/* pour le moment pwd marche, a revoir lorsqu'on aura le cd. Il faudra peut etre une fonction qui lancera
tous les builtins pour eviter de saccager le main. ERRNO -12 permet de ne pas exit dans la fonction ft_exit.
!!!!!!!! MAIN TEMPORAIRE !!!!!!!!! */

//EXIT EST GLOBALEMENT FONCTIONNEL, NEED GERER L'OVERFLOW/UNDERFLOW ET DEVOIR LE RESTRUCTURER PAR LA SUITE, ET TOUT FREE 
//(avec une structure, sa sera plus facile de tout free directement dans ft_exit pour exit direct dedans)!

