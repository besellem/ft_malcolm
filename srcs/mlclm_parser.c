/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlclm_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:06:14 by besellem          #+#    #+#             */
/*   Updated: 2022/08/11 17:09:06 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

#define ERROR_STR B_RED"Error: "CLR_COLOR

int		mlclm_parser(int ac, char **av, const t_parsing_opts *opts, t_mlclm *mlclm)
{
	// check number of mandatory arguments
	if ((ac - opts->end_pos) != 4)
	{
		ft_printf(ERROR_STR "invalid number of arguments\n");
		return -1;
	}
	
	// an illegal option has been found
	if (option_set(opts->opts, OPT_ILLEGAL))
	{
		ft_printf(ERROR_STR "illegal option -- %c\n",
			find_option_symbol(opts->opts ^ OPT_ILLEGAL));
		return -1;
	}

	mlclm->src_ip = inet_addr(av[opts->end_pos]);
	if (INADDR_NONE == mlclm->src_ip)
	{
		ft_printf(ERROR_STR "invalid source ip -- %s\n",
			av[opts->end_pos]);
		return -1;
	}
	
	mlclm->dst_ip = inet_addr(av[opts->end_pos + 2]);
	if (INADDR_NONE == mlclm->dst_ip)
	{
		ft_printf(ERROR_STR "invalid destination ip -- %s\n",
			av[opts->end_pos + 2]);
		return -1;
	}
	
	mlclm->verbose = option_set(opts->opts, OPT_V_MIN);

	return 0;
}
