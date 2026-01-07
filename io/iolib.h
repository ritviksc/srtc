#ifndef IOLIB_H
#define IOLIB_H

#include <stddef.h>
#include <unistd.h>

ssize_t read_from_file(int fd, void *buf, size_t count);
ssize_t write_to_file(int fd, void *buf, size_t count);
ssize_t open_file(const char *filename, int flags, umode_t mode);
ssize_t close_file(unsigned int fd);


#endif // IOLIB_H