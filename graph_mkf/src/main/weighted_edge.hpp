#ifndef _WEIGHTED_EDGE_HPP_
#define _WEIGHTED_EDGE_HPP_

#include "edge_decorator.hpp"

/**
  * @brief
  * edge_decorator abstract class for weighted edges of graph  
  */
class weighted_edge: public edge_decorator 
{
private:
    /** Edge weight */
    int m_weight;
public:
    /** Getting the weight of edge*/
    int get_weight() ;
public:
	//* Constructor */ 
	weighted_edge(base_edge* edge, const int weigth);
	//* Desstructor */ 
	~weighted_edge();
	
};
#endif  //_WEIGHTED_EDGE_HPP_