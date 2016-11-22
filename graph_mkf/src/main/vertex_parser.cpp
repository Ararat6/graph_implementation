#include "vertex_parser.hpp"
#include "flyweight.hpp"
#include "parser_exception.hpp"
#include <stdlib.h>
#include <sstream>

void vertex_parser::create_graph(std::string file_path)
{
    flyweight* vertex_flyweight = new flyweight();
    std::string line;
    std::fstream input_file;
    input_file.open(file_path.c_str());
   	//int direction = -1;

	//std::cout << "direction"  ;
    if(getline( input_file, line )) { 
		 std::istringstream iss(line);
		 std::string str_direction ;
		 iss >> str_direction;
		 if ( 0 == str_direction.compare("0") || 0 == str_direction.compare("1")) {
		 	//direction = atoi(str_direction.c_str());
			str_direction = "";
		    iss >> str_direction;
		 }
		
		// std::cout << "direction--" << direction << "\n";
		 //std::cout << "direction_str--" << str_direction.size() << "\n";
		 if(str_direction.size() > 0) {
			throw parser_exception("Incorrect input format");
		 }
 					 
	} else {
		throw parser_exception("Input file path incorrect");
	}

    if (input_file.is_open()) {
    
        while (getline( input_file, line )) {
            std::string vertex_name;
            int pos = 0;
            edge* current_edge = new edge();
    
           /* while ((pos = line.find(" ")) 
                    != std::string::npos) {
                vertex_name = line.substr(0, pos);
                line.erase(0, pos + 1);
                vertex* current_vertex = vertex_flyweight->get_vertex(vertex_name);
                add_vertex_to_edge(current_vertex, current_edge);
				if(current_vertex == current_edge->get_source_vertex()){
                	current_vertex->add_edge(current_edge);
				}
            }*/
    
			std::istringstream iss(line);
			std::string word;
			int i =0 ;
			for( ;iss >> word; ++i ) {
				vertex* current_vertex = vertex_flyweight->get_vertex(vertex_name);
				add_vertex_to_edge(current_vertex, current_edge);
				if(current_vertex == current_edge->get_source_vertex()){
					current_vertex->add_edge(current_edge);
				}
			}

            std::string edge_weight = line.substr(0, pos);
            current_edge->set_weight(edge_weight);
        }
        input_file.close();
    }
    set_vertices(vertex_flyweight->get_vertices());
}

void vertex_parser::add_vertex_to_edge(vertex* current_vertex, edge* current_edge)
{
    if (NULL == current_edge->get_source_vertex()) {
        current_edge->set_source_vertex(current_vertex);
    } else {
        current_edge->set_destination_vertex(current_vertex);
    }
}

void vertex_parser::set_vertices(std::vector<vertex*>* vertices)
{
    m_vertices = vertices;
}

std::vector<vertex*>* vertex_parser::get_vertices()
{
    return m_vertices;
}
vertex_parser::vertex_parser()
{
    m_vertices = new std::vector<vertex*>();
}
