cmake_minimum_required (VERSION 2.6)

project (SpiderFish CXX C)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "--std=c++0x")
endif()

find_package (Boost REQUIRED)
include_directories (${Boost_INCLUDE_DIR})

find_package (SDL REQUIRED)
include_directories (${SDL_INCLUDE_DIR})

find_package (SDL_mixer REQUIRED)
include_directories (${SDLMIXER_INCLUDE_DIR})

find_package (SDL_ttf REQUIRED)
include_directories (${SDLTTF_INCLUDE_DIR})

find_package (SDL_image REQUIRED)
include_directories (${SDLIMAGE_INCLUDE_DIR})

set(RESOURCE_DIR "\"../resources/\"")
configure_file(${CMAKE_SOURCE_DIR}/src/SpiderFish.h.in ${CMAKE_SOURCE_DIR}/src/SpiderFish.h)

set (
  SPIFI_SOURCES
src/SpiderFishGame.h
src/Game.cpp
src/Util/ObjectPool.cpp
src/Util/Iterator2D.cpp
src/Util/Iterator2D.h
src/Util/any_iterator.hpp
src/Util/FauxContainer.h
src/Util/FauxContainer.cpp
src/Util/detail/any_iterator_metafunctions.hpp
src/Util/detail/any_iterator_abstract_base.hpp
src/Util/detail/any_iterator_wrapper.hpp
src/Util/ObjectPool.h
src/ImageManager.cpp
src/Sprite.h
src/Sprite.cpp
src/SpiderFish.h
src/Collision/CollisionSpace.cpp
src/Collision/PhysicalEntity.h
src/Collision/PhysicalEntity.cpp
src/Collision/BruteForceSpace.h
src/Collision/CollisionManger.cpp
src/Collision/BruteForceSpace.cpp
src/Collision/CollisionManager.h
src/Collision/CollisionSpace.h
src/Game.h
src/GameObject.cpp
src/GameObject.h
src/SpiderFishGame.cpp
src/ImageManager.h
src/Ship.h
src/main.cpp
src/Ship.cpp
  )

add_executable (spifi ${SPIFI_SOURCES})
target_link_libraries (
  spifi 
  ${SDL_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${SDLTTF_LIBRARY} 
  ${SDLIMAGE_LIBRARY}
  ${BOOST_LIBRARIES}
)

