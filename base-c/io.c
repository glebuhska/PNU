#include "io.h"

// --- Системные вызовы (статические) ---

static inline long sys_write(int fd, const char *buf, size_t count) {
    long ret;
    __asm__ volatile ("syscall" : "=a" (ret) : "a" (1), "D" (fd), "S" (buf), "d" (count) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_read(int fd, char *buf, size_t count) {
    long ret;
    __asm__ volatile ("syscall" : "=a" (ret) : "a" (0), "D" (fd), "S" (buf), "d" (count) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_exit(long code) {
    long ret;
    __asm__ volatile ("syscall" : "=a" (ret) : "a" (60), "D" (code) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_ioctl(int fd, unsigned long req, void *arg) {
    long ret;
    __asm__ volatile ("syscall" : "=a" (ret) : "a" (16), "D" (fd), "S" (req), "d" (arg) : "rcx", "r11", "memory");
    return ret;
}

// --- Реализация функций для вашего шелла ---

void pputc(char c) {
    sys_write(1, &c, 1);
}

void pputs(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') len++;
    sys_write(1, str, len);
}

void pexit(int code) {
    sys_exit(code);
}

long pread(int fd, char *buf, size_t count) {
    return sys_read(fd, buf, count);
}

long pioctl(int fd, unsigned long req, void *arg) {
    return sys_ioctl(fd, req, arg);
}