
#include "MapDist.h"

MapDist::MapDist(const MapPoint &p1, const MapPoint &p2){
    deltaLatitude=fabs(p2.latitude - p1.latitude);
    deltaLongitude=fabs(p2.longitude - p1.longitude);
}

double MapDist::angularDistance() const{
    return sqrt(deltaLatitude*deltaLatitude + deltaLongitude*deltaLongitude);
}

double MapDist::getlongitude() const{
    return deltaLongitude;
}

double MapDist::getlatitude() const{
    return deltaLatitude;
}

MapDist distance(const MapPoint &p1, const MapPoint &p2){
    MapDist obj(p1,p2);
    return obj;
}