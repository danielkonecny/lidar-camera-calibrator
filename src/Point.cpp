/**
 * Calibrator
 * Application for calibrating camera and lidar data.
 * @file            Point.cpp
 * @author          Daniel Konecny (xkonec75)
 * @organisation    Brno University of Technology - Faculty of Information Technologies
 * @date            28. 06. 2021
 */

#include <iostream>

#include "Point.h"

using namespace std;

Point::Point(long long int newX, long long int newY, long long int newZ,
             long long int newReflexivity, long long int newTag, long long int newTimestamp) {
    this->x = newX;
    this->y = newY;
    this->z = newZ;
    this->reflexivity = newReflexivity;
    this->tag = newTag;
    this->timestamp = newTimestamp;
}

long long int Point::GetX() const {
    return this->x;
}

[[maybe_unused]] void Point::SetX(long long int newX) {
    this->x = newX;
}

long long int Point::GetY() const {
    return this->y;
}

[[maybe_unused]] void Point::SetY(long long int newY) {
    this->y = newY;
}

long long int Point::GetZ() const {
    return this->z;
}

[[maybe_unused]] void Point::SetZ(long long int newZ) {
    this->z = newZ;
}

long long int Point::GetReflexivity() const {
    return this->reflexivity;
}

[[maybe_unused]] void Point::SetReflexivity(long long int newReflexivity) {
    this->reflexivity = newReflexivity;
}

long long int Point::GetTag() const {
    return this->tag;
}

[[maybe_unused]] void Point::SetTag(long long int newTag) {
    this->tag = newTag;
}

long long int Point::GetTimestamp() const {
    return this->timestamp;
}

[[maybe_unused]] void Point::SetTimestamp(long long int newTimestamp) {
    this->timestamp = newTimestamp;
}

[[maybe_unused]] void Point::PrintPoint() const {
    cout << "X: " << this->GetX() << " - Y: " << this->GetY() << " - Z: " << this->GetZ() << " - Reflexivity: ";
    cout << this->GetReflexivity() << " - Tag: " << this->GetTag() << " - Timestamp: " << this->GetTimestamp() << endl;
}
