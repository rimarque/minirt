/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:41:05 by bde-sous          #+#    #+#             */
/*   Updated: 2024-03-18 19:41:05 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	ft_put_err(char *str)
{
	ft_putstr_fd("minirt: Invalid Map\n", 2);
	printf("%s\n", str);
	return (0);
}

int	ft_stack_length(t_obj_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	add_node(char *str, t_obj_list **head)
{
	t_obj_list	*node;

	node = (t_obj_list *)malloc(sizeof(t_obj_list));
	if (node == NULL)
	{
		free(str);
		return (0);
	}
	node->obj = ft_strdup(str);
	node->next = *head;
	*head = node;
	return (1);
}

int	final_check(t_scene *scene)
{
	if (scene->amb == NULL)
		return (ft_put_err("amb") & 0);
	if (scene->cam == NULL)
		return (ft_put_err("cam") & 0);
	if (scene->light == NULL)
		return (ft_put_err("light") & 0);
	if (scene->obj == NULL)
		return (ft_put_err("obj") & 0);
	if (scene->temp == NULL)
		return (ft_put_err("lista") & 0);
	return (1);
}
