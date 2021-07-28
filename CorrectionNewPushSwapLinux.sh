# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CorrectionNewPushSwapLinux.sh                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grannou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 07:05:36 by grannou           #+#    #+#              #
#    Updated: 2021/07/15 21:46:25 by grannou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#To include a bash library:
#. ./BashColorsLibrary.sh

Reset="\033[0m"
Red="\033[1;49;31m"
Green="\033[1;49;32m"
Yellow="\033[1;49;33m"
Blue="\033[1;49;34m"
Purple="\033[1;49;35m"
Cyan="\033[1;49;36m"

#average_score=0

#tput blink; echo "Norminette **/*.h"; tput sgr0; norminette **/*.h; sleep 1
tput blink; echo "\n${Yellow}Norminette **/*.h${Reset}\n"; tput sgr0; sleep 1; norminette **/*.c

tput blink; echo "\n${Yellow}Norminette **/*.c${Reset}\n"; tput sgr0; sleep 1; norminette **/*.c

echo "\n*******************************************\n"
tput blink; echo "\n${Yellow}Checking Makefile rules make, make clean, make fclean, make re${Reset}\n"; sleep 3;
echo "\n*******************************************\n"
make; make clean; make fclean; make re


tput blink; echo "\n${Yellow}Checker Error Managing Tests:${Reset}"; sleep 1;
echo "${Purple}./checker_linux norminet${Reset}"; ./checker_linux norminet
echo "${Purple}./checker_linux 42 42${Reset}"; ./checker_linux 42 42
echo "${Purple}./checker_linux 987654321987654321987654321${Reset}"; ./checker_linux 987654321987654321987654321
echo "${Purple}./checker_linux${Reset}"; ./checker_linux
# Check error
<<comment
#echo "${Purple}./checker_linux 23 4 16 42 15 8 + non valid instructions${Reset}"; ./checker_linux 23 4 16 42 15 8
#echo "${Purple}./checker_linux 23 4 16 42 15 8 + valid instructions with spaces${Reset}"; ./checker_linux 23 4 16 42 15 8

tput blink; echo "\n${Yellow}Checker False Tests:${Reset}"; sleep 1;
echo "${Purple}./checker_linux 0 9 1 8 2 7 3 6 4 5 + sa pb rrr + ctrl D${Reset}"; ./checker_linux 0 9 1 8 2 7 3 6 4 5
echo "${Purple}./checker_linux 0 9 1 8 2 7 3 6 4 5 with non sorting valid instruction + ctrl D${Reset}"; ./checker_linux 0 9 1 8 2 7 3 6 4 5

tput blink; echo "\n${Yellow}Checker True Tests:${Reset}"; sleep 1;
echo "${Purple}./checker_linux 0 1 2 + ctrl D${Reset}"; ./checker_linux 0 1 2
echo "${Purple}valgrind ./checker_linux 0 1 2${Reset}"; valgrind ./checker_linux 0 1 2
echo "${Purple}./checker_linux 0 9 1 8 2 + pb ra pb ra sa ra pa pa + ctrl D${Reset}"; ./checker_linux 0 9 1 8 2
echo "${Purple}valgrind ./checker_linux 0 9 1 8 2 + pb ra pb ra sa ra pa pa + ctrl D${Reset}"; valgrind ./checker_linux 0 9 1 8 2

comment

echo "\n${Green}Push swap Error Managing Tests:${Reset}"; sleep 3;
echo "${Purple}./push_swap ${Reset}"; ./push_swap
echo "${Purple}./push_swap Norminet${Reset}"; ./push_swap "Norminet"
echo "${Purple}./push_swap 42 42 ${Reset}"; ./push_swap 42 42
echo "${Purple}./push_swap 0 1 3 42 2 21474836484749${Reset}"; ./push_swap 0 1 3 42 2 21474836484749
echo "${Purple}./push_swap 0 1 3 42 2 2147483648474933333333333333${Reset}"; ./push_swap 0 1 3 42 2 21474836484749333333333333333
echo "${Purple}./push_swap \"\" 3 2 1${Reset}"; ./push_swap "" 3 2 1
echo "${Purple}./push_swap \"\" 2${Reset}"; ./push_swap "" 2
echo "${Purple}./push_swap \"1\" 1 2 3 2${Reset}"; ./push_swap "1" 1 2 3 2
echo "${Purple}./push_swap \" 1\" 2 3 2${Reset}"; ./push_swap " 1" 2 3 2
echo "${Purple}./push_swap 42 \"       43\" 2${Reset}"; ./push_swap 42 "       43" 2
echo "${Purple}./push_swap 0 1 2 3 \"--1\" 2 ${Reset}"; ./push_swap 0 1 2 3 "--1" 2
echo "${Purple}./push_swap 0 1 2 3 \"&\" 2${Reset}"; ./push_swap 0 1 2 3 "&" 2
echo "${Purple}./push_swap 0 1 2 3 -5 2${Reset}"; ./push_swap 0 1 2 3 -5 2
sleep 3;
echo "\n${Green}Push swap Identity Tests:${Reset}"; sleep 3;
echo "${Purple}./push_swap 42${Reset}"; ./push_swap 42
echo "${Purple}./push_swap 0 1 2 3${Reset}"; ./push_swap 0 1 2 3
echo "${Purple}./push_swap 0 1 2 3 4 5 6 7 8 9${Reset}"; ./push_swap 0 1 2 3 4 5 6 7 8 9
sleep 3;


