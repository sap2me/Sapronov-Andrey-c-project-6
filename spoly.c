#include "spoly.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define OUT_OF_MEMORY_EXCEPTION 3
#define INDEX_OUT_OF_BOUNDS_EXCEPTION 4

SPoly* create(unsigned size) {
    SPoly *tmp = NULL;
    if (!(tmp = (SPoly*) malloc(sizeof(SPoly)))) {
        exit(OUT_OF_MEMORY_EXCEPTION);
    }
    if (!(tmp->data = (double*) malloc(size * sizeof(double)))) {
        exit(OUT_OF_MEMORY_EXCEPTION);
    }
    tmp->size = size;
    return tmp;
}

double get(SPoly* arr, int index) {
    if (index < 0) {
        unsigned realIndex = arr->size + index;
        if (realIndex < arr->size) {
            return arr->data[realIndex];
        } else {
            exit(INDEX_OUT_OF_BOUNDS_EXCEPTION);
        }
    } else {
        if (index < arr->size) {
            return arr->data[index];
        } else {
            exit(INDEX_OUT_OF_BOUNDS_EXCEPTION);
        }
    }
}
double set(SPoly* arr, int index, double value) {
    if (index < 0) {
        unsigned realIndex = arr->size + index;
        if (realIndex < arr->size) {
            return (arr->data[realIndex] = value);
        } else {
            exit(INDEX_OUT_OF_BOUNDS_EXCEPTION);
        }
    } else {
        if (index < arr->size) {
            return (arr->data[index] = value);
        } else {
            exit(INDEX_OUT_OF_BOUNDS_EXCEPTION);
        }
    }
}

void zeros(SPoly* arr) {
    unsigned i;
    for (i = 0; i < arr->size; i++) {
        arr->data[i] = 0;
    }
}
void input(SPoly* arr) {
    unsigned i;
    for (i = 0; i < arr->size; i++) {
            printf("Input koeficient near x^%d:",i);
            double k;
            scanf("%lf",&k);

    arr->data[i] = k;
    }
}

void input_str(SPoly* arr){
    char my_string[100];
    printf("Input string:");
    scanf("%s",my_string);
    char *istr ;
    istr= strtok (my_string,"+");
    unsigned n=0;
   while (istr != NULL)
   {
       char  *stopstring;
       double Num=0;
       Num = strtof (istr,&stopstring);
       set(arr,n,Num);
       n++;
        

    

    
      istr = strtok (NULL,"+");
   }
}


void input_file(SPoly* arr,char name[]){
    FILE *file;
    file=fopen(name, "r");
    char my_string[100];

    fscanf(file,"%s",my_string);
    char *istr ;
    istr= strtok (my_string,"+");
    unsigned n=0;
   while (istr != NULL)
   {
       char  *stopstring;
       double Num=0;
       Num = strtof (istr,&stopstring);
       set(arr,n,Num);
       n++;
        

    

    
      istr = strtok (NULL,"+");
   }
   fclose(file);
}




