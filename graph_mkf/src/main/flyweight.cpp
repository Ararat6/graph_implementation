#include "flyweight.hpp"
#include "vertex.hpp"

vertex* flyweight::get_vertex(const std::string& vertex_name)
{
    

    vertex* ver = m_vertices[vertex_name];
    if(NULL == ver) {
        ver = new vertex(vertex_name);
        m_vertices[vertex_name] = ver;
        m_vert_vector.push_back(ver);
    }
    return ver;
}

std::vector<vertex*>* flyweight::get_vertices()
{
    return &m_vert_vector;
}

