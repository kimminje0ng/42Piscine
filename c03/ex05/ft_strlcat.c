/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:47:10 by minjeki2          #+#    #+#             */
/*   Updated: 2022/02/10 19:15:04 by minjeki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = ft_len(dest);
	src_len = ft_len(src);
	while (*dest)
		dest++;
	i = dest_len;
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	if (dest_len > size)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
