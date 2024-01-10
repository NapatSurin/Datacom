#include <stdio.h>

void explode(const char *input_str, char splitter) {
    int count = 0;
    while (*input_str != '\0') {
        char buffer[100];  
        int buffer_index = 0;
        while (*input_str != splitter && *input_str != '\0') {
            buffer[buffer_index] = *input_str;
            buffer_index++;
            input_str++;
        }
        buffer[buffer_index] = '\0';
        printf("str2[%d] = \"%s\"\n", count, buffer);
        count++;
        if (*input_str != '\0') {
            input_str++;
        }
    }
    printf("count = %d\n", count);
}

int main() {
    const char *str1 = "I/Love/You";
    char splitter = '/';
    explode(str1, splitter);
    return 0;
}
