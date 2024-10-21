#include <errno.h>
#include <internal/syscall.h>
#include <time.h>
#include <unistd.h>
unsigned int sleep(unsigned int sec) {
  struct timespec time_req;
  time_req.sec = sec;
  time_req.nsec = 0;
  nanosleep(&time_req, 0);
  return 0;
}
