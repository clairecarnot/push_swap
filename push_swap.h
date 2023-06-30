/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:11:32 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/22 17:43:30 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				pos;
	int				majorpos;
	struct s_list	*next;
}		t_list;

int			ft_check_params(char *number);
int			ft_dupl_check(t_list *a);
int			ft_order_check(t_list *a);
long int	ft_atoi(const char *nptr);
char		**ft_split(char *number, int *argc);
char		**ft_splitexec(char *number, char **d);
int			ft_nstr(char *number);
int			ft_len(char *number);
void		ft_free(char **d);
char		*ft_substr(char *number, int len);
t_list		*ft_stack_init(int argc, char **argv);
t_list		*ft_lstnew(void *content);
void		ft_lstclear(t_list **lst);
void		ft_swap(t_list *stack);
void		ft_push(t_list **stack_from, t_list **stack_to);
void		ft_rotate(t_list **stack);
void		ft_rev_rotate(t_list **stack);
void		ft_lstaddfront(t_list **lst, t_list *new);
void		swap_a(t_list *a);
void		swap_b(t_list *b);
void		swap_ab(t_list *a, t_list *b);
void		push_a(t_list **a, t_list **b);
void		push_b(t_list **b, t_list **a);
void		rotate_a(t_list **a);
void		rotate_b(t_list **b);
void		rotate_ab(t_list **a, t_list **b);
void		rev_rotate_a(t_list **a);
void		rev_rotate_b(t_list **b);
void		rev_rotate_ab(t_list **a, t_list **b);
void		ft_push_swap(t_list **a, t_list **b);
int			*tab_init(t_list *a, int *tab, int size);
int			*ft_tab_sort(int *tab, int size);
int			ft_lstsize(t_list **lst);
void		ft_sort(int *x, int *y);
int			ft_getmedian(int *tab, int size);
int			ft_getmax(int *tab, int size);
void		ft_firstpush(t_list **stack_a, t_list **b, int med_a, int max_a);
void		ft_sortloop(t_list **a, t_list **b, int max_a);
void		ft_posinit(t_list **stack_a, t_list **stack_b);
int			ft_getcost(t_list **stack_b, t_list **b, t_list **a, int max_a);
t_list		*ft_getmajor(t_list **stack_b, t_list **stack_a, int max_a);
void		ft_movea(t_list **a, t_list **cheapest_b);
void		ft_moveb(t_list **a, t_list **b, t_list **cheapest_b);
t_list		*ft_getmin(t_list **a);
void		ft_finalsort(t_list **a, t_list **b);
void		ft_three(t_list **a, int size);
void		ft_ten(t_list **a, t_list **b);
void		ft_down_to_three(t_list **a, t_list **b, t_list *min_a, int size_a);
void		ft_moveab(t_list **a, t_list **b, t_list **cheapest_b);
void		ft_mutual_rotate(t_list **a, t_list **b, t_list **cheapest_b);
void		ft_mutual_revrotate(t_list **a, t_list **b, t_list **cheapest_b);

#endif
