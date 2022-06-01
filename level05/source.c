#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  char *str = fgets(str, 0x64, stdin);

  for(int i = 0; str[i]; i++){
    str[i] = tolower(str[i]);
  }
  printf(str);
  exit(0);
}
