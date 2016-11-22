#include "input_parser.hpp"
#include <stdlib.h>

graph* input_parser::create_graph(std::string &file_path)
{
	m_vertices_count = 0;
	graph* _graph = m_graphs[file_path];
	if(NULL == _graph) {
		_graph = new graph();
	} else {
		return _graph;
	}

	std::string line;
	std::stringstream buffer;
	read_file(file_path, buffer);
		std::cout << __LINE__ << std::endl;

//	if("" != buffer) {
		if(getline( buffer, line )) { 
		std::cout << __LINE__ << std::endl;
			std::istringstream iss(line);

			if(!init_parameter(line, _graph)) {
		std::cout << __LINE__ << std::endl;
				return NULL;
			}
		} else {
			std::cout << "buferr read exception" << std::endl;
			return NULL;
		}
		std::cout << __LINE__ << std::endl;
		if(parse_graph(buffer, _graph)) {
		std::cout << __LINE__ << std::endl;
			std::cout << m_vertices_count << "v count  " << std::endl;
			std::cout << _graph->get_vertices_count() << "get v count  " << std::endl;
			if( m_vertices_count != _graph->get_vertices_count()) {
				std::cout << "exception graph  creation count" << std::endl;
				return NULL; 
			}
		} else {
			std::cout << "exception graph  creation " << std::endl;
			return NULL;
		}

/*	} else {
		//genereta excp
		return NULL;
	}*/
}

void input_parser::read_file(const std::string& file_path, std::stringstream& buffer)
{
		std::cout << __LINE__ << std::endl;
	std::fstream input_file;
	input_file.open(file_path.c_str());
	if(input_file) {
		std::cout << __LINE__ << std::endl;
		buffer << input_file.rdbuf();
		input_file.close();
	} 
}

bool input_parser::init_parameter(std::string first_line, graph* _graph)
{
		std::cout << __LINE__ << std::endl;
	std::istringstream iss(first_line);
	std::string str_direction ;
	if(iss >> str_direction) {
		std::cout << __LINE__ << std::endl;
		if ( 0 == str_direction.compare("0") ) {
			_graph->set_direction(undirected);
		}
		else if	( 0 == str_direction.compare("1") ) {
			//int direction = atoi(str_directi on.c_str());
			_graph->set_direction(directed);
		} else {
			//TODO generate excp
			std::cout << "Incorrect input format, for directon set (1) or (0) " << std::endl;
			return false;
		}
	} else {
		return false;
	}
	std::string str_vertex_count ;
	if(iss >> str_vertex_count) {
		std::cout << __LINE__ << std::endl;
		int int_vertex_count;
		int_vertex_count = atoi(str_vertex_count.c_str());
		if(int_vertex_count > 1) {
			m_vertices_count = int_vertex_count;
		} else {
			//TODO generate excp   
			std::cout << "Incorrect input format, for count " << std::endl;
			return false;
		}
	} else {
		//TODO generate excp
		std::cout << "Incorrect input format, for count " << std::endl;
		return false;
	}
	std::string str_weight ;
	if(iss >> str_weight) {
		std::cout << __LINE__ << std::endl;
		if ( 0 == str_weight.compare("0") ) {
			_graph->set_edge_weight(weighted);
		}
		else if	( 0 == str_weight.compare("1") ) {
			_graph->set_edge_weight(unweighted);
		} else {
			//TODO generate excp
			std::cout << "Incorrect input format, for edge weight set (1) or (0) " << std::endl;
			return false;
		}
	} else {
		std::cout << "Incorrect input format, for edge weight set (1) or (0) " << std::endl;
		return false;
	}
	return true;
}		





bool input_parser::parse_graph(std::stringstream& buffer, graph* _graph)
{
		std::cout << __LINE__ << std::endl;
	std::string line;
	int weight = 0;
	int j;
	if(_graph->get_edge_weight() == weighted) {
		std::cout << __LINE__ << std::endl;
		j = 3;
	} else {
		std::cout << __LINE__ << std::endl;
		j = 2;
	}
	while(getline(buffer, line)) {
		std::cout << __LINE__ << std::endl;
		std::istringstream iss(line);
		std::string word;
		int i = 1 ;
		vertex* source = NULL; 
		vertex* destination = NULL;
		for( ;iss >> word ; ++i ) {
			if(i <= j){
				if(i == 1){
					source = _graph->add_vertex(word);
				}
				if(i == 2){
					destination = _graph->add_vertex(word);
				}

				if(i == 3){
					weight = atoi(word.c_str());
					if(weight < 1){
						//TODO excp
						std::cout << "enter weight positiv integer"	<< std::endl;
					}
				}
			} else break;


		}
		if(i < j || i > j){
			//TODO exp
			std::cout << "incorrect input, please input " << std::endl;
				return false;
		} else {
			if(j == 2){
				_graph->add_edge_for_vertices(source, destination);
			} else {
				_graph->add_edge_for_vertices(source, destination, weight);
			}
		}
	}
	return true;
}










