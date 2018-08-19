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

To do 

## License

GPL (\>= 2)