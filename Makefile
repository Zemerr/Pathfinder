NAME = pathfinder

LIB = ./libmx/libmx.a

LIBA = libmx.a

HEADER = inc/pathfinder.h

HEADERS = pathfinder.h

SRC = src/mx_atoi.c \
	src/mx_isdigit.c \
	src/mx_strjoin_one.c \
	src/mx_strjoin_two.c \
	src/mx_strjoin_both.c \
	src/mx_del_intarr.c \
	src/mx_del_list.c \
	src/mx_strfind.c \
	src/mx_printstr_err.c \
	src/mx_digit_str.c \
	src/mx_printchar_err.c \
	src/mx_printint_err.c \
	src/mx_isalpha.c \
    src/path.c \

SRCS = mx_atoi.c \
    mx_isdigit.c \
    mx_strjoin_one.c \
    mx_strjoin_two.c \
    mx_strjoin_both.c \
    mx_del_intarr.c \
    mx_del_list.c \
    mx_strfind.c \
    mx_printstr_err.c \
    mx_digit_str.c \
    mx_printchar_err.c \
    mx_printint_err.c \
    mx_isalpha.c \
    path.c \

OUT = mx_atoi.o \
	mx_isdigit.o \
	mx_strjoin_one.o \
	mx_strjoin_two.o \
	mx_strjoin_both.o \
	mx_del_intarr.o \
	mx_del_list.o \
	mx_strfind.o \
	mx_printstr_err.o \
	mx_digit_str.o \
	mx_printchar_err.o \
	mx_printint_err.o \
	mx_isalpha.o \
    path.o \

CFLAGS = -std=c11 -Werror -Wall -Wextra -Wpedantic

INC = inc/pathfinder.h

all: install clean

install:
	@make -C libmx install
	@cp $(SRC) .
	@cp $(LIB) .	
	@clang $(CFLAGS) -c $(SRC)
	@clang $(CFLAGS) $(LIBA) $(OUT) -I $(HEADER) -o $(NAME)
	@mkdir -p obj
	@cp $(OUT) obj/
	@rm -rf $(OUT)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)



clean:
	@make -C libmx clean
	@rm -rf $(SRCS)	
	@rm -rf $(LIBA)
	@rm -rf obj

reinstall: uninstall install clean











