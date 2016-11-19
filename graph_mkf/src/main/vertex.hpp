#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_
#include <vector>
#include <string>

class edge;

/** 
  * @brief
  * Class for all vertices
  */
class vertex
{
private:
    /** Vector of neighbour vertices edges, 
      * which shows destination for this vertex
      */
    std::vector<edge*> m_edges;
    std::string m_name;
	bool m_is_visited;
public:
    /** For adding edge in vertex */
    void add_edge(edge* vertex_edge);
    /** For getting edges of vertex */
	std::vector<edge*>* get_edges();
    /** For getting vertex degree */
    int get_degree() const;
    /** For getting vertex name */
    std::string get_name() const;
	void set_visited(const bool is_visited);
	bool get_visited() const;
public:
    /** Constructor */
    vertex(const std::string& name);
    /** Destructor */
    ~vertex();
};
#endif  //_VERTEX_HPP_
