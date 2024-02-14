include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # don't build the supplied example games
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED

if(NOT raylib_FOUND) # If there's none, fetch and build raylib
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)

    if(NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

set(CATCH_VERSION v3.5.2)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG ${CATCH_VERSION}
)

FetchContent_MakeAvailable(Catch2)

if(NOT DEFINED ASIO_CMAKE_ASIO_SOURCE_DIR)
  set(ASIO_CMAKE_ASIO_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
endif()

set(ASIO_CMAKE_ASIO_DEP_DIR "${ASIO_CMAKE_ASIO_SOURCE_DIR}/asio")

set(ASIO_CMAKE_ASIO_TAG asio-1-29-0)
find_package(asio QUIET) # QUIET or REQUIRED

if(NOT asio_FOUND) # If there's none, fetch and build asio
    FetchContent_Declare(asio
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG ${ASIO_CMAKE_ASIO_TAG}
        GIT_SHALLOW TRUE
        SOURCE_DIR ${ASIO_CMAKE_ASIO_DEP_DIR}
    )

    FetchContent_GetProperties(asio)

    if(NOT asio_POPULATED) # Have we downloaded asio yet?
        FetchContent_Populate(asio)
        message(STATUS "Populating asio ${ASIO_CMAKE_ASIO_TAG} done; src at ${asio_SOURCE_DIR}")
    endif()
endif()

add_library(asio INTERFACE)

target_include_directories(asio
    INTERFACE ${asio_SOURCE_DIR}/asio/include
)

target_compile_definitions(asio
    INTERFACE
    ASIO_STANDALONE
    ASIO_NO_DEPRECATED
)

if(UNIX)
    target_link_libraries(asio
        INTERFACE pthread
    )
elseif(WIN32)
    # macro see @ https://stackoverflow.com/a/40217291/1746503
    macro(get_WIN32_WINNT version)
        if(CMAKE_SYSTEM_VERSION)
            set(ver ${CMAKE_SYSTEM_VERSION})
            string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
            string(REGEX MATCH "^([0-9]+)" verMajor ${ver})

            # Check for Windows 10, b/c we'll need to convert to hex 'A'.
            if("${verMajor}" MATCHES "10")
                set(verMajor "A")
                string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
            endif("${verMajor}" MATCHES "10")

            # Remove all remaining '.' characters.
            string(REPLACE "." "" ver ${ver})

            # Prepend each digit with a zero.
            string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
            set(${version} "0x${ver}")
        endif(CMAKE_SYSTEM_VERSION)
    endmacro(get_WIN32_WINNT)

    if(NOT DEFINED _WIN32_WINNT)
        get_WIN32_WINNT(ver)
        set(_WIN32_WINNT ${ver})
    endif()

    message(STATUS "Set _WIN32_WINNET=${_WIN32_WINNT}")

    target_compile_definitions(asio
        INTERFACE
        _WIN32_WINNT=${_WIN32_WINNT}
        WIN32_LEAN_AND_MEAN
    )
endif()