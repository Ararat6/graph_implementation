#ifndef _SEARCH_HPP_
#define _SEARCH_HPP_
#include "algorithm.hpp"
#include "graph.hpp"


class search: public algorithm
{
public:
//      virtual void execute(vertex* source_vertex);
//      virtual void execute(vertex* source_vertex, vertex* destination_vertex);
public:
        void BFS(vertex* ver);
	void DFS(vertex* ver);
public:
        search(graph* graph);
};

#endif  //_SEARCH_HPP_

