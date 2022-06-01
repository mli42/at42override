#include <stdio.h>
#include <stdint.h>

// gcc -m32 poc.c

int main(void)
{
  int32_t victoire = 0xffffd8cf;
  int32_t to_win = 0;

  printf("AAAABBBB%55495x%1$hn%10032x%2$hn", &to_win, (char*)(&to_win) + 2);
  printf("\nto win = %p\n", to_win);

  if (to_win == victoire)
    printf("victoire\n");
}
