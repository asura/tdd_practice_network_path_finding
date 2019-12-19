#include "PathFinderTestsTexture.h"

#include <catch2/catch.hpp>
#include <regex>

void PathFinderTestsTexture::checkMinPath(
    const std::string& the_graph,
    const int the_expected_length,
    const std::string& the_expected_path)
{
    auto sut = createPathFinder(the_graph);

    sut.findPath("A", "Z");

    CHECK(sut.length() == the_expected_length);
    CHECK(sut.path() == the_expected_path);
}

PathFinder PathFinderTestsTexture::createPathFinder(const std::string& the_graph)
{
    PathFinder sut;

    const std::regex edge_pattern(R"((\D+)(\d+)(\D+))");
    std::smatch match;
    const bool match_success = std::regex_match(the_graph, match, edge_pattern);

    if (!match_success)
    {
        return sut;
    }

    REQUIRE(match.size() == 4);

    INFO("start="
         << match[1]
         << "end="
         << match[3]
         << "length="
         << match[2]);
    sut.addEdge(
        match[1],
        match[3],
        std::stoi(match[2]));

    return sut;
}
