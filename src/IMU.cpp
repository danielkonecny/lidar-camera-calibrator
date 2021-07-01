/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            IMU.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#include <iostream>

#include "IMU.h"

using namespace std;

IMU::IMU(double newGyroX, double newGyroY, double newGyroZ,
         double newAccuracyX, double newAccuracyY, double newAccuracyZ, long long int newTimestamp) {
    this->gyroX = newGyroX;
    this->gyroY = newGyroY;
    this->gyroZ = newGyroZ;
    this->accuracyX = newAccuracyX;
    this->accuracyY = newAccuracyY;
    this->accuracyZ = newAccuracyZ;
    this->timestamp = newTimestamp;
}

[[maybe_unused]] void IMU::PrintIMU() const {
    cout << "Gyro X: " << this->gyroX << " - Gyro Y: " << this->gyroY << " - Gyro Z: " << this->gyroZ;
    cout << " - Accuracy X: " << this->accuracyX << " - Accuracy Y: " << this->accuracyY;
    cout << " - Accuracy Z: " << this->accuracyZ << " - Timestamp: " << this->timestamp << endl;
}
