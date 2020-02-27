cmake_minimum_required(VERSION 3.8)
project (multithread)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) #aqui dizemos onde ficara o executável
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #útil pra YCM (youcompleteme)

link_libraries(pthread)
add_executable(multithread src/mthread.cpp)
#target_link_libraries(multithread pthread)



