#include "edge.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

void edge::set_weight(const std::string& weight)
{
   // std::string::size_type sz; 
    m_weight = atoi(weight.c_str());
}
int edge::get_weight() const
{
    return m_weight;
}
void edge::set_source_vertex(vertex* source)
{
    m_source_vertex = source;
}
vertex* edge::get_source_vertex() const
{
    return m_source_vertex;
}
void edge::set_destination_vertex(vertex* dest)
{
    m_destination_vertex = dest;
}
vertex* edge::get_destination_vertex() const
{
    return m_destination_vertex;
}
edge::edge():m_weight(0)
			,m_source_vertex(NULL)
			,m_destination_vertex(NULL)
{
}
edge::~edge()
{
}
