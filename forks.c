#include "stdio.h"

#include<unistd.h> // for fork, exec
#include<sys/types.h>  // for PID
#include<sys/wait.h> // for wait

int main() {
    printf("hello\n");
}
