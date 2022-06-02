#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <string.h>

int auth(char *login, int pass) {

  strcspn(login, "\n");
  login['\n'] = 0;
  if (strnlen(login) > 5)
  {
    if (ptrace() == -1)
    {
      puts(); //tampering detected
      return false;
    }
    // Calcul du password en fonction du login
    int true_pass = login;

    if (true_pass == pass)
      return true;
    else
      return false;
  }
}


int main() {
  char login[0x30 - 0x20] = { 0 };
  unsigned int password;

  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(login, 0x20,stdin);

  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  scanf("%u", &password);

  if (auth())
  {
    puts("Authenticated!");
    system("/bin/sh");
  }
  // __stack_chk_fail(); // canary protection
  return(0);
}
