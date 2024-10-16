// Brij Malhotra
// lab2.cpp
// Purpose: Using structs/classes to check whether places are within a given region

#include <iostream>

using namespace std;

// Function prototypes and declaration 

struct Location{
    float lat;
    float longi;
};

struct RegionChecker{
    bool isInRegion(Location verify);
};

struct PartitionResult{
    Location * insideRegion;
    Location * outsideRegion;
};

PartitionResult partition(Location * area, RegionChecker check);

const Location BOTTOMLEFT = {47.491683, -122.417678};
const Location TOPRIGHT = {47.731835, -122.271341};

int main (){

    return 0;
}

bool RegionChecker::isInRegion(Location verify){
    if(verify.lat >= BOTTOMLEFT.lat && verify.longi >= BOTTOMLEFT.longi){
        if(verify.lat <= TOPRIGHT.lat && verify.longi <= TOPRIGHT.longi){
        return true;
        }
    }
    return false;
}

PartitionResult partition(Location * area, RegionChecker check){        // You did not specify how many entries so I did not put 
    PartitionResult locationCheck;                                      // an arbitrary number and instead just left it blank. 
    int numLocations = 20;
    
    locationCheck.insideRegion = new Location[numLocations];
    locationCheck.outsideRegion = new Location[numLocations];

    int inside = 0;
    int outside = 0;

    for (int i = 0; i < numLocations; i++){
        if (check.isInRegion(area[i]) == true){
            locationCheck.insideRegion[inside] = area[i];
            inside++;
        } else {
            locationCheck.outsideRegion[outside] = area[i];
            outside++;
        }
    }

    return locationCheck;
}
