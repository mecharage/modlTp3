
PROJECT( Test_TP3 )

cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

include( gtest.cmake )

# -------------------------------------- #
#             TP3 CONFIGURATION          #
# -------------------------------------- #

message ( " ----  TP3 UNIT TESTS ---- " )

ExternalProject_Get_Property( googletest binary_dir )

link_directories( ${binary_dir} )
include_directories(AFTER include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wfatal-errors -pedantic -fno-rtti")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMKE_CXX_FLAGS_RELEASE} -DNDEBUG -O3")

# -------------------------------------------------- #
#     Source and header files                        #
# -------------------------------------------------- #

set( ZZ3-TP3_SOURCES
	src/Classe.cpp
	src/Echantillon.cpp
	src/Valeur.cpp
   )

set( ZZ3-TP3_HEADERS
     include/Classe.h
     include/Echantillon.h
     include/Histogramme.h
     include/Histogramme.tpp
     include/Valeur.h
   )

set( ZZ3-TP3_SOURCES_TEST
   )

set( ZZ3-TP3_HEADERS_TEST
     test/test_Echantillon.inl
     test/test_Histogramme.inl
   )

INCLUDE_DIRECTORIES( src/ )

# Add test executable target
ADD_EXECUTABLE( TP3
                src/main.cpp
                ${ZZ3-TP3_SOURCES}
                ${ZZ3-TP3_HEADERS}
              )

ADD_EXECUTABLE ( TP3_test
                 test/TP3_test.cpp
                 ${ZZ3-TP3_SOURCES}
                 ${ZZ3-TP3_HEADERS}
                 ${ZZ3-TP3_SOURCES_TEST}
                 ${ZZ3-TP3_HEADERS_TEST}
               )

SET_TARGET_PROPERTIES( TP3 PROPERTIES LINKER_LANGUAGE C )
SET_TARGET_PROPERTIES( TP3_test PROPERTIES LINKER_LANGUAGE C )

FIND_PACKAGE( Threads )
TARGET_LINK_LIBRARIES( TP3 ${CMAKE_THREAD_LIBS_INIT} )
TARGET_LINK_LIBRARIES( TP3_test ${CMAKE_THREAD_LIBS_INIT} )

# Create dependency of TP3_test on googletest
ADD_DEPENDENCIES( TP3_test googletest )

# Specify TP3_test's link libraries
IF ( WIN32 )
   TARGET_LINK_LIBRARIES( TP3_test
                          debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
                          optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
                        )
ELSE()
   TARGET_LINK_LIBRARIES(TP3_test gtest pthread)
ENDIF()
