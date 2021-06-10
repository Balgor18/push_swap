./push_swap 1 2 3 4 5 | wc -l
./push_swap 1 2 3 5 4 | wc -l
./push_swap 1 2 4 3 5 | wc -l
./push_swap 1 2 4 5 3 | wc -l
./push_swap 1 2 5 3 4 | wc -l
./push_swap 1 2 5 4 3 | wc -l
./push_swap 1 3 2 4 5 | wc -l


./push_swap 1 3 2 5 4 #| wc -l
./push_swap 1 3 4 2 5 #| wc -l
./push_swap 1 3 4 5 2 #| wc -l
./push_swap 1 3 5 2 4 #| wc -l
./push_swap 1 3 5 4 2 #| wc -l

# ^^^^^^^^^^^^^^^^^^^^
#         WORK


# MOYENNE DE 12 sur tout les tests voir si il passe
# TO MUCH VERIF
#./push_swap 1 4 2 3 5
./push_swap 1 4 2 3 5 | wc -l
#echo "------------------"
#./push_swap 1 4 2 5 3
./push_swap 1 4 2 5 3 | wc -l
#echo "------------------"
#./push_swap 1 4 3 2 5
./push_swap 1 4 3 2 5 | wc -l
#echo "------------------"
#./push_swap 1 4 3 5 2
./push_swap 1 4 3 5 2 | wc -l
#echo "------------------"
#./push_swap 1 4 5 2 3
./push_swap 1 4 5 2 3 | wc -l
#echo "------------------"
#./push_swap 1 4 5 3 2
./push_swap 1 4 5 3 2 | wc -l


./push_swap 1 5 2 3 4 | wc -l
./push_swap 1 5 2 4 3 | wc -l
./push_swap 1 5 3 2 4 | wc -l
./push_swap 1 5 3 4 2 | wc -l
./push_swap 1 5 4 2 3 | wc -l
./push_swap 1 5 4 3 2 | wc -l


# ------ end verif check after

# ------ moyenne de ~ 6 ~ 7
./push_swap 2 1 3 4 5 | wc -l
./push_swap 2 1 3 5 4 | wc -l
./push_swap 2 1 4 3 5 | wc -l
./push_swap 2 1 4 5 3 | wc -l
./push_swap 2 1 5 3 4 | wc -l
./push_swap 2 1 5 4 3 | wc -l


# MOYENNE DE 12 sur tout les tests voir si il passe
./push_swap 2 3 1 4 5 | wc -l
./push_swap 2 3 1 5 4 | wc -l
./push_swap 2 3 4 1 5 | wc -l
./push_swap 2 3 4 5 1 | wc -l
./push_swap 2 3 5 1 4 | wc -l
./push_swap 2 3 5 4 1 | wc -l

./push_swap 2 3 1 4 5 | wc -l
./push_swap 2 3 1 5 4 | wc -l
./push_swap 2 3 4 1 5 | wc -l
./push_swap 2 3 4 5 1 | wc -l
./push_swap 2 3 5 1 4 | wc -l
./push_swap 2 3 5 4 1 | wc -l


# je depasse mais sinon tj moyenne de 12 13
./push_swap 2 4 1 3 5 | wc -l
./push_swap 2 4 1 5 3 | wc -l
./push_swap 2 4 3 1 5 | wc -l
./push_swap 2 4 3 5 1 | wc -l
./push_swap 2 4 5 1 3 | wc -l
./push_swap 2 4 5 3 1 | wc -l


#!/bin/bash
echo before comment
: <<'END'
bla bla
blurfl

