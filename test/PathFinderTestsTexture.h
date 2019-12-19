#ifndef PATHFINDERTESTSTEXTURE_H
#define PATHFINDERTESTSTEXTURE_H

#include "PathFinder.h"

#include <string>

class PathFinderTestsTexture
{
protected:
    void checkMinPath(
        const std::string& the_graph,
        const int the_expected_length,
        const std::string& the_expected_path);

private:
    /// グラフ文字列をもとにエッジを生成し、PathFinderに追加する
    PathFinder createPathFinder(const std::string& the_graph);
};

#endif  // PATHFINDERTESTSTEXTURE_H
