# Distributed ML Cpp

Simple ML Models in Cpp

### Installation

0. Create a python venv

1. https://github.com/mlpack/mlpack/

```bash
git clone https://github.com/mlpack/mlpack.git
cd mlpack
cmake -S . -B build -DDOWNLOAD_DEPENDENCIES=ON
sudo cmake --build build --target install
```

2. (optional) https://www.boost.org/doc/libs/1_62_0/more/getting_started/unix-variants.html#errors-and-warnings

### Building of simpleMLmodel.cpp

Run a command like

```bash
g++ -std=c++17 simpleMLmodel.cpp -o simpleMLmodel \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/armadillo-12.6.5/include \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/stb/include \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/ensmallen-2.21.1/include \
    -I/Users/rayaq/Desktop/uWaterloo/FYDP/code/MLCpp/mlpack/build/deps/cereal-1.3.0/include -I/usr/local/include/ \
    -w -framework Accelerate
```
