#include <Rcpp.h>

// Load src/ directory header files
#include "routineA.h"
#include "routineB.h"

//' Package functions
//' 
//' Functions listed here are derived from the exported _C++_ functions.
//' Note that all functions work even after being split into multiple separate
//' files. 
//' 
//' @param x Vector of Numeric Values with length \eqn{n}.
//' 
//' @return A vector of numeric values with length \eqn{n}.
//' 
//' @rdname exported_funcs
//' @export
//' @examples
//' my_vec = c(3.5, 8, -1.5, -2, 0, 42)
//' calc_modifications(my_vec)
// [[Rcpp::export]]
Rcpp::NumericVector calc_modifications(Rcpp::NumericVector x) {
  
  // Calculate the modification from the A routine
  Rcpp::NumericVector A = calc_A_routine(x); 
  
  // Calculate the modification from the B routine
  Rcpp::NumericVector B = calc_B_routine(x); 
  
  // Calculate the element-wise total.
  Rcpp::NumericVector C = A + B;
  
  return C;
}
