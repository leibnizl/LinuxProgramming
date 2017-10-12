#include <iostream>
#include <fcntl.h>


int main() {
    int fd = open("a.txt", O_RDONLY);
    if (-1 == fd) {
        std:: cout << "open error" << std:: endl;
    }

    return 0;
}