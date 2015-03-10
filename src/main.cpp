#include <RcppArmadillo.h>
#include "testA.h"
#include "testB.h"

// [[Rcpp::export]]
double testfunction(const arma::colvec & x) {
    return testfunctionA(x) + testfunctionB(x);
}