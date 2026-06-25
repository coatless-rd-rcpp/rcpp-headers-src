# Package functions

Functions listed here are derived from the exported *C++* functions.
Note that all functions work even after being split into multiple
separate files.

## Usage

``` r
calc_modifications(x)

calc_A_routine(x)

calc_B_routine(x)
```

## Arguments

- x:

  Vector of Numeric Values with length \\n\\.

## Value

A vector of numeric values with length \\n\\.

## Examples

``` r
my_vec = c(3.5, 8, -1.5, -2, 0, 42)
calc_modifications(my_vec)
#> [1]  5 14 -5 -6 -2 82
my_vecA = c(881, 884, 1,2,-4)
calc_A_routine(my_vecA)
#> [1] 877 880  -3  -2  -8
my_vecB = c(512,32, -1, 1.3, 5.9)
calc_B_routine(my_vecB)
#> [1] 514.0  34.0   1.0   3.3   7.9
```
