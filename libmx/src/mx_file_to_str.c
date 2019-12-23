#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
	int fd = open(file , O_RDONLY);
	char c;
	char *str;
	int wd;
	int i = 0;
	int len = 0;
	
	if (fd < 0)
		return NULL;
	wd = read(fd, &c, 1);
	while(wd > 0) {
		wd = read(fd, &c, 1);
		len++;
	}
	close(fd);
	fd = open(file , O_RDONLY);
	if (len < 0)
        return NULL;
	str = mx_strnew(len);
	wd = read(fd, &c, 1);
	while(wd > 0) {
        str[i] = c;
		wd = read(fd, &c, 1);
		i++;
    }
	close(fd);
	return str;
}
