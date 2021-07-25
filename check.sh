#!/bin/zsh

N=0

chmod 755 code_me.sh
if [ -f ex00/ft_strcmp.c ]
then
  STRCMP=ft_strcmp.o
  ((N=N+1))
  DEFINE_STRCMP="-D STRCMP"
  gcc -Wall -Wextra -Werror -c ex00/ft_strcmp.c -o ft_strcmp.o
fi

if [ -f ex01/ft_strncmp.c ]
then
  STRNCMP=ft_strncmp.o
  ((N=N+1))
  DEFINE_STRNCMP="-D STRNCMP"
  gcc -Wall -Wextra -Werror -c ex01/ft_strncmp.c -o ft_strncmp.o
fi

if [ -f ex02/ft_strcat.c ]
then
  STRCAT=ft_strcat.o
   ((N=N+1))
   DEFINE_STRCAT="-D STRCAT"
   gcc -Wall -Wextra -Werror -c ex02/ft_strcat.c -o ft_strcat.o
fi

if [ -f ex03/ft_strncat.c ]
then
  STRNCAT=ft_strncat.o
   ((N=N+1))
   DEFINE_STRNCAT="-D STRNCAT"
   gcc -Wall -Wextra -Werror -c ex03/ft_strncat.c -o ft_strncat.o
fi

if [ -f ex04/ft_strstr.c ]
then
  STRSTR=ft_strstr.o
   ((N=N+1))
   DEFINE_STRSTR="-D STRSTR"
   gcc -Wall -Wextra -Werror -c ex04/ft_strstr.c -o ft_strstr.o
fi

if [ -f ex05/ft_strlcat.c ]
then
  STRLCAT=ft_strlcat.o
   ((N=N+1))
   DEFINE_STRLCAT="-D STRLCAT"
   gcc -Wall -Wextra -Werror -c ex05/ft_strlcat.c -o ft_strlcat.o
fi

if test $N -eq 0
then
  echo "Please put tester's files in day_03 folder"
  exit
fi
gcc -Wall -Wextra -Werror ${DEFINE_STRCMP} ${DEFINE_STRNCMP} ${DEFINE_STRCAT} ${DEFINE_STRNCAT} ${DEFINE_STRSTR} \
${DEFINE_STRLCAT} main.c "${STRCMP}" "${STRNCMP}" "${STRCAT}" "${STRNCAT}" "${STRSTR}" "${STRLCAT}"
rm *.o
./a.out