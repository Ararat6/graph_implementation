#include "vertex_parser.hpp"
#include "flyweight.hpp"

void vertex_parser::create_graph(std::string file_path)
{
    flyweight* vertex_flyweight = new flyweight();
    std::string line;
    std::fstream input_file;
    input_file.open(file_path.c_str());
    
    if (input_file.is_open()) {
    
        while (getline( input_file, line )) {
            std::string vertex_name;
            int pos = 0;
            edge* current_edge = new edge();
    
            while ((pos = line.find(" ")) 
                    != std::string::npos) {
                vertex_name = line.substr(0, pos);
                line.erase(0, pos + 1);
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
