//
// Created by Danijel Tomić on 27. 02. 24.
//

#include <iostream>
#include <algorithm>

using namespace std;

void getPossibleCarsByPart(const int *inputs, int *output) {
    output[0] = inputs[0] / 4;
    output[1] = inputs[1] / 1;
    output[2] = inputs[2] / 2;
}

void getLeftovers(const int *inputs, int carsBuilt, int *leftovers) {
    leftovers[0] = inputs[0] - (carsBuilt * 4);
    leftovers[1] = inputs[1] - carsBuilt;
    leftovers[2] = inputs[2] - (carsBuilt * 2);
}

void getAdditionalParts(int theoreticalAssembledCars, const int *leftovers, int *additionalParts) {
    additionalParts[0] = (theoreticalAssembledCars * 4) - leftovers[0];
    additionalParts[1] = (theoreticalAssembledCars) - leftovers[1];
    additionalParts[2] = (theoreticalAssembledCars * 2) - leftovers[2];
}

int getPossibleCarsBuilt(const int *input) {
    int minIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (input[i] < input[minIndex])
            minIndex = i;
    }
    return input[minIndex];
}

int getTheoreticalCarsBuilt(const int *input) {
    int maxIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (input[i] > input[maxIndex])
            maxIndex = i;
    }
    return input[maxIndex];
}

float caluclateAditionalPartsPrice(const int* additionalParts){
    float result = 0;
    result += (additionalParts[0] * 0.30f);
    result += (additionalParts[1] * 1.8f);
    result += (additionalParts[2] * 0.15f);
    return result;
}

int main() {
    int inputs[] = {0, 0, 0};
    int outputAssembledCars[] = {0, 0, 0};
    int outputLeftovers[] = {0, 0, 0};
    int outputAditionalParts[] = {0, 0, 0};
    int builtCars, theoreticalBuiltCars;

    int inputIndex = 0;

    do {
        switch (inputIndex) {
            case 0:
                cout << "Input number of wheels: ";
                break;
            case 1:
                cout << "Input number of chassies: ";
                break;
            case 2:
                cout << "Input number of mirrors: ";
                break;
        }

        cin >> inputs[inputIndex];
        if(inputs[inputIndex] > 0)
            inputIndex++;

    } while (inputs[0] <= 0 || inputs[1] <= 0 || inputs[2] <= 0);

    cout << endl;

    getPossibleCarsByPart(inputs, outputAssembledCars);
    builtCars = getPossibleCarsBuilt(outputAssembledCars);
    getLeftovers(inputs, builtCars, outputLeftovers);
    theoreticalBuiltCars = getTheoreticalCarsBuilt(outputLeftovers);
    getAdditionalParts(theoreticalBuiltCars, outputLeftovers, outputAditionalParts);

    cout << "Able to build: " << builtCars << endl;
    cout << "We still have: " << endl;
    cout << "Num of wheels: " << outputLeftovers[0] << endl;
    cout << "Num of bodies: " << outputLeftovers[1] << endl;
    cout << "Num of mirrors: " << outputLeftovers[2] << endl;
    cout << endl;

    cout << "We need: " << endl;
    cout << "Num of wheels: " << outputAditionalParts[0] << endl;
    cout << "Num of bodies: " << outputAditionalParts[1] << endl;
    cout << "Num of mirrors: " << outputAditionalParts[2] << endl;
    cout << "Price of additional parts: " << caluclateAditionalPartsPrice(outputAditionalParts) << "€" << endl;

    return 0;
}