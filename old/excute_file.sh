echo "<$1>"
./a.out test_case/$1 > result
diff result test_case/$1

