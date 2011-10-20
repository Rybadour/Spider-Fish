cmake_minimum_required (VERSION 2.6)

project (SpiderFish CXX C)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "--std=c++0x")
endif()

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
src/ImageManager.cpp
src/PlayerShip.cpp
src/CollisionManager.cpp
src/ShipHalo.cpp
src/Bullet.h
src/Sprite.h
src/Sprite.cpp
src/PhysicalEntity.h
src/PhysicalEntity.cpp
src/SingleShooter.cpp
src/Game.h
src/EnemyData.h
src/GameObject.cpp
src/Weapon.cpp
src/EnemyData.cpp
src/GameObject.h
src/OrbBullet.h
src/SpiderFishGame.cpp
src/SingleShooter.h
src/ImageManager.h
src/PlayerShip.h
src/Bullet.cpp
src/OrbBullet.cpp
src/EnemyPeeShooter.h
src/Ship.h
src/EnemyPeeShooter.cpp
src/SpiderFish.h.in
src/main.cpp
src/Weapon.h
src/EnemyShip.h
src/CollisionManager.h
src/tags
src/EnemyShip.cpp
src/Ship.cpp
src/ShipHalo.h
  )

add_executable (spifi ${SPIFI_SOURCES})
target_link_libraries (
  spifi 
  ${SDL_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${SDLTTF_LIBRARY} 
  ${SDLIMAGE_LIBRARY}
)

