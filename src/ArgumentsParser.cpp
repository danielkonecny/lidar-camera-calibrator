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

long long int ArgumentsParser::LoadInteger(char *numberAsChars) {
    string::size_type length;
    string numberAsString = numberAsChars;
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

double ArgumentsParser::LoadDouble(char *numberAsChars) {
    string::size_type length;
    string numberAsString = numberAsChars;
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

void ArgumentsParser::PrintHelp() {
    cout << "CALIBRATOR" << endl <<
         "-h (--help)       Show help." << endl <<
         "-I (--image)      Location of input image." << endl <<
         "-v (--verbose)    Print information about the camera state." << endl <<
         "-V (--video)      Location of input video." << endl;
}

bool ArgumentsParser::ProcessArguments(int argc, char *argv[]) {
    const char *const short_opts = "hI:vV:";

    const option long_opts[] = {
            {"help",    no_argument,       nullptr, 'h'},
            {"image",   no_argument,       nullptr, 'I'},
            {"verbose", no_argument,       nullptr, 'v'},
            {"video",   required_argument, nullptr, 'V'},
            {nullptr,   no_argument,       nullptr, 0}
    };

    while (true) {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (opt == -1) {
            break;
        }

        switch (opt) {

            case 'i':
                imageLocation = optarg;
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
