# libunit
A custom C unit testing framework with comprehensive error detection and logging, developed as part of the 42 School curriculum.

## Overview
This project implements a complete unit testing framework for C programs. It provides robust test execution with fork-based isolation, signal handling, timeout detection, and detailed logging. The framework automatically detects various types of errors including segmentation faults, memory issues, and infinite loops.

## Features
### Core Functionality
- Fork-based test isolation prevents crashes from affecting other tests
- Comprehensive signal handling (SEGV, SIGBUS, SIGABRT, SIGFPE, SIGPIPE, SIGILL)
- Timeout detection for infinite loops and hanging tests
- Colorized output with clear status indicators
- Detailed error logging with diagnostic information

### Advanced Testing
- **Stdout Comparison**: Capture and validate function output
- **Memory Safety**: Detects segfaults, bus errors, and memory corruption
- **Process Management**: Proper cleanup and resource management
- **Exit Code Tracking**: Records and reports test exit codes
- **Signal Analysis**: Provides detailed signal information and debugging hints

### Logging & Reporting
- Individual test logs with failure analysis
- Aggregate statistics across all test suites
- Color-coded console output for immediate feedback
- Comprehensive error descriptions and debugging suggestions

## Project Structure
```
.
├── framework/                   # Core testing framework
│   ├── Makefile                 # Framework build configuration
│   ├── libunit.h                # Main header with API definitions
│   ├── colors.h                 # Color constants for output
│   ├── load_test.c              # Test registration system
│   ├── launch_tests.c           # Test execution engine
│   ├── compare_stdout.c         # Output comparison utilities
│   ├── utils_print.c            # Formatted output functions
│   ├── utils_counter.c          # Test statistics tracking
│   ├── utils_log.c              # File logging system
│   └── utils_signal.c           # Signal handling utilities
├── tests/                       # Framework validation tests
│   ├── dummy/                   # Error condition demonstrations
│   └── helper/                  # Error generation functions
└── real-tests/                  # Actual libft function tests
    ├── ft_isalpha/              # Character validation tests
    ├── ft_strlen/               # String length tests
    ├── ft_strcmp/               # String comparison tests
    └── ft_putnbr_fd/            # Number output tests
```

## Compilation
### Prerequisites
- GCC or compatible C compiler
- Make build system
- POSIX-compliant system (Linux/macOS)

### Build Commands
```bash
# Build framework library
cd framework && make

# Build and run validation tests
cd tests && make test

# Build and run real function tests
cd real-tests && make test

# Clean all builds
make fclean
```

## Usage
### Basic Test Creation
```c
#include "libunit.h"

int my_test_function(void)
{
    if (my_function() == expected_result)
        return (0);  // Success
    else
        return (-1); // Failure
}

int test_launcher(void)
{
    t_list *testlist = NULL;
    
    load_test(&testlist, "Test_Name", &my_test_function);
    return (launch_tests("my_function", testlist));
}
```

### Output Comparison Testing
```c
#include "libunit.h"

static void caller_function(void)
{
    my_print_function(42);  // Prints to stdout
}

int output_test(void)
{
    if (compare_stdout(caller_function, "42") == 0)
        return (0);  // Output matches
    else
        return (-1); // Output differs
}
```

## Test Results
### Status Indicators
- **[OK]**: Test passed successfully
- **[KO]**: Test failed (wrong return value or logic error)
- **[SEGV]**: Segmentation fault detected
- **[BUSE]**: Bus error (memory alignment issue)
- **[ABRT]**: Abort signal (assertion failure, double free)
- **[SFPE]**: Floating point exception (division by zero)
- **[PIPE]**: Broken pipe (write to closed descriptor)
- **[SILL]**: Illegal instruction
- **[TIMEOUT]**: Test exceeded time limit (infinite loop)

### Example Output
```bash
ft_strlen: Basic_Test: [OK]
ft_strlen: NULL_Test: [SEGV]
ft_strlen: Empty_Test: [OK]
ft_strlen: Whitespace_Test: [OK]
ft_strlen: 42Chars_Test: [OK]
4/5 tests passed
```

## Implementation Details
### Fork-Based Isolation
Each test runs in a separate child process, preventing crashes from affecting the test suite. Parent process monitors child exit status and signals.

### Signal Handling
Comprehensive signal detection with detailed error analysis:
- **SIGSEGV**: Null pointer dereference, buffer overflow
- **SIGBUS**: Unaligned memory access, hardware issues
- **SIGABRT**: Double free, assertion failures
- **SIGFPE**: Division by zero, invalid floating point operations

### Timeout Management
```c
// 10-second timeout per test (configurable)
#define TIMEOUT_PERIOD 10

signal(SIGALRM, timeout_handler);
alarm(TIMEOUT_PERIOD);
```

### Memory Management
- Automatic cleanup of test structures and linked lists
- Proper resource deallocation even on test failures
- No memory leaks in framework code

## Advanced Features
### Detailed Logging
Each test function generates a `.log` file with comprehensive failure analysis:
```
Function: ft_strlen
Passed: 4/5
Failed: 1 tests

NULL_Test: [SEGV]
    SIGNAL: SIGSEGV [11]
    EXIT_CODE: -
    ACTUAL: Invalid memory reference (segfault)
    [INFO] Check null pointers, array bounds, freed memory.
```

### Statistics Tracking
- Total test count across all suites
- Pass/fail ratios with aggregate reporting
- Final summary with celebration for perfect scores

### Stdout Redirection
Safe capture and comparison of function output without affecting test framework output.

## Error Detection Examples
```c
// Segmentation fault detection
int segv_test(void) { return ft_strlen(NULL) == 0 ? 0 : -1; }

// Timeout detection  
int timeout_test(void) { while(1); return 0; }

// Bus error detection (platform-specific)
int bus_test(void) { char arr[4]; *(int*)(arr+1) = 42; return 0; }
```

## Testing Philosophy
- **Isolation**: Each test runs independently
- **Safety**: Framework continues despite individual test crashes
- **Clarity**: Clear visual feedback and detailed error information
- **Completeness**: Tests all common error conditions

## Standards Compliance
- **42 Norm**: Follows strict coding standards (Norminette compliant)
- **POSIX**: Uses standard system calls and libraries
- **Memory Safety**: Zero memory leaks in framework code
- **Signal Safety**: Proper signal handling and cleanup

## Author
**nweber & nmihaile** - 42 Heilbronn Students
