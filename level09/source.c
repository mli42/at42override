#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct huge_struct {
  char msg[140];
  char username[40];
  int coucou;
} huge_structure;

void secret_backdoor(void) {
  char cmd[0x80];

  fgets(cmd, 0x80, stdin);
  system(cmd);
}

void set_username(huge_structure *structe) {
  int i;
  char username[128];

  bzero(username, 0x10 * 8); // == 128
  puts(">: Enter your username");


  printf(">>: ");
  fgets(username, 0x80, stdin);

  i = 0;
  while(i <= 0x28 || structe->username[i] != '\0')
  {
    structe->username[i] = username[i];
    i++;
  }
  printf(">: Welcome, %s", structe->username);
}

void set_msg(huge_structure *structe) {
  char password[0x400];

  bzero(password, 0x80 * 8); // == 0x400 == 1024
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(password, 0x400, stdin);
  strncpy(structe->msg, password, password[0xb4]);
}


void handle_message(void) {
  char buffer[0xc0 - 0xc];

  huge_structure structe;
  bzero(&structe.username, 40);
  set_username(&structe);
  set_msg(&structe);
  puts(">: Msg sent!\n");
}

int main(void) {
  puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
  handle_message();
}
