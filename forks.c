#include "stdio.h"

#include<unistd.h> // for fork, exec
#include<sys/types.h>  // for PID
#include<sys/wait.h> // for wait

int main() {
    printf("hello\n");
    int process = fork();
    if(process < 0) {
        printf("An error occurred while creating a child process.");
        return -1;
    }
    printf("123\n"); // call twice
}
