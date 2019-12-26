NAME = pathfinder

LIB = ./libmx/libmx.a



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
    src/mx_find_path.c \
    src/mx_create_dextra_arr.c \
    src/mx_dextra_mat.c \
    src/mx_free_two.c \
    src/mx_update_cycle.c \
    src/mx_findmin.c \
    src/mx_write_result.c \
    src/mx_find_char.c \
    src/mx_create_tmp_arr.c \
    src/mx_write_in_list.c \
    src/mx_push_onpalce.c \
    src/mx_creat_arr_list.c \
    src/mx_find_index.c \
    src/mx_create_result.c \
    src/mx_buildlist.c \
    src/mx_allvalid.c \
    src/mx_validation_four.c \
    src/mx_valid_island.c \
    src/mx_print_error_line.c \



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
    mx_find_path.o \
    mx_create_dextra_arr.o \
    mx_dextra_mat.o \
    mx_free_two.o \
    mx_update_cycle.o \
    mx_findmin.o \
    mx_write_result.o \
    mx_find_char.o \
    mx_create_tmp_arr.o \
    mx_write_in_list.o \
    mx_push_onpalce.o \
    mx_creat_arr_list.o \
    mx_find_index.o \
    mx_create_result.o \
    mx_buildlist.o \
    mx_allvalid.o \
    mx_validation_four.o \
    mx_valid_island.o \
    mx_print_error_line.o \


CFLAGS = -std=c11 -Werror -Wall -Wextra -Wpedantic

INC = inc/pathfinder.h

all: install clean

install:
	@make -C libmx install		
	@clang $(CFLAGS) -c $(SRC)
	@clang $(CFLAGS) $(LIB) $(OUT) -I $(HEADER) -o $(NAME)
	@mkdir -p obj
	@cp $(OUT) obj/
	@rm -rf $(OUT)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)


clean:
	@make -C libmx clean	
	@rm -rf obj

reinstall: uninstall install












