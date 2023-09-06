cmake_minimum_required(VERSION 3.10)

project(ImageProcessingLibrary)

add_executable(app main.c)

# Include the API folder
add_subdirectory(API)

# Link the imported target to the app
target_link_libraries(app PRIVATE api_library)