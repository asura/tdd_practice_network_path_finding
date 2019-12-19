include_directories(
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/third_party/catch2/single_include
  ${CMAKE_SOURCE_DIR}/third_party/spdlog/include
)

add_executable(
  Tester
  main.cpp
)

target_link_libraries(
  Tester
  Catch2::Catch2
  spdlog::spdlog
)

add_test(
  NAME Tester
  COMMAND Tester -r junit -o ${CMAKE_BINARY_DIR}/test_result_Tester.xml
)
