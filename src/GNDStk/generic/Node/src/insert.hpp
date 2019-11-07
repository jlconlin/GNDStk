template< typename String >
auto& insert( String name ){
  Node_t::insert( name, Node{ name } );
  return *this;
}
