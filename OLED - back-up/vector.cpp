

hwlib::ostream & operator<<( hwlib::ostream & lhs, const vector & pos ){
   lhs << "(" << pos.x << "," << pos.y << ")";
   return lhs;
}