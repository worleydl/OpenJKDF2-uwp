set(SDL_MIXER_ROOT ${CMAKE_BINARY_DIR}/SDL_mixer)
set(SDL_ROOT ${CMAKE_BINARY_DIR}/SDL)
set(SDL2_INCLUDE_DIR ${CMAKE_BINARY_DIR}/SDL/include/SDL2)


ExternalProject_Add(
    SDL_mixer
    SOURCE_DIR          ${CMAKE_SOURCE_DIR}/lib/SDL_mixer
    BINARY_DIR          ${SDL_MIXER_ROOT}
    INSTALL_DIR         ${SDL_MIXER_ROOT}
    UPDATE_DISCONNECTED TRUE
    PATCH_COMMAND cd ${CMAKE_SOURCE_DIR}/lib/SDL_mixer && chmod +x ${CMAKE_SOURCE_DIR}/lib/SDL_mixer/external/download.sh && ${CMAKE_SOURCE_DIR}/lib/SDL_mixer/external/download.sh || true
    CMAKE_ARGS          --toolchain ${CMAKE_TOOLCHAIN_FILE}
                        --install-prefix ${SDL_MIXER_ROOT}
                        -DCMAKE_BUILD_TYPE:STRING=Release
                        -DBUILD_SHARED_LIBS:BOOL=FALSE
                        -DSDL2MIXER_MOD:BOOL=FALSE
                        -DSDL2MIXER_CMD:BOOL=FALSE
                        -DSDL2MIXER_MIDI:BOOL=FALSE
                        -DSDL2MIXER_DEPS_SHARED:BOOL=FALSE
                        -DSDL2MIXER_SAMPLES:BOOL=FALSE
                        -DSDL2MIXER_VENDORED:BOOL=TRUE
                        -DSDL2MIXER_FLAC:BOOL=FALSE
                        -DSDL2MIXER_OGG:BOOL=TRUE
                        -DSDL2MIXER_OPUS:BOOL=TRUE
                        -DSDL2MIXER_VORBIS:STRING=VORBISFILE
                        
    CMAKE_CACHE_ARGS
                        -DSDL2_DIR:STRING=${SDL_ROOT}/../
                        -DSDL_DIR:STRING=${SDL_ROOT}/../
                        -DSDL_INCLUDE_DIR:STRING=${SDL2_INCLUDE_DIR}
                        -DSDL2_INCLUDE_DIR:STRING=${SDL2_INCLUDE_DIR}
                        -DSDL2_LIBRARY:STRING=${SDL_LIBRARIES}

    DEPENDS             SDL::SDL
)
# *Replicate* variables generated by `FindSDL_mixer`
set(SDL_MIXER_FOUND TRUE)
set(SDL_MIXER_INCLUDE_DIRS ${SDL_MIXER_ROOT}/include/SDL2)
if(TARGET_WIN32)
    set(SDL_MIXER_LIBRARIES ${SDL_MIXER_ROOT}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}SDL2_mixer${CMAKE_STATIC_LIBRARY_SUFFIX})
else()
    set(SDL_MIXER_LIBRARIES ${SDL_MIXER_ROOT}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}SDL2_mixer${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()
set(SDL_MIXER_VERSION 2.6.3)
string(REGEX MATCH "^[0-9]+" SDL_MIXER_VERSION_MAJOR ${SDL_MIXER_VERSION})
string(REGEX REPLACE "^[0-9]+\\.([0-9]+).*" "\\1" SDL_MIXER_VERSION_MINOR ${SDL_MIXER_VERSION})
string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" SDL_MIXER_VERSION_PATCH ${SDL_MIXER_VERSION})
message(SDL_MIXER_VERSION_MAJOR\ ==\ ${SDL_MIXER_VERSION_MAJOR})
message(SDL_MIXER_VERSION_MINOR\ ==\ ${SDL_MIXER_VERSION_MINOR})
message(SDL_MIXER_VERSION_PATCH\ ==\ ${SDL_MIXER_VERSION_PATCH})
# *Replicate* SDL target
if(NOT TARGET SDL::Mixer)
    add_library(SDL::Mixer STATIC IMPORTED)
endif()
add_dependencies(SDL::Mixer SDL_mixer)
file(MAKE_DIRECTORY ${SDL_MIXER_INCLUDE_DIRS})
set_target_properties(
    SDL::Mixer PROPERTIES
    IMPORTED_LOCATION ${SDL_MIXER_LIBRARIES}
    IMPORTED_IMPLIB ${SDL_MIXER_LIBRARIES}
)
target_include_directories(SDL::Mixer INTERFACE ${SDL_MIXER_INCLUDE_DIRS})
target_link_directories(SDL::Mixer INTERFACE ${SDL_MIXER_ROOT}/lib)
