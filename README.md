# Building the samples

## Sample 1

```shell
g++ -g -Wall -Wextra -Wpedantic -std=c++11 -o build/sample1 \
    src/sample1/main.cpp -lpthread
```

## Sample 2

```shell
g++ -g -Wall -Wextra -Wpedantic -std=c++11 -o build/sample2 \
    src/sample2/main.cpp -pthread
```

# References

- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
