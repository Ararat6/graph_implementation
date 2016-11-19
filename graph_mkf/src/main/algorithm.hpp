#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_
#include "vertex.hpp"
#include "edge.hpp"
#include "graph.hpp"

class algorithm
{
public:
	virtual void execute(vertex* source_vertex) = 0;
	virtual void execute(vertex* source_vertex, vertex* destination_vertex) = 0;
};
#endif //_ALGORITHM_HPP_
