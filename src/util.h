#ifndef UTIL_H
#define UTIL_H

#include <dpp/snowflake.h>
#include <vector>
#include <string>

/**
 * This function reads an enviromental variable. Check return value to see if the data in value should be trusted.
 *
 * @param KEY the name of the enviromental
 * @param _value the value of the enviromental variable, if it was able to be read successfully
 * 
 * @return true if the variable was found and was able to be read from successfully.
 */

bool getEnvValue(const std::string& KEY, std::string& _value);


std::string chooseRandomReaction();

void processMessage(std::string& _message, bool& containsConcord, bool& containsUpdate, bool& containsLicense);

#endif // UTIL_H
