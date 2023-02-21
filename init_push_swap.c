/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:22:25 by jebucoy           #+#    #+#             */
/*   Updated: 2023/02/21 16:47:20 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creates ONE node for each num
static t_stack	*create_new_node(char *nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = ft_atoi(nbr);
	new->next = NULL;
	return (new);
}

//returns the first node/ sets the value for the next nodes
static t_stack	*init_stack_a(char **nbrs)
{
	int		i;
	t_stack	*current;
	t_stack	*head;

	i = 1;
	current = create_new_node(nbrs[i]);
	head = current;
	while (nbrs[++i])
	{
		current->next = create_new_node(nbrs[i]);
		current = current->next;
	}
	return (head);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

//initialize the structures
t_data	*init_struct(char **nbrs)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = init_stack_a(nbrs);
	data->head_a = data->a;
	data->b = NULL;
	data->head_b = NULL;
	return (data);
}
