#include "graph.hpp"
#include <iostream>

vertex* graph::add_vertex(const std::string& name)
{
	vertex* _vertex = get_vertex_by_name(name);
	if(NULL == _vertex) {
		_vertex = new vertex(name);
		if(NULL != _vertex) {
			m_vertices->push_back(_vertex);
			return _vertex;
		} else {
			//TODO exception CANNOT create vertex
		}
	} else {
		return _vertex;
	}
}
vertex* graph::get_vertex_by_name(const std::string& name) 
{
    //size_t size = m_vertices->size(); 
    //std::cout << "graph size " <<size<<std::endl;
    std::vector<vertex*> ::iterator begin = m_vertices->begin();
    std::vector<vertex*> ::iterator end   = m_vertices->end();
    for(; begin != end; ++begin) {
        if( (*begin)->get_name().compare(name) == 0) {
            return *begin;
        }
    }
    return NULL;
}
void graph::add_edge_for_vertices(vertex* source, vertex* destination)
{
	base_edge* b_edge = new edge();
	b_edge->set_source_vertex(source);
	b_edge->set_destination_vertex(destination);
	source->add_edge(b_edge);
	if(get_direction() == undirected) {
		destination->add_edge(b_edge);
	}

}
void graph::add_edge_for_vertices(vertex* source, vertex* destination, int weight)
{
	base_edge* b_edge = new weighted_edge(new edge, weight);
	b_edge->set_source_vertex(source);
	b_edge->set_destination_vertex(destination);
	source->add_edge(b_edge);
	if(get_direction() == undirected) {
		destination->add_edge(b_edge);
	}

}
direction graph::get_direction() const
{
    return m_direction;
}
void graph::set_direction(direction dir)
{
	m_direction = dir;
}
edge_weight graph::get_edge_weight() const
{
	return m_edge_weight;
}
void graph::set_edge_weight(edge_weight weight)
{
	m_edge_weight = weight;
}
int graph::get_vertices_count() const
{
	return m_vertices->size();
}
graph::graph() 
{}

graph::~graph()
{}
