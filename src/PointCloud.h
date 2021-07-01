/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            PointCloud.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            28. 06. 2021
 */

#ifndef CALIBRATOR_POINT_CLOUD_H
#define CALIBRATOR_POINT_CLOUD_H

#include <vector>

#include "Point.h"

using namespace std;

class PointCloud {
private:
    vector<Point> pointCloud;

public:
    [[maybe_unused]] void AddPoint(Point point);

    [[maybe_unused]] void AddPoint(vector<long long int> pointNumbers);

    [[maybe_unused]] void AddPoint(long long int x, long long int y, long long int z,
                                   long long int reflexivity, long long int tag, long long int timestamp);

    Point GetPoint(size_t index);

    void PrintPointCloud();
};


#endif //CALIBRATOR_POINT_CLOUD_H
