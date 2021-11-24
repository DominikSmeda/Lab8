#pragma once
#include <cmath>

#include "MapPoint.h"

class MapPoint;

class MapDist{
    public:
        MapDist(const MapPoint &p1, const MapPoint &p2);

        double angularDistance() const;
        double getlongitude() const;
        double getlatitude() const;
    
    private:
        double deltaLatitude;
        double deltaLongitude;
};

MapDist distance(const MapPoint &p1, const MapPoint &p2);