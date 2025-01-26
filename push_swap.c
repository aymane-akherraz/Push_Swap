/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:33:15 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/24 16:13:40 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	while (a->next && a->n < a->next->n)
		a = a->next;
	if (a->next)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	size_t		s;
	t_list		*a;
	t_list		*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		while (i < argc)
			check_space(argv[i++], &a);
		s = ft_lstsize(a);
		if (s > 1 && is_sorted(a))
		{
			if (s <= 3)
				tiny_sort(&a, s);
			else
				sort(&a, &b);
		}
		ft_lstclear(&a);
	}
}
