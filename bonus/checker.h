/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:20:07 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/23 20:20:08 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

t_list	*fill_stack(char **arv);
void	check_stack(char **arv);
void	check_duplicate(char **av);
int		is_sorted(t_list *stack);
void	call_operation(char *operation, t_list **a, t_list **b);
int		is_sorted(t_list *stack);
void	fifteen(void);
void	check_duplicate(char **av);
void	check_stack(char **av);

int		ft_strcmp(char *s1, char *s2);

void	ss(t_list **a, t_list **b);
void	push(t_list **donator, t_list **receiver);
void	swap(t_list *a);
void	rotate(t_list **stack);
void	rr(t_list **a, t_list **b);
void	rrotate(t_list **stack);
void	rrr(t_list **a, t_list **b);

int		ft_strcmp(char *s1, char *s2);
void	error(void);
int		ft_atoi(const char *str);
void	check_mn(unsigned long value, int sign);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list	**lst, t_list *new);
int		ft_isdigit(int c);

#endif