/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            IMUPointsLoader.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#ifndef CALIBRATOR_IMU_POINTS_LOADER_H
#define CALIBRATOR_IMU_POINTS_LOADER_H

#include <fstream>
#include <string>

#include "IMUPoints.h"

using namespace std;

class IMUPointsLoader {
private:
    fstream imuPointsFile;

public:
    explicit IMUPointsLoader(const string& fileName);

    ~IMUPointsLoader();

    IMUPoints LoadFile();
};


#endif //CALIBRATOR_IMU_POINTS_LOADER_H
