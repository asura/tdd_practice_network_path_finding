cmake_minimum_required(
  VERSION 3.10.0
)

#######################################
# プロジェクト設定
project(
  NetworkPathFinding
  VERSION 0.1.0
  LANGUAGES CXX
)

# C++規格
set(CMAKE_CXX_STANDARD 17)

# Debug or Release
if(CMAKE_BUILD_TYPE)
  if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
  else()
    message(FATAL_ERROR "変数CMAKE_BUILD_TYPEにはDebugかReleaseを指定してください")
  endif()
else()
  message(FATAL_ERROR "変数CMAKE_BUILD_TYPEが定義されていません")
endif()

# ビルドコマンドを出力 (要 CMake 2.8.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#######################################
# clang-tidyを実行させる (要 CMake 3.6)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--header-filter=${CMAKE_SOURCE_DIR}/include")

#######################################
# テスト関連
include(CTest)
enable_testing()

#######################################
# ビルド対象
add_subdirectory(third_party/catch2)
add_subdirectory(third_party/spdlog)
add_subdirectory(test)
