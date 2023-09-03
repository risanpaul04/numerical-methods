#include<stdio.h>

float trapezoidal(float h, int n, float arr[]){
    float add = 0;
    for(int i=1; i<n; i++){
        add += arr[i];
    }
    float res = h/2*(arr[0] + arr[n] + 2*add);
    return res;
}

float simpson_1_3rd(float h, int n, float arr[]){
    float add_odd = 0, add_even = 0;
    for(int i=1; i<n; i++){
       if(i%2!=0){
           add_odd += arr[i];
       }
       else{
           add_even += arr[i];
       }  
    }
    float res = h/3*(arr[0] + arr[n] + 4*add_odd + 2*add_even);
    return res;
}

float simpson_3_8th(float h, int n, float arr[]){
    float add_3x = 0, add_rest = 0;
    for(int i=1; i<n; i++){
        if(i%3==0){
            add_3x += arr[i]; //adds multiples of 3
        }
        else{
            add_rest += arr[i]; //adds rest of the y
        }
    }
    float res = 3*h/8 * (arr[0] + arr[n] + 3*add_rest + 2*add_3x);
    return res;
}

int main(){
    int i, n;
    float ul, ll;
    printf("Number of instances: ");
    scanf("%d", &n);
    printf("Upper limit & lower limit: ");
    scanf("%f %f", &ul, &ll);
    float arr_x[n+1], arr_y[n+1];
    float h = (ul -ll)/n;
    float x = 0.0;
    for(i=0; i<=n; i++){
        arr_x[i] = x;
        printf("x%d: %f\n", i, x);
        x = x + h;
    }
    printf("\n");

    // for(int i=0; i<=6; i++){
    //     printf("%f ", arr_x[i]);
    // }

    float y;
    for(i=0; i<=n; i++){
        arr_y[i] =1/(1+arr_x[i]*arr_x[i]);
    }
    printf("Value of All y: \n");
    for(i=0; i<=n; i++){
        printf("y%d: %f\n",i, arr_y[i]);
    }

    //Calculation of  the  integral using Trapezoidal method
    printf("\nResult using Trapezoidal method: %f\n", trapezoidal(h, n, arr_y));

    //Calculation of  the  integral using Simpson's one third method
    printf("\nResult using Simpson's one third rule: %f\n", simpson_1_3rd(h, n, arr_y));

    //Calculation of  the  integral using Simpson's 3 8th method
    printf("\nResult using Simpson's three eighth rule: %f\n", simpson_3_8th(h, n, arr_y));

    return 0;
}