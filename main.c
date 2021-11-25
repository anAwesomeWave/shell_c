#include <stdio.h>
#include <string.h>
#include <malloc.h>


/*void free_mem(char** a, char*** b) {
    free(*a);
    char** ptr = *b;
    while(*ptr != NULL) {
        free(*ptr);
        ptr ++;
    }
    //free(*ptr);
    free(*b);
}*/

char* allocation_error() {
    printf("allocation error occurred");
    return NULL;
}

void* read_line(int* len) { /* чтобы мы вне функции знали, какая длина у строки */
    int total_size = 1; /* will double size of array if *len >= size - 1(because of '/0' symbol)*/
    char* str = (char*)(malloc(sizeof(char))); /* FREE FREE FREE memory*/
    if(str == NULL) {
        return (char*)allocation_error();
    }
    printf("> ");
    char c = (char)getchar();
    while(c != '\n') { /* we don't need '\n' symbol itself */
        str[(*len) ++] = c; /*БЛЯТЬ НЕ *(len) ++  А (*len) ++ это же приоритетность*/
        if(*len == total_size) {
            total_size *= 2;
            str = (char *) realloc(str, total_size * sizeof(char)); /* FREE FREE FREE memory*/
            if(str == NULL) {
                return (char*)allocation_error();
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
    char delim[] = " \t\r\n\v\f";
    char** args = (char **) malloc(sizeof(char*)); /*one line here we care only about memory for pointer
 *  this pointer can point at array of any size but we have to allocate memory for it
 *  it's similar to 2D vector
 * */
    if(!args)
        return (char **) allocation_error();
    int argcnt = 0; /* number of lines in args */
    int sz = 1;
    char* newArg = strtok(line, delim); // TODO: rewrite without strtok
    while(newArg != NULL) {
        args[argcnt ++] = newArg;
        if(argcnt == sz) {
            sz *= 2;
            args = (char**) realloc(args, sizeof(char*) * sz);
            if(args == NULL)
                return (char**) allocation_error();
        }
        newArg = strtok(NULL, delim); // subcall
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

        if(line == NULL)
            return;
        args = split_line(line);
        if(args == NULL)
            return;

        char** ptr = args; // BUG WAS HERE
        // char* ptr = *args;
        while(*ptr != NULL) {
            printf("%s\n", *ptr);
            ptr ++;
        }

        //free_mem(&line, &args);
        free(line);
        free(args); // memory leak may occur. check later with valgrind
        // TODO: check for memory leaking.
    }while(0);
}

int main(int argc, char** argv) { /* argv - array of strings.
                    lines are separated by spaces */
    run_loop();
    return 0;
}