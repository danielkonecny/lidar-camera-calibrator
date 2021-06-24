/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            ArgumentsParser.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            24. 06. 2021
 */

using namespace std;

#define DEFAULT_IMAGE_LOCATION "image.jpg"
#define DEFAULT_VIDEO_LOCATION "video.avi"
#define DEFAULT_VERBOSE false


class ArgumentsParser {
private:
    string imageLocation = DEFAULT_IMAGE_LOCATION;
    string videoLocation = DEFAULT_VIDEO_LOCATION;
    bool verbose = DEFAULT_VERBOSE;

    static void PrintHelp();

    static long long int LoadInteger(char *numberAsChars);

    static double LoadDouble(char *numberAsChars);

public:
    bool ProcessArguments(int argc, char *argv[]);

    [[nodiscard]] bool IsVerbose() const;

    string GetImageLocation();

    string GetVideoLocation();
};
