/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:24:22 by besellem          #+#    #+#             */
/*   Updated: 2022/08/11 17:04:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

#define ERROR_STR B_RED"Error: "CLR_COLOR
#define PRINT_USAGE() do { \
		ft_printf("Usage: ./%s [-v] <source ip> <source MAC address> " \
				  "<target ip> <target MAC address>\n", \
				  ft_basename(av[0]));\
	} while (0);

#define FT_MALCOLM_MAX_ARGS 6

void	print_args(const t_mlclm *mlclm)
{
	ft_printf("src_ip: %s\n", inet_ntoa(*(struct in_addr *)&mlclm->src_ip));
	ft_printf("dst_ip: %s\n", inet_ntoa(*(struct in_addr *)&mlclm->dst_ip));
	ft_printf("src_mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
		mlclm->src_mac[0], mlclm->src_mac[1], mlclm->src_mac[2],
		mlclm->src_mac[3], mlclm->src_mac[4], mlclm->src_mac[5]);
	ft_printf("dst_mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
		mlclm->dst_mac[0], mlclm->dst_mac[1], mlclm->dst_mac[2],
		mlclm->dst_mac[3], mlclm->dst_mac[4], mlclm->dst_mac[5]);
	ft_printf("verbose: %s\n", mlclm->verbose ? "true" : "false");
}

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

int		main(int ac, char **av)
{
	const t_parsing_opts	opts = parse_args(ac, av, true, "v");
	t_mlclm					mlclm = {0};

	if (mlclm_parser(ac, av, &opts, &mlclm) < 0)
	{
		PRINT_USAGE();
		return 1;
	}

	print_args(&mlclm);

	return 0;
}
