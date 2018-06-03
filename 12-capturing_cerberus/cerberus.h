/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cerberus.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 18:28:00 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 12:27:29 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CERBERUS_H
# define CERBERUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <pthread.h>

# define BUFFER_SIZE 512
# define SERVER_IP "127.0.0.1"
# define SERVER_PORT 4000
# define CLIENT_PORT 3000

struct	s_server_info
{
	int		client_fd;
	int		port;
	char	ip[100];
}		t_server_info;

#endif
