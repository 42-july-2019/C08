/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:15:48 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/19 16:03:23 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					set_el(t_stock_str *element, char *str)
{
	int		i;
	int		size;
	char	*copy;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	if (!(copy = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	element->size = size;
	element->str = str;
	element->copy = copy;
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;
	t_stock_str	curr_el;

	i = 0;
	if (!(array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	curr_el.str = 0;
	array[ac] = curr_el;
	while (i < ac)
	{
		if (!(set_el(&curr_el, av[i])))
			return (0);
		array[i] = curr_el;
		i++;
	}
	return (array);
}
