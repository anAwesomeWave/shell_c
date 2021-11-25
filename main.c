#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* allocation_error() {
    printf("allocation error occurred");
    return NULL;
}

char* read_line(int* len) { /* чтобы мы вне функции знали, какая длина у строки */
    int total_size = 1; /* will double size of array if *len >= size - 1(because of '/0' symbol)*/
    char* str = (char*)(malloc(sizeof(char))); /* FREE FREE FREE memory*/
    if(str == NULL) {
        return allocation_error();
    }
    printf("> ");
    char c = (char)getchar();
    while(c != '\n') { /* we don't need '\n' symbol itself */
        str[(*len) ++] = c; /*БЛЯТЬ НЕ *(len) ++  А (*len) ++ это же приоритетность*/
        if(*len == total_size) {
            total_size *= 2;
            str = (char *) realloc(str, total_size * sizeof(char)); /* FREE FREE FREE memory*/
            if(str == NULL) {
                return allocation_error();
            }
        }
        c = (char)getchar();
    }
    str[*len] = '\0'; /* mb resize needed??*/
    return str; /* FREE FREE FREE memory*/
}

char** split_line(char* line) {
    /*will use strtok -> no need in length of line */
    /* для strtok нужны разделители, не содержащиеся в исходной строке*/
    char delim[] = " ";
    char** args = (char **) malloc(sizeof(char*)); /*one line */
    if(!args)
        return (char **) allocation_error();
    int argcnt = 0; /* number of lines in args */
    int sz = 1;
    char* newArg = strtok(line, " \t\r\n\v\f");
    while(newArg != NULL) {
        //args[argcnt] = (char*) malloc(sizeof(char) * strlen(newArg)); // allocate the necessary amount of bytes for
        // every char of new command
        args[argcnt ++] = newArg;
        printf("%s", args[argcnt-1]);
        if(argcnt == sz) {
            sz *= 2;
            args = (char**) realloc(args, sizeof(char*) * sz);
        }
        newArg = strtok(NULL, " \t\r\n\v\f"); // subcall
    }
    args[argcnt] = NULL; // end of sequence
    return args;
}


void run_loop() {
    char *line;
    char **args;
    int status = 0; /* DEBUG */

    do {
        int len = 0;
        line = read_line(&len);
        if(line == NULL) {
            return;
        }
        args = split_line(line);
        char* ptr = *args;
        while(ptr != NULL) {
            //printf("%s", ptr);
            ptr ++;
        }

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