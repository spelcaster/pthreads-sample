#include <pthread.h>
#include <errno.h>

#include <cstring>
#include <iostream>

const int kThreadsCoutner = 4;
const int kSize = 1000;
const int kExtraSize = 1000000;

pthread_attr_t attr;

void* do_something (void *thread_id)
{
  double data[kSize][kSize];
  size_t my_stack_size;

  long id = reinterpret_cast<long>(thread_id);
  pthread_attr_getstacksize(&attr, &my_stack_size);

  std::cout << "Thread #" << id << ": stack size = " << my_stack_size;
  std::cout << " bytes" << std::endl;

  for (int i = 0; i < kSize; i++)
    for (int j = 0; j < kSize; j++)
      data[i][j] = ((i * j) / 3.452) + (kSize - i);

  pthread_exit(NULL);
}

int main ()
{
  pthread_t threads[kThreadsCoutner];
  size_t stack_size;
  int status;

  pthread_attr_init(&attr);
  pthread_attr_getstacksize(&attr, &stack_size);

  std::cout << "Default stack size: " << stack_size << std::endl;

  stack_size = sizeof(double) * kSize * kSize + kExtraSize;

  std::cout << "Stack size needed per thread: " << stack_size << std::endl;

  // update stack size
  pthread_attr_setstacksize(&attr, stack_size);

  for (long i = 0; i < kThreadsCoutner; ++i) {
    status = pthread_create(
      &threads[i], &attr, do_something, reinterpret_cast<void*>(i)
    );

    if (status) {
      std::cout << strerror(status) << std::endl;
      return -1;
    }
  }

  pthread_exit(NULL);
  return 0;
}
