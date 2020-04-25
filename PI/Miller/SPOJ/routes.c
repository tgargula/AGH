//https://pl.spoj.com/problems/HILLS2/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846 //coz spoj is stoopid and can't read M_PI from math orz

void distance(int n){
	double x, y;
	int angle;
	char command[8];
	int amount;
	for(int i=0; i<n; i++){
		scanf("%s", command);
		if(command[0] == 'P'){
			x = 0;
			y = 0;
			angle = 90;
			//printf("prep %lf%lf\n", x, y);
		}else if(command[0] == 'M'){ //MOVE
			scanf("%d", &amount);
			double converted_angle = (double)(angle) * (double)(M_PI) / (double)(180);
			x += (double)(amount) * cos(converted_angle);
			y += (double)(amount) * sin(converted_angle);
		}else{//TURN
			scanf("%d", &amount);
			angle += 360 + amount;
			angle %= 360;
		}
	}
	printf("%0.2f\n", sqrt(x*x + y*y));
}

int main(void){
	int t;
	scanf("%d", &t);
	int n;
	while(t--){
		scanf("%d", &n);
		distance(n);
	}
	return 0;
}	
