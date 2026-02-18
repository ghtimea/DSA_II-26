cmake_minimum_required(VERSION 3.20)
project(DSA_II_26 C)

set(CMAKE_C_STANDARD 11)

# This creates a runnable target for Lab 1 Classwork
add_executable(lab1_classwork lab_1/classwork/main.c)

# This creates a runnable target for Lab 1 Homework
add_executable(lab1_homework lab_1/homework/main.c)

# You can add more as you go, for example:
# add_executable(lab2_classwork lab_2/classwork/main.c)