cmake_minimum_required(VERSION 3.10)
project(Database)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../Debug)
#set (CMAKE_PREFIX_PATH "/home/pinje/Qt/5.11.0/gcc_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED COMPONENTS system)

SET(USER_MANAGEMENT_SRC
        Database/cpp/database.cpp
        Database/header/database.h
        utility/createfile.cpp
        )
SOURCE_GROUP(USER_MANAGEMENT FILES ${USER_MANAGEMENT_SRC})


IF(MSVC)
    # /FS is to use jom calling multiple cl threads
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG_INIT} -D_DEBUG -D_DRAWGI /Zi /W4 /FS")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE_INIT} -D_SECURE_SCL=0 /W4 /FS")
ELSE()
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG_INIT} -D_DEBUG -D_DRAWGI -Wno-deprecated-declarations")
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE_INIT} -D_SECURE_SCL=0 -Wno-deprecated-declarations")
ENDIF()

IF(MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_INIT} /ENTRY:mainCRTStartup")
ENDIF()

add_executable(${PROJECT_NAME} main.cpp ${USER_MANAGEMENT_SRC})
target_link_libraries(${PROJECT_NAME}  -lboost_system -lboost_filesystem)
target_link_libraries(${PROJECT_NAME}  -lsqlite3)






