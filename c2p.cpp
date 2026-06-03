#include "io.hpp"

namespace pnu {

    namespace {
        inline long sys_write(int fd, const char* buf, size_t count) {
            long ret;
            __asm__ volatile (
                "syscall" 
                : "=a" (ret) 
                : "a" (sys_write_num), "D" (fd), "S" (buf), "d" (count) 
                : "rcx", "r11", "memory"
            );
            return ret;
        }

        inline long sys_read(int fd, char* buf, size_t count) {
            long ret;
            __asm__ volatile (
                "syscall" 
                : "=a" (ret) 
                : "a" (sys_read_num), "D" (fd), "S" (buf), "d" (count) 
                : "rcx", "r11", "memory"
            );
            return ret;
        }

        inline long sys_exit(long code) {
            long ret;
            __asm__ volatile (
                "syscall" 
                : "=a" (ret) 
                : "a" (sys_exit_num), "D" (code) 
                : "rcx", "r11", "memory"
            );
            return ret;
        }

        inline long sys_ioctl(int fd, unsigned long req, void* arg) {
            long ret;
            __asm__ volatile (
                "syscall" 
                : "=a" (ret) 
                : "a" (sys_ioctl_num), "D" (fd), "S" (req), "d" (arg) 
                : "rcx", "r11", "memory"
            );
            return ret;
        }
    } // namespace


    void pputc(char c) {
        sys_write(stdout_fd, &c, 1);
    }

    void pputs(const char* str) {
        size_t len = 0;
        while (str[len] != '\0') {
            len++;
        }
        sys_write(stdout_fd, str, len);
    }

    void pexit(int code) {
        sys_exit(code);
        while (true);

    }

    long pread(int fd, char* buf, size_t count) {
        return sys_read(fd, buf, count);
    }

    long pioctl(int fd, unsigned long req, void* arg) {
        return sys_ioctl(fd, req, arg);
    }
} // кто-то читает сурсы?
