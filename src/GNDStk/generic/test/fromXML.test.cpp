#include <istream>

#include "catch.hpp"

#include "GNDStk.hpp"

pugi::xml_document doc;
std::string testNode();
SCENARIO( "Converting from XML to generic::Node" ){
  auto sNode = testNode();
  std::istringstream iNode{ sNode };

  GIVEN( "a pugixml::node" ){

    auto pNode = pugi::xml_document::load_string( sNode.c_str() );
    
  } // GIVEN
} // SCENARIO

std::string testNode(){
  return R"xml(
<regions1d>
  <axes>
    <axis index="1" label="energy_in" unit="eV"/>
    <axis index="0" label="crossSection" unit="b"/>
  </axes>
  <XYs1d index="0">
    <values length="42">
      1.00000000e-05 0.000000e+00 2.53000000e-02 0.000000e+00 4.00000000e+05 0.000000e+00 4.01000000e+05 -1.660000e-03 4.50000000e+05 -1.660000e-03 4.51000000e+05 -1.720000e-03 5.00000000e+05 
    </values>
  </XYs1d>
  <XYs1d index="1">
    <values length="5376">
      8.80000000e+07 1.182806e+00 8.90000000e+07 1.171179e+00 9.00000000e+07 1.159459e+00 9.10000000e+07 1.146647e+00 9.20000000e+07 1.132441e+00 9.30000000e+07 1.117779e+00 9.40000000e+07 
    </values>
  </XYs1d>
  </regions1d>
                )xml";
}
