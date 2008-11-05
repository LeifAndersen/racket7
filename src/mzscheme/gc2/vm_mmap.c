/* Provides: */
static void os_vm_free_pages(void *p, size_t len);
static void *os_vm_alloc_pages(size_t len);
static void protect_pages(void *p, size_t len, int writeable);
/* Requires: */
/* Optional:
      CHECK_USED_AGAINST_MAX(len)
      GCPRINT
      GCOUTF
      DONT_NEED_MAX_HEAP_SIZE --- to disable a provide
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>

#ifndef GCPRINT
# define GCPRINT fprintf
# define GCOUTF stderr
#endif
#ifndef CHECK_USED_AGAINST_MAX
# define CHECK_USED_AGAINST_MAX(x) /* empty */
#endif

static long page_size;
#ifndef MAP_ANON
static int fd;
static int fd_created;
#endif

static void os_vm_free_pages(void *p, size_t len)
{
  if (munmap(p, len)) {
    GCPRINT(GCOUTF, "Unmap warning: %lx, %ld, %d\n", (long)p, (long)len, errno);
  }
}

static void *os_vm_alloc_pages(size_t len)
{
  void *r;

#ifndef MAP_ANON
  if (!fd_created) {
    fd_created = 1;
    fd = open("/dev/zero", O_RDWR);
  }
#endif

  /* Round up to nearest page: */
  if (len & (page_size - 1))
    len += page_size - (len & (page_size - 1));

#ifdef MAP_ANON
  r = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
#else
  r = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
#endif

  if (r  == (void *)-1)
    return NULL;

  return r;
}


static void protect_pages(void *p, size_t len, int writeable)
{
  if (len & (page_size - 1)) {
    len += page_size - (len & (page_size - 1));
  }

  mprotect(p, len, (writeable ? (PROT_READ | PROT_WRITE) : PROT_READ));
}

#include "alloc_cache.c"
#include "rlimit_heapsize.c"
