/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:50:07 by jebucoy           #+#    #+#             */
/*   Updated: 2023/02/21 18:44:46 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_invalid_arg(char **av)
{
	int	s;
	int	c;

	s = 1;
	c = 0;
	while (av[s])
	{
		c = 0;
		while(av[s][c])
		{
			if ((!ft_isdigit(av[s][c]) && av[s][c] != ' ' && av[s][c] != '-')
				|| (av[s][c] == '-' && !ft_isdigit(av[s][c + 1])))
			{
				ft_putendl_fd("Invalid Arguments", 2);
				exit(EXIT_FAILURE);
			}
			c++;
		}
		s++;
	}
}