/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:03:26 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/06 09:23:49 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	rotate(a);
	ft_putstr("ra", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putstr("rb", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr", 1);
}

void	rra(t_list **a)
{
	rev_rotate(a);
	ft_putstr("rra", 1);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	ft_putstr("rrb", 1);
}
