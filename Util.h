#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024


int check_string(char buffer[BUFFER_SIZE], int size) {
    int bufferLen =(int)strlen(buffer) - size;
    (bufferLen <=0) ? bufferLen = 0:
    printf("Over the Maximum Size:\n");
    return bufferLen;
}
#endif /* _UTIL_H */
