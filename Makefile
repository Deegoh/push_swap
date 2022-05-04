#color
GREEN = \e[32m
RED = \e[31m
WHITE = \e[39m
YELLOW = \e[33m
HIDDEN = \e[8m
RESET = \e[0m
#push_swap
NAME = push_swap
ifeq ($(shell uname),Darwin)
	CHECKER = checker_Mac
else
	CHECKER = checker_linux
endif
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g3 -fsanitize=address
SRC = push_swap.c\
	  print_utils.c\
	  init_utils.c\
	  parse_arg.c\
	  dll_utils.c\
	  nodes_utils.c\
	  rules_node.c\
	  op_utils.c\
	  simple_sort.c\
	  algo.c\
	  quick_sort.c

RM = rm -f
LIBFT_DIR = ./libft/
INCLUDE = -I$(LIBFT_DIR)
LIB = -lft -L$(LIBFT_DIR)
# ARG =`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
# ARG =`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`
ARG =11 4 370 201 322 251 227 49 43 90 411 147 400 438 364 22 420 40 405 381 132 44 41 286 261 118 330 85 476 439 488 197 135 499 119 422 79 208 77 365 447 235 99 29 339 120 451 134 357 232 109 55 309 60 269 270 61 348 300 413 102 266 495 190 107 104 477 329 450 18 142 149 352 493 390 243 181 317 325 78 172 37 343 160 272 316 136 463 449 431 254 130 207 303 333 443 368 374 202 248 200 173 359 279 150 367 47 382 129 215 158 6 249 427 423 452 298 110 242 218 331 53 257 121 409 399 280 321 167 65 378 159 435 100 194 327 246 483 180 63 57 76 421 289 473 92 380 209 117 481 389 428 291 164 198 222 156 334 196 394 51 412 56 416 328 34 161 137 459 138 446 256 408 414 74 487 482 292 219 182 204 259 285 217 395 492 383 115 287 460 241 177 175 113 324 171 216 229 64 212 111 267 494 268 419 485 340 131 151 315 144 21 231 490 68 28 86 466 195 95 355 441 434 375 205 27 13 93 82 349 313 373 398 276 193 105 433 185 467 294 191 188 271 274 332 174 305 122 255 10 258 369 155 260 221 192 170 393 183 69 442 17 387 35 71 31 166 236 301 410 19 154 312 371 25 20 396 48 335 295 474 98 347 418 306 426 240 275 199 456 1 39 141 157 230 484 36 284 290 281 70 97 234 214 58 30 379 228 297 277 424 498 245 346 384 307 103 124 479 283 225 470 12 415 165 112 140 16 52 432 458 3 108 262 153 54 360 125 468 453 425 213 96 356 14 320 80 465 148 62 440 403 220 282 139 323 75 46 402 5 178 472 223 67 278 407 489 388 478 265 363 50 377 126 2 163 314 319 342 88 162 83 362 189 239 8 448 457 417 143 454 497 341 392 296 350 94 264 491 26 72 89 247 203 318 376 146 237 226 273 66 91 184 42 336 486 345 461 81 406 116 475 152 24 87 84 429 496 23 308 302 344 224 233 358 15 444 326 133 455 179 353 169 168 45 471 9 445 123 252 386 299 311 250 238 397 211 127 437 186 404 338 337 114 436 304 469 372 244 187 59 401 38 263 293 354 430 351 206 462 33 310 391 366 32 176 101 288 106 480 464 128 361 145 210 73 385 253 7
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft v1 v2 test run wc checker lldb

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) all -sC $(LIBFT_DIR)
	@$(CC) $(OBJ) $(LIB) $(INCLUDE) $(CFLAGS) -o $(NAME)
	@printf "\r$(GREEN)🚀 Creating $(NAME)$(RESET)\n"
	@sleep 0.5
	@printf "\r$(HIDDEN)🚀 Creating $(NAME)$(RESET)\r"

clean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)
	@printf "\r$(YELLOW)♻️  Clean $(NAME)$(RESET)\n"
	@sleep 0.5
	@printf "\r$(HIDDEN)♻️  Clean $(NAME)$(RESET)\r"
	@$(MAKE) clean -sC $(LIBFT_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@printf "\r$(RED)🗑️  Remove $(NAME)$(RESET)\n"
	@sleep 0.5
	@printf "\r$(HIDDEN)🗑️  Remove $(NAME)$(RESET)\r"

re: fclean all

v1: all
	./pyviz.py $(ARG)

v2: all
	./push_swap_visualizer2.py --min 1 --max 10000 --size 500

test: all
	cp $(NAME) ../push_swap_tester/.
	bash ../push_swap_tester/tester.sh

run: all
	./$(NAME) $(ARG)

wc: all
	./$(NAME) $(ARG) | wc -l

checker: all
	./$(NAME) $(ARG) | ./$(CHECKER) $(ARG)

lldb: all
	lldb $(NAME) $(ARG)
