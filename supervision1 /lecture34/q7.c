#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void) {
    long long count = 0;
    int fd = open("rockyou.txt", O_RDONLY);
    struct stat st;
    fstat(fd, &st);
    size_t filesize = st.st_size;
    char *region = (char *) mmap(
        NULL, filesize,
        PROT_READ, MAP_PRIVATE,
        fd, 0
    );
    
    if (region == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }
    for (size_t i = 0; i < filesize; i++) {
        count += (unsigned char) region[i];
    }
    printf("%lld\n", count);
    close(fd);
    return 0;
}