echo "\n${White}-----------------------------------------------------${Reset}"
<<start

./push_swap 5 8 4 2 | ./checker_linux 5 8 4 2 > diff.txt # ./push_swap 5 8 4 2 | wc -l; sleep 1;

result=$(cat diff.txt)
if [ "$result" = "Error\n" ]; then echo "${Red}"; else echo "${Green}";
fi
echo "$result"
start

echo "\n${White}-----------------------------------------------------${Reset}"
echo "\n${Green}Push swap Simple Version Tests:${Reset}"
echo "\n${Green}valgrind ./push_swap with 3 shuffled int -> 2 instructions max:${Reset}"; sleep 3;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 3;
echo "\n${Green}Launching 10 tests of ./push_swap with 3 shuffled int -> 2 instructions max:${Reset}"; sleep 1;

ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
echo "\n${Green}********** SPECIAL TESTS **********${Reset}"; sleep 3;
ARG=`ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (-3..-1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG="42 -42 0";./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG1="42"; ARG2="-42"; ARG3="0";./push_swap $ARG1 $ARG2 $ARG3 | ./checker_linux $ARG1 $ARG2 $ARG3; ./push_swap $ARG1 $ARG2 $ARG3 | wc -l; sleep 1;


echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;





echo "\n${White}-----------------------------------------------------${Reset}"

echo "\n${Green}Push swap Simple Version Tests:${Reset}"
echo "\n${Green}valgrind ./push_swap with 5 shuffled int -> 12 instructions max:${Reset}"; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 3;
echo "\n${Green}Launching 10 tests of ./push_swap with 5 shuffled int -> 12 instructions max:${Reset}"; sleep 1
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
echo "\n${Green}********** SPECIAL TESTS **********${Reset}"; sleep 3;
ARG=`ruby -e "puts (-3..1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (-42..-38).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG="42 -42 0 -77 1024"  ;./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG1="42"; ARG2="-42"; ARG3="0"; ARG4="-77"; ARG5="1024";./push_swap $ARG1 $ARG2 $ARG3 $ARG4 $ARG5 | ./checker_linux $ARG1 $ARG2 $ARG3 $ARG4 $ARG5; \
./push_swap $ARG1 $ARG2 $ARG3 $ARG4 $ARG5 | wc -l; sleep 1;
ARG1="42 -42 0"; ARG2="-77 1024";./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG1="42 -42 0 -77"; ARG2="1024";./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;

echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;




echo "\n${White}-----------------------------------------------------${Reset}"

