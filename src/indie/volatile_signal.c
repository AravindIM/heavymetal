#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t flag = 0;

void handler(int signum);

int main() {
  setbuf(stdout, NULL);
  signal(SIGINT, handler);

  printf("Waiting for Ctrl+C");

  while (!flag) {
    printf(".");
    sleep(1);
  }
  printf("\nSignal received. Exiting!\n");
}

void handler(int signum) { flag = 1; }