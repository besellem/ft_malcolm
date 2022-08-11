/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malcolm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:24:19 by besellem          #+#    #+#             */
/*   Updated: 2022/08/11 17:08:21 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALCOLM_H
# define FT_MALCOLM_H

/*
** *****************************************************************************
**	Includes
** *****************************************************************************
*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <signal.h>

# include <libft.h>


/*
** *****************************************************************************
**	Defines
** *****************************************************************************
*/
typedef struct
{
	in_addr_t	src_ip;
	in_addr_t	dst_ip;
	char		src_mac[6];
	char		dst_mac[6];
	int			verbose;
}	t_mlclm;


/*
** *****************************************************************************
**	Prototypes
** *****************************************************************************
*/
int		mlclm_parser(int, char **, const t_parsing_opts *, t_mlclm *);


#endif
