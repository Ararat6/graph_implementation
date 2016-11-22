#include "weighted_edge.hpp"

int weighted_edge::get_weight() 
{
	return m_weight;
}

weighted_edge::weighted_edge(base_edge* edge, const int weight):edge_decorator(edge)
															   ,m_weight(weight)
{}
	 
weighted_edge::~weighted_edge() {}