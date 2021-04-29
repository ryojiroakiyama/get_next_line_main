./file_1.sh
echo from file BUFFER_SIZE=1---------------------------------------------------------------from here!
./a.out test_case/empty
./a.out test_case/single_1char
./a.out test_case/single_3char
./a.out test_case/single_2547char
./a.out test_case/multiple_1char
./a.out test_case/multiple_3char
./a.out test_case/multiple_2547char
./file_63.sh
echo from file BUFFER_SIZE=63--------------------------------------------------------------from here!
./a.out test_case/single_62char
./a.out test_case/single_63char
./a.out test_case/single_64char
./file_1024.sh
echo from file BUFFER_SIZE=1024------------------------------------------------------------from here!
./a.out test_case/empty
./a.out test_case/single_1char
./a.out test_case/single_3char
./a.out test_case/single_2547char
./a.out test_case/multiple_1char
./a.out test_case/multiple_3char
./a.out test_case/multiple_2547char
