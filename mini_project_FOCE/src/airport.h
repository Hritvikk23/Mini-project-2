#pragma once
#include<string>
using namespace std;

class Airport{
    public:
    int air_id=0;
    string name,city,country,iata,icao;
    double lat = 0.0, lon = 0.0;
};