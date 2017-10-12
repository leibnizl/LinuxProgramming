#include <iostream>
#include <fcntl.h>
#include <errno.h>

int main() {
    int fd = open("a.txt", O_RDONLY);
    if (-1 == fd) {
        std:: cout << "open error" << std:: endl;
        std:: cout << "errno is " << errno << std:: endl;
        
    }
    return 0;
}