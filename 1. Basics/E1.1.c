/*

Assignment: Calculate the sin of an value

1. Shift the value to the -pi/2 to pi/2 range
2. Use the Taylor Series 
3. Stop when the difference is less than epsilon (some small value) 

Use ONLY pow() and fabs() from math.h
*/

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-5

float sin_calculator(float); //Calculates sin(x)
int factorial(int); //Calculates n!
float module(float); //Calculates x mod (pi/2)

int main(){

    //Interface
    printf("Type the angle value (rad): ");
    float angle = 0;
    scanf("%f",&angle);

    float value = sin_calculator(angle);

    printf("The sin of %.2f is %.6f",angle,value);

    return 0;
}

float module(float angle){
    float UPPER = 1.570796; 
    float DOWN = -1.570796;
    float PI = 3.141592;
    float value = angle;
    if(value > UPPER){
        while(value > UPPER) {value -= PI;}
        return value;
    } 
    else if(value < DOWN) {
        while(value < DOWN) {value += PI;}
        return value;
    }
    return value;
};

float sin_calculator(float angle){
    
    float sum = 0;
    float oangle = module(angle);
    float x = 1;
    int n = 0;
    while(fabs(x)>EPSILON)
    {
        //Beware when using the same value in recurrence
        x = (pow(-1,n)*pow(oangle,2*n+1))
            /factorial(2*n+1); 
        sum += x;
        n++;
    }
    return sum;
}

int factorial(int n){
    int product = 1;
    int var = n;
    while(var>1){
        product *= var;
        var--;  
    }
    return product;
}
