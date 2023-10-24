project(sotLibExample CXX)

##################################################
# Copied from tests/CMakeLists.txt, should be moved to a common file
# Find dependencies
find_package(Armadillo REQUIRED)
find_package(Threads REQUIRED)
find_package(BLAS REQUIRED)
message(STATUS "Found BLAS: " ${BLAS_LIBRARIES})
find_package(LAPACK REQUIRED)
message(STATUS "Found LAPACK: " ${LAPACK_LIBRARIES})

# Set the library and include directories
SET(libdirs ${ARMADILLO_SOURCE_DIR} ${BLAS_SOURCE_DIR} ${LAPACK_SOURCE_DIR})
SET(includes ${ARMADILLO_INCLUDE_DIRS} ${BLAS_INCLUDE_DIRS} ${LAPACK_INCLUDE_DIRS})
SET(libs ${ARMADILLO_LIBRARIES} ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
LINK_DIRECTORIES(${libdirs} ${libs})
include_directories(${includes} "../include")

# Enable C++11 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no \
        C++11 support. Please use a different C++ compiler.")
endif()


add_library(sotLib ../include/sot.h)
add_executable(example main.cpp)
set_target_properties(sotLib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(example PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(example sotLib)