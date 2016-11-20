#include "shortest_path.hpp"


virtual void shortest_path::execute(vertex* source_vertex)
{
	
}

virtual void shortest_path::execute(vertex* source_vertex, vertex* destination_vertex)
{
}


void shortest_path::set_path(std::vector<vertex*> & vertices)
{
}

void shortest_path::set_distance(int dist)
{
	m_distance = dist;
	std::cout << dist << " " << __LINE__ << std::endl;
}

std::vector<vertex*> shortest_path::get_path() const
{
	return m_path;
}

int shortest_path::get_distance() const
{
	std::cout << m_distance << " " << __LINE__ << std::endl;
	return m_distance;
}


void shortest_path::dijkstra(const std::string &source, const std::string &destination)
{
	vertex* source_vertex = find_vertex(source);
	vertex* destination_vertex = find_vertex(destination);
	std::cout<< "source = " << 	source_vertex->get_name() <<"\n";//
	std::cout<< "destinatioan = " <<destination_vertex->get_name()<<"\n";//
	vertex* curr_vertex;
	std::queue<vertex*> que;
	que.push(source_vertex); 
	std::map<vertex*, int> v_map;

	while(!que.empty()){
		curr_vertex = que.front();
		std::cout<< "curr_vertex = " << curr_vertex->get_name() <<"\n";//
		que.pop();



		std::vector<edge*>::iterator it_begin	= curr_vertex->get_edges()->begin();
		std::vector<edge*>::iterator it_end	= curr_vertex->get_edges()->end();
		bool check = true;
		std::cout << __LINE__ << std::endl;//
		//std::cout<< "it_bergin = " << (*it_begin)->get_source_vertex()->get_name() <<"\n";//
		//std::cout<< "it_bergin = " << (*it_end)->get_destination_vertex()->get_name() <<"\n";//
		std::cout << __LINE__ << std::endl;//
		for(; it_begin != it_end; ++it_begin){
			std::cout << __LINE__ << std::endl;//
			std::cout<< "it_bergin = " << (*it_begin)->get_destination_vertex()->get_name() <<"\n";//
			check = short_path_to_map(it_begin, v_map, check);
			if(check == true){
				que.push((*it_begin)->get_destination_vertex());
			}
		}
	}

	std::cout << __LINE__ << std::endl;	
	/*
	std::map<vertex*, int>::iterator iit = v_map.begin();
	std::map<vertex*, int>::iterator eend = v_map.end();	
	for( ; iit != eend; ++iit)
		std::cout << v_map[*iit]<< std::endl;
	*/
	//set_path(v_map);
	set_distance(v_map[destination_vertex]);

}

bool shortest_path::short_path_to_map(std::vector<edge*>::iterator it, std::map<vertex*,int>& v_map, bool check)
{
	std::cout << __LINE__ << std::endl;
	int weight_path = v_map[ (*it) -> get_destination_vertex() ];
	int new_weight_path = (*it)->get_weight() + v_map[(*it)->get_source_vertex()];

	if(weight_path == 0 || weight_path > new_weight_path){
		v_map[(*it)->get_destination_vertex()] = new_weight_path;
		return true;
	}
	return false;
}

vertex* shortest_path::find_vertex(std::string target_vertex)
{
	flyweight* find_vertex = new flyweight();
	std::cout<< "target vertices = " << 	find_vertex->get_vertex(target_vertex)->get_name() <<"\n";
	return find_vertex->get_vertex(target_vertex);
}


shortest_path::shortest_path(graph* graph)
		:m_distance(0)
{
		_graph = graph;	
}
