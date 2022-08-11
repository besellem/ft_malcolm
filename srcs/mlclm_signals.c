/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlclm_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:22:49 by besellem          #+#    #+#             */
/*   Updated: 2022/08/11 17:27:15 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

// TODO: clean up
void	mlclm_sigint_handler(__unused int sig)
{
	ft_printf("\nexit\n");
	exit(0);
}
