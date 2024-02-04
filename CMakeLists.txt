cmake_minimum_required(VERSION 3.14)
project(imageland LANGUAGES C CXX)

add_executable(imageland
    src/main.cpp
)
target_compile_features(imageland PUBLIC cxx_std_20)
