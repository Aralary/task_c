cmake_minimum_required(VERSION 3.0.0)
project(task1)

add_subdirectory(area_lib)

message("AREA_LIB_LIBRARIES = ${AREA_LIB_LIBRARIES}")
message("AREA_LIB_INCLUDE_DIRS = ${AREA_LIB_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} main.c)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
target_include_directories(${PROJECT_NAME} PUBLIC ${AREA_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${AREA_LIB_LIBRARIES})

add_subdirectory(Tests)