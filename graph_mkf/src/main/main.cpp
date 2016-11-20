#include "graph.hpp"
#include "edge.hpp"
#include "vertex_parser.hpp"
#include "algorithm.hpp"
#include "search.hpp"
#include "shortest_path.hpp"
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

    graph* test_graph = new graph(vertices, undirected);
    std::cout << "test" << test_graph->get_direction() << "\n";
     

    std::vector<vertex*>::iterator it = vertices->begin();
    std::vector<vertex*>::iterator end = vertices->end();
	for( ; it != end; ++it ){
		std::vector<edge*>::iterator _it = (*it)->get_edges()->begin();
		std::vector<edge*>::iterator _end = (*it)->get_edges()->end();
		std::cout<< "\n" << "---name vertex = " << (*it)->get_name();
		for( ; _it != _end; ++_it){
			std::cout << "\n	|s_vertex = " << (*_it)->get_source_vertex()->get_name() << "|"  
				  << "		|d_vertex = " << (*_it)->get_destination_vertex()->get_name() << "|"
				  << "		|weight edge = " << (*_it)->get_weight()  << "|";
		}
		std::cout << "\n\n";
	}


	/*algorithm* alg = new search(test_graph);
	alg -> DFS("v7");
	alg -> BFS("v7");
	algorithm* alg = new shortest_path(test_graph);
	alg -> dijkstra("v1", "v5");
	int dist = alg -> get_distance();
	std::cout << dist << std::endl;*/
		

    return 0;
}



