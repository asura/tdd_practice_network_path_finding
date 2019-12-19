#include "PathFinder.h"

PathFinder::PathFinder()
    : m_length(0)
{
}

void PathFinder::addEdge(
    const std::string& the_start_node,
    const std::string& the_end_node,
    int the_length)
{
    m_edges.emplace_back(the_start_node, the_end_node, the_length);
}

void PathFinder::findPath(
    const std::string& the_start_node_name,
    const std::string& the_end_node_name)
{
    m_path.clear();

    for (const auto& edge : m_edges)
    {
        if (edge.start_node() != the_start_node_name)
        {
            continue;
        }

        if (edge.end_node() != the_end_node_name)
        {
            continue;
        }

        m_length += edge.length();
        m_path.push_back(edge.start_node());
        m_path.push_back(edge.end_node());
    }
}

int PathFinder::length() const
{
    return m_length;
}

std::string PathFinder::path() const
{
    std::ostringstream oss;

    oss << "{";
    for (const auto& path : m_path)
    {
        oss << path;
    }
    oss << "}";

    return oss.str();
}
