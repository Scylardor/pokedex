PROJECT(pokedex)

# Requirements part
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
FIND_PACKAGE(Qt4 COMPONENTS QtXml QtGui REQUIRED)

# Defining some useful variables here
FILE(GLOB PROJECT_SRCS "src/*.cpp")
FILE(GLOB PROJECT_HEADERS "inc/*.hh")

# For Qt
QT4_WRAP_CPP(helloworld_HEADERS_MOC ${PROJECT_HEADERS})

# Includes part
INCLUDE_DIRECTORIES("inc/")
INCLUDE(${QT_USE_FILE})

# Adds some flags to the compiler
ADD_DEFINITIONS(-Wall -Wextra ${QT_DEFINITIONS})

# Useful if you want to put the built binary elsewhere than in the 'build' directory
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

ADD_EXECUTABLE(pokedex ${PROJECT_SRCS} ${helloworld_HEADERS_MOC})
TARGET_LINK_LIBRARIES(pokedex ${QT_LIBRARIES})
