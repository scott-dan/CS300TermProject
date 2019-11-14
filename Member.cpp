//
// Created by Cody Potter on 10/24/2019.
//

#include "Member.h"

//////////////////// Constructors ////////////////////
/**
 * Constructor from JSON file
 * @param memberRef - a reference to a Json::Value (typically being read from a file)
 * @param key - the key of the memberRef value (typically being read from a file)
 */
Member::Member(Json::Value& memberRef, std::string key) {
    name =      memberRef["name"].asString();
    id =        key;
    isValid =   memberRef["isValid"].asBool();
    street =    memberRef["street"].asString();
    city =      memberRef["city"].asString();
    state =     memberRef["state"].asString();
    zip =       memberRef["zip"].asString();

    for (int i = 0; i < memberRef["services"].size(); i++) {
        services.push_back(memberRef["services"][i].asString());
    }
}

/**
 * Constructor for User Interface
 * @param newID - new identifier (must be unique; see database.generateNewActorID()
 * @param newName - new member's name
 * @param newStreet - new member's street
 * @param newCity - new members's city
 * @param newState - new member's state
 * @param newZip - new member's zip
 */
Member::Member(std::string newID, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip) {
    name =      newName;
    id =        newID;
    isValid =   true; // consciously starting new members in a valid state
    street =    newStreet;
    city =      newCity;
    state =     newState;
    zip =       newZip;
}

//////////////////// Getters ////////////////////
/**
 * Get JSON Value
 * @return a Json::Value representation of the member class instance
 */
Json::Value Member::getJsonValue() {
    Json::Value jsonValue;

    jsonValue["name"] = name;
    jsonValue["id"] = id;
    jsonValue["street"] = street;
    jsonValue["city"] = city;
    jsonValue["state"] = state;
    jsonValue["zip"] = zip;
    jsonValue["isValid"] = isValid;

    for (int i = 0; i < services.size(); i++) {
        jsonValue["services"][i] = services[i];
    }

    return jsonValue;
}

//////////////////// Setters ////////////////////
