/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            PointCloudLoader.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            01. 07. 2021
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "PointCloudLoader.h"
#include "ArgumentsParser.h"

vector<long long int> LoadLine(const string& lineString) {
    stringstream lineStream(lineString);
    string cell;
    vector<long long int> lineNumbers;

    while (getline(lineStream, cell, ',')) {
        long long int number = LoadInteger(cell);
        lineNumbers.push_back(number);
    }

    return lineNumbers;
}

PointCloudLoader::PointCloudLoader(const string &fileName) {
    pointCloudFile.open(fileName, fstream::in);
}

PointCloudLoader::~PointCloudLoader() {
    pointCloudFile.close();
}

PointCloud PointCloudLoader::LoadFile() {
    PointCloud pointCloud;

    string lineString;
    vector<long long int> lineNumbers;
    while(getline(pointCloudFile, lineString)) {
        lineNumbers = LoadLine(lineString);
        pointCloud.AddPoint(lineNumbers);
    }

    return pointCloud;
}
