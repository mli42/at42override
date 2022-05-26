#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  int wstatus = 0; // 0x20 - 0x1c => 4
  char s[0xa0 - 0x20] = { 0 };
  int a; // 0xa4 - 0xa0
  int b; // 0xa8 - 0xa4
  int c; // 0xac - 0xa8
  pid_t pid;

  if ((pid = fork()) != 0) {
    return 0;
  }

  return (0);
}
