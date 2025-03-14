
cmake_minimum_required(VERSION 3.10)
project(App)

# Specify source files
set(APP_SOURCES
    SandBox2D.cpp
    s_app.cpp
)

# Create the executable
add_executable(app ${APP_SOURCES})

# Link the Neko library to the app
target_link_libraries(app PRIVATE neko)

set_target_properties(app PROPERTIES
    #RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app  # For Release builds
    #RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app      # For Debug builds
    #INSTALL_RPATH "./lib/"
    #INSTALL_RPATH_USE_LINK_PATH TRUE
    BUILD_RPATH "./lib"
)
# Install the target
install(TARGETS app
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/Out/app
)# Specify the include directories for the app
target_include_directories(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../neko/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../neko/vendor/glm/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/../neko/vendor/imgui
)


# Copy the neko shared library to the engine folder after building
#add_custom_command(TARGET app POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:neko> ${CMAKE_CURRENT_SOURCE_DIR}/engine/
#    COMMENT "Copying neko library to engine folder"
#)
