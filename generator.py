
tabl = [1, 2, 3, 4, 5]

"""
tableau_key_value ={
					'florian' : 20,
					'isabelle' : 44}

for people , val in tableau_key_value.items() :
	print(people + " = age " + str(val))
"""

for b1 in tabl :
	for b2 in tabl :
		for b3 in tabl :
			for b4 in tabl :
				for b5 in tabl :
					if b1 != b2 and b1 != b3 and b1 != b4 and b1 != b5 and b2 != b3 and b2 != b4 and b2 != b5 and b3 != b4 and b3 != b5 and b4 != b5 :
						print("./push_swap " + str(b1) +" "+ str(b2) +" "+ str(b3) +" "+ str(b4) +" "+ str(b5))
