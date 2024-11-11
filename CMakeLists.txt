cmake_minimum_required(VERSION 3.5)

# Name the project
project(minefield)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include the wxWidgets use file
include(${wxWidgets_USE_FILE})

# Define the source files for the project
set(SRC_FILES
        main.cpp
        app/cApp.cpp
        main/cMain.cpp
)

# Define the build target for the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link the wxWidgets libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})