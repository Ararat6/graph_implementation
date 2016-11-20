#ifndef _SHORTEST_PATH_HPP_
#define _SHORTEST_PATH_HPP_
#include "algorithm.hpp"
#include "flyweight.hpp"
#include "graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <map>


class shortest_path: public algorithm 
{

private:
	int m_distance;
	std::vector<vertex*> m_path;
	graph* _graph;

private:
	void set_path(std::vector<vertex*>& );
	void set_distance(int);
	vertex* find_vertex(std::string);
public:
	std::vector<vertex*> get_path() const;
	int get_distance() const;

public:
	virtual void execute(vertex* source_vertex);
	virtual void execute(vertex* source_vertex, vertex* destination_vertex);

public:
	void dijkstra(const std::string & source, const std::string & destination);
	bool short_path_to_map(std::vector<edge*>::iterator it, std::map<vertex*,int>& v_map, bool check);

public:
	shortest_path(graph* graph);



};


#endif //_SHORTEST_PATH_HPP_

