cmake_minimum_required( VERSION 3.4.3 )

project( PipeNetWork CXX )

# Directories to include header files from
include_directories( inc )
include_directories( external/catch )
include_directories( external/linalg/inc)


# Gather source files into CMake variables
file( GLOB SOURCE_FILES src/*.cpp)
file( GLOB TEST_FILES test/*.cpp)
file( GLOB HEADER_FILES inc/*.h* )

# This enables exporting all symbols to the dll on windows
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
if( CMAKE_COMPILER_IS_GNUCXX )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11 -Wall -Wextra" )
endif( CMAKE_COMPILER_IS_GNUCXX )

#-------------------Set up external linalg project----------------------
add_subdirectory( external/linalg)

# ----------------- Set up PipeNetWork library -------------------------

# Add library from the collected source files. The headers are given so visual studio displays them
add_library( pipenetwork SHARED ${SOURCE_FILES} ${HEADER_FILES} ) 

# specify the relative path the shared library object shall be installed to
if( WIN32 )
  install( TARGETS pipenetwork RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX} )
else( )
  install( TARGETS pipenetwork LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX} )
endif( )

target_link_libraries( pipenetwork linalg )

# ------------------- Set up unit tests ---------------------------

# Add an executable and link to the library
add_executable( pipenetwork_test ${TEST_FILES}  )

target_link_libraries( pipenetwork_test pipenetwork linalg )

# specify the relative path the testrunner shall be installed to
install( TARGETS pipenetwork_test RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX} )

# To be able to debug in Windows we have to copy the linalg library to the pipenetwork debug folder.
# This adds a post build command that after building pipenetwork_test copies linalg.dll over.
if( MSVC )
    add_custom_command(TARGET pipenetwork_test POST_BUILD        	
        COMMAND ${CMAKE_COMMAND} -E copy 					
            $<TARGET_FILE_DIR:linalg>/linalg.dll  
            $<TARGET_FILE_DIR:pipenetwork_test>)
endif( )

#--------------------Set up main drivers---------------------------
add_executable( main drivers/main.cpp ${HEADER_FILES} )
target_link_libraries( main pipenetwork linalg )