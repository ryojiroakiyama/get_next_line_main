gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ../get_next_line.c ../get_next_line_utils.c main_special_cases.c cnt_mf.c
echo "-----------line == NULL-----------"
./a.out test_case/akiyama 0
echo "-----------read faile-------------"
./a.out test_case/ryojiro rf
echo "-----------malloc faile-----------"
./a.out test_case/zushi mf
rm a.out
