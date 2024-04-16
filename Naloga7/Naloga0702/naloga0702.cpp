//
// Created by Danijel Tomić on 14. 04. 24.
//
#include <vector>
#include "VectorUtil.h"
#include "Point.h"

using namespace std;

int main()
{
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());

    vector<Point> listPoints;
    cout << " --- Default generator of 3 objects --- " << endl;
    fillDefault(listPoints, 3);
    printColor<ColorCode::Red>(listPoints);

    vector<float> listFloats = {1.1f, 2.2f, 3.3f, 4.5f, 5.5f, 5.5f, 5.5f};
    vector<vector<float>> slicedFloat = slice(listFloats, 1);

    print(slicedFloat[0]);
    print(slicedFloat[1]);
    print(slicedFloat[2]);

    cout << " --- Removed: --- " << endl;
    vector<float> removeVec = {1.1f, 3.3f};
    removeElements(listFloats, removeVec);
    print(listFloats);

    cout << "--sub--" << endl;
    vector<float> subVec = subVector(listFloats, 0, 1);
    print(subVec);

    vector<float> listFloats2 = reverse(listFloats);
    cout << " --- Reverse: --- " << endl;
    print(listFloats2);

    vector<float> larger = getLarger(listFloats, 2.2f);
    cout << "-- larger -- " << endl;
    print(larger);

    cout << " --- To int vector: --- " << endl;
    print(toInt(listPoints));

    vector<std::string> listStrings = {"2", "asd", "34"};
    cout << " --- To int vector: --- " << endl;
    print(toInt(listStrings));

    vector<float> removedDuplicates = removeDuplicates(listFloats);
    cout << "-- remove duplicates --" << endl;
    print(removedDuplicates);

    vector<int> listInt;
    cout << " --- Default generator of 3 objects --- " << endl;
    fillDefault(listInt, 3);
    print(listInt);
    return 0;
}