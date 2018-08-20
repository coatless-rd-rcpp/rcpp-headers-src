#include <Rcpp.h>
#include "routineB.h"

//' @rdname exported_funcs
//' @export
//' @examples
//' my_vecB = c(512,32, -1, 1.3, 5.9)
//' calc_B_routine(my_vecB)
// [[Rcpp::export]]
Rcpp::NumericVector calc_B_routine(Rcpp::NumericVector x) {
  Rcpp::NumericVector b = x + 2;
  return b;
}
