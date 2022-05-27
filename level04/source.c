#include <sys/types.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
  int wstatus = 0; // 0x20 - 0x1c => 4
  char s[0xa0 - 0x20] = { 0 };
  int a; // 0xa4 - 0xa0
  int b; // 0xa8 - 0xa4
  int c; // 0xac - 0xa8
  pid_t pid;

  if ((pid = fork()) == 0) {
    // Child process

    // #define PR_SET_PDEATHSIG  1  /* Second arg is a signal */
    // SIGHUP = 1 ? => Hangup
    prctl(1, 1);

    // PTRACE_TRACEME = 0,
    /* Indicate that the process making this request should be traced.
     All signals received by this process can be intercepted by its
     parent, and its parent can use the other `ptrace' requests.  */
    ptrace(0, 0, NULL, NULL);
    puts("Give me some shellcode, k");
    gets(s);
    return 0;
  }
  begin_wait:
  wait(&wstatus);

  a = b = wstatus;
  // SAR: signed division
  if (((a & 0x7f) == 0) || (((b & 0x7f) + 1) >> 1) != 0) {
    puts("child is exiting...");
    return 0;
  }

  // PTRACE_PEEKUSER = 3,
  /* Return the word in the process's user area at offset ADDR.  */
  c = ptrace(3, pid, 0x2c, 0);
  if (c != 0xb)
    goto begin_wait;

  puts("no exec() for you");
  kill(pid, 9);
  return (0);
}
