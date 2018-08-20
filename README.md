## Separating Compiled Code into Individual Units with Headers

[![Travis-CI Build Status](https://travis-ci.org/r-pkg-examples/rcpp-headers-src.svg?branch=master)](https://travis-ci.org/r-pkg-examples/rcpp-headers-src)

The `SrcDir` R package provides an example of using header files to split 
apart functions into separate code files while still being able to use each
function.

In essence, this project shows how to go from:

```bash
src/
    |-> large-code-file.cpp
```

to: 

```bash
src/
    |-> combined-routines.cpp
    |-> routineA.cpp
    |-> routineA.h
    |-> routineB.cpp
    |-> routineB.h
```

For further organization, see the [SubdirSrc](https://github.com/r-pkg-examples/rcpp-headers-subdirs)
package for an example of compiling code found in `src/` subdirectories 
(e.g. `src/A`, `src/B`).

### Usage

To install the package, you must first have a compiler on your system that is 
compatible with R. For help on obtaining a compiler consult either
[macOS](http://thecoatlessprofessor.com/programming/r-compiler-tools-for-rcpp-on-os-x/)
or 
[Windows](http://thecoatlessprofessor.com/programming/rcpp/install-rtools-for-rcpp/)
guides.

With a compiler in hand, one can then install the package from GitHub by:

```r
# install.packages("devtools")
devtools::install_github("r-pkg-examples/rcpp-headers-src")
library("SrcDir")
```

### Implementation Details

Separating out code into different files requires the use of header files (`.h`).
Headers provide a way to share function definitions and preprocessor macros
between two or more _C++_ files (`.cpp`). Using the header inside of another
file requires the use of the `#include` 
[preprocessor directive](https://en.wikipedia.org/wiki/Preprocessor),
which effectively "copies" the contents of the header into the other file.

Take for instance the [`routineA.cpp`](https://github.com/r-pkg-examples/rcpp-headers-src/blob/master/src/routineA.cpp) file.

```cpp
#include <Rcpp.h>
#include "routineA.h"

// [[Rcpp::export]]
Rcpp::NumericVector calc_A_routine(Rcpp::NumericVector x) {
  Rcpp::NumericVector a = x - 4;
  return a;
}
```

Note, there are two different kinds of `#include` used: 

- `#include <header_system.h>`
    - `<>` indicate a system header file found in system directories or supplied with `-I`.
    - `Rcpp.h` is a system library as it is located outside of the project space.
- `#include "header_local.h"`
    - `""` means the file resides in the working directory of the program.

For more details, please see [Section 2.1 Include Syntax](https://gcc.gnu.org/onlinedocs/cpp/Include-Syntax.html#Include-Syntax)
of the [`gcc` documentation](https://gcc.gnu.org/onlinedocs/cpp/index.html#SEC_Contents).

The accompanying header file would be [`routineA.h`](https://github.com/r-pkg-examples/rcpp-headers-src/blob/master/src/routineA.h). The header would
contain the function definition for `calc_A_routine()` as it is the only
function declared within the file.

```cpp
// Defines a header file containing function signatures for functions in src/

// Protect signatures using an inclusion guard.
#ifndef routineA_H
#define routineA_H

Rcpp::NumericVector calc_A_routine(Rcpp::NumericVector x);

#endif
```

As the header contents is "copied", it is important to protect the function
definitions to ensure they are only included once. To prevent this from happening,
an [inclusion guard](https://en.wikipedia.org/wiki/Include_guard) is
used. By checking for whether a variable is defined with `#ifndef`, the header
file can be copied completely or skip the define portion. In short, the
design pattern for this can be succiently stated as:

```cpp
#ifndef myfilename_H
#define myfilename_H

// Contents here

#endif
```

From here, both routines A and B can be included inside a third file
such as [`combined-routines.cpp`](https://github.com/r-pkg-examples/rcpp-headers-src/blob/master/src/combined-routines.cpp). The inclusion statements would be:

```cpp
#include <Rcpp.h>

// Load directory header files
#include "routineA.h"
#include "routineB.h"

// additional code
```

## License

GPL (\>= 2)