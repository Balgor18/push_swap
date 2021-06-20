NAME = push_swap

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC =	ft_print.c find_min.c \
		ft_pa.c\
		ft_pb.c\
		ft_rr.c\
		ft_rrr.c\
		ft_ss.c\
		init_struct.c\
		push_swap.c\
		solver.c\
		sort_3.c\
		sort_tab.c\
		verif.c\
		verif2.c

OBJ = $(SRC:.c=.o)

$(NAME): libft $(OBJ)
			@$(CC) $(CFLAGS) -o $@ $(OBJ) -Llibft -lft
# -fsanitize=address

#			COMMANDE ARG=`ruby -e "puts (1..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG

#			test 49
#			./push_swap 36 10 21 26 19 18 1 24 48 46 41 23 17 30 9 13 3 38 4 39 6 7 28 20 14 35 42 25 44 29 2 15 5 22 32 12 16 34 31 43 33 27 49 37 11 45 8 40 47

#			test 50
#			./push_swap 13 46 28 34 48 35 22 23 32 41 14 39 24 33 47 25 15 44 37 16 21 11 26 6 27 36 7 1 19 2 29 3 20 40 10 43 8 49 38 50 31 30 17 5 18 9 12 42 4 45

#			test 100
#			./push_swap 36 19 59 84 26 53 18 31 55 63 43 25 73 6 74 92 98 77 30 7 76 28 13 96 40 5 37 100 38 16 29 70 80 79 52 12 4 64 41 51 42 85 27 86 49 75 17 1 47 35 9 54 44 88 15 72 83 67 71 93 21 94 81 11 58 8 3 33 57 14 32 95 24 99 22 78 90 68 69 46 91 56 50 97 61 39 45 34 87 82 89 10 65 2 48 23 20 62 60 66

#| wc -l

#			test 500
#			./push_swap 167 228 196 47 417 76 492 75 171 56 126 158 401 320 248 484 154 337 415 161 380 341 134 168 169 485 259 304 434 201 177 36 44 35 389 218 38 398 17 455 181 2 408 377 265 208 463 125 70 264 335 409 74 308 302 462 173 350 147 288 270 124 166 345 160 214 491 394 16 312 111 495 374 193 52 69 429 256 97 443 162 353 50 444 356 419 323 163 195 468 64 223 231 378 369 11 305 251 176 5 98 358 191 180 384 172 104 194 51 260 217 351 319 282 225 459 458 141 465 311 431 284 456 119 440 59 63 102 245 112 239 346 1 37 235 340 328 317 439 100 108 135 338 375 386 149 40 175 275 379 287 58 303 71 113 371 365 347 318 6 490 236 497 8 115 15 475 110 137 230 327 268 143 19 324 486 54 357 53 41 309 21 359 420 306 281 430 388 42 498 234 370 441 12 144 170 467 469 156 28 416 277 60 27 67 73 457 294 20 339 325 480 153 200 300 26 14 61 452 109 131 31 227 206 139 483 78 226 150 421 94 448 295 367 267 381 435 9 331 344 437 433 182 403 237 414 142 159 400 254 411 216 283 310 329 238 314 240 252 207 247 399 392 412 95 133 422 487 229 178 285 151 258 96 84 246 499 174 292 410 293 453 120 152 395 62 30 276 155 290 316 7 197 184 451 446 332 116 315 46 244 413 476 210 242 348 213 224 373 192 447 326 426 199 262 87 393 243 65 3 330 263 13 250 255 333 271 212 466 157 360 33 79 190 122 209 128 364 222 382 322 43 189 297 436 488 349 396 220 164 23 106 99 291 450 405 127 49 10 301 321 101 343 406 129 82 390 361 241 460 385 362 489 183 88 471 130 425 90 89 132 273 336 114 24 427 221 342 57 80 18 232 454 404 391 286 34 105 355 372 117 261 45 138 77 278 481 424 66 188 86 474 482 121 233 494 22 136 272 266 185 123 402 296 289 91 187 368 418 118 202 500 280 205 25 445 449 211 92 219 32 68 432 140 29 93 473 203 39 146 478 428 145 179 279 397 354 48 313 72 352 472 470 198 442 107 81 55 383 493 464 479 215 423 257 376 249 299 363 85 165 407 477 387 148 204 274 83 4 298 366 269 186 253 438 496 307 103 334 461


#			./push_swap 1 4 2 3 5 | wc -l
#			./push_swap 4 3 10 11 9 2
#			valgrind ./push_swap 2 1 3 6 5 8
#			valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2 1 3 6 5 8
#			./push_swap 2 one 3 6 5 8
#			./push_swap "4 67 3 87 23"
#			./push_swap "4 one 3 87 23"

libft :
		make -C libft/

%.o: %.c
				$(CC) $(CFLAGS) -I. -Imlx -o $@ -c $?

all: $(NAME)

norme :
#		@make -C libft/ norme
		norminette -R CheckForbiddenSourceHeader $(SRC)
		norminette -R CheckDefine push_swap.h

clean:
				$(RM) $(OBJ)
				@make -C libft/ clean

fclean: clean
				$(RM) $(NAME)
				@make -C libft/ fclean

re: fclean all

.PHONY: clean all fclean re libft
