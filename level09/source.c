#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct huge_struct {
  char msg[140];
  char username[40];
  int size;
} huge_structure;

void secret_backdoor(void) {
  char cmd[0x80];

  fgets(cmd, 0x80, stdin);
  system(cmd);
}

void set_username(huge_structure *data) {
  int i;
  char username[128];

  bzero(username, 0x10 * 8); // == 128
  puts(">: Enter your username");


  printf(">>: ");
  fgets(username, 0x80, stdin);

  i = 0;
  while(i <= 0x28 || data->username[i] != '\0')
  {
    data->username[i] = username[i];
    i++;
  }
  printf(">: Welcome, %s", data->username);
}

void set_msg(huge_structure *data) {
  char password[0x400];

  bzero(password, 0x80 * 8); // == 0x400 == 1024
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(password, 0x400, stdin);
  strncpy(data->msg, password, data->size);
}

void handle_message(void) {
  huge_structure data;

  bzero(&data.username, 40);
  data.size = 0x8c;
  set_username(&data);
  set_msg(&data);
  puts(">: Msg sent!\n");
}

int main(void) {
  puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
  handle_message();
}
