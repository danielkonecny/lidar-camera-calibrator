/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            IMUPointsLoader.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#include <iostream>
#include <sstream>

#include "IMUPointsLoader.h"
#include "ArgumentsParser.h"

IMUPointsLoader::IMUPointsLoader(const string &fileName) {
    imuPointsFile.open(fileName, fstream::in);
}

IMUPointsLoader::~IMUPointsLoader() {
    imuPointsFile.close();
}

IMUPoints IMUPointsLoader::LoadFile() {
    IMUPoints imuPoints;

    string lineString;
    vector<long long int> lineNumbers;
    while(getline(imuPointsFile, lineString)) {
        stringstream lineStream(lineString);
        string cell;

        getline(lineStream, cell, ',');
        double gyroX = LoadDouble(cell);
        getline(lineStream, cell, ',');
        double gyroY = LoadDouble(cell);
        getline(lineStream, cell, ',');
        double gyroZ = LoadDouble(cell);
        getline(lineStream, cell, ',');
        double accuracyX = LoadDouble(cell);
        getline(lineStream, cell, ',');
        double accuracyY = LoadDouble(cell);
        getline(lineStream, cell, ',');
        double accuracyZ = LoadDouble(cell);
        getline(lineStream, cell, ',');
        long long int timestamp = LoadInteger(cell);

        imuPoints.AddPoint(gyroX, gyroY, gyroZ, accuracyX, accuracyY, accuracyZ, timestamp);
    }

    return imuPoints;
}
