cmake_minimum_required(VERSION 3.9)
project(Corewar)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -Werror -Wall")

file(GLOB LIBFT
        libft/srcs/*.c)

file(GLOB SRCS_ASM
        srcs_common/*.c
        srcs_asm/*.c
        includes/*.h)

file(GLOB SRCS_COR
        srcs_common/*.c
        srcs_corewar/*.c
        includes/*.h)

add_executable(asm ${SRCS_ASM} ${LIBFT})
add_executable(corewar ${SRCS_COR} ${LIBFT})