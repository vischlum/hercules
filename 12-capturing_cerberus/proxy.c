/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proxy.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 19:00:19 by vischlum     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 14:39:50 by vischlum    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cerberus.h"

void	socket_loop(int server_fd, struct s_server_info *info)
{
	char	buffer[BUFFER_SIZE];
	int		bytes;

	bytes = 0;
	while (1)
	{
		bzero(&buffer, sizeof(buffer));
		bytes = read(info->client_fd, buffer, sizeof(buffer));
		if (bytes > 0)
		{
			write(server_fd, buffer, sizeof(buffer));
			dprintf(1, "From client: %s\n", buffer);
			fflush(stdout);
		}
		bzero(&buffer, sizeof(buffer));
		bytes = read(server_fd, buffer, sizeof(buffer));
		if (bytes > 0)
		{
			write(info->client_fd, buffer, sizeof(buffer));
			dprintf(1, "From server: %s\n", buffer);
		}
	}
}

void	run_socket(struct s_server_info *info)
{
	int						server_fd;
	struct sockaddr_in		server_sd;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		dprintf(2, "Server socket not created\n");
	dprintf(2, "Server socket created\n");
	bzero(&server_sd, sizeof(server_sd));
	server_sd.sin_family = AF_INET;
	server_sd.sin_port = htons(info->port);
	server_sd.sin_addr.s_addr = inet_addr(info->ip);
	if ((connect(server_fd, (struct sockaddr *)&server_sd, \
					sizeof(server_sd))) == -1)
		dprintf(2, "Server connection not established");
	dprintf(2, "Server socket connected\n");
	socket_loop(server_fd, info);
	return ;
}

void	proxy_ascii(void)
{
	dprintf(1, "\e[31m\e[1m\t\tWelcome to the Realm of Cerberus!\e[22m\n");
	dprintf(1, "                            /\\_/\\____,\r\n");
	dprintf(1, "                  ,___/\\_/\\ \\  ~     /\r\n");
	dprintf(1, "                  \\     ~  \\ )   XXX\r\n");
	dprintf(1, "                    XXX     /    /\\_/\\___,\r\n");
	dprintf(1, "                       \\o-o/-o-o/   ~    /\r\n");
	dprintf(1, "                        ) /     \\    XXX\r\n");
	dprintf(1, "                       _|    / \\ \\_/\r\n");
	dprintf(1, "                    ,-/   _  \\_/   \\\r\n");
	dprintf(1, "                   / (   /____,__|  )\r\n");
	dprintf(1, "                  (  |_ (    )  \\) _|\r\n");
	dprintf(1, "                 _/ _)   \\   \\__/   (_\r\n");
	dprintf(1, "         b'ger  (,-(,(,(,/      \\,),),)\r\n\e[39m");
	return ;
}

void	proxy_loop(int proxy_fd)
{
	int						client_fd;
	struct s_server_info	*item;

	client_fd = 0;
	proxy_ascii();
	while (1)
	{
		client_fd = accept(proxy_fd, (struct sockaddr*)NULL, NULL);
		if ((client_fd > 0) && (fork() == 0))
		{
			item = malloc(sizeof(struct s_server_info));
			item->client_fd = client_fd;
			item->port = SERVER_PORT;
			strcpy(item->ip, SERVER_IP);
			while (1)
				run_socket(item);
			sleep(1);
		}
	}
	return ;
}

int		main(void)
{
	int					proxy_fd;
	struct sockaddr_in	proxy_sd;

	proxy_fd = 0;
	bzero(&proxy_sd, sizeof(proxy_sd));
	proxy_sd.sin_family = AF_INET;
	proxy_sd.sin_port = htons(CLIENT_PORT);
	proxy_sd.sin_addr.s_addr = INADDR_ANY;
	if ((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		dprintf(2, "Failed to create socket");
		return (-1);
	}
	if ((bind(proxy_fd, (struct sockaddr*)&proxy_sd, sizeof(proxy_sd))) == -1)
	{
		dprintf(2, "Failed to bind socket");
		return (-1);
	}
	if ((listen(proxy_fd, SOMAXCONN)) == -1)
	{
		dprintf(2, "Failed to listen");
		return (-1);
	}
	proxy_loop(proxy_fd);
	return (0);
}
