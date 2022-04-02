/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:17:05 by daeidi-h          #+#    #+#             */
/*   Updated: 2022/03/28 22:27:39 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mod(float x)
{
	if (x)
		return (x);
	return (x * -1);
}

int	max(float x, float y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	min(float x, float y)
{
	if (x >= y)
		return (y);
	return (x);
}
