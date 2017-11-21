#include "pipette.h"

int main(){
  pipe(d1);
  pipe(d2);
  f = fork();

  if ( f == 0 ){ //if child
    //write to first descriptor
    temp = 9;
    //close(d1[reed]);
    write(d1[rite], &temp, sizeof(temp));
    printf("[child] trying to do math on: %d\n", temp);

    read(d2[reed], &ans, sizeof(ans)); //wait and then read from child
    printf("[parent] received: %d\n", ans);
  }
  else {
    int status;
    close(d1[rite]);
    read(d1[reed], &ans, sizeof(ans));
    printf("[parent] sending 9\n");
    close(d2[reed]);
    ans = ans + 10 + 2;
    printf("What's 9 + 10?\n");
    write(d2[rite], &ans, sizeof(ans));
    wait(&status);
  }
  return 0;
}
