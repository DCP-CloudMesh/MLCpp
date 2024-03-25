/*
g++ -std=c++17 simpleMLmodel.cpp -o simpleMLmodel \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/armadillo-12.6.5/include \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/stb/include \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/ensmallen-2.21.1/include \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/cereal-1.3.0/include -I/usr/local/include/ \
    -w -framework Accelerate
*/
#include <mlpack/core.hpp>

using namespace mlpack;
using namespace std;

template<typename T>
arma::mat simpleAggregationModel(const T& arg) {
  return arg;
};

template<typename T, typename... Types>
arma::mat simpleAggregationModel(const T& firstArg, const Types&... arg) {
  return firstArg * simpleAggregationModel(arg...);
};

int main() {
  arma::mat matrixA, matrixB, matrixC, matrixD, result;
  data::Load("data/matrixA.csv", matrixA);
  data::Load("data/matrixB.csv", matrixB);
  data::Load("data/matrixC.csv", matrixC);
  data::Load("data/matrixD.csv", matrixD);

  // print all the matrices
  cout << "Matrix A: " << endl << matrixA << endl;
  cout << "Matrix B: " << endl << matrixB << endl;
  cout << "Matrix C: " << endl << matrixC << endl;
  cout << "Matrix D: " << endl << matrixD << endl;

  // Perform simple mm aggregation
  result = simpleAggregationModel(matrixA, matrixB, matrixC, matrixD);
  cout << "Result of matrix multiplication: " << endl;
  cout << result << endl;

  // Save the result to a file
  data::Save("result.csv", result);
  std::cout << "Matrix multiplication completed. Result saved to result.csv." << std::endl;

  // check if result is correct
  arma::mat expectedResult;
  data::Load("data/expectedResult.csv", expectedResult);
  cout << "Result match is " << (arma::approx_equal(result, expectedResult, "absdiff", 1e-5) ? "True" : "False") << endl;

  return 0;
}
