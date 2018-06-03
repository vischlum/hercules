#!/bin/sh
ssh-keygen -t rsa -b 4096
ssh-copy-id -p 3022 vischlum@localhost
# Test with: ssh -p 3022 vischlum@localhost
# because VirtualBox was configured to bind local port 3022 to VM port 22
