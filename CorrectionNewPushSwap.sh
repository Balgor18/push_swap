# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CorrectionPushSwap.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grannou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 10:02:39 by grannou           #+#    #+#              #
#    Updated: 2021/05/18 15:22:07 by grannou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#To include a bash library:
. ~/mnt/Custom/BashColorsLibrary.sh

#average_score=0

#tput blink; echo "Norminette **/*.h"; tput sgr0; norminette **/*.h; sleep 1
tput blink; echo "\n${Yellow}Norminette **/*.h${Reset}\n"; tput sgr0; sleep 1; norminette **/*.c

tput blink; echo "\n${Yellow}Norminette **/*.c${Reset}\n"; tput sgr0; sleep 1; norminette **/*.c

echo "\n${Yellow}Checking Makefile rules make, make clean, make fclean, make re${Reset}\n"; sleep 1;
make; make clean; make fclean; make re

#echo "\n${Yellow}Checker Error Managing Tests:${Reset}"; sleep 1;
#echo "${Purple}./checker norminet${Reset}"; ./checker norminet
#echo "${Purple}./checker 42 42${Reset}"; ./checker 42 42
#echo "${Purple}./checker 987654321987654321987654321${Reset}"; ./checker 987654321987654321987654321
#echo "${Purple}./checker${Reset}"; ./checker
#echo "${Purple}./checker 23 4 16 42 15 8 + non valid instructions${Reset}"; ./checker 23 4 16 42 15 8
#echo "${Purple}./checker 23 4 16 42 15 8 + valid instructions with spaces${Reset}"; ./checker 23 4 16 42 15 8

#echo "\n${Yellow}Checker False Tests:${Reset}"; sleep 1;
#echo "${Purple}./checker 0 9 1 8 2 7 3 6 4 5 + sa pb rrr + ctrl D${Reset}"; ./checker 0 9 1 8 2 7 3 6 4 5
#echo "${Purple}./checker 0 9 1 8 2 7 3 6 4 5 with non sorting valid instruction + ctrl D${Reset}"; ./checker 0 9 1 8 2 7 3 6 4 5

#echo "\n${Yellow}Checker True Tests:${Reset}"; sleep 1;
#echo "${Purple}./checker 0 1 2 + ctrl D${Reset}"; ./checker 0 1 2
#echo "${Purple}valgrind ./checker 0 1 2${Reset}"; valgrind ./checker 0 1 2
#echo "${Purple}./checker 0 9 1 8 2 + pb ra pb ra sa ra pa pa + ctrl D${Reset}"; ./checker 0 9 1 8 2
#echo "${Purple}valgrind ./checker 0 9 1 8 2 + pb ra pb ra sa ra pa pa + ctrl D${Reset}"; valgrind ./checker 0 9 1 8 2

echo "\n${Yellow}Push swap Error Managing Tests:${Reset}"; sleep 1;
echo "${Purple}./push_swap Norminet${Reset}"; ./push_swap "Norminet"
echo "${Purple}./push_swap 42 42 ${Reset}"; ./push_swap 42 42
echo "${Purple}./push_swap 0 1 3 42 2 21474836484749${Reset}"; ./push_swap 0 1 3 42 2 21474836484749
echo "${Purple}./push_swap ${Reset}"; ./push_swap
echo "${Purple}./push_swap 0 1 2 3 4 5 6 7 8 9${Reset}"; ./push_swap 0 1 2 3 4 5 6 7 8 9

echo "\n${Yellow}Push swap Identity Tests:${Reset}"; sleep 1;
echo "${Purple}./push_swap 42${Reset}"; ./push_swap 42
echo "${Purple}./push_swap 0 1 2 3${Reset}"; ./push_swap 0 1 2 3
echo "${Purple}./push_swap 0 1 2 3 4 5 6 7 8 9${Reset}"; ./push_swap 0 1 2 3 4 5 6 7 8 9

echo "\n${Yellow}Push swap Simple Version Tests:${Reset}"
echo "\n${Yellow}valgrind ./push_swap with 3 shuffled int -> 2 instructions max:${Reset}"; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 3;
echo "\n${Yellow}Launching 10 tests of ./push_swap with 3 shuffled int -> 2 instructions max:${Reset}"; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;

echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;

echo "\n${Yellow}Push swap Simple Version Tests:${Reset}"
echo "\n${Yellow}valgrind ./push_swap with 5 shuffled int -> 12 instructions max:${Reset}"; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 3;
echo "\n${Yellow}Launching 10 tests of ./push_swap with 5 shuffled int -> 12 instructions max:${Reset}"; sleep 1
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;

echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;

echo "\n${Yellow}Push swap Intermediate Version Tests:${Reset}"
echo "\n${Yellow}valgrind ./push_swap with 100 shuffled int -> 700/900/1100/1300/1500 instructions max:${Reset}"; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_OS $ARG; ./push_swap $ARG | wc -l
echo "\n${Yellow}Launching 10 tests of ./push_swap with 100 shuffled int -> 700/900/1100/1300/1500 instructions max:${Reset}"; sleep 3;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;

echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;

echo "\n${Yellow}Push swap Advanced Version Tests:${Reset}"
echo "\n${Yellow}valgrind ./push_swap with 500 shuffled int -> 5500/7000/8500/10000/11500 instructions max:${Reset}"; sleep 1
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_OS $ARG; ./push_swap $ARG | wc -l
echo "\n${Yellow}Launching 10 tests of ./push_swap with 100 shuffled int -> 5500/7000/8500/10000/11500 instructions max:${Reset}"; sleep 3;

#average_score=0
#score=0
#ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;./push_swap $ARG | wc -l); sleep 1;
#average_score=$[$average_score+$score];
#ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l; score="$(./push_swap $ARG | wc -l)"; sleep 1;
#average_score=$[$average_score+$score];

ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG; ./push_swap $ARG | wc -l; sleep 1;


average_score=$[$average_score/2]
echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;

echo "\n${Yellow}END OF TESTS${Reset}\n"; sleep 1;
echo "\n${Yellow}Executing make fclean command and opening code in VSCode...${Reset}\n";
make fclean; sleep 1;
code .
