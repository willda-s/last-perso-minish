/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:08:25 by willda-s          #+#    #+#             */
/*   Updated: 2025/05/10 16:44:23 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum s_type
{
	WORD,
	COMMANDS,
	ARGUMENT,
	REDIRECTION,
	PIPE,
	SMPL_QUOTE,
	DBL_QUOTE,
	VAR_ENV,
	CARAC_SPE
}			t_type;

typedef struct s_token
{
	char	*value;
	t_type	type;
	struct s_token	*next;
}			t_token;