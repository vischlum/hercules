/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   server.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <vischlum@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 10:38:21 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:05:39 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cerberus.h"

void	server_loop(int my_socket)
{
	char				buffer[BUFFER_SIZE];
	char				*answer;
	int					adress_size;
	int					client_socket;
	struct sockaddr_in	client_adress;

	adress_size = sizeof(client_adress);
	while (1)
	{
		client_socket = accept(my_socket, (struct sockaddr *)&client_adress,
				(socklen_t *)&adress_size);
		if (fork() == 0)
		{
			close(my_socket);
			read(client_socket, buffer, BUFFER_SIZE);
			if (!strcmp(buffer, "ping") || !strcmp(buffer, "Ping"))
				answer = "pong pong";
			else
				answer = "Try again";
			write(client_socket, answer, BUFFER_SIZE);
			shutdown(client_socket, 2);
			close(client_socket);
			return ;
		}
	}
}

int		main(void)
{
	int					my_socket;
	struct sockaddr_in	my_adress;

	bzero(&my_adress, sizeof(my_adress));
	my_adress.sin_family = AF_INET;
	my_adress.sin_port = htons(SERVER_PORT);
	my_adress.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((my_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error when creating socket");
		return (-1);
	}
	bind(my_socket, (struct sockaddr *)&my_adress, sizeof(my_adress));
	listen(my_socket, 5);
	server_loop(my_socket);
	shutdown(my_socket, 2);
	close(my_socket);
	return (0);
}
