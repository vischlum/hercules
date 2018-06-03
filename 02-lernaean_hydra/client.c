/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   client.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 10:49:54 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:12:06 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

/*
 ** Initialising sockaddr_in structure
*/

int	client_init(void)
{
	struct sockaddr_in	server_sock_addr;
	int					host_addr;
	int					to_server_socket;

	bzero(&server_sock_addr, sizeof(server_sock_addr));
	host_addr = inet_addr(SERVER_IP);
	bcopy(&host_addr, &server_sock_addr.sin_addr, sizeof(host_addr));
	server_sock_addr.sin_port = htons(30000);
	server_sock_addr.sin_family = AF_INET;
	if ((to_server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Error when creating socket");
		return (-1);
	}
	if (connect(to_server_socket, (struct sockaddr *)&server_sock_addr,
				sizeof(server_sock_addr)) < 0)
	{
		perror("Error when establishing connection");
		return (-1);
	}
	return (to_server_socket);
}

int	main(int ac, char **av)
{
	int					to_server_socket;
	char				buffer[BUFFER_SIZE];

	if (ac != 2)
		puts("Usage: ./client <message>");
	else
	{
		to_server_socket = client_init();
		if (to_server_socket != -1)
		{
			write(to_server_socket, av[1], strlen(av[1]));
			read(to_server_socket, buffer, BUFFER_SIZE);
			puts(buffer);
		}
		shutdown(to_server_socket, 2);
		close(to_server_socket);
	}
	return (0);
}
