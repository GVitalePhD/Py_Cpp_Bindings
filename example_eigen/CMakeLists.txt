cmake_minimum_required(VERSION 3.15)
project(eigenbind)

find_package(pybind11 REQUIRED)   # e.g. installed via pip install pybind11
find_package(Eigen3 REQUIRED NO_MODULE)

pybind11_add_module(eigenbind bindings.cpp)

target_link_libraries(eigenbind PRIVATE Eigen3::Eigen)
target_compile_features(eigenbind PRIVATE cxx_std_17)