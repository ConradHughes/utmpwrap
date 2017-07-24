#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <utempter.h>
#include <wait.h>

int
main(int argc, char **argv)
{
  pid_t child;

  if(utempter_add_record(STDIN_FILENO, (char *) NULL) != 0)
    return EXIT_FAILURE;

  if((child = fork())) {
    if(child < 0)
      return EXIT_FAILURE;
    if(waitpid(child, (int *) NULL, 0) != child)
      return EXIT_FAILURE;
    if(utempter_remove_record(STDIN_FILENO) != 0)
      return EXIT_FAILURE;
    return EXIT_SUCCESS;
  }

  execv(argv[1], argv + 2);
  /*NOTREACHED*/
}
