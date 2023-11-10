// Osmolovsky BBBO-04-23 11 var
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

void dialog(int& x, int& y, int& z, int& step, int& num){
    system("clear || cls");
    int correct = 0;
    printf("Please, specify values of x, y, z, step and num.\nEnter x: ");
    correct = scanf("%d%*c", &x);
    while(!correct){
        printf("Wrong input! Reenter x: ");
        correct = scanf("%d", &x);
        while(getchar() != '\n');
    } 

    printf("Enter y: ");
    correct = scanf("%d%*c", &y);
    while(correct != 1){
        printf("Wrong input! Reenter y: ");
        correct = scanf("%d%*c", &y);
        while(getchar() != '\n');
    }
    printf("Enter z:");
    correct = scanf("%d%*c", &z);
    while(correct != 1){
        printf("Wrong input! Reenter z: ");
        correct = scanf("%d%*c", &z);
        while(getchar() != '\n');
    }
    printf("Enter step:");
    correct = scanf("%d%*c", &step);
    while(correct != 1){
        printf("Wrong input! Reenter step: ");
        correct = scanf("%d%*c", &step);
        while(getchar() != '\n');
    }
    printf("Enter num:");
    correct = scanf("%d%*c", &num);
    while(correct != 1){
        printf("Wrong input! Reenter num: ");
        correct = scanf("%d%*c", &num);
        while(getchar() != '\n');
    }
}

int ch2int(char* str, int size){
    int result = 0;
    for(int i=0; i < size; i++){
        if( str[i] >= 48 && str[i] <= 57)
            result += (*(str+i)-48) * pow(10, size - i - 1);
        else{
            printf("Error: can't translate %c to integer\n", str[i]);
            return 0;
        }
    }
    return result;
}

float* calcA(int x, int y, int z, int step, int num){
    if(y<0){
        printf("Can't calculate A: y < 0\n");
        return 0;
    }
    float* result = new float[num];
    for(int i=0; i<num; i++){
        result[i] = exp(6.8 * z) + y * ( x * sqrt(y));
        z += step;
    }
    return result;
}

float* calcB(int x, int y, int z, int step, int num){
    if(x+y<0){
        printf("Can't calculate B: y < 0\n");
        return 0;
    }
    float* result = new float[num];
    int i=0;
    while(i<num){
        result[i] = sqrt(y + x) - z;
        z += step;
        i++;
    }
    return result;
}

float* calcC(int x, int y, int z, int step, int num){
    int j=0;
    if(z<0){
        for( ; z < 0 || j < num; j++){
            z += step;   
        }
        if(z < 0){
            printf("There is no calculates for C\n");
        }
    }
    float* result = new float[num-j];
    int i=0;
    do{
        result[i] = tan(x) - y * sqrt(pow(z, 3));
        z += step;
        i++;
    }while(i<num);
    return result;
}

void printArray(float* arr, int size){
    for(int i=0; i<size; i++){
        printf("%.3f ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int x=0, y=0, z=0, step=0, num=0;
    char ex;
    
    if(argc == 6){
        x = ch2int(argv[1], std::strlen(argv[1]));
        y = ch2int(argv[2], std::strlen(argv[2]));
        z = ch2int(argv[3], std::strlen(argv[3]));
        step = ch2int(argv[4], std::strlen(argv[4]));
        num = ch2int(argv[5], std::strlen(argv[5]));
    }
    do {

        system("clear || cls");
        printf("Author: Kirill Osmolovsky, BBBO-04-23, 11 variant\n");
        printf("Menu:\n(1) Input values\n(2) Calculate A\n(3) Calculate B\n(4) Calculate C\n(5) Exit program\n");
        scanf("%c%*c", &ex);
        switch(ex){
            case '1':
                dialog(x, y, z, step, num);
                break;
            case '2':{
                float* A = calcA(x, y, z, step, num);
                printf("Input values: x=%d y=%d z=%d step=%d num=%d\n", x, y, z, step, num);
                printf("Array A: ");
                printArray(A, num);
                printf("(type enter to clear the screen) ");
                while(getchar() != '\n');
                break;}
            case '3':{
                float* B = calcB(x, y, z, step, num);
                printf("Input values: x=%d y=%d z=%d step=%d num=%d\n", x, y, z, step, num);
                printf("Array B: ");
                printArray(B, num);
                printf("(type enter to clear the screen) ");
                while(getchar() != '\n');
                break;}
            case '4':{
                float* C = calcC(x, y, z, step, num);
                printf("Input values: x=%d y=%d z=%d step=%d num=%d\n", x, y, z, step, num);
                printf("Array C: ");
                printArray(C, num);
                printf("(type enter to clear the screen) ");
                while(getchar() != '\n');
                break;}
            case '5':{
                printf("Exit? y/n ");
                scanf("%c%*c", &ex);
                break;}
        }
    } while(ex != 'y');
    return 0; }
