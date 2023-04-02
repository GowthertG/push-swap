/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhaddouc <hhaddouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:52:30 by hhaddouc          #+#    #+#             */
/*   Updated: 2022/06/25 05:32:57 by hhaddouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EXIST 7
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	size;
	int	chunk;
	int	range[2];
	int	mid_chunk;
	int	chunk_index[2];
	int	chunk_size;
	int	index;
	int	insorted;
}	t_data;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

////////////////utils\\\\\\\\\\\\\\\/
t_list	*fill_stack(char **arv);
void	check_stack(char **arv);
void	check_duplicate(char **av);
int		is_sorted(t_list *stack);
void	fill_array(char	**av, int *array);
void	bubble_sort(int *array, int size);
int		*sort_array(char	**av, int ac);
void	error(void);

/////////////small_sorting\\\\\\\\\\\/
int		smaller_index(t_list *a);
void	small_sort(t_list **a, t_list **b);
void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_fifteen(t_list **stack_a, t_list **stack_b);
int		index_hunter(t_list *stack, char *target);

//////////////instructions\\\\\\\\\\\/
void	ss(t_list **a, t_list **b);
void	push(t_list **donator, t_list **receiver, char instruction);
void	swap(t_list *a, char instruction);
void	rotate(t_list **stack, char instruction);
void	rr(t_list **a, t_list **b);
void	rrotate(t_list **stack, char instruction);
void	rrr(t_list **a, t_list **b);

//////////////big_sorting\\\\\\\\\\/
void	big_sort(t_list **stack_a, t_list **stack_b, t_data *chunk, int	*array);
void	get_chunk(t_list **stack_a, t_list **stack_b, t_data *chunk);
void	push_chunk(t_data *chunk, int *array,
			t_list **stack_a, t_list **stack_b);
void	sub_sort(t_list **stack_a, t_list **stack_b,
			int *array, t_data *chunk);
void	init_data(t_list **stack_a, t_data *chunk);
int		catch_number(int content, int *array, t_data *chunk);
void	get_range(t_data *chunk);
int		exist(int bigger, t_list **stack_a);
void	sort_chunks(t_list **stack_a,
			t_list **stack_b, int *array, t_data *chunk);

/////////////////libft\\\\\\\\\\\\\\\\\/
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
void	check_mn(unsigned long value, int sign);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list	**lst, t_list *new);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

#endif