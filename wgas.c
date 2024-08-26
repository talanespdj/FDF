/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgas.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:31:36 by tespandj          #+#    #+#             */
/*   Updated: 2024/06/13 16:42:00 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	wgas(char *str)
{
	perror(str);
	exit(1);
}

void	wegotasplituation(struct spt x)
{
	int	i;

	i = 0;
	while (x.split[i] && i <= x.op)
	{
		free(x.split[i]);
		i++;
	}
	free(x.split);
}
