/*Generates sequence in the child process*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  //checks if number was provided in command line
  if (argc == 2) {
    char *a = argv[1]; //gets argument from command line
    int num = atoi(a); //converts argument to number
    pid_t pid;
    pid = fork();

    //checks if argument is positive or not
    if (num >= 0) {
      //child process created
      if (pid == 0) {
        printf("%d\n", num);
        while (num > 1) {
          if (num % 2 == 0) {
            num = num / 2;
          }
          else {
            num = 3 * num + 1;
          } // end else
          printf("%d\n", num);
        } // end while
      } // end if
      //child process not created
      else if (pid == -1) {
        printf("Child process was not created.\n");
        exit(0);
      }
      //parent process
      else {
        printf("Parent is waiting on child\n");
        wait(NULL);
        printf("Complete\n");
      }
    } //end if
    else {
      printf("Integer must be positive.\n");
      exit(0);
    } //end else
  } //end if
   else {
     printf("Integer expected.\n");
     exit(0);
   } //end else

  return 0;
}
