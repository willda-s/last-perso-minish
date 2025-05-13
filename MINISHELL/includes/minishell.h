/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:06:41 by willda-s          #+#    #+#             */
/*   Updated: 2025/05/12 19:15:16 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>

//////////// TOKEN HEADER ///////////

#include "token.h"

//////////// BUILTINS ///////////////

void	ft_pwd(void);

void	ft_env(char **env);

int		ft_exit(char **str);

int		ft_echo(char **str);

int		ft_cd(char **str);

int		ft_unset(char **str, char **env);

int		ft_export(char **str, char **env);

void	exec_builtins(char **str, char **env, char *input);

///////////////// FREE ///////////////

void	free_tab(char **str);

//////////////////////////////////////

// typedef struct s_data
// {
// 	char *input; //direct dans data ?
// 	char **str; //tableau du split modifie pour les quote de input ?? ou stocker dans parsing ?
// 	t_env	*env; //structure pour l'env avec char *key && char *value ??
// 	t_parsing *parsing; //structure qui contiendra la structure token ? ou juste appelez s_token ? 
// 	s_data *next;
// }