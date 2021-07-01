/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            Point.h
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            28. 06. 2021
 */

#ifndef CALIBRATOR_POINT_H
#define CALIBRATOR_POINT_H


class Point {
private:
    long long int x;
    long long int y;
    long long int z;
    long long int reflexivity;
    long long int tag;
    long long int timestamp;

public:
    Point(long long int newX, long long int newY, long long int newZ,
          long long int newReflexivity, long long int newTag, long long int newTimestamp);

    [[nodiscard]] long long int GetX() const;

    [[maybe_unused]] void SetX(long long int newX);

    [[nodiscard]] long long int GetY() const;

    [[maybe_unused]] void SetY(long long int newY);

    [[nodiscard]] long long int GetZ() const;

    [[maybe_unused]] void SetZ(long long int newZ);

    [[nodiscard]] long long int GetReflexivity() const;

    [[maybe_unused]] void SetReflexivity(long long int newReflexivity);

    [[nodiscard]] long long int GetTag() const;

    [[maybe_unused]] void SetTag(long long int newTag);

    [[nodiscard]] long long int GetTimestamp() const;

    [[maybe_unused]] void SetTimestamp(long long int newTimestamp);

    [[maybe_unused]] void PrintPoint() const;
};


#endif //CALIBRATOR_POINT_H
