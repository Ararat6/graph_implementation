#ifndef _VERTEX_PARSER_HPP_
#define _VERTEX_PARSER_HPP_

#include "vertex.hpp"
#include "edge.hpp"
#include <vector>
#include <fstream>
#include <iostream>

class vertex_parser
{
private:
    std::vector<vertex*>* m_vertices;    
    std::string m_path;
private:
    void add_vertex_to_edge(vertex* current_vertex, edge* current_edge);
    void set_vertices(std::vector<vertex*>* vertices);    
public:
    //constructor
    vertex_parser();
    std::vector<vertex*>* get_vertices();
    void create_graph(std::string file_path);
};
#endif  //_VERTEX_PARSER_HPP_
