/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   <qcoudeyr@student.42perpignan.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:39:17 by qcoudeyr          #+#    #+#             */
/*   Updated: 2023/02/23 13:20:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int main(void /* int argc, char *argv */)
{

	if (get_next_line(42) != NULL && get_next_line(424422) != NULL)
		ft_putstr_fd("FAIL TO RETURN NULL ON BAD FD SET\n", 1);
	else
		ft_putstr_fd("SUCCES TO RETURN NULL ON BAD FD SET\n", 1);
		
		
	
	return (0);
}