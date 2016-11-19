#ifndef _FLYWEIGHT_HPP_
#define _FLYWEIGHT_HPP_
 
#include "vertex.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>

class flyweight
{
private:
    std::map<std::string,vertex*> m_vertices;
    std::vector<vertex*>  m_vert_vector;
public:
    std::vector<vertex*>* get_vertices();
    vertex* get_vertex(const std::string& vertex_name);
};
#endif //_FLYWEIGHT_HPP_
