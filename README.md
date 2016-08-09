# Building the samples

## Sample 1 - Simple pthreads example

```shell
g++ -g -Wall -Wextra -Wpedantic -std=c++11 -o build/sample1 \
    src/sample1/main.cpp -lpthread
```

## Sample 2 - Passing struct as an argument

```shell
g++ -g -Wall -Wextra -Wpedantic -std=c++11 -o build/sample2 \
    src/sample2/main.cpp -pthread
```

## Sample 3 - Pthread joining

```shell
g++ -g -Wall -Wextra -Wpedantic -std=c++11 -o build/sample3 \
    src/sample3/main.cpp -pthread
```

## Sample 4 - Stack Management

```shell
g++ -g -Wall -Wextra -Wpedantic -std=c++11 -o build/sample4 \
    src/sample4/main.cpp -pthread
```

# References

- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
