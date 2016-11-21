#include "graph.hpp"
#include <iostream>
#include <cassert>

// DEL ME graph* graph::instance = NULL;
direction graph::get_direction() const
{
    return m_direction;
}

vertex* graph::get_vertex_by_id(const std::string& name) 
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

std::vector<vertex*>* graph::get_vertices() const
{
	return m_vertices;
}
void graph::set(vertex* _vertex)
{
	m_vertices->push_back(_vertex);
}

/* DEL ME
void graph::set_direction(const direction& dir)
{
    
}

graph* graph::get_instance()
{
         
    if(NULL == instance) {
       instance = new graph();
    }
    assert(NULL != instance); 
    return instance;
}
void init_graph(const std::vector<vertex*>& vertices)
{
}*/

graph::graph(std::vector<vertex*>* vertices, direction graph_dir)
            :m_vertices(vertices)
            ,m_direction(graph_dir)
{
}
graph::~graph()
{
}
