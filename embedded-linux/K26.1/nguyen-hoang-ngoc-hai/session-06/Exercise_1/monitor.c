#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

static volatile sig_atomic_t running = 1;

void handle_sigterm(int sig) {
    (void)sig;
    running = 0;
}

int main(void) {
    setbuf(stdout, NULL);

    signal(SIGTERM, handle_sigterm);

    while (running) {
        printf("Monitor service is running... PID=%d\n", getpid());
        sleep(1);
    }

    printf("Service shutting down...\n");
    return 0;
}