
#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;

pugi::xml_document doc;
std::string testNode();

SCENARIO( "Creating Node from XML" ){
  auto sNode = testNode();
  std::istringstream iNode{ sNode };

  GIVEN( "a pugixml::node" ){
    doc.load_string( sNode.c_str() );

    WHEN( "a generic Node is created" ){
      generic::Node gNode{ doc.child( "regions1d" ) };

    } // WHEN

  } // GIVEN
} // SCENARIO

/*
SCENARIO( "testing" ){
  doc.load_string( testNode().c_str( ) );
  auto regions1d = doc.child( "regions1d" );
  auto axes = regions1d.child( "axes" );

  for( const auto& child: axes.children() ){
    njoy::Log::info( "child: {}", child.name() );
  }
} // SCENARIO
 */

std::string testNode(){
  return R"xml(
<regions1d>
  <axes>
    <axis index="1" label="energy_in" unit="eV"/>
    <axis index="0" label="crossSection" unit="b"/>
  </axes>
  <XYs1d index="0">
    <values length="4">
      1.00000000e-05 0.500000e+00 2.53000000e-02 2.000000e+00 4.00000000e+05
    </values>
  </XYs1d>
  <XYs1d index="1">
    <values length="4">
      8.80000000e+07 1.182806e+00 8.90000000e+07 1.171179e+00
    </values>
  </XYs1d>
</regions1d>
                )xml";
}
