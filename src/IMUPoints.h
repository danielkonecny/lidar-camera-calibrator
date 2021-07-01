/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            IMUPoints.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#ifndef CALIBRATOR_IMU_POINTS_H
#define CALIBRATOR_IMU_POINTS_H

#include <vector>

#include "IMU.h"

using namespace std;

class IMUPoints {
private:
    vector<IMU> imuPoints;

public:
    [[maybe_unused]] void AddPoint(double gyroX, double gyroY, double gyroZ,
                  double accuracyX, double accuracyY, double accuracyZ, long long int timestamp);

    void PrintIMUPoints();
};


#endif //CALIBRATOR_IMU_POINTS_H