./push_swap 2 5 1 3 4
./push_swap 2 5 1 4 3
./push_swap 2 5 3 1 4
./push_swap 2 5 3 4 1
./push_swap 2 5 4 1 3
./push_swap 2 5 4 3 1
./push_swap 3 1 2 4 5
./push_swap 3 1 2 5 4
./push_swap 3 1 4 2 5
./push_swap 3 1 4 5 2
./push_swap 3 1 5 2 4
./push_swap 3 1 5 4 2
./push_swap 3 2 1 4 5
./push_swap 3 2 1 5 4
./push_swap 3 2 4 1 5
./push_swap 3 2 4 5 1
./push_swap 3 2 5 1 4
./push_swap 3 2 5 4 1
./push_swap 3 4 1 2 5
./push_swap 3 4 1 5 2
./push_swap 3 4 2 1 5
./push_swap 3 4 2 5 1
./push_swap 3 4 5 1 2
./push_swap 3 4 5 2 1
./push_swap 3 5 1 2 4
./push_swap 3 5 1 4 2
./push_swap 3 5 2 1 4
./push_swap 3 5 2 4 1
./push_swap 3 5 4 1 2
./push_swap 3 5 4 2 1
./push_swap 4 1 2 3 5
./push_swap 4 1 2 5 3
./push_swap 4 1 3 2 5
./push_swap 4 1 3 5 2
./push_swap 4 1 5 2 3
./push_swap 4 1 5 3 2
./push_swap 4 2 1 3 5
./push_swap 4 2 1 5 3
./push_swap 4 2 3 1 5
./push_swap 4 2 3 5 1
./push_swap 4 2 5 1 3
./push_swap 4 2 5 3 1
./push_swap 4 3 1 2 5
./push_swap 4 3 1 5 2
./push_swap 4 3 2 1 5
./push_swap 4 3 2 5 1
./push_swap 4 3 5 1 2
./push_swap 4 3 5 2 1
./push_swap 4 5 1 2 3
./push_swap 4 5 1 3 2
./push_swap 4 5 2 1 3
./push_swap 4 5 2 3 1
./push_swap 4 5 3 1 2
./push_swap 4 5 3 2 1
./push_swap 5 1 2 3 4
./push_swap 5 1 2 4 3
./push_swap 5 1 3 2 4
./push_swap 5 1 3 4 2
./push_swap 5 1 4 2 3
./push_swap 5 1 4 3 2
./push_swap 5 2 1 3 4
./push_swap 5 2 1 4 3
./push_swap 5 2 3 1 4
./push_swap 5 2 3 4 1
./push_swap 5 2 4 1 3
./push_swap 5 2 4 3 1
./push_swap 5 3 1 2 4
./push_swap 5 3 1 4 2
./push_swap 5 3 2 1 4
./push_swap 5 3 2 4 1
./push_swap 5 3 4 1 2
./push_swap 5 3 4 2 1
./push_swap 5 4 1 2 3
./push_swap 5 4 1 3 2
./push_swap 5 4 2 1 3
./push_swap 5 4 2 3 1
./push_swap 5 4 3 1 2
./push_swap 5 4 3 2 1

END
echo after comment


./push_swap 2 5 1 3 4
./push_swap 2 5 1 4 3
./push_swap 2 5 3 1 4
./push_swap 2 5 3 4 1
./push_swap 2 5 4 1 3
./push_swap 2 5 4 3 1
./push_swap 3 1 2 4 5
./push_swap 3 1 2 5 4
./push_swap 3 1 4 2 5
./push_swap 3 1 4 5 2
./push_swap 3 1 5 2 4
./push_swap 3 1 5 4 2
./push_swap 3 2 1 4 5
./push_swap 3 2 1 5 4
./push_swap 3 2 4 1 5
./push_swap 3 2 4 5 1
./push_swap 3 2 5 1 4
./push_swap 3 2 5 4 1
./push_swap 3 4 1 2 5
./push_swap 3 4 1 5 2
./push_swap 3 4 2 1 5
./push_swap 3 4 2 5 1
./push_swap 3 4 5 1 2
./push_swap 3 4 5 2 1
./push_swap 3 5 1 2 4
./push_swap 3 5 1 4 2
./push_swap 3 5 2 1 4
./push_swap 3 5 2 4 1
./push_swap 3 5 4 1 2
./push_swap 3 5 4 2 1
./push_swap 4 1 2 3 5
./push_swap 4 1 2 5 3
./push_swap 4 1 3 2 5
./push_swap 4 1 3 5 2
./push_swap 4 1 5 2 3
./push_swap 4 1 5 3 2
./push_swap 4 2 1 3 5
./push_swap 4 2 1 5 3
./push_swap 4 2 3 1 5
./push_swap 4 2 3 5 1
./push_swap 4 2 5 1 3
./push_swap 4 2 5 3 1
./push_swap 4 3 1 2 5
./push_swap 4 3 1 5 2
./push_swap 4 3 2 1 5
./push_swap 4 3 2 5 1
./push_swap 4 3 5 1 2
./push_swap 4 3 5 2 1
./push_swap 4 5 1 2 3
./push_swap 4 5 1 3 2
./push_swap 4 5 2 1 3
./push_swap 4 5 2 3 1
./push_swap 4 5 3 1 2
./push_swap 4 5 3 2 1
./push_swap 5 1 2 3 4
./push_swap 5 1 2 4 3
./push_swap 5 1 3 2 4
./push_swap 5 1 3 4 2
./push_swap 5 1 4 2 3
./push_swap 5 1 4 3 2
./push_swap 5 2 1 3 4
./push_swap 5 2 1 4 3
./push_swap 5 2 3 1 4
./push_swap 5 2 3 4 1
./push_swap 5 2 4 1 3
./push_swap 5 2 4 3 1
./push_swap 5 3 1 2 4
./push_swap 5 3 1 4 2
./push_swap 5 3 2 1 4
./push_swap 5 3 2 4 1
./push_swap 5 3 4 1 2
./push_swap 5 3 4 2 1
./push_swap 5 4 1 2 3
./push_swap 5 4 1 3 2
./push_swap 5 4 2 1 3
./push_swap 5 4 2 3 1
./push_swap 5 4 3 1 2
./push_swap 5 4 3 2 1
