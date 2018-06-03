#!/bin/sh

./manger &
sleep 1
kill -6 $(top -l1 | grep manger | awk '{print $1}')
# You can also use -9 or -17
rm -f *.poo

# If you open the binary with otool -Vt, you notice that:
# - Podargos is involved with the ruins process
# - Lampon creates the malloc
# - Xanthos launches "bash yes"
# - Deinos creates the poo files
# You can also use r2 -A then afl to see the functions used by manger

./assets/mymanger.py
