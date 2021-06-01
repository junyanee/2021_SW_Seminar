#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileSize(FILE* fp);

int main(void)
{
    char* buffer;
    int size;

    FILE* fp = fopen("hello.txt", "r");

    if (fp == NULL)
        return 0;

    size = getFileSize(fp);
    buffer = malloc(size + 1);
    memset(buffer, 0, size + 1);

    fread(buffer, size, 1, fp);

    printf("%s\n", buffer);
    printf("buffer size: %d\n", size);

    fclose(fp);

    free(buffer);

    return 0;
}
int getFileSize(FILE* fp)
{
    int size;
    int currPos = ftell(fp);

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    fseek(fp, currPos, SEEK_SET);

    return size;
}