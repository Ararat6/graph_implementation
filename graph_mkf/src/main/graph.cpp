#include "graph.hpp"
#include <iostream>
#include <cassert>

// DEL ME graph* graph::instance = NULL;
direction graph::get_direction() const
{
    return m_direction;
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
