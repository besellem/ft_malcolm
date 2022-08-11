/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:24:22 by besellem          #+#    #+#             */
/*   Updated: 2022/08/11 17:22:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malcolm.h"

// TODO: to remove
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

int		main(int ac, char **av)
{
	const t_parsing_opts	opts = parse_args(ac, av, true, "v");
	t_mlclm					mlclm = {0};

	if (mlclm_parser(ac, av, &opts, &mlclm) < 0)
	{
		ft_printf("Usage: ./%s [-v] <source ip> <source MAC address> "
				  "<target ip> <target MAC address>\n",
				  ft_basename(av[0]));
		return 1;
	}
	
	print_args(&mlclm);

	signal(SIGINT, &mlclm_sigint_handler);

	while (1);

	return 0;
}
