//
// Created by Danijel Tomić on 14. 04. 24.
//
#include <vector>
#include "VectorUtil.h"
#include "Point.h"

using namespace std;

int main()
{
    vector<Point> listPoints;
    cout << " --- Default generator of 3 objects --- " << endl;
    fillDefault(listPoints, 3);
    print(listPoints);

    vector<float> listFloats = {1.1f, 2.2f, 3.3f};
    vector<float> listFloats2 = reverse(listFloats);
    cout << " --- Reverse: --- " << endl;
    print(listFloats2);

    cout << " --- To int vector: --- " << endl;
    print(toInt(listPoints));

    vector<std::string> listStrings = {"2", "asd", "34"};
    cout << " --- To int vector: --- " << endl;
    print(toInt(listStrings));

    vector<int> listInt;
    cout << " --- Default generator of 3 objects --- " << endl;
    fillDefault(listInt, 3);
    print(listInt);

    vector<vector<int>> vecVec;
    vector<int> vec;
    fillDefault(vec, 5);
    vecVec.push_back(vec);
    vec.clear();
    fillDefault(vec, 5);
    vecVec.push_back(vec);
    vec.clear();
    fillDefault(vec, 5);
    vecVec.push_back(vec);
    vec.clear();
    vec = mergeVectors(vecVec);
    print(vec);

    return 0;
}