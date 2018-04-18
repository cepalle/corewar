cmake_minimum_required(VERSION 3.9)
project(Corewar)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror -Wall")

file(GLOB_RECURSE LIBFT
        libft/srcs/*.c)

file(GLOB_RECURSE SRCS_ASM
        srcs_common/*.c
        srcs_asm/*.c
        includes/*.h)

file(GLOB_RECURSE SRCS_COR
        srcs_common/*.c
        srcs_corewar/*.c
        includes/*.h)

include_directories(includes)
include_directories(libft/includes)

add_executable(asm ${SRCS_ASM} ${LIBFT})
add_executable(corewar ${SRCS_COR} ${LIBFT})
