# MIT License 
# Copyright (c) 2018-Today Michele Adduci <adduci@tutanota.com>
#
# Dependencies

# Required for Testing
if(BUILD_TESTING)
  find_package(catch2 REQUIRED)
endif()

# Optional Dependency, doesn't trigger error if missing
find_package(OpenSSL)
find_package(Catch2)
find_package(SDL2_ttf)
find_package(SDL2_image)
find_package(SDL2)
find_package(OpenAL)
find_package(asio)
find_package(CURL)
find_package(OpenSSL)
find_package(flatbuffers)
find_package(joltphysics)
find_package(box2d)
find_package(spdlog)
find_package(EASTL)
find_package(imguizmo)
find_package(imgui)
find_package(assimp)
find_package(flecs)