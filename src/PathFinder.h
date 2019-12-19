#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Edge.h"

#include <deque>
#include <sstream>
#include <string>

class PathFinder
{
    std::deque<Edge> m_edges;
    std::deque<std::string> m_path;
    int m_length;

public:
    PathFinder();

    void addEdge(
        const std::string& the_start_node,
        const std::string& the_end_node,
        int the_length);

    void findPath(
        const std::string& the_start_node_name,
        const std::string& the_end_node_name);

    int length() const;

    std::string path() const;
};

#endif  // PATHFINDER_H
