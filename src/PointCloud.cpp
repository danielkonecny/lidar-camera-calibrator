/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            PointCloud.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            28. 06. 2021
 */

#include <iostream>

#include "PointCloud.h"

using namespace std;

[[maybe_unused]] void PointCloud::AddPoint(Point point) {
    this->pointCloud.push_back(point);
}

[[maybe_unused]] void PointCloud::AddPoint(long long int x, long long int y, long long int z,
                                           long long int reflexivity, long long int tag, long long int timestamp) {
    Point newPoint(x, y, z, reflexivity, tag, timestamp);
    this->pointCloud.push_back(newPoint);
}

void PointCloud::AddPoint(vector<long long int> pointNumbers) {
    if (pointNumbers.size() != 6) {
        cerr << "Wrong number of numbers on a line in a point cloud file: ";
        for (const auto &elem : pointNumbers) {
            cerr << elem << " ";
        }
        cerr << endl;
    } else {
        Point newPoint(pointNumbers[0], pointNumbers[1], pointNumbers[2],
                       pointNumbers[3], pointNumbers[4], pointNumbers[5]);
        this->pointCloud.push_back(newPoint);
    }
}

[[maybe_unused]] Point PointCloud::GetPoint(size_t index) {
    return this->pointCloud[index];
}

void PointCloud::PrintPointCloud() {
    cout << "Point Cloud Summary" << endl;
    cout << "- Size: " << pointCloud.size() << endl;

    size_t index = 0;
    cout << "- Point examples: " << endl;
    cout << "-- " << index + 1 << ". ";
    pointCloud[index].PrintPoint();
    cout << "-- ..." << endl;

    index = pointCloud.size() % 1000;
    cout << "-- " << index + 1 << ". ";
    pointCloud[index].PrintPoint();
    cout << "-- ..." << endl;

    index = pointCloud.size() % 10000;
    cout << "-- " << index + 1 << ". ";
    pointCloud[index].PrintPoint();
    cout << "-- ..." << endl;
}

