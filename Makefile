SERVER = server

CLIENT = client

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC = inc

LFTDIR = libft

CFLAGS += -I./$(INC)

CFLAGS += -I./$(LFTDIR)/$(INC)

LDFLAGS = -Llibft -lft

SRCDIR = srcs

SRC_SERV = server.c

SRC_CL = client.c

S_SRC = $(addprefix $(SRCDIR)/, $(SRC_SERV)) 
 
C_SRC = $(addprefix $(SRCDIR)/, $(SRC_CL))

S_OBJ = $(S_SRC:.c=.o)

C_OBJ = $(C_SRC:.c=.o)

RM = rm -f

all: $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJ)
	$(CC) $(CFLAGS) $(S_OBJ) $(LDFLAGS) -o $(SERVER)

$(CLIENT): $(C_OBJ)
	$(CC) $(CFLAGS) $(C_OBJ) $(LDFLAGS) -o $(CLIENT)

%.o: %.c
	make -C libft
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make fclean -C libft
	$(RM) $(C_OBJ)
	$(RM) $(S_OBJ)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
