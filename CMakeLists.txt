# CMakeLists.txt
# Set the minimum requiered CMake version
cmake_minimum_required(VERSION 3.15)

# Set the project name
# and version MAJOR.MINOR.PATCH.TWEAK
project(GuessTheNumber VERSION 0.0.0.1)

# Options
set(MAX_TRIES 5)

# Configure files
configure_file(include/config.h.in config.h)

# Create the executable by giving it a name,
# and a list of source files
add_executable(gtn src/main.c)

# Find OpenSSL
FIND_LIBRARY(CRYPTO NAMES crypto libcrypto REQUIRED PATHS /usr/local/lib/libcrypto.dylib)
FIND_LIBRARY(OPENSSL NAMES openssl ssl libopenssl REQUIRED)
target_link_libraries(gtn ${CRYPTO} ${OPENSSL})

# Add include directories
target_include_directories(gtn PUBLIC ${CMAKE_CURRENT_BINARY_DIR} SYSTEM /usr/local/opt/openssl@1.1/include)