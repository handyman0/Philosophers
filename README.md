*This project has been created as part of the 42 curriculum by lmelo-do.*

# Philosophers

> I never thought philosophy would be so deadly

## Description

The Philosophers project is a multithreaded simulation of the classic "Dining Philosophers" problem. It demonstrates the fundamentals of concurrent programming, thread synchronization, and deadlock prevention using POSIX threads (pthreads) and mutexes.

### Problem Overview

One or more philosophers sit at a round table with a bowl of spaghetti in the middle. Each philosopher takes turns thinking, eating, and sleeping. Between each philosopher is a single fork. To eat, a philosopher must pick up both forks on either side. The challenge is to implement a solution where all philosophers can eat without causing a deadlock.

### Learning Objectives

- Understanding threads and multithreading concepts
- Working with mutexes for synchronization
- Managing shared resources in concurrent systems
- Preventing deadlock and data races

## Instructions

### Compilation

To compile the project, navigate to the `philo/` directory and run:

```bash
cd philo
make
```

**Compilation flags used:**
- `-Wall -Wextra -Werror` (strict compilation)
- `-pthread` (pthread library linking)

### Execution

Run the program with the following arguments:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

**Arguments:**
- `number_of_philosophers`: Number of philosophers (1-200)
- `time_to_die`: Time in milliseconds a philosopher can survive without eating
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher sleeps
- `number_of_times_each_philosopher_must_eat` (optional): If set, the simulation stops when all philosophers have eaten this many times

### Example

```bash
./philo 5 800 200 200
```

This simulates 5 philosophers with a death timer of 800ms, eating time of 200ms, and sleeping time of 200ms.

### Make Rules

- `make` or `make all`: Compile the program
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild the project from scratch
- `make pretty`: Compile with formatted debug output
- `make debug`: Compile with thread sanitizer for debugging

## Resources

### Documentation & References

- [POSIX Threads (pthreads)](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/pthread.h.html)
- [Mutexes and Synchronization](https://www.man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html)
- [The Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [gettimeofday documentation](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)

### AI Usage

AI tools were used to assist with:
- Code structure organization and best practices
- Understanding edge cases in thread synchronization
- Testing strategies and validation approaches
- Documentation and clarity of technical writing

No AI-generated code was directly copied into the project. All implementation was performed manually based on research and understanding of threading concepts.

---

**Author:** lmelo-do
