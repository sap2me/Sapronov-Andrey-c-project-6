#include "spoly.h"
#include <stdio.h>


void func1(){
    printf("Input power-1 for the first polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);

    printf("\nInput power-1 for the second polinom m=");
    unsigned m;
    scanf("%u",&m);
    SPoly *arr2 =create(m);
    input(arr2);
    printf("\n");
    print(arr2);

    unsigned size;
    if(n>=m) size=n;
    if(m>n) size=m;
    SPoly *arr =create(size);
    arr=summary(arr1,arr2);
    printf("\n(");
    print(arr1);
    printf(")+(");
    print(arr2);
    printf(")=");
    print(arr);
    printf("\n");

}

void func2(){
    printf("Input power-1 for the first polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);

    printf("\nInput power-1 for the second polinom m=");
    unsigned m;
    scanf("%u",&m);
    SPoly *arr2 =create(m);
    input(arr2);
    printf("\n");
    print(arr2);

    unsigned size;
    if(n>=m) size=n;
    if(m>n) size=m;
    SPoly *arr =create(size);
    arr=subtraction(arr1,arr2);
    printf("\n(");
    print(arr1);
    printf(")-(");
    print(arr2);
    printf(")=");
    print(arr);
    printf("\n");
}

void func3(){
    printf("Input power-1 for the first polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);

    printf("\nInput power-1 for the second polinom m=");
    unsigned m;
    scanf("%u",&m);
    SPoly *arr2 =create(m);
    input(arr2);
    printf("\n");
    print(arr2);

    unsigned size;
    if(n==1&& m==1) size=1;
    if(m!=1 || n!=1) size=m*n-1;
    SPoly *arr =create(size);
    arr=multiply(arr1,arr2);
    printf("\n(");
    print(arr1);
    printf(")*(");
    print(arr2);
    printf(")=");
    print(arr);
    printf("\n");
}
void func4(){
    printf("Input power-1 for the first polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);

    printf("\nInput power-1 for the second polinom m=");
    unsigned m;
    scanf("%u",&m);
    SPoly *arr2 =create(m);
    input(arr2);
    printf("\n");
    print(arr2);

    unsigned size;
    if(n==1&& m==1) size=1;
    if(m!=1 || n!=1) size=n-m+1;
    SPoly *arr =create(size);
    arr=devide(arr1,arr2);

    SPoly* ost=create(n);
    ost=devide_ost(arr1,arr2);
    printf("\n(");
    print(arr1);
    printf(")/(");
    print(arr2);
    printf(")=(");
    print(arr);
    printf(")+(ost");
    print(ost);
    printf(")\n");
}

void func5(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);

    printf("\nInput const for the the integration polinom const=");
    double c;
    scanf("%lf",&c);

    unsigned size=n+1;

    SPoly *arr =create(size);
    arr=integration(arr1,c);
    printf("\nintegrate(");
    print(arr1);
    printf("+%.2lf",c);

    printf("=");
    print(arr);
    printf("\n");
}
void func6(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);
    printf("\nIntegral:");
    print(integration(arr1,0));
    printf("\nInput: a=");
    double a;
    scanf("%lf",&a);
    printf("\nInput: b=");
    double b;
    scanf("%lf",&b);



    double result=integration_value(arr1,a,b);

    printf("\nintegrate from a to b(");
    print(arr1);
    printf(")=");

    printf("%lf\n",result);


}

void func7(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);


    unsigned size=n-1;

    SPoly *arr =create(size);
    arr=derivative(arr1);
    printf("\n(");
    print(arr1);
    printf(")'=");
    print(arr);
    printf("\n");
}
void func8(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);


    unsigned size=n-1;

    SPoly *arr =create(size);
    arr=derivative(arr1);
    printf("\n(");
    print(arr1);
    printf(")'=");
    print(arr);
    printf("\n");
    printf("Input x=");
    double x;
    scanf("%lf",&x);

    double value=derivative_value(arr1,x);
    printf("Derivative in point=%lf\n",value);
}

void func9(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print(arr1);

    printf("\nInput x=");
    double x;
    scanf("%lf",&x);

    double value=value_in_point(arr1,x);
    printf("Value in point=%lf\n",value);
}

void func10(){
     printf("VEnter the polinom, if coeficient =0, input 0x^n:\n");
     printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input_str(arr1);
    print(arr1);
    printf("\n");

}

void func11(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input(arr1);
    printf("\n");
    print_file(arr1,"spoly_file.txt");
}

void func12(){
    printf("Input power-1 of polinom n=");
    unsigned n;
    scanf("%u",&n);
    SPoly *arr1 =create(n);
    input_file(arr1,"spoly_file.txt");
    print(arr1);
    printf("\n");


}
int main(){
    printf("Menu:\n1-Sum \n2-Substruction \n3-Multiply\n4-division\n5-integrate\n6-definit integrate\n7-derivative\n8-derivative in point\n9-value in point\n10-input polinom in a row\n11-print polinom in file\n12-input from file\n0-break\n");
int action;
    while(action>0){
        printf("Input number of action:");
    scanf("%d",&action);
    if(action==1) func1();
    if(action==2) func2();
    if(action==3) func3();
    if(action==4) func4();
    if(action==5) func5();
    if(action==6) func6();
    if(action==7) func7();
    if(action==8) func8();
    if(action==9) func9();
    if(action==10) func10();
    if(action==11) func11();
    if(action==12) func12();
    }
}
