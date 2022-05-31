

int auth() {

  strcspn();
  strnlen();
  ptrace();
  puts();
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
