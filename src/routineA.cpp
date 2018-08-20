#include <Rcpp.h>
#include "routineA.h"

//' @rdname exported_funcs
//' @export
//' @examples
//' my_vecA = c(881, 884, 1,2,-4)
//' calc_A_routine(my_vecA)
// [[Rcpp::export]]
Rcpp::NumericVector calc_A_routine(Rcpp::NumericVector x) {
  Rcpp::NumericVector a = x - 4;
  return a;
}