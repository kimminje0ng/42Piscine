
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
echo "\n\033\033[32;1m"Invalid Case Test 1"\033[m"
read $a

./bsq ./testcase/invalid/test1_invalid_empty.txt | cat -e
./bsq ./testcase/invalid/test1_invalid_map.txt | cat -e
./bsq ./testcase/invalid/test1_invalid_no_colomn_line.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Invalid Case Test 2"\033[m"
read $a

./bsq ./testcase/invalid/test2_invalid_map.txt | cat -e
./bsq ./testcase/invalid/test2_invalid_map2.txt | cat -e
./bsq ./testcase/invalid/test2_invalid_map3.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Invalid Case Test 3"\033[m"
read $a

./bsq ./testcase/invalid/test3_invalid_header.txt | cat -e
./bsq ./testcase/invalid/test3_invalid_header2.txt | cat -e
./bsq ./testcase/invalid/test3_invalid_header3.txt | cat -e
./bsq ./testcase/invalid/test3_invalid_same_char.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Invalid Case Test 4"\033[m"
read $a

./bsq ./testcase/invalid/test4_invalid_height_longer.txt | cat -e
./bsq ./testcase/invalid/test4_invalid_height_shorter.txt | cat -e

echo "\n"
echo "\n\033\033[32;1m"Invalid Case Test 5"\033[m"
read $a

./bsq ./testcase/invalid/test5_invalid_width_longer.txt | cat -e
./bsq ./testcase/invalid/test5_invalid_width_shorter.txt | cat -e
