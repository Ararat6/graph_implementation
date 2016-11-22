#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include "base_edge.hpp"

/**
  * @brief
  * edge class implemented unweighted edge from base_edge abstract class 
  */
class edge: public base_edge
{
public:
	int get_weight();
public:
	/** Constructor */
	edge();
	/** Destructor */
	~edge();
};
#endif // _EDGE_HPP_
