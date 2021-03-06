#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Too Few Args!\n");

        return 1;
    } else if (strcmp(argv[1], "compile") == 0) {
        char* source = read_ascii_file(argv[2]);

        printf("%s\n", source);
        free(source);
    }

    return 0;
}