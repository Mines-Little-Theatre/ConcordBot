#include <iostream>
#include <random>
#include <algorithm>

#include "util.h"



bool getEnvValue(const std::string& KEY, std::string& _value){
    const char* valuePtr = std::getenv(KEY.c_str());

    if (valuePtr == nullptr){
        std::cerr << "Failed to locate key: " << KEY << std::endl;
        return false;
    }
    
    _value = valuePtr;

    return true;
}




std::string chooseRandomReaction(){
    const std::string AVAILABLE_REACTIONS[] = { "😠", "😡", "🤬", "😤", "👎", "🖕" };
    const size_t NUMBER_OF_REACTIONS = 6;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(0, NUMBER_OF_REACTIONS - 1);

    return AVAILABLE_REACTIONS[dist(gen)];
}




void processMessage(std::string& _message, bool& containsConcord, bool& containsUpdate, bool& containsLicense){
    const std::string CONCORD = "concord";
    const std::string UPDATE = "update";
    const std::string STATUS = "status";
    const std::string LICENSE = "license";

    // lower case the string
    std::transform(_message.begin(), _message.end(), _message.begin(), ::tolower);


    containsConcord = _message.find(CONCORD) != std::string::npos;

    if(!containsConcord){
        return;
    }


    containsUpdate = _message.find(UPDATE) != std::string::npos || _message.find(STATUS) != std::string::npos;

    containsLicense = _message.find(LICENSE) != std::string::npos;

}


