

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>


int main() {

  uint64_t to_test = 0x1;
  unsigned int to_check;

  while(to_test != 0xffffffff)
  {
    while (to_test % 3 == 0 || ((to_test << 2) != 114 ))
      to_test++;
    to_check = to_test << 2;
    printf("%" PRIx64 " %u %u\n", to_test, to_check, to_test % 3); 
    to_test++;
  }
  printf("%p %u %d\n", to_test, to_check, to_test % 3); 
}
