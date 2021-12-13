#include "stdio.h"

#include<unistd.h> // for fork, exec
#include<sys/types.h>  // for clock_t (some basic derived types)
#include<sys/wait.h> // for wait
#include<stdlib.h> // for exit()

int main() {
    printf("hello\n");
    int process = fork();
    if(process < 0) {
        printf("An error occurred while creating a child process.");
        return -1;
    }
    if(process == 0) {
        printf("This is child process.\nMy PID is %d\n",  getpid()); // getpid return pid_t (int)
        printf("PID of parent - %d\n", getppid());
        sleep(2);
        printf("PPID of orphan - %d\n(init process - parent of all processes. "
               "first process to start when a computer boots up and runs until the system shuts down.)", getppid());
        // after parent's process has finished running
    }else{
        sleep(1);
        printf("This is parent. My PID is %d\n", getpid());
        printf("PID OF child process is %d\n", process);
        exit(0);
    }
}
