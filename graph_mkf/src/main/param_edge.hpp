#ifndef _PARAM_EDGE_HPP_
#define _PARAM_EDGE_HPP_

#include "base_edge.hpp"

/**
  * @brief
  * edge_decorator  class for weighted edges of graph  
  */
class param_edge: public base_edge 
{
private:
    /** Source vertex of edge */
    base_edge* m_edge;
public:
    /** Getting the weight of edge*/
    virtual int get_weight() = 0 ;
protected:
	//* Constructor */ 
	param_edge(base_edge* edge);
	
};
#endif  //_PARAM_EDGE_HPP_
