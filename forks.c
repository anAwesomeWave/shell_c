#include "stdio.h"

#include<unistd.h> // for fork, exec
#include<sys/types.h>  // for clock_t (some basic derived types)
#include<sys/wait.h> // for wait

int main() {
    printf("hello\n");
    int process = fork();
    if(process < 0) {
        printf("An error occurred while creating a child process.");
        return -1;
    }
    if(process == 0) {
        printf("This is child process.\nMy PID is %d\n",  getpid()); // getpid return pid_t (int)
        printf("PID of parent - %d", getppid());
    }else{
        printf("This is parent. My PID is %d\n", getpid());
        printf("PID OF child process is %d\n", process);

    }
}
