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
void pputc(char c);
void pputs(const char *str);
long pread(int fd, char *buf, size_t count);
void pexit(int code);
size_t pstrlen(const char *str);

#endif