cmake_minimum_required(VERSION 3.8.0)

set (CMAKE_VERBOSE_MAKEFILE ON)

add_library(cpp
            SHARED
            ${NODE_MODULES_DIR}/react-native/ReactCommon/jsi/jsi/jsi.cpp
            ../cpp/react-native-jsi-module.cpp
            cpp-adapter.cpp
)

include_directories(
        ${NODE_MODULES_DIR}/react-native/React
        ${NODE_MODULES_DIR}/react-native/React/Base
        ${NODE_MODULES_DIR}/react-native/ReactCommon/jsi
        ../cpp
)

set_target_properties(
        cpp PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(
        cpp
        android
)
