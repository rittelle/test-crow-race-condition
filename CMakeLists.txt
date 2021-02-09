cmake_minimum_required(VERSION 3.0)

project(crow-race-condition-test)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Boost 1.7 REQUIRED COMPONENTS system)

add_executable(bin main.cc)
target_link_libraries(bin Threads::Threads ZLIB::ZLIB Boost::system)

add_custom_target(run
    DEPENDS bin
    COMMAND $<TARGET_FILE:bin> 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running the server executable …"
    USES_TERMINAL
)

