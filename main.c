#include <stdio.h>

char* read_line() {
}



void run_loop() {
    char *line;
    char **args;
    int status = 0; /* DEBUG */

    do {
        printf("> ");
        line = read_line();
        /*args = (split_line(line));
        status = (execute(args))*/

    }while(status);
}

int main(int argc, char** argv) {
    printf("Have %d arguments\n", argc);
    for(int i = 0; i < argc; i ++) {
        printf("%s\n", *(argv + i));
    }
    run_loop()
    return 0;
}