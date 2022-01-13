gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c main_bonus.c
echo "==>akiyama<=="
cat test_case/akiyama
echo "==>ryojiro<=="
cat test_case/ryojiro
echo "==>zushi<=="
cat test_case/zushi
echo "----------output below------------"
./a.out test_case/akiyama test_case/ryojiro test_case/zushi
rm a.out
