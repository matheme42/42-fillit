/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strccount.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 16:02:34 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 14:36:08 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strccount(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == c)
			j++;
	return (j);
}
