/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:20:32 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/25 18:29:54 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **a)
{
	int	i;

	i = 0;
	if (a)
	{
		while (a[i])
			free(a[i++]);
		free(a);
		a = NULL;
	}
}

void	handle_err(t_list **head, char **arr)
{
	ft_putstr("Error", 2);
	free_arr(arr);
	ft_lstclear(head);
	exit(1);
}

int	check_dup(t_list **head, int num)
{
	t_list	*p;

	p = *head;
	while (p)
	{
		if (p->n == num)
			return (0);
		p = p->next;
	}
	return (1);
}

void	isvalid(char *s, t_list **head, char **arr)
{
	long	n;
	t_list	*node;

	if (!ft_isint(s))
	{
		n = ft_atoi(s);
		if (n <= INT_MAX && n >= INT_MIN)
		{
			if (check_dup(head, n))
			{
				if (*head)
					node = ft_lstnew(n, ft_lstlast(*head)->index + 1);
				else
					node = ft_lstnew(n, 0);
				ft_lstadd_back(head, node);
			}
			else
				handle_err(head, arr);
		}
		else
			handle_err(head, arr);
	}
	else
		handle_err(head, arr);
}

void	check_space(char *s, t_list **a)
{
	int		j;
	char	**arr;

	arr = NULL;
	if (ft_strchr(s, ' '))
	{
		arr = ft_split(s, ' ');
		if (arr && *arr)
		{
			j = 0;
			while (arr[j])
				isvalid(arr[j++], a, arr);
			free_arr(arr);
		}
		else
			handle_err(a, arr);
	}
	else
		isvalid(s, a, arr);
}
