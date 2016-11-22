#ifndef _BASE_EDGE_HPP_
#define _BASE_EDGE_HPP_

#include <iostream>

class vertex;

/**
  * @brief
  * base_edge abstract class for information about edges of graph  
  */
class base_edge 
{
private:
    /** Source vertex of edge */
    vertex* m_source_vertex;
    /** Destination vertex of edge*/
    vertex* m_destination_vertex;
public:
    /** Setting the weight of edge*/
    //void set_weight(const std::string& weight);
    /** Getting the weight of edge*/
    virtual int get_weight() = 0;
    /** Setting the source vertex of edge*/
    void set_source_vertex(vertex*);
    /** Getting the source vertex of edge*/
    vertex* get_source_vertex() const;
    /** Setting the destination vertex of edge*/
    void set_destination_vertex(vertex*);
    /** Getting the destination vertex of edge*/
    vertex* get_destination_vertex() const;
protected:
	base_edge();
};
#endif  //_BASE_EDGE_HPP_
