#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("2.4.in", O_RDWR);
    if (fd == -1) {
        std:: cout << "open error" << std:: endl;
        return 0;
    }
    char buf = 'q';
    std:: cout << write(fd, &buf, 1) << std:: endl;
    return 0;
}