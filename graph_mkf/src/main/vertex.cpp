#include "vertex.hpp"
std::vector<edge*>* vertex::get_edges()
{
	return &m_edges;
}
void vertex::add_edge(edge* vertex_edge)
{
    m_edges.push_back(vertex_edge);
}
int vertex::get_degree() const
{
    return 0;
}
std::string vertex::get_name() const
{
    return m_name;
}
void vertex::set_visited(const bool is_visited)
{
	m_is_visited = is_visited;
}
bool vertex::get_visited() const
{
	return m_is_visited;
}
vertex::vertex(const std::string& name)
   // :m_name(name)
{
    m_name = name;
}
vertex::~vertex()
{
}
