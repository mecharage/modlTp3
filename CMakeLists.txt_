cmake_minimum_required(VERSION 3.0)
project(tp3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wfatal-errors -pedantic -fno-rtti")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")

include_directories(AFTER include)

file(GLOB_RECURSE H_FILES include/*.h)
file(GLOB_RECURSE CPP_FILES src/*.cpp)
file(GLOB_RECURSE TPP_FILES src/*.tpp)
set(SOURCE_FILES ${H_FILES} ${CPP_FILES} ${TPP_FILES})

add_executable(tp3 ${SOURCE_FILES})

target_link_libraries(tp3
)

#add_custom_target(
#	dataFiles ALL
#	${CMAKE_COMMAND} -E create_symlink "${CMAKE_SOURCE_DIR}/data" "${CMAKE_BINARY_DIR}/data"
#	COMMENT "Linking data directory"
#)
