cmake_minimum_required(VERSION 3.7)
project(Serveur C)

set(CMAKE_C_STANDARD 99)

add_executable(Serveur main.c init.c listbook.c listgenre.c tree.c)