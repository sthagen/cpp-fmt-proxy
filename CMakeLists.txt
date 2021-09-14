cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# ---- Project ----

project(fmt_proxy LANGUAGES CXX)

option(FMT_EXAMPLES "whether or not to build the examples" ON)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

CPMAddPackage(
  NAME fmt
  GIT_TAG 7.1.3
  GITHUB_REPOSITORY fmtlib/fmt
)

CPMAddPackage(
  NAME doctest
  GITHUB_REPOSITORY sthagen/doctest
  GIT_TAG 2020.12
)

# ---- Create binary ----

add_executable(fmt_test main.cpp)
target_link_libraries(fmt_test doctest fmt)
set_target_properties(fmt_test PROPERTIES CXX_STANDARD 17)

# ---- Enable testing ----

enable_testing() 
add_test(fmt_test fmt_test)

# ---- Create the examples ----

message(STATUS "Note the fetched includes are taken from below: ${FETCHCONTENT_BASE_DIR}")
if (FMT_EXAMPLES)
    macro(fmt_examples EXAMPLENAME)
        add_executable(${EXAMPLENAME} ${ARGN})
        set_target_properties(${EXAMPLENAME} PROPERTIES FOLDER examples)
        set_target_properties(${EXAMPLENAME} PROPERTIES CXX_STANDARD 17)
        target_include_directories(${EXAMPLENAME} PUBLIC "${FETCHCONTENT_BASE_DIR}/fmt-src/include/")
        add_test(NAME ${EXAMPLENAME} COMMAND ${EXAMPLENAME})
    endmacro()
    add_subdirectory(examples)
endif()
