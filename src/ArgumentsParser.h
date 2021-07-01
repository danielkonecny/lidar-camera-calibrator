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
#define DEFAULT_POINT_CLOUD_LOCATION "point_cloud"
#define DEFAULT_IMU_POINTS_LOCATION "imu_points"
#define DEFAULT_VERBOSE false

[[maybe_unused]] long long int LoadInteger(const string& numberAsString);
[[maybe_unused]] long long int LoadInteger(char *numberAsChars);
[[maybe_unused]] double LoadDouble(const string& numberAsString);
[[maybe_unused]] double LoadDouble(char *numberAsChars);

class ArgumentsParser {
private:
    string imageLocation = DEFAULT_IMAGE_LOCATION;
    string videoLocation = DEFAULT_VIDEO_LOCATION;
    string pointCloudLocation = DEFAULT_POINT_CLOUD_LOCATION;
    string imuPointsLocation = DEFAULT_IMU_POINTS_LOCATION;
    bool verbose = DEFAULT_VERBOSE;

    static void PrintHelp();

public:
    bool ProcessArguments(int argc, char *argv[]);

    [[nodiscard]] bool IsVerbose() const;

    string GetImageLocation();

    string GetVideoLocation();

    string GetPointCloudLocation();

    string GetImuPointsLocation();
};
