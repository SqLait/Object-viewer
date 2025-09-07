cmake_minimum_required(VERSION 3.14)
project(ObjectViewer C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include headers from your own project
# include_directories(include)
# include_directories(vendor)
file(GLOB SOURCES "src/*.c" "impl/*.c")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wstrict-prototypes -Wall -Wno-sign-compare -Wpointer-arith -Wformat-security -Wswitch-enum -Wunused-parameter -Wstrict-aliasing -Wbad-function-cast -Wcast-align -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-field-initializers -Wno-override-init")

set(SOKOL_HEADERS
    vendor/sokol_gfx.h
    vendor/sokol_app.h)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/vendor)
target_link_libraries(main PRIVATE
    -lX11
    -lXi
    -lXcursor
    -lGL
    -lasound
    -ldl
    -lm
)

# Copy assets after build
# add_custom_command(TARGET main POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#             ${CMAKE_SOURCE_DIR}/assets
#             ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
# )

