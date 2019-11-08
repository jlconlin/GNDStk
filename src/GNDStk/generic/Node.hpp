class Node: public knoop::Node< std::string >{
private:
  using Node_t = knoop::Node< std::string >;

public:
  #include "GNDStk/generic/Node/src/metadata.hpp"
  #include "GNDStk/generic/Node/src/insert.hpp"
  #include "GNDStk/generic/Node/src/ctor.hpp"

  using Node_t::insert;
};
