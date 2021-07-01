/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            IMUPoints.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#include <iostream>

#include "IMUPoints.h"

using namespace std;

[[maybe_unused]] void IMUPoints::AddPoint(double gyroX, double gyroY, double gyroZ,
                         double accuracyX, double accuracyY, double accuracyZ, long long int timestamp) {
    IMU newPoint(gyroX, gyroY, gyroZ, accuracyX, accuracyY, accuracyZ, timestamp);
    this->imuPoints.push_back(newPoint);
}

void IMUPoints::PrintIMUPoints() {
    cout << "IMU Points Summary" << endl;
    cout << "- Size: " << imuPoints.size() << endl;

    size_t index = 0;
    cout << "- Point examples: " << endl;
    cout << "-- " << index + 1 << ". ";
    imuPoints[index].PrintIMU();
    cout << "-- ..." << endl;

    index = imuPoints.size() % 1042;
    cout << "-- " << index + 1 << ". ";
    imuPoints[index].PrintIMU();
    cout << "-- ..." << endl;

    index = imuPoints.size() % 10042;
    cout << "-- " << index + 1 << ". ";
    imuPoints[index].PrintIMU();
    cout << "-- ..." << endl;
}
