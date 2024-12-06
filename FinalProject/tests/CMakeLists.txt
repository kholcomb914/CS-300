cmake_minimum_required(VERSION 3.20)

set(this Testing)

set(Sources
    testing.cpp
)

add_executable(${this} ${Sources})
target_link_libraries(${this} PUBLIC
    gtest_main
    Hamming
)

add_test(
    NAME ${this}
    COMMAND ${this}
)
