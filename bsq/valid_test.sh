
#!/bin/bash

echo -e "\n"
echo -e "\n\033\033[32;1m"test sh : BSQ"\033[m"
echo -e "\n"

echo -e "\n\033\033[32;1m"make fclean"\033[m"
read $a
make fclean
ls
echo -e "\n"

echo -e "\n\033\033[32;1m"make clean"\033[m"
read $a
make
make clean
ls
echo -e "\n"

echo -e "\n\033\033[32;1m"make all"\033[m"
read $a
make all
ls
echo -e "\n"

echo -e "\n\033\033[32;1m"relink"\033[m"
read $a
make
echo -e "\n"

echo -e "\n\033\033[32;1m"Make DONE"\033[m"


echo "\n"
echo "\n\033\033[32;1m"Valid Case Test 1"\033[m"
read $a

./bsq ./testcase/valid/test1_valid_only_one.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test1_valid_only_one2.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Valid Case Test 2"\033[m"
read $a

./bsq ./testcase/valid/test2_valid_one_colomn.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test2_valid_one_colomn2.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test2_valid_one_colomn3.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test2_valid_one_colomn4.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Valid Case Test 3"\033[m"
read $a

./bsq ./testcase/valid/test3_valid_one_line_colomn.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test3_valid_one_line_colomn2.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test3_valid_one_line_colomn3.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test3_valid_one_line_colomn4.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test3_valid_one_line_colomn5.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test3_valid_one_line_colomn6.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Valid Case Test 4"\033[m"
read $a

./bsq ./testcase/valid/test4_valid.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test4_valid2.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test4_valid3.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test4_valid4.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test4_valid5.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test4_valid6.txt | cat -e
echo "\n"
./bsq ./testcase/valid/test4_valid7.txt | cat -e
