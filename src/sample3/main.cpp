#include <pthread.h>
#include <errno.h>

#include <cstring>
#include <cmath>
#include <iostream>

const int kThreadsCounter = 4;

void* do_something (void *t)
{
  double result = 0.0;

  long thread_id = reinterpret_cast<long>(t);

  std::cout << "Thread #" << thread_id << " starting..." << std::endl;

  for (int i = 0; i < 1000000; i++) {
    result = result + sin(i) * tan(i);
  }

  std::cout << "Thread #" << thread_id << " done.";
  std::cout << " Result = " << result << std::endl;

  pthread_exit(static_cast<void*>(t));
}

int main ()
{
  pthread_t threads[kThreadsCounter];
  pthread_attr_t attr;
  int status;

  void *data;

  // initialize thread attribute
  pthread_attr_init(&attr);

  // set thread detched attribute
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for (int i = 0; i < kThreadsCounter; i++) {
    std::cout << "Creating Thread #" << i << std::endl;

    status = pthread_create(
      &threads[i], NULL, do_something, reinterpret_cast<void*>(i)
    );

    if (status) {
      std::cout << strerror(status) << std::endl;
      return -1;
    }
  }

  // free attribute and wait for the other threads
  pthread_attr_destroy(&attr);

  for (int i = 0; i < kThreadsCounter; i++) {
    status = pthread_join(threads[i], &data);

    if (status) {
        std::cout << strerror(status) << std::endl;
        return -1;
    }

    std::cout << "Main: completed join with Thread #" << i;
    std::cout << " having a status of " << data << std::endl;
  }

  std::cout << "Main: program completed. Exitting." << std::endl;
  pthread_exit(NULL);
  return 0;
}
