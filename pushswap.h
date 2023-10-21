/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:15:47 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/09 18:32:04 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				data;
	struct s_node	*next;
}					t_node;

/*input check and management*/
char				**ft_split(char *s, char c);
int					ft_atoi(char *str);
int					checker(char c);
int					ft_strlcpy(char *dst, char *src, int d);
int					is_number(char *input);
int					isstrint(char *str);
int					checkdups(t_node *numbers);
int					indexer(t_node **numbers);
/*argument processing*/
void				oarg(char *str, t_node **head);
void				margs(char **str, t_node **head);
void				processargs(int argc, char **argv, t_node **head);
/*list utils*/
void				ft_lstadd_front(char *v, t_node **head);
t_node				*ft_lstlast(t_node *lst);
void				freelist(t_node *head);
t_node				*ft_pop(t_node **head);
void				ft_putendl_fd(char *s, int fd);
void				ft_error(void);
void				ft_lstadd_back(char *s, t_node **lst);
int					ft_issorted(t_node *n);
int					ft_stack_max(t_node *a);
/*swapping*/
void				swap(t_node **head);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
/*rotation*/
void				r(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
/*reverse rotation*/
void				rrotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
/* pushing*/
void				push(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				sorter(t_node **a, t_node **b, int i);
/*extra utils*/
int					ft_sqrt(int nb);
int					cr(t_node *stack, int index);
/*sorting*/
void				sort(t_node **a, int i);
void				sorter3(t_node **a);
void				sorter4(t_node **a, t_node **b);
void				sorter5(t_node **a, t_node **b);
#endif