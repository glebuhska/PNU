#ifndef IO_H
#define IO_H
typedef long size_t;
#define SYS_READ  0
#define SYS_WRITE 1
#define SYS_EXIT  60
#define SYS_FORK  57
#define SYS_EXECVE 59
#define STDIN  0
#define STDOUT 1
void my_putc(char c);
void my_puts(const char *str);
long my_read(int fd, char *buf, size_t count);
void my_exit(int code);
size_t my_strlen(const char *str);

#endif