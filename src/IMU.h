/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            IMU.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#ifndef CALIBRATOR_IMU_H
#define CALIBRATOR_IMU_H


class IMU {
private:
    double gyroX;
    double gyroY;
    double gyroZ;
    double accuracyX;
    double accuracyY;
    double accuracyZ;
    long long int timestamp;

public:
    IMU(double newGyroX, double newGyroY, double newGyroZ,
        double newAccuracyX, double newAccuracyY, double newAccuracyZ, long long int newTimestamp);

    [[maybe_unused]] void PrintIMU() const;
};


#endif //CALIBRATOR_IMU_H
