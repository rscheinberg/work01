#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	
	//direction check
	if(x0 > x1) {
		int temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	
	//determing the octant
	
	//slope
	float m;
	if(x1 - x0 == 0) m = 10000; //value greater than greatest possible slope based on screen size
	else m = (float)(y1 - y0)/(float)(x1 - x0);
	
	//octant1
	if(m >= 0 && m <= 1) {
		
		//define variables
		int a = y1 - y0;
		int b = -x1 + x0;
		int d = 2 * a + b;
		int x = x0;
		int y = y0;
		
		//based on psuedo code
		while(x <= x1) {
			plot(s, c, x, y);
			if(d > 0) {
				y++;
				d += 2 * b;
			}
			x++;
			d += 2 * a;
		}
	}
	
	//octant2
	else if(m > 1) {
			
		//define variables
		int a = y1 - y0;
		int b = -x1 + x0;
		int d = a + 2 * b;
		int x = x0;
		int y = y0;
		
		//based on psuedo code
		while(y <= y1) {
			plot(s, c, x, y);
			if(d < 0) {
				x++;
				d += 2 * a;
			}
			y++;
			d += 2 * b;
		}
	}
	
	//octant8 (whoops wrong order, should be after 7)
	else if(m < 0 && m >= -1) {
				
		//define variables
		int a = y1 - y0;
		int b = -x1 + x0;
		int d = 2 * a - b;
		int x = x0;
		int y = y0;
		
		//based on psuedo code
		while(x <= x1) {
			plot(s, c, x, y);
			if(d < 0) {
				y--;
				d -= 2 * b;
			}
			x++;
			d += 2 * a;
		}
	}
	
	//octant7
	else {
					
		//define variables
		int a = y1 - y0;
		int b = -x1 + x0;
		int d = a - 2 * b;
		int x = x0;
		int y = y0;
		
		//based on psuedo code
		while(y >= y1) {
			plot(s, c, x, y);
			if(d > 0) {
				x++;
				d += 2 * a;
			}
			y--;
			d -= 2 * b;
		}
	}
	
}
