#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "vertex.hpp"
#include <string>
#include <vector>


/** Definition of types of graph */ 
enum direction { directed, undirected };


/**
  * @brief 
  * A singleton class to represent a graph. 
  * A graph is an vector of vertices.
  */ 
class graph 
{
private:
    /** Single object of graph type */
    ///FIXME static graph* instance;
private:
    /** Vector of all vertices */
    std::vector<vertex*>* m_vertices;
    /** Member for fix graph direction type */
    direction m_direction;
public:
    vertex* get_vertex_by_id(const std::string& name);
	std::vector<vertex*>* get_vertices() const;
	void set(vertex* _vertex);
    /** Function for get graph direction type */
    direction get_direction() const;
public:
    /** Static function for get single object of graph */
    ///FIXME static graph* get_instance();
public:
    /** For initialisation vertices's vector */
    ///FIXME void init_graph(const std::vector<vertex*>& vertices);
    /** For set graph's direction  */
    //void set_direction(const direction&);
private:
    /** Copy constructor */
    //graph(const graph&);
public:
    /** Constructor */
    graph(std::vector<vertex*>* vertices, direction graph_dir);
    /** Destructor */
    ~graph();    

};

#endif //_GRAPH_HPP_
