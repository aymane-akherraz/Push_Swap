/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:54:25 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/25 09:21:32 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header_bonus.h"

void	exit_with_err(t_list **a, t_list **b, char *s)
{
	ft_putstr("Error", 2);
	free(s);
	get_next_line(0, 1);
	ft_lstclear(a);
	ft_lstclear(b);
	exit(1);
}

void	cmp_exc(char *s, t_list **a, t_list **b)
{
	if (!ft_strcmp(s, "sa\n"))
		sa(a);
	else if (!ft_strcmp(s, "sb\n"))
		sb(b);
	else if (!ft_strcmp(s, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(s, "pa\n"))
		pa(b, a);
	else if (!ft_strcmp(s, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(s, "ra\n"))
		ra(a);
	else if (!ft_strcmp(s, "rb\n"))
		rb(b);
	else if (!ft_strcmp(s, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(s, "rra\n"))
		rra(a);
	else if (!ft_strcmp(s, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(s, "rrr\n"))
		rrr(a, b);
	else
		exit_with_err(a, b, s);
	free(s);
}

void	get_ops(t_list **a, t_list **b)
{
	char	*s;

	s = get_next_line(0, 0);
	while (s)
	{
		cmp_exc(s, a, b);
		s = get_next_line(0, 0);
	}
}

void	check_order(t_list *a)
{
	while (a->next && a->n < a->next->n)
		a = a->next;
	if (a->next)
		ft_putstr("KO", 1);
	else
		ft_putstr("OK", 1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_list		*a;
	t_list		*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		while (i < argc)
			check_space(argv[i++], &a);
		get_ops(&a, &b);
		if (ft_lstsize(b))
		{
			ft_putstr("KO", 1);
			ft_lstclear(&b);
		}
		else
			check_order(a);
		ft_lstclear(&a);
	}
}
