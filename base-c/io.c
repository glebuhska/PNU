#include "io.h"
static inline long sys_write(int fd, const char *buf, size_t count) {
    long ret;
    __asm__ volatile (
        "syscall"
        : "=a" (ret)
        : "a" (1), "D" (fd), "S" (buf), "d" (count)
        : "rcx", "r11", "memory"
    );
    return ret;
}

static inline long syscall_exit(long number, long arg1) {
    long ret;
    __asm__ volatile (
        "syscall"
        : "=a" (ret)
        : "a" (number), "D" (arg1)
        : "rcx", "r11", "memory"
    );
    return ret;
}
long sys_execve(const char *filename, char *const argv[], char *const envp[]) {
    long ret;
    __asm__ volatile (
        "syscall"
        : "=a" (ret)
        : "a" (59), "D" (filename), "S" (argv), "d" (envp)
        : "rcx", "r11", "memory"
    );
    return ret;
}
long sys_fork() {
    long ret;
    __asm__ volatile (
        "syscall"
        : "=a" (ret)
        : "a" (57)
        : "rcx", "r11", "memory"
    );
    return ret;
}

void pputc(char c) {
    sys_write(1, &c, 1);
}

void pputs(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') len++;
    sys_write(1, str, len);
}

void exit(int code) {
    syscall_exit(60, code); // ну как тебе читать мой код, только не думай предлагать хотябы 1 строчку под gpl
}