/*

Assignment: Implement a calculator interface/menu that can do

** sin, cos, tan, sqrt **

based on the previous assignment

Use ONLY pow() and fabs() from math.h.

Note 1: The use of absolute expressions creates a serious problem
The calculations of pow(x,n) and factorial(n) become large too fast
Even if they become small, their values are too large to be computed.
Note 2: Its better to use recursion. Module() helps to prevent large
values computed at once.
*/

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-3

float sin_calculator(float); //Calculates sin(x)
float cos_calculator(float); //Calculates cos(x)
float tan_calculator(float); //Calculates tan(x)
float sqrt_calculator(float); //Calculates sqrt(x)

void interface();

float module(float); //Calculates x mod (pi/2) in (0,pi)

int main(){
    printf("Scientific Calculator\n\n");
    //Interface
    char index = 0;
    int flag = 0;
    while(index!='q'){
    
        if(flag==0)
        {
            interface();
        }
        flag = 0;

        printf("Type the option: ");
        scanf(" %c",&index); //The space before the %c makes it consume an empty character!
        while ((getchar() != '\n')) {}; 

        float value;
        switch(index)
        {
            case '1': //sin
                printf("Type the value (in rad): ");
                scanf("%f",&value);
                printf("sin(%.2f) = %.2f\n\n",value,sin_calculator(value));
                break;
            case '2': //cos
                printf("Type the value (in rad): ");
                scanf("%f",&value);
                printf("cos(%.2f) = %.2f\n\n",value,cos_calculator(value));
                break; //Breaks the switch, not the while
            case '3': //tan
                printf("Type the value (in rad): ");
                scanf("%f",&value);
                printf("tan(%.2f) = %.2f\n\n",value,tan_calculator(value));
                break;
            case '4': //sqrt
                printf("Type the value: ");
                scanf("%f",&value);
                printf("sqrt(%.2f) = %.2f\n\n",value,sqrt_calculator(value));
                break;
            default:
                flag = 1;
                break;
        }
    }

    return 0;
}

void interface() {
    printf("\tPress '1' to use SINE\n");
    printf("\tPress '2' to use COSINE\n");
    printf("\tPress '3' to use TANGENT\n");
    printf("\tPress '4' to use SQUARE ROOT\n");
    printf("\tPress 'q' to exit\n");
    return;
};

float module(float angle){
    float UPPER = 3.141592; 
    float DOWN = 0;
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
    float x = oangle;
    int n = 1;
    while(fabs(x)>EPSILON)
    {
        //Beware when using the same value in recurrence
        sum += x;
        x *= (-1)*(oangle*oangle)/((2*n)*(2*n+1)); 
        n++;
    }
    return sum;
}

float cos_calculator(float angle){

    float sum = 0;
    float oangle = module(angle);
    float x = 1;
    int n = 1;
    while((fabs(x)>EPSILON))
    {
        //Beware when using the same value in recurrence
        sum += x;
        x *= (-1)*(oangle*oangle)/((2*n)*(2*n-1)); 
        n++;
    }
    return sum;
}

float tan_calculator(float angle){
    float oangle = module(angle);
    float s = sin_calculator(oangle);
    float c = cos_calculator(oangle);
    float ratio = s/c;
    if((fabs(c)<EPSILON)||isinf(ratio)){
        printf("\ntan: Error: cosine is too small\n");
        return 0;
    } else 
        return ratio;
}

float sqrt_calculator(float x){
    if(x<0){
        printf("sqrt: Error: value must be positive");
        return 0;
    }
    //Bissection method
    float est = 0;
    float UPPER = x;
    float DOWN = 0;
    while((fabs(x-(est*est)))>1e-3)
    {
        est = (UPPER + DOWN)/2.0;
        if(est*est > x)
        {
            UPPER = est;
            //printf("UPPER:%f,DOWN:%f,est:%f\n",UPPER,DOWN,est);
        } 
            else 
            {
                DOWN = est;
                //printf("UPPER:%f,DOWN:%f,est:%f\n",UPPER,DOWN,est);
            }
    }
    return est;
}