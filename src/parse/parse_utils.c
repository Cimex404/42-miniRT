/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:45:39 by jgraf             #+#    #+#             */
/*   Updated: 2025/03/14 17:14:04 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*	These are the parsing utils. These are used to check the number of splits
*	possible for each section of the input (123,321,52 -> 3 split values for
*	a ',' delimiter).
*/

void	free_split(char **splt)
{
	int	i;

	i = 0;
	while (splt[i])
	{
		gc_free(splt[i]);
		i ++;
	}
	gc_free(splt);
}

int	get_number_of_split_elements(char **element)
{
	int	i;

	i = 0;
	while (element[i])
		i ++;
	return (i);
}

int	get_number_of_splits(char *str, char c)
{
	int		i;
	int		nmb;

	i = 0;
	nmb = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i ++;
		if (str[i] && str[i] != c)
		{
			nmb ++;
			while (str[i] && str[i] != c)
				i ++;
		}
	}
	return (nmb);
}

char	*get_split_param(char *str, int i)
{
	char	**param;
	char	*trimmed;

	param = ft_split(str, ',');
	if (!param)
		fatal_error(ERR_MEMORY, NULL);
	trimmed = ft_strtrim(param[i], " ");
	return (trimmed);
}
