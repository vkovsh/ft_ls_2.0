NAME				=	ft_ls

CC					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra -g

SRC_PATH			=	./srcs/

INC_PATH			=	./includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
LIBFTPRINTF_PATH	=	./libft/
LIBFT_PATH			=	$(LIBFTPRINTF_PATH)/libft/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)

SRC_NAME			=	main.c					\
						get_args.c				\
						parse_args.c			\
						print_verbose_info.c	\
						print_info.c			\
						is_flag_set.c			\
						get_file_type.c			\
						read_directory.c		\
						is_system_dot_dir.c		\
						sort.c					\
						compare.c				\
						ft_error.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTPRINTF_PATH)libft.so
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@make -C $(LIBFTPRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

