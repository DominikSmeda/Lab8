
#include "MapPoint.h"

MapPoint::MapPoint(){
    longitude=0;
    latitude=0;
    createCity("Punkt");
}

MapPoint::MapPoint(const char *city, double longitude, char EW, double latitude, char NS){
    this->longitude = (EW=='E')?longitude:-longitude;
    this->latitude = (NS =='N')?latitude:-latitude;

    createCity(city);
}

MapPoint::MapPoint(const char *city, double longitude, double latitude){
    this->longitude=longitude;
    this->latitude=latitude;
    createCity(city);
}

MapPoint::~MapPoint(){
    std::cout<<"Usuwanie "<<city<<std::endl;
    delete [] city;
}

void MapPoint::createCity(const char * city){
    this->city = new char[strlen(city)+1];
    strcpy(this->city,city);
}

void MapPoint::print() const{
    std::cout<<"Wspolrzedne dla "<<(city)<<": "<<std::abs(longitude);

    if(longitude>0){
        std::cout<<"E";
    }
    else{
        std::cout<<"W";
    }
    std::cout<<", "<<std::abs(latitude);
    if(latitude>0){
        std::cout<<"N";
    }
    else{
        std::cout<<"S";
    }
    std::cout<<std::endl;
}

void MapPoint::movePoint(double longitudeShift, double latitudeShift){
    longitude+=longitudeShift;
    latitude+=latitudeShift;
}

char* MapPoint::getName() const{
    return city;
}

const MapPoint& MapPoint::closestPlace(const MapPoint *p1, const MapPoint *p2) const{
    const MapDist d1(*this,*p1);
    const MapDist d2(*this,*p2);

    if(d1.angularDistance()>d2.angularDistance()){
        return *p2;
    }
    else{
        return *p1;
    }
}

MapPoint inTheMiddle(const MapPoint *p1, const MapPoint *p2, char *name){
    MapPoint obj(name, (p1->longitude+p2->longitude)/2, (p1->latitude+p2->latitude)/2);
    return obj;
}