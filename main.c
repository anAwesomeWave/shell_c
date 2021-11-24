#include <stdio.h>
#include <malloc.h>

char* read_line(int* len) { /* чтобы мы вне функции знали, какая длина у строки */
    int total_size = 1; /* will double size of array if *len >= size - 1(because of '/0' symbol)*/
    char* str = (char*)(malloc(sizeof(char))); /* FREE FREE FREE memory*/
    /*if(str == NULL) ... */
    printf("> ");
    char c = (char)getchar();
    while(c != '\n') { /* we don't need '\n' symbol itself */
        str[(*len) ++] = c; /*БЛЯТЬ НЕ *(len) ++  А (*len) ++ это же приоритетность*/
        if(*len == total_size) {
            total_size *= 2;
            str = (char *) realloc(str, total_size * sizeof(char)); /* FREE FREE FREE memory*/
        }
        c = (char)getchar();
    }
    str[*len] = '\0'; /* mb resize needed??*/
    return str; /* FREE FREE FREE memory*/
}



void run_loop() {
    char *line;
    char **args;
    int status = 0; /* DEBUG */

    do {
        int len = 0;
        line = read_line(&len);
        printf("%s", line);
        /*args = (split_line(line));
        status = (execute(args))*/
        free(line);
    }while(status);
}

int main(int argc, char** argv) { /* argv - array of strings.
                    lines are separated by spaces */
    run_loop();
    return 0;
}