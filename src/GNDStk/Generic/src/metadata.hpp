const auto& metadata() const{
  return (*this)[ "metadata" ];
}

// template< typename String >
const auto& metadata( std::string key ) const{
  return (*this)[ "metadata" ][ key ].get< std::string >();
}

template< typename String1, typename String2 >
auto& metadata( String1 key, String2 value ){
  (*this)[ "metadata" ].insert( key, Node_t{ value } );
  return *this;
}
