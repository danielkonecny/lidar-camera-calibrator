/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            main.cpp
 * @version         1.0
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            24. 06. 2021
 */

#include <iostream>

#include "main.h"
#include "ArgumentsParser.h"

using namespace std;

int main(int argc, char *argv[]) {
    int exitCode = 0;

    ArgumentsParser parser;
    bool argsOk = parser.ProcessArguments(argc, argv);

    if (argsOk) {
        if (parser.IsVerbose()) {
            cout << "Verbose ON" << endl;
        } else {
            cout << "Verbose OFF" << endl;
        }
        cout << "Image location: " << parser.GetImageLocation() << endl;
        cout << "Video location: " << parser.GetVideoLocation() << endl;
    } else {
        exitCode = 1;
    }

    return exitCode;
}
