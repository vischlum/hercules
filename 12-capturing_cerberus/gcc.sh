#!/bin/sh
gcc -Wall -Wextra -Werror proxy.c -o proxy
gcc -Wall -Wextra -Werror server.c -o server
gcc -Wall -Wextra -Werror client.c -o client
# Launch first the proxy, then the server, then the client
