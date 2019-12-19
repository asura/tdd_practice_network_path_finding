#ifndef EDGE_H
#define EDGE_H

#include <string>

class Edge
{
    const std::string m_start_node;
    const std::string m_end_node;
    const int m_length;

public:
    Edge() = delete;

    Edge(const std::string& the_start_node, const std::string& the_end_node, int the_length)
        : m_start_node(the_start_node)
        , m_end_node(the_end_node)
        , m_length(the_length)
    {
    }

    const std::string& start_node() const { return m_start_node; }
    const std::string& end_node() const { return m_end_node; }
    int length() const { return m_length; }
};

#endif  // EDGE_H
