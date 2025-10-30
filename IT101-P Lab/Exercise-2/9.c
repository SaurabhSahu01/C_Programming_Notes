#include <stdio.h>

int main(){
    int n; // number of employees
    scanf("%d", &n);

    // array to store the salaries of the employees
    double salary[n];
    // array to store the gender of the employees
    char gender[n];

    for(int i = 0; i < n; i++){
        scanf("%lf %c", &salary[i], &gender[i]); // reading input in one line
    }

    // logic to calculate the bonus based on gender and salary
    for(int i = 0; i < n; i++){
        double sal = salary[i];
        char gen = gender[i];

        // bonus based on gender
        if(gen == 'M'){
            // bonus is 5% if male
            sal += salary[i]*0.05;
        }
        else{
            // bonus is 10% if female
            sal += salary[i]*0.1;
        }

        // bonus based on salary
        if(salary[i] < 10000){
            // 2% bonus if salary is less than 10000
            sal += salary[i]*0.02;
        }

        // update the salary in the original salary array
        salary[i] = sal;
    }

    // print the salary
    for(int i = 0; i < n; i++){
        printf("%.2lf\n", salary[i]);
    }

    return 0;
}