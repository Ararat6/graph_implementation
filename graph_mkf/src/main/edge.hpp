#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include <string>

class vertex;

/**
  * @brief
  * Edge class for information about edges of graph  
  */
class edge 
{
private:
    /** Weight of edge */
    int m_weight;
    /** Source vertex of edge */
    vertex* m_source_vertex;
    /** Destination vertex of edge*/
    vertex* m_destination_vertex;
public:
    /** Setting the weight of edge*/
    void set_weight(const std::string& weight);
    /** Getting the weight of edge*/
    int get_weight() const;
    /** Setting the source vertex of edge*/
    void set_source_vertex(vertex*);
    /** Getting the source vertex of edge*/
    vertex* get_source_vertex() const;
    /** Setting the destination vertex of edge*/
    void set_destination_vertex(vertex*);
    /** Getting the destination vertex of edge*/
    vertex* get_destination_vertex() const;
public:
    /** Constructor */
    edge();
    /** Destructor */
    ~edge();
};
#endif  //_EDGE_HPP_
