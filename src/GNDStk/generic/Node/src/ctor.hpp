template< typename String >
Node( String name ):
  Node_t( Node_t::makeMap() )
{ 
  this->insert( "name", Node_t{ name } );
  this->insert( "metadata", Node_t::makeMap() );
}

Node( pugi::xml_node xmlNode ):
  Node( xmlNode.name() )
{
  for( pugi::xml_attribute& attr : xmlNode.attributes() ) {
    this->metadata( attr.name(), attr.value() );
  }

  for( pugi::xml_node child: xmlNode.children() ) {
    this->insert( child.name(), Node( child ) );
  }
}
