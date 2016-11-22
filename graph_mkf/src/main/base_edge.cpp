#include "base_edge.hpp"

void base_edge::set_source_vertex(vertex* source)
{
    m_source_vertex = source;
}

vertex* base_edge::get_source_vertex() const
{
    return m_source_vertex;
}

void base_edge::set_destination_vertex(vertex* dest)
{
    m_destination_vertex = dest;
}

vertex* base_edge::get_destination_vertex() const
{
    return m_destination_vertex;
}

base_edge::base_edge():m_source_vertex(NULL)
		              ,m_destination_vertex(NULL)
{}
