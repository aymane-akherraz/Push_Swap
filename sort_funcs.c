/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:10:21 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/25 10:42:20 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_list *p, size_t t1, size_t t2)
{
	size_t	cost_a;
	size_t	cost_b;

	if (p->index <= (t1 / 2))
		cost_b = p->index;
	else
		cost_b = t1 - p->index;
	if (p->target->index <= (t2 / 2))
		cost_a = p->target->index;
	else
		cost_a = t2 - p->target->index;
	if ((p->index <= (t1 / 2) && p->target->index <= (t2 / 2))
		|| (p->index > (t1 / 2) && p->target->index > (t2 / 2)))
	{
		if (cost_a > cost_b)
			p->push_cost = cost_a;
		else
			p->push_cost = cost_b;
	}
	else
		p->push_cost = cost_a + cost_b;
}

void	set_biggest_target(t_list *b, t_list *a, size_t tb, size_t ta)
{
	t_list	*h;

	while (b)
	{
		h = a;
		while (h)
		{
			if (h->n > b->n)
			{
				if (!(b->target))
					b->target = h;
				else if (h->n < b->target->n)
					b->target = h;
				set_cost(b, tb, ta);
			}
			h = h->next;
		}
		if (!(b->target))
		{
			b->target = ft_min(a);
			set_cost(b, tb, ta);
		}
		b = b->next;
	}
}

void	rot_both(t_list **a, t_list **b, t_list *n)
{
	size_t	ma;
	size_t	mb;

	ma = ft_lstsize(*a) / 2;
	mb = ft_lstsize(*b) / 2;
	if (n->index <= mb && n->target->index <= ma)
	{
		while (n->index && n->target->index)
			rr(a, b);
	}
	else if (n->index > mb && n->target->index > ma)
	{
		while (n->index && n->target->index)
			rrr(a, b);
	}
}

void	set_rank(t_list *a)
{
	t_list	*p;
	t_list	*p2;

	p = a;
	while (p)
	{
		p->rank = 0;
		p2 = a;
		while (p2)
		{
			if (p2->n < p->n)
				p->rank = p->rank + 1;
			p2 = p2->next;
		}
		p = p->next;
	}
}

void	sort(t_list **a, t_list **b)
{
	t_list	*n;

	set_rank(*a);
	while (ft_lstsize(*a) > 3 && is_sorted(*a))
	{
		if ((*a)->rank <= (ft_lstsize(*a) / 3))
		{
			pb(a, b);
			set_rank(*a);
		}
		else
			ra(a);
	}
	tiny_sort(a, ft_lstsize(*a));
	while (ft_lstsize(*b))
	{
		set_biggest_target(*b, *a, ft_lstsize(*b), ft_lstsize(*a));
		n = find_cheapest_cost(*b);
		rot_both(a, b, n);
		to_top(n->index, ft_lstsize(*b), b, 'b');
		to_top(n->target->index, ft_lstsize(*a), a, 'a');
		init_target(*b);
		pa(b, a);
	}
	to_top(ft_min(*a)->index, ft_lstsize(*a), a, 'a');
}
