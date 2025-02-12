//Created by Max VR on 12/01/2019

#include "Database.h"

using namespace std;

//Gathers input from user to pass to database addMember function
void getMember(Database & database) {
    string inputName;
    string inputStreet;
    string inputCity;
    string inputState;
    string inputZip;

    cout << "\nPlease enter the name of the member to add: ";
    getline(cin, inputName);
    cin.ignore(1000, '\n');
    cout << "\nPlease enter the street address of the member to add: ";
    getline(cin, inputStreet);
    cout << "\nPlease enter the name of the city in which the member is located: ";
    getline(cin, inputCity);
    cout << "\nPlease enter the state of the member to add: ";
    getline(cin, inputState);
    cout << "\nPlease enter the zip of the member to add: ";
    getline(cin, inputZip);
    database.addMember(inputName, inputStreet, inputCity, inputState, inputZip);
    database.update();
    cout << "\n\nMember added to database.";
    return;
}

//Same as getMember but for providers
void getProvider(Database & database) {
    string inputName;
    string inputStreet;
    string inputCity;
    string inputState;
    string inputZip;

    cout << "\nPlease enter the name of the provider to add: ";
    getline(cin, inputName);
    cin.ignore(1000, '\n');
    cout << "\nPlease enter the street address of the provider to add: ";
    getline(cin, inputStreet);
    cout << "\nPlease enter the name of the city in which the provider is located: ";
    getline(cin, inputCity);
    cout << "\nPlease enter the state of the provider to add: ";
    getline(cin, inputState);
    cout << "\nPlease enter the zip of the provider to add: ";
    getline(cin, inputZip);
    database.addProvider(inputName, inputStreet, inputCity, inputState, inputZip);
    database.update();
    cout << "\n\nProvider added to database.";
    return;
}

//Prompts user for ID to delete, displays name to confirm with user, 
//prompts for confirmation, deletes if confirmation is provided
void deleteMember(Database & database) {
    string inputID;
    char input;
    
    cout << "\nPlease input the ID of the member to delete: ";
    getline(cin, inputID);
    cin.ignore(1000, '\n');
    Member memberToDelete = database.members.at(inputID);
    cout << "\nThat member ID matches the following member: " << memberToDelete.name;
    cout << "\nAre you sure you want to delete? y/n: ";
    cin >> input;
    
    if(toupper(input) == 'Y'){
        cout << "\nMember has been removed";
        database.removeMember(inputID);
        database.update();
    }
    else {
        cout << "\nThe member has not been removed.";
    }
    return;
}
//Same as deleteMember, but for providers
void deleteProvider(Database & database) {
    string inputID;
    char input;

    cout << "\nPlease input the ID of the provider to delete: ";
    getline(cin, inputID);
    cin.ignore(1000, '\n');
    Provider providerToDelete = database.providers.at(inputID);
    cout << "\nThat provider ID matches the following provider: " << providerToDelete.name;
    cout << "\nAre you sure you want to delete? y/n: ";
    cin >> input;
    if(toupper(input) == 'Y'){
        cout << "\nProvider has been removed";
        database.removeProvider(inputID);
        database.update();
    }
    else {
        cout << "\nThe provider has not been removed.";
    }
    return;
}

//prompts user for ID to pass to database editMember function
void changeMember(Database & database) {
    string inputID;
    
    cout << "\nPlease input the name of the member to edit: ";
    getline(cin, inputID);
    cin.ignore(1000, '\n');
    database.editMember(inputID);
    return;
}

//Again, same as member but for provider
void changeProvider(Database & database) {
    string inputID;
    
    cout << "\nPlease input the name of the provider to edit: ";
    getline(cin, inputID);
    cin.ignore(1000, '\n');
    database.editProvider(inputID);
    return;
}
