#!/bin/sh

gcc -c -Wall -Wextra -Werror *.c
ar r libft.a *.o 
