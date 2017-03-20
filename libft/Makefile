# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhalford <jack@crans.org>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 16:09:36 by jhalford          #+#    #+#              #
#    Updated: 2017/03/20 12:05:06 by wescande         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc
AR			=	ar -rc
MKDIR		=	mkdir -p
RM			=	/bin/rm -rf

W_FLAGS		=	-Wall -Wextra -Werror
D_FLAGS		=	-g
V_FLAGS		=	-fvisibility=hidden
FLAGS		=	$(W_FLAGS) $(D_FLAGS) $(V_FLAGS)

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

SRC_DIR		=	src/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	=	\
btree/btree_apply_by_level.c\
btree/btree_apply_infix.c\
btree/btree_apply_prefix.c\
btree/btree_apply_suffix.c\
btree/btree_create_node.c\
btree/btree_del.c\
btree/btree_delone.c\
btree/btree_insert_data.c\
btree/btree_level_count.c\
btree/btree_map.c\
btree/btree_print.c\
btree/btree_search_item.c\
char/ft_isalnum.c\
char/ft_isalpha.c\
char/ft_isascii.c\
char/ft_isdigit.c\
char/ft_isprint.c\
char/ft_tolower.c\
char/ft_toupper.c\
cliopts/cliopts_get.c\
cliopts/cliopts_has.c\
color/ft_color_mk.c\
color/ft_color_mkif.c\
color/ft_color_reset.c\
color/ft_color_set.c\
dlst/ft_dlstadd_after.c\
dlst/ft_dlstadd_before.c\
dlst/ft_dlstdel.c\
dlst/ft_dlstdelone.c\
dlst/ft_dlstlast.c\
dlst/ft_dlstnew.c\
dlst/ft_dlstrtostr.c\
dlst/ft_dlstsize.c\
error/error.c\
ft_printf/ft_conversion.c\
ft_printf/ft_fmt_simplify.c\
ft_printf/ft_fmt_validate_conv.c\
ft_printf/ft_fmt_validate_flags.c\
ft_printf/ft_fmt_validate_mod.c\
ft_printf/ft_printf.c\
ft_printf/ft_printf_color.c\
ft_printf/ft_printf_parse.c\
ft_printf/ft_transform.c\
ft_printf/ft_vprintf.c\
ft_printf/lib_fmt.c\
ft_printf/lib_fmt_error.c\
ft_printf/lib_pad.c\
ft_printf/lib_pad_sharp.c\
get_next_line/get_next_line.c\
lst/ft_id.c\
lst/ft_lst_at.c\
lst/ft_lst_bfree.c\
lst/ft_lst_cfree.c\
lst/ft_lst_delif.c\
lst/ft_lst_delsub.c\
lst/ft_lst_filter.c\
lst/ft_lst_find.c\
lst/ft_lst_merge.c\
lst/ft_lst_order_delsub.c\
lst/ft_lst_print.c\
lst/ft_lst_print2.c\
lst/ft_lst_removeif.c\
lst/ft_lst_reverse.c\
lst/ft_lst_size.c\
lst/ft_lst_sorted_insert.c\
lst/ft_lst_sorted_merge.c\
lst/ft_lstadd.c\
lst/ft_lstdel.c\
lst/ft_lstdelone.c\
lst/ft_lsteadd.c\
lst/ft_lstiter.c\
lst/ft_lstlast.c\
lst/ft_lstmap.c\
lst/ft_lstnadd.c\
lst/ft_lstnew.c\
lst/ft_lstnew_range.c\
lst/ft_lstsort.c\
lst/pop.c\
lst/push.c\
math/ft_addrcmp.c\
math/ft_ilen.c\
math/ft_ilen_base.c\
math/ft_itoa.c\
math/ft_itoa_base.c\
math/ft_lllen.c\
math/ft_lllen_base.c\
math/ft_lltoa_base.c\
math/ft_uilen.c\
math/ft_uitoa_base.c\
math/ft_ulltoa_base.c\
math/id.c\
mem/ft_bzero.c\
mem/ft_memalloc.c\
mem/ft_memccpy.c\
mem/ft_memchr.c\
mem/ft_memcmp.c\
mem/ft_memcpy.c\
mem/ft_memdel.c\
mem/ft_memmove.c\
mem/ft_memset.c\
mem/ft_realloc.c\
path/ft_path_notdir.c\
printing/ft_putchar.c\
printing/ft_putendl.c\
printing/ft_putnbr.c\
printing/ft_putstr.c\
sstr/ft_sstradd.c\
sstr/ft_sstrcat.c\
sstr/ft_sstrdel.c\
sstr/ft_sstrdup.c\
sstr/ft_sstrfree.c\
sstr/ft_sstrprint.c\
sstr/ft_sstrprint_fd.c\
sstr/ft_sstrsort.c\
sstr/ft_sstrstr.c\
str/ft_atoi.c\
str/ft_convert_base.c\
str/ft_putaddr_fd.c\
str/ft_split_whitespaces.c\
str/ft_str3join.c\
str/ft_strappend.c\
str/ft_strbetween.c\
str/ft_strcat.c\
str/ft_strcatf.c\
str/ft_strchr.c\
str/ft_strchrcpy.c\
str/ft_strclr.c\
str/ft_strcmp.c\
str/ft_strcpy.c\
str/ft_strcspn.c\
str/ft_strcut.c\
str/ft_strdel.c\
str/ft_strdup.c\
str/ft_strdupchr.c\
str/ft_strduptr.c\
str/ft_strequ.c\
str/ft_strinsert.c\
str/ft_stris.c\
str/ft_striter.c\
str/ft_striteri.c\
str/ft_strjoin.c\
str/ft_strlcat.c\
str/ft_strlen.c\
str/ft_strlenchr.c\
str/ft_strmap.c\
str/ft_strmapi.c\
str/ft_strncat.c\
str/ft_strncmp.c\
str/ft_strncpy.c\
str/ft_strnequ.c\
str/ft_strnew.c\
str/ft_strnstr.c\
str/ft_strrchr.c\
str/ft_strreplace.c\
str/ft_strrev.c\
str/ft_strsplit.c\
str/ft_strstr.c\
str/ft_strsub.c\
str/ft_strtok.c\
str/ft_strtrim.c\
sys/dup2_close.c\
sys/ft_getenv.c\
sys/ft_xattr_count.c\
sys/ft_xattr_print.c\
time/ft_mytime_free.c\
time/ft_mytime_get.c\
time/ft_time_isrecent.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all:
	@make -j $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@# @strip -x $(NAME)
	@printf "\r\033[48;5;15;38;5;25m✅ MAKE $(NAME)\033[0m\033[K\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) $(FLAGS) -MMD -c $< -o $@\
		-I $(INC_DIR)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)
	@$(MKDIR) $(dir $(OBJS))

clean:
	@$(RM) $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖ clean $(NAME).\033[0m\033[K\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME).\033[0m\033[K\n"

re: fclean all

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
