/* -*- Mode: C; tab-width: 8; c-basic-offset: 2; indent-tabs-mode: nil; -*- */

#include "rrutil.h"

int main(void) {
  int fd = open("/dev/tty", O_RDWR);
  if (fd == -1 && errno == ENXIO) {
    atomic_puts("/dev/tty does not exist, skipping test");
    atomic_puts("EXIT-SUCCESS");
    return 0;
  }
  test_assert(fd >= 0);
  test_assert(13 == write(fd, "EXIT-SUCCESS\n", 13));
  return 0;
}