void print(SPoly* arr){
    unsigned i;
    unsigned n=(arr->size);
    int k=0;
    for (i = 0; i < n; i++) {
            if(i==0 && get(arr, i)!=0) {
                    printf("%.2lf", get(arr, i));
            k++;
            }
            if(i==1){
                    if(get(arr, i)>0 &&k!=0) printf("+%.2lfx", get(arr, i));
                        if(get(arr, i)>0 &&k==0){
                            printf("%.2lfx", get(arr, i));
                            k++;
                        }

                        if(get(arr, i)<0 &&k!=0) printf("%.2lfx", get(arr, i));
                        if(get(arr, i)<0 && k==0){
                            printf("%.2lfx", get(arr, i));
                            k++;
                        }


            }
            if(i>1 && i<n-1){
                    if(get(arr, i)>0 && k!=0) printf("+%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)>0 && k==0) {printf("%.2lfx^%u", get(arr, i),i);k++;}
                if(get(arr, i)<0 && k!=0) printf("%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)<0 && k==0){ printf("%.2lfx^%u", get(arr, i),i);k++;}

            }
            if(i==(n-1) && i>1){
                if(get(arr, i)>0 && k!=0) printf("+%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)>0 && k==0) {printf("%.2lfx^%u", get(arr, i),i);k++;}
                if(get(arr, i)<0 && k!=0) printf("%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)<0 && k==0){ printf("%.2lfx^%u", get(arr, i),i);k++;}

            }

    }

}
void print_file(SPoly* arr,char name[]){
    FILE *file;
    file=fopen(name, "w");
    unsigned i;
    unsigned n=(arr->size);
    int k=0;
    for (i = 0; i < n; i++) {
            if(i==0 && get(arr, i)!=0) {
                    fprintf(file,"%.2lf", get(arr, i));
            k++;
            }
            if(i==1){
                    if(get(arr, i)>0 &&k!=0) fprintf(file,"+%.2lfx", get(arr, i));
                        if(get(arr, i)>0 &&k==0){
                            fprintf(file,"%.2lfx", get(arr, i));
                            k++;
                        }

                        if(get(arr, i)<0 &&k!=0) fprintf(file,"%.2lfx", get(arr, i));
                        if(get(arr, i)<0 && k==0){
                            fprintf(file,"%.2lfx", get(arr, i));
                            k++;
                        }


            }
            if(i>1 && i<n-1){
                    if(get(arr, i)>0 && k!=0) fprintf(file,"+%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)>0 && k==0) {fprintf(file,"%.2lfx^%u", get(arr, i),i);k++;}
                if(get(arr, i)<0 && k!=0) fprintf(file,"%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)<0 && k==0){ fprintf(file,"%.2lfx^%u", get(arr, i),i);k++;}

            }
            if(i==(n-1) && i>1){
                if(get(arr, i)>0 && k!=0) fprintf(file,"+%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)>0 && k==0) {fprintf(file,"%.2lfx^%u", get(arr, i),i);k++;}
                if(get(arr, i)<0 && k!=0) fprintf(file,"%.2lfx^%u", get(arr, i),i);
                if(get(arr, i)<0 && k==0){ fprintf(file,"%.2lfx^%u", get(arr, i),i);k++;}

            }

    }
    fprintf(file,"\n");

    fclose(file);
  getchar();
}

void clearArr(SPoly* arr) {
    free(arr->data);
    arr->data = NULL;
}

void freeArr(SPoly **arr) {
    clearArr(*arr);
    free(*arr);
    arr = NULL;
}
void resizeArr(SPoly* arr, unsigned newSize) {
    if (!(arr->data = (double*) realloc(arr->data, newSize * sizeof(double)))) {
        exit(OUT_OF_MEMORY_EXCEPTION);
    }
    arr->size = newSize;
}
SPoly* summary(SPoly* arr1,SPoly* arr2){
    unsigned n_1=arr1->size;
    unsigned n_2=arr2->size;
    unsigned n_max,n_min;

    if(n_1>n_2){
        n_max=n_1;
        n_min=n_2;
    }
    else{
        n_max=n_2;
        n_min=n_1;
    }
    SPoly* arr=create(n_max);
    int i;

    for(i=0;i<n_max;i++){
            if(i<n_min){
                set(arr,i,get(arr1,i)+get(arr2,i));
            }
            if(i>=n_min && i<n_max && n_max==n_1){
                set(arr,i,get(arr1,i));
            }
            if(i>=n_min && i<n_max && n_max==n_2){
                set(arr,i,get(arr2,i));
            }
    }



    return arr;
}
SPoly* subtraction(SPoly* arr1,SPoly* arr2){
    unsigned n_1=arr1->size;
    unsigned n_2=arr2->size;
    unsigned n_max,n_min;

    if(n_1>n_2){
        n_max=n_1;
        n_min=n_2;
    }
    else{
        n_max=n_2;
        n_min=n_1;
    }
    SPoly* arr=create(n_max);
    int i;

    for(i=0;i<n_max;i++){
            if(i<n_min){
                set(arr,i,get(arr1,i)-get(arr2,i));
            }
            if(i>=n_min && i<n_max && n_max==n_1){
                set(arr,i,get(arr1,i));
            }
            if(i>=n_min && i<n_max && n_max==n_2){
                set(arr,i,-get(arr2,i));
            }
    }



    return arr;
}


SPoly* derivative(SPoly* arr){
    unsigned n=arr->size;
    SPoly* arr2=create(n-1);
    for(int i=0;i<n-1;i++){
        set(arr2,i,get(arr,i+1)*(i+1));
    }

    return arr2;

}


double value_in_point(SPoly* arr,double x){

    double res=0;
    unsigned n=arr->size;

    for(int i=0;i<n;i++){
        res+=get(arr,i)*(double)pow(x,(double)i);
    
    
    }
    return res;
}

double derivative_value(SPoly* arr,double x){
    unsigned n=arr->size;
    SPoly* deriv=create(n-1);
    deriv=derivative(arr);
    double res=value_in_point(deriv,x);

    return res;

}
SPoly* integration(SPoly* arr,double c){

    unsigned n=arr->size;
    SPoly* arr2=create(n+1);
    set(arr2,0,c);
    for(int i=1;i<(n+1);i++){

        set(arr2,i,get(arr,i-1)/i);
    }


    return arr2;

}
double integration_value(SPoly* arr,double a,double b){
    unsigned n=arr->size;
    SPoly* arr2=create(n+1);
    arr2=integration(arr,0);
    double res=value_in_point(arr2,b)-value_in_point(arr2,a);
    return res;

}
SPoly* multiply_num(SPoly* arr, double a){
    unsigned n=arr->size;
    SPoly* arr1=create(n);
    for(int i=0;i<n;i++){
        set(arr1,i,get(arr,i)*a);
    }

    return arr1;
}
SPoly* multiply(SPoly* arr1,SPoly* arr2){

    unsigned n=arr1->size;
    unsigned m=arr2->size;
    unsigned size;


    if(n==1 && m!=1){

         size=m;
         SPoly* arr=create(size);
         arr=multiply_num(arr2,get(arr1,0));
         return arr;
    }
    if(m==1 && n!=1){
        size=n;
        SPoly* arr=create(size);
         arr=multiply_num(arr1,get(arr2,0));
         return arr;
    }
    else {
            if(n==1 && m==1){
         size=1;
    }
    else {size=n*m-1;
    }
    SPoly* arr=create(size);
    for(int k=0;k<n;k++){


        for(int i=0;i<m;i++){

                double value=get(arr,i+k);
                double coef=value+get(arr1,k)*get(arr2,i);
                set(arr,i+k,coef);
        }


    }

    return arr;
}
}
SPoly* devide_num(SPoly* arr, double a){
    unsigned n=arr->size;
    SPoly* arr1=create(n);
    for(int i=0;i<n;i++){
        set(arr1,i,get(arr,i)/a);
    }

    return arr1;
}
SPoly* devide(SPoly* arr1,SPoly*arr2){
    unsigned n=arr1->size;
    unsigned m=arr2->size;


    SPoly* ob_3;
    SPoly* ob_1;
    SPoly* ob_2;
    SPoly* ob_4;

    ob_3=create(n);
    ob_1=create(n);
    ob_2=create(m);
    ob_4=create(n-m+1);
    zeros(ob_4);

    ob_1=arr1;
    ob_2=arr2;

    int k=0;
    while(n-k>=m){
        double mnojnik=get(ob_1,n-k-1)/get(ob_2,m-1);
    

    
    

        set(ob_4,n-m-k,mnojnik);
    
    
        ob_3=multiply(ob_4,ob_2);
    
    
        ob_1=subtraction(ob_1,ob_3);
    
    


        k++;
    }
    return ob_4;
}
SPoly* devide_ost(SPoly* arr1,SPoly* arr2){
    return(subtraction(arr1,multiply(arr2,devide(arr1,arr2))));
}
