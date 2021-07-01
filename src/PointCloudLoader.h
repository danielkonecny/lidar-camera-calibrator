/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            PointCloudLoader.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */


#ifndef CALIBRATOR_POINT_CLOUD_LOADER_H
#define CALIBRATOR_POINT_CLOUD_LOADER_H

#include <fstream>
#include <string>

#include "PointCloud.h"

using namespace std;

vector<long long int> LoadLine(const string& lineString);

class PointCloudLoader {
private:
    fstream pointCloudFile;

public:
    explicit PointCloudLoader(const string& fileName);

    ~PointCloudLoader();

    PointCloud LoadFile();
};


#endif //CALIBRATOR_POINT_CLOUD_LOADER_H
