/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-18 19:33:06 by bde-sous          #+#    #+#             */
/*   Updated: 2024/03/25 21:14:04 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	freestack(t_obj_list *stack)
{
	t_obj_list	*aux;
	int			i;

	i = 0;
	while (stack != NULL)
	{
		aux = stack;
		stack = stack->next;
		free(aux->obj);
		free(aux);
		i++;
	}
	return (i);
}

void	ft_free_objarray(t_obj *obj, int len)
{
	int	i;

	i = 0;
	if (obj == NULL)
		return ;
	while (i < len)
		free(&obj[i]);
	free(obj);
}

void	ft_free_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_free_scene(t_scene *scene)
{
	if (scene->amb != NULL)
		free(scene->amb);
	if (scene->cam != NULL)
		free(scene->cam);
	if (scene->light != NULL)
		free(scene->light);
	if (scene->temp != NULL)
		freestack(scene->temp);
	if (scene->obj != NULL)
		free(scene->obj);
}

int	ft_freedoublepointer(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
	return (1);
}
