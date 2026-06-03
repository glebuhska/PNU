#ifndef IO_HPP
#define IO_HPP



using size_t = unsigned long;

namespace pnu {

    constexpr int stdin_fd  = 0;
    constexpr int stdout_fd = 1;


    constexpr long sys_read_num   = 0;
    constexpr long sys_write_num  = 1;
    constexpr long sys_ioctl_num  = 16;
    constexpr long sys_exit_num   = 60;


    void pputc(char c);
    void pputs(const char* str);
    [[noreturn]] void pexit(int code);


    long pread(int fd, char* buf, size_t count);
    long pioctl(int fd, unsigned long req, void* arg);
}

#endif
