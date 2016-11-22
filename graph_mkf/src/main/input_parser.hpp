#ifndef _INPUT_PARSER_HPP_
#define _INPUT_PARSER_HPP_

#include "vertex.hpp"
#include "graph.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

class input_parser
{
private:
	int m_vertices_count;
    std::map <std::string , graph* > m_graphs;    
private:

	bool parse_graph(std::stringstream& buffer, graph* _graph);
	bool init_parameter(std::string first_line, graph* _graph);
	void read_file(const std::string& path, std::stringstream& buffer);
public:
    graph* create_graph(std::string& file_path);
};
#endif  //_INPUT_PARSER_HPP_
