/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:58:19 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/25 09:55:43 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheapest_cost(t_list *h)
{
	t_list	*c;

	c = h;
	h = h->next;
	while (h)
	{
		if (h->push_cost < c->push_cost)
			c = h;
		h = h->next;
	}
	return (c);
}

t_list	*ft_max(t_list *h)
{
	t_list	*m;

	m = h;
	h = h->next;
	while (h)
	{
		if (h->n > m->n)
			m = h;
		h = h->next;
	}
	return (m);
}

t_list	*ft_min(t_list *h)
{
	t_list	*m;

	m = h;
	h = h->next;
	while (h)
	{
		if (h->n < m->n)
			m = h;
		h = h->next;
	}
	return (m);
}

void	tiny_sort(t_list **h, size_t s)
{
	t_list	*m;

	if (*h && s <= 3)
	{
		m = ft_max(*h);
		if (s == 3)
		{
			if (m->index == 0)
				ra(h);
			else if (m->index == 1)
				rra(h);
		}
		if ((*h)->next && (*h)->n > (*h)->next->n)
			sa(h);
	}
}

void	to_top(size_t index, size_t	t, t_list **h, char s)
{
	int	c;

	if (index > (t / 2))
	{
		c = t - index;
		while (c--)
		{
			if (s == 'b')
				rrb(h);
			else
				rra(h);
		}
	}
	else
	{
		c = index;
		while (c--)
		{
			if (s == 'b')
				rb(h);
			else
				ra(h);
		}
	}
}
