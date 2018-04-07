# Cmake file for linklist
cmake_minimum_required(VERSION 3.2)

set(linklist_filename singly_linklist.c)
add_executable(linklist
    linklist.c
    ${linklist_filename}
)

target_include_directories(linklist PRIVATE ./)
target_link_libraries(linklist PRIVATE dlt)

install(TARGETS linklist RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
