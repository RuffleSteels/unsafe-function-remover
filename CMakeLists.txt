cmake_minimum_required(VERSION 3.30)
project(clang_execv_rewriter)

set(CMAKE_CXX_STANDARD 20)

# Path to your LLVM/Clang install
set(LLVM_DIR "C:/Program Files/LLVM/lib/cmake/llvm")
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Include directories and definitions
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Our executable
add_executable(clang_execv_rewriter main.cpp)

# On MSVC, increase object‐file section limits
if (MSVC)
    target_compile_options(clang_execv_rewriter PRIVATE /bigobj)
endif()

# Link against LLVM and Clang libraries
llvm_map_components_to_libnames(llvm_libs
        Support
        Core
        Option
)

target_link_libraries(clang_execv_rewriter
        PRIVATE
        clangTooling
        clangBasic
        clangASTMatchers
        clangRewrite
        ${llvm_libs}
)