echo "\n${Green}Push swap Intermediate Version Tests:${Reset}"
echo "\n${Green}valgrind ./push_swap with 100 shuffled int -> 700/900/1100/1300/1500 instructions max:${Reset}"; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_linux $ARG; ./push_swap $ARG | wc -l
echo "\n${Green}Launching 10 tests of ./push_swap with 100 shuffled int -> 700/900/1100/1300/1500 instructions max:${Reset}"; sleep 3;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
echo "\n${Green}********** SPECIAL TESTS **********${Reset}"; sleep 3;
ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (-100..-1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG="-898559283 187816814 1763325167 1911345874 804820950 1164757943 -2015837126 491402873 -984990861 1698369042 740047574 1438792766 \
2035181278 1233881184 654679430 700333770 -954808175 -371907914 422750862 1047685161 -1853665794 381613618 696014203 -171794500 923525871 \
1916599021 -487358480 -1373924260 1717014587 -425006489 -216971393 -21893449 -1842695526 966298136 -1963016564 -40722413 -708105870 \
1395364134 -290065351 391996401 932775339 1234011948 88542239 1728966373 -591169059 -1009202914 -1763581457 -1098940445 897473171 \
-775489578 2129637307 1225988991 2083024994 -463979690 435061488 -2044628035 106031346 -861283800 -1913813295 -683806169 -244072787 \
-357662830 -995808477 1562759707 -639143802 1625444214 -1187044798 -1200287723 1451428023 -679476022 1620788919 -1031438617 -1712939605 \
452065618 -273244022 -600712954 481984486 -1787205872 -1945064612 -989190136 -313628414 -311958266 1325804489 371424841 1710639901 \
-1475727946 -1046714436 -2026146829 -123588241 -143036366 -1600542880 1981617352 -1976466093 -718989263 -956169582 513381265 1750972164 \
-401386283 1926437540 1706760344"; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;


echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;





echo "\n${White}-----------------------------------------------------${Reset}"

echo "\n${Green}Push swap Advanced Version Tests:${Reset}"
echo "\n${Green}valgrind ./push_swap with 500 shuffled int -> 5500/7000/8500/10000/11500 instructions max:${Reset}"; sleep 1
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; valgrind ./push_swap $ARG | valgrind ./checker_linux $ARG; ./push_swap $ARG | wc -l
echo "\n${Green}Launching 10 tests of ./push_swap with 100 shuffled int -> 5500/7000/8500/10000/11500 instructions max:${Reset}"; sleep 3;

#average_score=0
#score=0
#ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l;./push_swap $ARG | wc -l); sleep 1;
#average_score=$[$average_score+$score];
#ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l; score="$(./push_swap $ARG | wc -l)"; sleep 1;
#average_score=$[$average_score+$score];

ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
echo "\n${Green}********** SPECIAL TESTS **********${Reset}"; sleep 3;
ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG=`ruby -e "puts (-500..-1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;
ARG="-1647471579 482476212 178696205 -298634703 1197299293 1482701235 -434045584 1643339086 433087115 -973392669 -497560884 1378317748 \
-55401157 1892477501 156216281 607086697 1836877585 -1960928772 877201017 -1446510214 1553096786 1426912165 1374220049 2141747136 \
-2014645987 62425016 -531181764 -1064240897 -990508877 -1596954515 -477466802 -1105424460 -1342289476 2036273982 299402949 -1970721534 \
828725915 -1843131454 1278623989 -1674466990 389373283 857288186 -306661920 -486728745 -1784191079 -1327452736 808870995 -1554947322 \
-1859827099 1595147666 -1979848518 -821313075 -857628956 94407931 -1151749208 -1452080883 1352075913 1871931826 2103384413 -1843939772 \
-1495498325 -263646074 1201779117 -919275052 654259435 420255928 715272905 -795576069 -1562818525 1186588405 899712457 1505510161 \
322854872 1551294886 1612885472 615944696 1676332246 -1755773100 -830859009 -163160250 147645244 -445950238 -958675385 -1174912216 \
-206747486 -92899187 -1229620026 -1173790804 -987566634 -443939924 1255791284 100489842 383655289 1617497452 -1250120532 -175145787 \
605736071 -720055711 -1552759366 -659573848 -383716871 -1917772020 89910534 -1471830390 199695761 1092828412 -1752660313 37252515 \
619896754 1498953288 320100335 -253249071 -1972781995 -598953716 413396131 -1213586385 -1145072479 -572427278 76904097 -354050775 \
560187973 1584237711 -445561113 1884775123 383192705 -455575789 -890639021 -242902093 981996887 277149190 1722729145 1680553291 \
-751443360 1980401499 1492392133 793264204 -127968531 -1916262455 599188696 -1995653677 2016724493 1313601103 1857534615 1021292526 \
-380265487 2008177180 920777135 30665599 1553898732 645057091 895924494 -1272664240 892691771 -1351588555 387638219 -1275613687 \
-1976327454 -799686807 1278313889 -85778476 751630597 -1534567701 -139930840 -969861067 1321002602 -929254689 -108974639 -1708301797 \
798717850 -1728856164 1306191263 395374847 1426479031 -1389317542 -1315524609 423086581 62560217 -140138652 -1066049555 -990189676 \
1556678669 -1755032756 1265659279 -1889290701 1316628709 807471494 -1938564048 185247070 1866573053 -217054149 -659094948 1288434910 \
-589945504 -848821978 -655294629 1815705661 -1599587197 2104135713 -968183511 -236464603 -188393528 -280047461 800117211 1250816804 \
-624469343 1718677376 -1541059065 -1140483503 132219195 -446664681 1806365961 260816836 -1303084189 25390657 1838742054 -1494577481 \
-79263650 -556050088 744995963 -1558045028 -1588384799 2126332967 1517886683 -1743971696 -1987695926 -938402165 -1212203661 -93574549 \
-273349282 1263111808 -868411909 -1315961460 802615908 1975727972 1390074897 1407009965 67111729 91651312 -1974543644 1162816401 \
 1899992679 -1973446276 -125145783 810151370 -1022158302 -194412505 -407759646 205546850 -228190092 1766717699 -1721105622 -1598027952 \
 849062679 -1166612097 -1507018093 929075583 -2125868064 -1480702242 -1367513952 1539360270 -2110660146 2108949971 938679769 1072564424 \
 1138755916 253592019 -413739686 -953113214 -510985799 101141659 2021524209 1049011458 -559196275 1127371260 -197078714 990233177 \
 75231024 148879111 637377150 1586546919 -550710651 1632582040 -300007347 -915343868 -261012066 958940033 -1787638553 1545886312 \
 1087162621 -998444038 147032536 2140063886 999018662 -28775123 2047718860 -1235022337 766919222 -386749500 -1272977075 -198826024 \
 382621207 1141318802 1167829772 1037776653 -2092866295 1893331693 -1098847210 -269420528 -1956214354 546052610 -925572027 -1899739891 \
 1409889518 -1234341963 -1151367657 -1803478063 -1310549945 993252357 -634580813 -1301057440 -1281594792 -707533836 -589747682 \
 -2121617431 -1769201229 -1596719818 -8126343 -1092732570 695891430 2119174754 358388410 -599746328 -22756279 -428895741 653016617 \
 679319652 -482922720 -161091431 1737622157 7305559 -631844346 -1833343139 1712121433 1116875090 589406417 -864734465 83672744 \
 1655262072 -605501339 2010842488 -1990790397 -83341489 1384413548 -213249601 1217698316 -875646487 773943725 839858042 -811679978 \
 54042844 955604283 455291190 -1494004797 1775706018 365481777 1516577989 623922903 1390122543 -1973843609 -582038145 1885061275 \
 355206320 -1246749898 844113109 -364034506 2095421095 -1515134419 -406394010 -1826129879 1816011627 1016152990 -1504367692 216176355 \
 -901351725 -1874772188 2057376997 -581822134 87340418 1566488594 1009813221 852266333 -1211693379 -1631463119 2070017129 856116876 \
 1721394312 -336386773 -1934747742 -1158575392 546525234 -819801327 -66563293 197143681 -1927774583 191908011 1837492713 918471012 \
 449326207 -821392917 -877524365 -467149337 1262039881 -1152068950 -1591549711 -205728357 1454756351 332993248 126644066 -701950406 \
 598211018 -1381051690 179772697 295022165 722555959 -1129930538 1220914797 1472973736 -335493594 1885187517 1301657743 -1147247302 \
 1008827690 1723557852 464373827 -531702494 682988082 2076282569 652336429 1249090706 -247305134 873977105 -2103895294 -1399049014 \
 -1569292727 -1861323274 642658487 498238458 -1487238272 404640295 -1582283810 -1122803047 -2038681378 -420482281 2095781743 \
 -1472761308 1694361244 2080060365 1010490367 2083509641 -696103952 416716563 1197151180 -1446304692 -475806597 -63753918 2117654589 \
 -965397837 2086110343 811467544 1269940437 373966200 1719804776 1998181421 -1271138751 -1507351305 1080954953 774321011 -1046213471 \
 100700402 453822438 -776369503 -23548169 -1424428053 -1954586013 1782755289 5898235 -1275632445 -244036039 969048046 644617833 \
 685962315 1300919777 1562976174 808919890 1412068494 -252794720 1153441846 -1983303317 2051412124 -1060938535"; \
 ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l; sleep 1;

average_score=$[$average_score/2]
echo "\n${Green}Average_score = ${Reset}$average_score\n"; sleep 1;

echo "\n${Green}END OF TESTS${Reset}\n"; sleep 1;
echo "\n${Yellow}Executing make fclean command and opening code in VSCode...${Reset}\n";

make fclean; sleep 1;


code .
