#include "shortest_path.hpp"


virtual void shortest_path::execute(vertex* source_vertex)
{
}

virtual void shortest_path::execute(vertex* source_vertex, vertex* destination_vertex)
{
}


void shortest_path::set_path(std::vector<vertex*> vertices)
{
}

void shortest_path::set_distance(int dist)
{
}

std::vector<vertex*> shortest_path::get_path() const
{
	return m_path;
}

int shortest_path::get_distance() const
{
	return m_distance;
}


void shortest_path::dijkstra(vertex* source_vertex, vertex* destination_vertex)
{
	vertex* curr_vertex;
	std::queue<vertex*> que;
	que.push(source_vertex); 
	std::map<vertex*, int> v_map;

	while(!que.empty()){
		curr_vertex = que.front();
		que.pop();
		std::vector<edge*>::iterator it_begin
			= curr_vertex->get_edges()->begin();
		std::vector<edge*>::iterator it_end
			= curr_vertex->get_edges()->end();
		bool check = true;

		for(; it_begin != it_end; ++it_begin){
			check = short_path_to_map(it_begin, v_map, check);
			if(check == true){
				que.push((*it_begin)->get_destination_vertex());
			}
		}
	}

	//set_path(std::vector<vertex*>);
	//set_distance(int );

}

bool shortest_path::short_path_to_map(std::vector<edge*>::iterator it, std::map<vertex*,int>& v_map, bool check)
{
	int weight_path = v_map[(*it)->get_destination_vertex()];
	int new_weight_path =(*it)->get_weight() + v_map[(*it)->get_source_vertex()];

	if(weight_path == 0 || weight_path > new_weight_path){
		v_map[(*it)->get_destination_vertex()] = new_weight_path;
		return true;
	}
	return false;
}


shortest_path::shortest_path(graph* graph)
		:m_distance(0)
{
}
