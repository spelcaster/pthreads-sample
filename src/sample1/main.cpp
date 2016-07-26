#include <errno.h>
#include <pthread.h>
#include <string.h>
#include <iostream>

const int kThreadsCounter = 5;

void* say_hello (void *thread_id)
{
  long id = reinterpret_cast<long>(thread_id);
  std::cout << "Hi there, I'm the thread #" << id << std::endl;
  pthread_exit(NULL);
}

int main ()
{
  pthread_t threads[kThreadsCounter];
  int status;

  for (long i = 0; i < kThreadsCounter; i++) {
    std::cout << "In main: creating thread #" << i << std::endl;
    status = pthread_create(
      &threads[i], NULL, say_hello, reinterpret_cast<void *>(i)
    );

    if (status) {
        std::cout << strerror(status) << std::endl;
        return -1;
    }
  }

  pthread_exit(NULL);
  return 0;
}
