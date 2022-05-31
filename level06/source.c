

int auth(login, pass) {

  strcspn(login, "\n");
  login['\n'] = 0;
  if (strnlen(login) > 5)
  {
  ptrace();
  puts();
  }
}


int main() {

  puts();   // ***********************************
  puts();  //         *		level06		  *
  puts();   
  printf("-> login: ");  //***********************************
  char *login = fgets(stdin);  //--> login
  puts();
  puts();
  puts();
              //  ***********************************
              //  ***** NEW ACCOUNT DETECTED ********
              //  ***********************************
  printf("-> Enter Serial: ");
  char *password = scanf(stdin);
  if (auth())
  {
    puts("authenticated ! ");
    system("/bin/sh");
  }
  else
    __stack_chk_fail();

  return(0);
}
