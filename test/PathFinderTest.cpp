#include "PathFinderTestsTexture.h"

#include <catch2/catch.hpp>

TEST_CASE_METHOD(
    PathFinderTestsTexture,
    "PathFinder成功ケース")
{
    // NOLINTNEXTLINE (google-build-using-namespace)
    const auto [test_case_name, graph, expected_length, expected_path] = GENERATE(
        table<std::string, std::string, int, std::string>(
            {{"エッジ1本のグラフ", "A1Z", 1, "{AZ}"},
             {"エッジ1本のグラフ(距離違い)", "A2Z", 2, "{AZ}"}}));

    INFO("test case : " << test_case_name);
    checkMinPath(graph, expected_length, expected_path);
}

TEST_CASE_METHOD(
    PathFinderTestsTexture,
    "PathFinder失敗ケース")
{
    // NOLINTNEXTLINE (google-build-using-namespace)
    const auto [test_case_name, graph, expected_length, expected_path] = GENERATE(
        table<std::string, std::string, int, std::string>(
            {{"空のグラフ", "", 0, "{}"},
             {"始点だけのグラフ", "A", 0, "{}"},
             {"始点も終点も含まないグラフ", "B1C", 0, "{}"},
             {"終点を含まないグラフ", "A1C", 0, "{}"},
             {"始点を含まないグラフ", "B1Z", 0, "{}"}}));

    INFO("test case : " << test_case_name);
    checkMinPath(graph, expected_length, expected_path);
}
