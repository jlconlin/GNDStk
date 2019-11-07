class Node: public knoop::Node< std::string >{
private:
  using Node_t = knoop::Node< std::string >;

public:
  #include "GNDStk/generic/Node/src/ctor.hpp"
  #include "GNDStk/generic/Node/src/metadata.hpp"
  #include "GNDStk/generic/Node/src/insert.hpp"

  using Node_t::insert;
};
