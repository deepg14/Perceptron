#include <stdio.h>
#include <math.h>

//Macros
#define THRESHOLD 0.5
#define TRAINING_DATA "training_data.txt"
#define TEST_DATA "test_data.txt"
// #define LEARNING_RATE 0.2

typedef struct perceptron {
    double slope;
    double offset;
    double training error;
} Perceptron; 

//method to train the perceptron off of inputted data
//does not return anything but updates the parameters of the
//inputted perceptron object
void train(Perceptron p, int *x, int *y, int *expectedOut, int numPoints, int iterations) {
    int i, j; //iterators

    double x[numPoints]; //initialize data
    double y[numPoints];
    int expected[numPoints];

    int numMistakes = 0; //counter for number of mistakes

    for(t = 0; t < iterations; t++) {
        for(i = 0; i < numPoints; i++) {
            //if a mistake is made
            if (y[i]*(p.slope * x[i] + p.offset) <= 0) {
                numMistakes++;
                p.slope = p.slope + y[i] * x[i];
                p.offset = p.offset + y[i];

                //uncomment to get report of parameter changes at each mistake
                printf("%s\n", "------------------------------------------------");
                printf("%s", "MISTAKE #");
                printf("%d\n", numMistakes);
                printf("%s", "Slope: ");
                printf("%f\n", p.slope);
                printf("%s", "Offset: ");
                printf("%f\n", p.offset);
            }
            //if no mistake is made, then move on to next data point
        }
    }

    //report the results of the training
    printf("%s\n", "------------------------------------------------");
    printf("%s\n", "The resulting parameters are: ");
    printf("%s", "Slope: ");
    printf("%f\n", p.slope);
    printf("%s", "Offset: ");
    printf("%f\n", p.offset);
    printf("%s", "The total number of mistakes made was: ");
    printf("%d\n", numMistakes);
}

//runs the perceptron on the training data to determine
//how well training data is handled. Essentially, training the
//perceptron for greater number of iterations leads to lower error
double traniningError(Perceptron p, int *x, int *y, int *) {

}

//classify test data and return test accuracy
double test() {

}

int main(void) {
    //declare a perceptron object
    Perceptron myModel = {.slope = 0; .offset = 0};

    //count number of lines in training file
    int numTrainingPoints;
    FILE *fp = fopen(TRAINING_DATA, "r");
    while(!feof(fp)) {
        ch = fgetc(fp);
        if(ch == '\n') {
            numTrainingPoints++;
        }
    }

    //read the training file
    double x[numTrainingPoints]; //initialize data storage arrays
    double y[numTrainingPoints];
    int expected[numTrainingPoints];

    int i = 0;
    while(fscanf(fp, "%f %f %d", &x[i], &y[i], &expected[i]) != EOF) {
        //0 is used for mistakes in the text files so that it is easier
        //to identify mistakes
        if (expected[i] == 0) {
            expected[i] == -1;
        }
    }


    //train the perceptron

    //test the perceptron

    //report test accuracy
}