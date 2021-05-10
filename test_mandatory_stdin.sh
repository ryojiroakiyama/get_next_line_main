gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main_mandatory_stdin.c
echo "BUF=1"
./ex_ex_stdin.sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 ../get_next_line.c ../get_next_line_utils.c main_mandatory_stdin.c
echo "BUF=5"
./ex_ex_stdin.sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=63 ../get_next_line.c ../get_next_line_utils.c main_mandatory_stdin.c
echo "BUF=63"
./ex_ex_stdin.sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1030 ../get_next_line.c ../get_next_line_utils.c main_mandatory_stdin.c
echo "BUF=1030"
./ex_ex_stdin.sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 ../get_next_line.c ../get_next_line_utils.c main_mandatory_stdin.c
echo "BUF=9999"
./ex_ex_stdin.sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1000000 ../get_next_line.c ../get_next_line_utils.c main_mandatory_stdin.c
echo "BUF=1000000"
./ex_ex_stdin.sh
rm result a.out

