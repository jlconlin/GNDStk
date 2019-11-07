template< typename String >
auto& insert( String name ){
  Node_t::insert( name, Generic{ name } );
  return *this;
}
