// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
   window w( 1128, 164, 2 );
   /*
   line diagonal_line( w, 5, 5, 30, 40 );
   diagonal_line.print();

   rectangle box( w, 20, 10, 30, 20 );
   box.print();
*/
   filled_rectangle filled_box( w, 20, 10, 50, 50 );
   filled_box.print();

   filled_rectangle linned_box( w, 70, 10, 100, 50 );
   linned_box.printLinned();
   /*
   circle ball( w, 70, 30, 20 );
   ball.print();
   */
   return 0;
}
