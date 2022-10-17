CC=GCC
FLAGS= -Wall -Werror -Wextra -I libft.h
AR=ar crs
RM=rm -rf

#colors
reset = \033[0m
sfr = \033[1;33m
7mr = \033[1;31m
zrq = \033[1;34m
khdr = \033[1;32m

SRCS= 	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen \
		ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper\
		ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strdup ft_memchr\
		ft_memcmp ft_strnstr ft_atoi ft_calloc ft_substr ft_strtrim	ft_strjoin\
		ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd\
		ft_putnbr_fd ft_putendl_fd
BONUS= 	ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone\
		ft_lstclear ft_lstiter ft_lstmap
OBJ=$(SRCS:=.o)
BONUS_O=$(BONUS:=.o)
NAME=libft.a

all: $(NAME)
	@echo "$(zrq)=======  libft.a : TAAAABI3A RABI3A  =======$(reset)"

bonus: all $(BONUS_O)
	$(AR) $(NAME) $(BONUS_O)

$(NAME): $(OBJ) $(BONUS_O)
	$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	@echo  "$(7mr)" $< "$(khdr) : COMMPILED$(reset)"
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(sfr)====  MR.propre : ANA M3AKOM 7OROBAT  ====$(reset)"
	@$(RM) $(OBJ) $(BONUS_O)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re