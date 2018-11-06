cmake_minimum_required(VERSION 2.6)
project(DISC_ENGINE)

include_directories(
  src
  contrib
)

if (MSVC)
  include_directories(
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/openal-soft/include
    contrib/msvc-windows-x86/ogg/include
    contrib/msvc-windows-x86/vorbis/include
)

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/vorbis/lib
)

endif()

if (MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(Goldwell 
 src/Goldwell/main.cpp)

add_library(Disc_Engine
 src/Disc_Engine/Disc_Engine.h
 src/Disc_Engine/Core.h
 src/Disc_Engine/Entity.h
 src/Disc_Engine/Component.h
 src/Disc_Engine/VertexBuffer.h
 src/Disc_Engine/VertexArray.h

 src/Disc_Engine/Window.h 
 src/Disc_Engine/Exception.h

 src/Disc_Engine/MeshRenderer.h
 
 src/Disc_Engine/Resources.h
 src/Disc_Engine/Resource.h
 src/Disc_Engine/Mesh.h
 src/Disc_Engine/Texture.h
 src/Disc_Engine/Shader.h

 src/Disc_Engine/Core.cpp
 src/Disc_Engine/Entity.cpp
 src/Disc_Engine/Component.cpp
 src/Disc_Engine/VertexBuffer.cpp
 src/Disc_Engine/VertexArray.cpp

 src/Disc_Engine/Window.cpp
 src/Disc_Engine/Exception.cpp

 src/Disc_Engine/MeshRenderer.cpp

 src/Disc_Engine/Mesh.cpp
 src/Disc_Engine/Texture.cpp
 src/Disc_Engine/Shader.cpp
)

if(MSVC)
  target_link_libraries(Goldwell 
    SDL2 glew32 opengl32 OpenAL32 ogg vorbis vorbisfile Disc_Engine
  )
else()
  target_link_libraries(Goldwell
    SDL2 GLU GLEW GL AL ogg vorbis vorbisfile Disc_Engine
  )
endif()

target_link_libraries(Goldwell Disc_Engine)

if(MSVC)
  add_custom_command(TARGET Goldwell POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:Goldwell>"
  )
  add_custom_command(TARGET Goldwell POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:Goldwell>"
  )   
  add_custom_command(TARGET Goldwell POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:Goldwell>"
  )
endif()