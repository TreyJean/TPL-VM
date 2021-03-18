#include "../include/util.h"

char* read_ascii_file(const char* path) {
    // Create file object
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Could not open file '%s'\n", path);
        return NULL;
    }

    // Get size of the file
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the file
    char* buff = (char*)malloc(sizeof(char) * (size * 1));
    if (!buff) {
        printf("Could not allocate memory for file!\n");
        return NULL;
    }
    fread(buff, 1, size, file);
    buff[size] = '\0';
    fclose(file);

    // Return contents
    return buff;
}