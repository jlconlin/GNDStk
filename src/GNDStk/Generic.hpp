class Generic: public knoop::Node< std::string >{
private:
  using Node_t = knoop::Node< std::string >;

public:
  #include "GNDStk/Generic/src/ctor.hpp"
  #include "GNDStk/Generic/src/metadata.hpp"
  #include "GNDStk/Generic/src/insert.hpp"

  using Node_t::insert;
};

// #include "GNDStk/generic/src/getString.hpp"

