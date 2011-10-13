cmake_minimum_required (VERSION 2.6)

# OSX stuff
If (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  # Force clang for Jeff
  INCLUDE (CMakeForceCompiler)
  CMAKE_FORCE_C_COMPILER(clang GNU)
  CMAKE_FORCE_CXX_COMPILER(clang++ GNU)
EndIf (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

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

FILE(GLOB_RECURSE SPIFI_SOURCES ../src/*.*)

Add_Executable (spifi ${SPIFI_SOURCES})
Target_Link_Libraries (
  spifi 
  ${SDL_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${SDLTTF_LIBRARY} 
  ${SDLIMAGE_LIBRARY}
  )

