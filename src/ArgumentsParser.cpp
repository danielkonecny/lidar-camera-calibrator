/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            ArgumentsParser.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            24. 06. 2021
 */


#include <iostream>
#include <getopt.h>

#include "ArgumentsParser.h"

using namespace std;

[[maybe_unused]] long long int LoadInteger(const string& numberAsString) {
    string::size_type length;
    long long int numberAsInt;

    try {
        numberAsInt = stoll(numberAsString, &length);
    }
    catch (const invalid_argument &ia) {
        cerr << "Invalid number conversion" << endl;
        throw;
    }
    catch (const out_of_range &oor) {
        cerr << "Number out of range" << endl;
        throw;
    }
    if (!numberAsString.substr(length).empty()) {
        cerr << "Invalid number format" << endl;
        throw;
    }

    return numberAsInt;
}

[[maybe_unused]] long long int LoadInteger(char *numberAsChars) {
    string numberAsString = numberAsChars;
    return LoadInteger(numberAsString);
}

[[maybe_unused]] double LoadDouble(const string& numberAsString) {
    string::size_type length;
    double numberAsDouble;

    try {
        numberAsDouble = stod(numberAsString, &length);
    }
    catch (const invalid_argument &ia) {
        cerr << "Invalid number conversion" << endl;
        throw;
    }
    catch (const out_of_range &oor) {
        cerr << "Number out of range" << endl;
        throw;
    }
    if (!numberAsString.substr(length).empty()) {
        cerr << "Invalid number format" << endl;
        throw;
    }

    return numberAsDouble;
}

[[maybe_unused]] double LoadDouble(char *numberAsChars) {
    string numberAsString = numberAsChars;
    return LoadDouble(numberAsString);
}

void ArgumentsParser::PrintHelp() {
    cout << "CALIBRATOR" << endl <<
         "-C (--point_cloud)    Location of file with point cloud." << endl <<
         "-h (--help)           Show help." << endl <<
         "-I (--image)          Location of input image." << endl <<
         "-P (--imu_points)     Location of file with IMU points." << endl <<
         "-v (--verbose)        Print information about the camera state." << endl <<
         "-V (--video)          Location of input video." << endl;
}

bool ArgumentsParser::ProcessArguments(int argc, char *argv[]) {
    const char *const short_opts = "C:hI:P:vV:";

    const option long_opts[] = {
            {"point_cloud", required_argument, nullptr, 'C'},
            {"help",        no_argument,       nullptr, 'h'},
            {"image",       required_argument, nullptr, 'I'},
            {"imu_points",  required_argument, nullptr, 'P'},
            {"verbose",     no_argument,       nullptr, 'v'},
            {"video",       required_argument, nullptr, 'V'},
            {nullptr,       no_argument,       nullptr, 0}
    };

    while (true) {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (opt == -1) {
            break;
        }

        switch (opt) {
            case 'C':
                pointCloudLocation = optarg;
                break;

            case 'I':
                imageLocation = optarg;
                break;

            case 'P':
                imuPointsLocation = optarg;
                break;

            case 'v':
                verbose = true;
                break;

            case 'V':
                videoLocation = optarg;
                break;

            case 'h':
            case '?':
            default:
                PrintHelp();
                return false;
        }
    }
    return true;
}


bool ArgumentsParser::IsVerbose() const {
    return verbose;
}

string ArgumentsParser::GetImageLocation() {
    return imageLocation;
}

string ArgumentsParser::GetVideoLocation() {
    return videoLocation;
}

string ArgumentsParser::GetPointCloudLocation() {
    return pointCloudLocation;
}

string ArgumentsParser::GetImuPointsLocation() {
    return imuPointsLocation;
}
