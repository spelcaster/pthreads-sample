#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <iostream>

const int kThreadsCounter = 5;
const int kTheAnswer = 42;

struct thread_data {
  int thread_id;
  int sum;
  char *message;
};

struct thread_data thread_data_arr[kThreadsCounter];

static char *messages[kThreadsCounter] = {
  "42 is",
  " the answer",
  "to life, ",
  " the universe ",
  "and everything"
};

void* show_data (void *thread_arg)
{
  struct thread_data *data = reinterpret_cast<struct thread_data*>(
    thread_arg
  );

  std::cout << data->thread_id << std::endl;
  std::cout << data->sum << std::endl;
  std::cout << data->message << std::endl;

  pthread_exit(NULL);
}

int main ()
{
  pthread_t threads[kThreadsCounter];
  int status;

  for (long i = 0; i < kThreadsCounter; i++) {
    thread_data_arr[i].thread_id = i;
    thread_data_arr[i].sum = i + kTheAnswer;
    thread_data_arr[i].message = messages[i];

    status = pthread_create(
      &threads[i], NULL, show_data, reinterpret_cast<void*>(&thread_data_arr[i])
    );

    if (status) {
      std::cout << strerror(status) << std::endl;
      return -1;
    }
  }

  pthread_exit(NULL);
  return 0;
}
