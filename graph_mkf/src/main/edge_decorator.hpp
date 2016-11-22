#ifndef _EDGE_DECORATOR_HPP_
#define _EDGE_DECORATOR_HPP_

#include "base_edge.hpp"

/**
  * @brief
  * edge_decorator  class for weighted edges of graph  
  */
class edge_decorator: public base_edge 
{
private:
    /** Source vertex of edge */
    base_edge* m_edge;
public:
    /** Getting the weight of edge*/
    virtual int get_weight() = 0 ;
protected:
	//* Constructor */ 
	edge_decorator(base_edge* edge);
	
};
#endif  //_EDGE_DECORATOR_HPP_