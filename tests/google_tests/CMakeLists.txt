cmake_minimum_required(VERSION 3.0)
project(minishell C CXX)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS "../../srcs/**/*.c")
file(GLOB LIBFT "../../libft/**/*.c")
file(GLOB XSYSCALL "../../srcs/xsyscall/*.c")

include_directories("../../libft/includes")
include_directories("../../includes")

add_library(minishell
  STATIC
  ${SRCS}
  ${LIBFT}
  ${XSYSCALL}
)

add_executable(main
        main.cpp
        exec.cpp
        lexer.cpp
        )

add_definitions(-w)

target_link_libraries(main
    PRIVATE
    GTest::GTest
    GTest::Main
    minishell
)
