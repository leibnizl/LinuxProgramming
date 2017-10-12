#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("2.5.in", O_RDWR | O_APPEND);
    if (-1 == fd) {
        std:: cout << "open error" << std:: endl;
        return 0;
    }
    char buf = 'm';
    char p[2];
    p[1] = 0;
    if (read(fd, p, 1) == -1) {
        std:: cout << "read1 error" << std:: endl;
        
    } else {
        std:: cout << "readed: " << p << std:: endl;
    }

    if (write(fd, &buf, 1) == -1) {
        std:: cout << "write error" << std:: endl;
        return 0;
    }

    off_t CurrentPosition = lseek(fd, 0, SEEK_CUR);
    if (CurrentPosition == -1) {
        std:: cout << "lseek1 error" << std:: endl;
    }
    std:: cout << "CurrentPosition: " << CurrentPosition << std:: endl;

    if (lseek(fd, 0, SEEK_SET) == -1) {
        std:: cout << "lseek2 error" << std:: endl;
        return 0;
    }

    if (read(fd, p, 1) == -1) {
        std:: cout << "read2 error" << std:: endl;
        
    } else {
        std:: cout << "readed: " << p << std:: endl;
    }

    off_t NewCurrentPosition = lseek(fd, 0, SEEK_CUR);
    if (NewCurrentPosition == -1) {
        std:: cout << "lseek3 error" << std:: endl;
        return 0;
    }
    std:: cout << "NewCurrentPosition: " << NewCurrentPosition << std:: endl;

    char buf1 = 'P';
    if (write(fd, &buf1, 1) == -1) {
        std:: cout << "write2 error" << std:: endl;
        return 0;
    }

    close(fd);
    return 0;
}