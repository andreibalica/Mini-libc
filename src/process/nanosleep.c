#include <errno.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <time.h>
#include <unistd.h>
int nanosleep(const struct timespec *t1, const struct timespec *t2) {
  int ret = syscall(__NR_nanosleep, t1, t2);
  if (ret < 0) {
    errno = -ret;
    return -1;
  }
  return ret;
}
