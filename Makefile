NAME				=	ft_ls

CC					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra

SRC_PATH			=	./srcs/

INC_PATH			=	./includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
LIBFT_PATH			=	./libft/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)

SRC_NAME			=	main.c					\
						get_args.c				\
						parse_args.c			\
						print_verbose_info.c	\
						print_info.c			\
						get_file_type.c			\
						read_directory.c		\
						is_system_dot_dir.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH) so
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT_PATH)libft.so
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

