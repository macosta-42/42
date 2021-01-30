/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macosta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 08:48:21 by macosta           #+#    #+#             */
/*   Updated: 2020/02/10 21:36:23 by macosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((src[i] != '\0') && (i <= (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (dest[j] != '\0')
	{
		j++;
	}
	return (j);
}
