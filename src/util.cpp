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

std::string chooseRandomAutoReplyLicense(){
    // for now this isnt random. 

    const std::string CONCORD_EASY = 
        "Thank you for your interest in licensing a show from Concord Theatricals!\n\n"
        "We hope to make the process of licensing straightforward, quick, and uncomplicated.";

    return CONCORD_EASY;
}

std::string chooseRandomAutoReplyUpdate() {
    const std::string CONCORD_DEFUALT = 
        "Thank you for contacting Concord Theatricals!\n\n"
        "We have recieved your email and will respond as swiftly as possible. We appreciate your patience.\n\n"
        "**PLEASE NOTE**:\n\n"
        "*Our US offices will be closed on Monday, Janurary 16th, in observance of Martin Luther King Jr. Day.*";

    const std::string CONCORD_LICENSE = 
        "**Please do not reply to this message. This is an automated email**\n\n"
        "This is an update regarding your Concord Musical Request 069420 for Concord the Musical.\n\n"
        "We are working very hard to do everything we can to get you a swift response. Please be aware,"
        " some licensing requests may be denied entirely. You will receive notification as soon as possible.\n\n";

    const std::string CONCORD_CANCELLED = 
        "**Please do not reply to this message. This is an automated email**\n\n"
        "We have not received the Licensing Fees due for Concord the Musical on License agreement 069420.\n\n"
        "Because of this non-payment, your licensing agreement for Concord the Musical has been cancelled. Please "
        "any and all advertisement and production plans for this title if you have not done so already. Should "
        "production open without payment of the required licensing fees, we *must* consider this a willful act "
        "of copyright infringment subject to the following penalties:\n"
        "\t- We must receive a number of first born children equal to or greater than the number of scripts ordered.\n"
        "\t- Our legal team is entitled to a number of kidneys equal to or greater than the number of seats in your venue.\n"
        "\t- You must send a 30 minute apology video from each member of your production including any support and production staff\n\n"
        "Please send your agreement to these terms to your licensing agent and your account will be reviewed for removal from suspension"
        "after a 2 year period.\n\n"
        "Thank you for choosing Concord Theatricals!";

    const std::string AVAILABLE_AUTO_REPLYS[] = {CONCORD_DEFUALT, CONCORD_LICENSE, CONCORD_CANCELLED};
    const int NUMBER_OF_AUTO_REPLYS = 3;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(0, NUMBER_OF_AUTO_REPLYS - 1);

    return AVAILABLE_AUTO_REPLYS[dist(gen)];

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


