
tabl = []

i = 0
while i < 10 :
	tabl.append(i)
	i+=1

"""
tableau_key_value ={
					'florian' : 20,
					'isabelle' : 44}

for people , val in tableau_key_value.items() :
	print(people + " = age " + str(val))


for b1 in tabl :
	for b2 in tabl :
		for b3 in tabl :
			for b4 in tabl :
				for b5 in tabl :
					for b6 in tabl :
						for b7 in tabl :
							for b8 in tabl :
								for b9 in tabl :
									for b10 in tabl :
										if b1 != b2 and b1 != b3 and b1 != b4 and b1 != b5 and b1 != b6 and b1 != b7 and b1 != b8 and b1 != b9 and b1 != b10 and b2 != b3 and b2 != b4 and b2 != b5 and b2 != b6 and b2 != b7 and b2 != b8 and b2 != b9 and b2 != b10 and b3 != b4 and b3 != b5 and b3 != b6 and b3 != b7 and b3 != b8 and b3 != b9 and b3 != b10 and b4 != b5 and b4 != b6 and b4 != b7 and b4 != b8 and b4 != b9 and b4 != b10 and b5 != b6 and b5 != b7 and b5 != b8 and b5 != b9 and b5 != b10 and b6 != b7 and b6 != b8 and b6 != b9 and b6 != b10 and b7 != b8 and b7 != b9 and b7 != b10 and b8 != b9 and b8 != b10 and b9 != b10:
											print("./push_swap " + str(b1) +" "+ str(b2) +" "+ str(b3) +" "+ str(b4) +" "+ str(b5) +" "+ str(b6) +" "+ str(b7) +" "+ str(b8) +" "+ str(b9) +" "+ str(b10) + " | wc -l")
										#if b1 == 0 and b2 == 3 and b3 == 9 and b4 == 8 and b5 == 7 and b6 == 6 and b7 == 5 and b8 == 4 and b9 == 2 and b10 == 1 :
										#	exit()
"""

for b1 in tabl :
	for b2 in tabl :
		for b3 in tabl :
			for b4 in tabl :
				for b5 in tabl :
					if b1 != b2 and b1 != b3 and b1 != b4 and b1 != b5 and b2 != b3 and b2 != b4 and b2 != b5 and b3 != b4 and b3 != b5 and b4 != b5:
						#print("./push_swap " + str(b1) +" "+ str(b2) +" "+ str(b3) +" "+ str(b4) +" "+ str(b5) )
						print("./push_swap " + str(b1) +" "+ str(b2) +" "+ str(b3) +" "+ str(b4) +" "+ str(b5) + " | wc -l")

