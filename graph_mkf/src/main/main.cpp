#include "graph.hpp"
#include "edge.hpp"
#include "vertex_parser.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>



int main()
{
    std::string file_path = "./graph.txt";
    vertex_parser parser;
    parser.create_graph(file_path);
    std::vector<vertex*>* vertices = parser.get_vertices();
    std::vector<vertex*>::iterator it = vertices->begin();
    std::vector<vertex*>::iterator end = vertices->end();

    graph* test_graph = new graph(vertices, undirected);
    std::cout << "test" << test_graph->get_direction() << "\n";
     

	for( ; it != end; ++it ){
		std::vector<edge*>::iterator _it = (*it)->get_edges()->begin();
		std::vector<edge*>::iterator _end = (*it)->get_edges()->end();
		std::cout<< "\n" << "---name vertex = " << (*it)->get_name() << "\n";
		for( ; _it != _end; ++_it){
			std::cout << "weight edge = " << (*_it)->get_weight() << "\n";
			std::cout << "source vertex = " << (*_it)->get_source_vertex()->get_name(); 
			std::cout << "destination vertex = " << (*_it)->get_destination_vertex()->get_name();
		}
	}

	/*
	algorithm* alg = new search(test_graph);
	alg -> dfs("v7");
	alg -> bfs("v7");
	alg = new shortest_path(test_graph);
	alg -> dijkstra(v1, v4)*/
		

    return 0;
}



