cmake_minimum_required (VERSION 2.6)

# +----------------------------------+
# | Install additional CMake modules |
# +----------------------------------+

find_file(CMAKE_MODULES Modules
  HINTS
    ${CMAKE_ROOT}
    $ENV{CMAKE_ROOT}
)

Function (INSTALL_MODULE MODULE_NAME)
  If (NOT EXISTS "${CMAKE_MODULES}/${MODULE_NAME}.cmake")
    file(
    INSTALL "CMakeModules/${MODULE_NAME}.cmake"
    DESTINATION "${CMAKE_MODULES}"
    )
  EndIf (NOT EXISTS "${CMAKE_MODULES}/${MODULE_NAME}.cmake")
EndFunction (INSTALL_MODULE)

Function (CHECK_MODULE_INSTALL MODULE_NAME)
  If (NOT EXISTS "${CMAKE_MODULES}/${MODULE_NAME}.cmake")
    Message (SEND_ERROR "${MODULE_NAME} CMake module not installed.")
    Message (STATUS
"\n\n
+-------------------------------------------->
| ${MODULE_NAME} CMake module not installed.
| To resolve...
| Copy: CMakeModules/${MODULE_NAME}.cmake
| To directory: ${CMAKE_MODULES}
+-------------------------------------------->
\n"
    )
  EndIf (NOT EXISTS "${CMAKE_MODULES}/${MODULE_NAME}.cmake")
EndFunction (CHECK_MODULE_INSTALL)

INSTALL_MODULE ("FindPackageHandleStandardArgs")
CHECK_MODULE_INSTALL ("FindPackageHandleStandardArgs")

INSTALL_MODULE ("GTest")
CHECK_MODULE_INSTALL ("GTest")


Message (FATAL_ERROR "hahaha")

# +---------------+
# | CMake options |
# +---------------+

Option (FORCE_CLANG "Force CLang as compiler?")

If (FORCE_CLANG)
  Message (STATUS "Forcing CLang compiler.")
  INCLUDE (CMakeForceCompiler)
  CMAKE_FORCE_C_COMPILER(clang GNU)
  CMAKE_FORCE_CXX_COMPILER(clang++ GNU)
EndIf (FORCE_CLANG)

# +-------------------+
# | spifi binary      |
# +-------------------+

Project (SpiderFish CXX C)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

Find_Package (Boost REQUIRED)
If (NOT Boost_FOUND)
  Message (FATAL_ERROR "Couldn't find Boost.")
Else (NOT Boost_FOUND)
  Include_Directories (${Boost_INCLUDE_DIR})
EndIf (NOT Boost_FOUND)

Find_Package (SDL REQUIRED)
If (NOT SDL_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl1.2-dev' package.")
Else (NOT SDL_FOUND)
  Include_Directories (${SDL_INCLUDE_DIR})
EndIf (NOT SDL_FOUND)

Find_Package (SDL_mixer REQUIRED)
If (NOT SDLMIXER_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-mixer development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-mixer1.2-dev' package.")
Else (NOT SDLMIXER_FOUND)
  Include_Directories (${SDLMIXER_INCLUDE_DIR})
EndIf (NOT SDLMIXER_FOUND)

Find_Package (SDL_ttf REQUIRED)
If (NOT SDLTTF_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-ttf development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-ttf2.0-dev' package.")
Else (NOT SDLTTF_FOUND)
  Include_Directories (${SDLTTF_INCLUDE_DIR})
EndIf (NOT SDLTTF_FOUND)

Find_Package (SDL_image REQUIRED)
If (NOT SDLIMAGE_FOUND)
  Message (FATAL_ERROR "Couldn't find SDL-image development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-image1.2-dev' package.")
Else (NOT SDLIMAGE_FOUND)
  Include_Directories (${SDLIMAGE_INCLUDE_DIR})
EndIf (NOT SDLIMAGE_FOUND)

# Sources

FILE(GLOB_RECURSE SPIFI_SOURCES_2 ../src/*.h)
FILE(GLOB_RECURSE SPIFI_SOURCES_3 ../src/*.hpp)
FILE(GLOB_RECURSE SPIFI_SOURCES_1 ../src/*.cpp)

set (SPIFI_SOURCES ${SPIFI_SOURCES_1} ${SPIFI_SOURCES_2} ${SPIFI_SOURCES_3})

Add_Executable (spifi ${SPIFI_SOURCES})
Target_Link_Libraries (
  spifi 
  ${SDL_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${SDLTTF_LIBRARY} 
  ${SDLIMAGE_LIBRARY}
  ${Boost_LIBRARIES}
  )

  
# +------------------- +
# | spifi_test binary  |
# +--------------------+

Include (FindGTest)

set (SPIFI_TEST_GO OFF)

Find_Package(GTest REQUIRED)
If (NOT GTEST_FOUND)
  Message (WARNING "Couldn't find GTest.")
  Message (WARNING "Skipping generation of spifi_tests binary.")
Else (NOT GTEST_FOUND)
  Include_Directories(${GTEST_INCLUDE_DIRS})
  set (SPIFI_TEST_GO ON)
EndIF (NOT GTEST_FOUND)

If (SPIFI_TEST_GO)
  FILE(GLOB_RECURSE SPIFI_TEST_SOURCES ../test/*.*)
  Add_Executable(spifi_test ${SPIFI_TEST_SOURCES})
  target_link_libraries(spifi_test ${GTEST_BOTH_LIBRARIES})
EndIf (SPIFI_TEST_GO)






