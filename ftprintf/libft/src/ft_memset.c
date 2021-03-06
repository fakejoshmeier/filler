/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:17:58 by jmeier            #+#    #+#             */
/*   Updated: 2017/09/24 22:33:07 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	t;
	char	*ptr;

	ptr = s;
	t = 0;
	while (t < n)
		*(ptr + t++) = c;
	return (s);
}
