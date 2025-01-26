/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:33:06 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/25 08:33:34 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				n;
	size_t			index;
	size_t			rank;
	size_t			push_cost;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

int		ft_isint(char *s);
int		is_sorted(t_list *a);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *s);
void	isvalid(char *s, t_list **head, char **arr);
void	check_space(char *s, t_list **a);
void	to_top(size_t index, size_t	t, t_list **h, char s);
void	tiny_sort(t_list **h, size_t s);
void	ft_putstr(char *s, int fd);
void	increment_idx(t_list *p);
void	decrement_idx(t_list *p);
void	init_target(t_list *h);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	tiny_sort(t_list **h, size_t s);
void	sort(t_list **a, t_list **b);
void	swap(t_list **h);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **s1, t_list **s2);
void	pb(t_list **a, t_list **b);
void	pa(t_list **b, t_list **a);
void	rotate(t_list **h);
void	rev_rotate(t_list **h);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
t_list	*ft_lstnew(int n, size_t i);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_min(t_list *h);
t_list	*ft_max(t_list *h);
t_list	*find_cheapest_cost(t_list *h);
t_list	*ft_lstbefore_last(t_list *lst);
size_t	ft_strlen(const char *s);
size_t	ft_lstsize(t_list *lst);

#endif
