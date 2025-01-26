/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:27:00 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/14 23:05:30 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	swap(a);
	ft_putstr("sa", 1);
}

void	sb(t_list **b)
{
	swap(b);
	ft_putstr("sb", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss", 1);
}

void	pa(t_list **b, t_list **a)
{
	if (*b)
		push(b, a);
	ft_putstr("pa", 1);
}

void	pb(t_list **a, t_list **b)
{
	if (*a)
		push(a, b);
	ft_putstr("pb", 1);
}
