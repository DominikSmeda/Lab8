#pragma once
#include <iostream>
#include <cstring>

#include "MapDist.h"

class MapDist;

class MapPoint{
    friend class MapDist;
    friend MapPoint inTheMiddle(MapPoint *p1, MapPoint *p2, char *name);

    public:
        MapPoint();
        MapPoint(const char *city, double longitude, char EW, double latitude, char NS);
        MapPoint(const char *city, double longitude, double latitude);
        ~MapPoint();

        MapPoint& closestPlace(MapPoint*p1,MapPoint*p2);
        char* getName() const;
        void print() const;
        void movePoint(double longitudeShift, double latitudeShift);

    private:
        char *city;
        double longitude;
        double latitude;

        void createCity(const char * city);
};

MapPoint inTheMiddle(MapPoint *p1, MapPoint *p2, char *name);