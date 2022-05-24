#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int nb;

  puts("***********************************");
  puts("*            -Level00 -           *");
  puts("***********************************");

  printf("Password:");
  scanf("%d", &nb);

  if (nb != 0x149c) // 5276
    puts("\nInvalid Password!");
  else {
    puts("\nAuthenticated!");
    system("/bin/sh");
  }

  return (0);
}
