/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:48:14 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/09 21:24:39 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*tmp;
	unsigned int	i;

	tmp = dest;
	while (*tmp)
		tmp++;
	i = 0;
	while (*src && i < nb)
	{
		*tmp = *src;
		tmp++;
		src++;
		i++;
	}
	*tmp = '\0';
	return (dest);
}
