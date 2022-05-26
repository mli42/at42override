#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void decrypt(int nb) {
  int a, b;
  long int c;
  char *str = (char *)(int [4]){ 0x757c7d51, 0x67667360, 0x7b66737e, 0x33617c7d };

  b = 0;
  c = strlen((char *)str);

  while (0 < c) {
    str += b;
    str += b;
    b += 1;
  }

  if (strncmp("Congratulations!", str, 0x11) == 0)
    puts("\nInvalid Password");
  else
    system("/bin/sh");
}

void test(int a, int b) {
  unsigned long int sub = b - a;

  if (sub > 0x15) {
    decrypt(rand());
    return ;
  }
  else {
    void (*fct)() = (void (*)())((sub << 2) + 0x80489f0);

    fct();
    return ;
  }

  decrypt(sub); // 15 times
}

int main(void) {
  int a;
  int b;

  srand(time(NULL));
  puts("***********************************");
  puts("*\t\tlevel03\t\t**");
  puts("***********************************");

  printf("Password:");
  scanf("%d", &a);

  test(a, 0x1337d00d); // 322424845

  return 0;
}
