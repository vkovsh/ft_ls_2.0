# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 19:36:03 by vkovsh            #+#    #+#              #
#    Updated: 2018/03/17 17:31:42 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STATIC_NAME			=	libft.a
DYNAMIC_NAME		=	libft.so

CC 					=	gcc
CC_FLAGS 			=	-Wall -Werror -Wextra -fPIC

INC_PATH			=	./includes/
OBJ_PATH			=	./obj/

LIBFT_SRCS_PATH		=	./srcs/
LIBFT_BASE_PATH		=	$(LIBFT_SRCS_PATH)base/
LIBFT_BINTREE_PATH	=	$(LIBFT_SRCS_PATH)bintree/
LIBFT_LIST_PATH		=	$(LIBFT_SRCS_PATH)list/
LIBFT_STREAM_PATH	=	$(LIBFT_SRCS_PATH)stream/
LIBFT_PRINTF_PATH	=	$(LIBFT_SRCS_PATH)ft_printf/

MACRO_PATH			=   $(LIBFT_PRINTF_PATH)macro/
PARSER_PATH			=   $(LIBFT_PRINTF_PATH)parser/

OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC			=	$(addprefix -I, $(INC_PATH))

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_NAME	+=	$(LIBFT_BASE_NAME:.c=.o)
OBJ_NAME	+=	$(LIBFT_BINTREE_NAME:.c=.o)
OBJ_NAME	+=	$(LIBFT_LIST_NAME:.c=.o)
OBJ_NAME	+=	$(LIBFT_STREAM_NAME:.c=.o)
OBJ_NAME    +=  $(MACRO_NAME:.c=.o)
OBJ_NAME    +=  $(PARSER_NAME:.c=.o)

PARSER_NAME =   parse_specs.c						\
				get_spec.c							\
				set_flag1.c							\
				set_width.c							\
				set_precision.c						\
				set_flag2.c							\
				set_type.c							\
				set_background.c					\
				set_color.c							\
				set_plus_and_space_to_value.c		\
				set_sharp_to_value.c				\
				set_precision_to_value.c			\
				set_precision_to_pointer.c			\
				set_precision_to_numeric.c			\
				set_precision_to_string.c			\
				set_width_to_value.c				\
				set_color_and_background_to_value.c

MACRO_NAME  =   check_double_percent.c  \
                fresh_value.c           \
                ft_output.c             \
                init_min_str.c          \
                init_list.c 			\
                set_spec.c				\
				is_unsigned.c			\
				is_flag1.c				\
				is_type.c				\
				join_none.c				\
				join_n.c				\
				join_t.c				\
				join_r.c				\
				join_big_s.c			\
				join_big_c.c			\
				join_signed_decimal.c	\
				join_unsigned_value.c	\
				join_c.c				\
				join_s.c				\
				join_percent.c			\
				join_p.c				\
				del_one.c				\
				is_numeric_type.c		\
				is_null_pointer.c

SRC_NAME	=	ft_printf.c 		\
				format_value.c 		\
				ft_dprintf.c		\
				check_asterisk.c	\
				set_value.c	

LIBFT_BASE_NAME	=	ft_arealpha.c		\
					ft_isupper.c   		\
					ft_strchr.c    		\
					ft_strmap.c    		\
					ft_strtolower.c		\
					ft_aredigits.c  	\
					ft_itoa.c      		\
					ft_strclr.c    		\
					ft_strmapi.c   		\
					ft_strtoupper.c		\
					ft_arehex.c     	\
					ft_lltoa.c     		\
					ft_strcmp.c    		\
					ft_strncat.c   		\
					ft_strtrim.c		\
					ft_atoi.c       	\
					ft_memalloc.c  		\
					ft_strcpy.c    		\
					ft_strncmp.c   		\
					ft_tolower.c		\
					ft_bzero.c      	\
					ft_memccpy.c   		\
					ft_strdel.c    		\
					ft_strncpy.c   		\
					ft_toupper.c		\
					ft_isalnum.c    	\
					ft_memchr.c    		\
					ft_strdup.c    		\
					ft_strnequ.c   		\
					ft_ulltoa_base.c	\
					ft_isalpha.c    	\
					ft_memcmp.c    		\
					ft_strequ.c    		\
					ft_strnew.c    		\
					ft_ulltoa.c			\
					ft_isascii.c    	\
					ft_striter.c   		\
					ft_strnstr.c   		\
					ft_wstr_to_str.c	\
					ft_isdigit.c    	\
					ft_memdel.c    		\
					ft_striteri.c  		\
					ft_strrchr.c		\
					ft_ishex.c      	\
					ft_memmove.c   		\
					ft_strjoin.c   		\
					ft_strsplit.c		\
					ft_islow.c      	\
					ft_memset.c    		\
					ft_strlcat.c   		\
					ft_strstr.c			\
					ft_isprint.c    	\
					ft_strcat.c    		\
					ft_strsub.c			\
					ft_nbrlen.c			\
					ft_strlen.c			\
					ft_memcpy.c

LIBFT_BINTREE_NAME	=	ft_bintree_del.c				\
						ft_bintree_delone.c				\
						ft_bintree_find.c				\
						ft_bintree_new.c				\
						ft_bintree_add.c				\
						ft_bintree_prefix_traverse.c	\
						ft_bintree_infix_traverse.c		\
						ft_bintree_postfix_traverse.c	\
						ft_balance.c					\
						ft_rotate.c						\
						ft_fixheight.c		

LIBFT_LIST_NAME	=		ft_lstadd.c			\
						ft_lstcount.c		\
						ft_lstdel.c			\
						ft_lstdelone.c		\
						ft_lstiter.c		\
						ft_lstmap.c			\
						ft_lstnew.c			\
						ft_lstrev.c

LIBFT_STREAM_NAME	=	ft_putchar.c		\
						ft_putchar_fd.c		\
						ft_putendl.c		\
						ft_putendl_fd.c		\
						ft_putnbr.c			\
						ft_putnbr_fd.c		\
						ft_putstr.c			\
						ft_putstr_fd.c		\
						get_next_line.c

all: a so

so: $(DYNAMIC_NAME)

a: $(STATIC_NAME)

$(DYNAMIC_NAME): $(OBJ)
	@$(CC) -shared -o $@ $^
	@echo "Compiling" [ $(DYNAMIC_NAME) ]

$(STATIC_NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(STATIC_NAME) ]

$(OBJ_PATH)%.o: $(LIBFT_PRINTF_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(LIBFT_BASE_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(LIBFT_BINTREE_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(LIBFT_LIST_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(LIBFT_STREAM_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(MACRO_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(PARSER_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(STATIC_NAME) ]..."

fclean: clean
	@rm -f $(STATIC_NAME)
	@rm -f $(DYNAMIC_NAME)
	@echo "Remove..." [ $(STATIC_NAME) ]
	@echo "Remove..." [ $(DYNAMIC_NAME) ]

re: fclean all

.PHONY: all clean fclean re so

.NOTPARALLEL: all clean fclean re so
