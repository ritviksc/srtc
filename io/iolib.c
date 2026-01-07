#include "syscalls/syscall.h"
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

ssize_t read_from_file(unsigned int fd, void *buf, size_t count)
{
    syscall_ret_t bytes_read = __syscall3(SYS_read,fd,buf,count);
    return (ssize_t)(bytes_read);
}

ssize_t write_to_file(unsigned int fd, void *buf, size_t count)
{
    syscall_ret_t bytes_written = __syscall3(SYS_write,fd,buf,count);
    return (ssize_t)(bytes_written);
}

ssize_t open_file(const char *filename, int flags, umode_t mode)
{
    syscall_ret_t result = __syscall3(SYS_open, filename, flags, mode);
    return (ssize_t)(result);
}

ssize_t close_file(unsigned int fd)
{
    syscall_ret_t result = __syscall1(SYS_close, fd);
    return (ssize_t)result;
}