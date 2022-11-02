#include <iostream>
#include <sstream>
#include <algorithm>
#include "pokemon.h"

using namespace std;

Pokemon::Pokemon(string name, int ndex, Type type1)
{
    _name = name;         //initializes name from a string given to the class function
    _ndex = ndex;         //initializes the index number from an integer given to the class function
    types[0] = type1;     //initializes the first type from data given to the class function
    type_count = 1;       //initializes the type count to 1, since there will only be one type in this constructor
}

Pokemon::Pokemon(string name, int ndex, Type type1, Type type2)
{
    _name = name;         //initializes name from a string given to the class function
    _ndex = ndex;         //initializes the index number from an integer given to the class function
    types[0] = type1;     //initializes the first type from data given to the class function
    types[1] = type2;     //initializes the second type from data given to the class function
    type_count = 2;       //initializes th type count to 2, since there are 2 types in this constructor
}

string Pokemon::name()
{
    return _name;         //returns the name
}

int Pokemon::Ndex()
{
    return _ndex;         //returns the index number
}

Pokemon::Type Pokemon::type1()
{
    return types[0];      //returns the first type
}

bool Pokemon::is_multitype()
{
    if (type_count == 1)  //if type count is 1, the bool will be set to false
        return false;

    else                  //otherwise, the bool will be true
        return true;      
}

Pokemon::Type Pokemon::type2()
{
    if (type_count == 1)  //if the type count is 1, then the first type will be returned
        return types[0];

    else                  //otherwise, the second type will be returned
        return types[1];
}

float Pokemon::damage_multiplier(Type attack_type)
{
    float attackMultp = 1.0;                          //initializes an attack multiplier to 1

    if (is_multitype() == false) {                    //if there is only one type, it will go through this branch of code
        if (attack_type == Pokemon::Normal)        //if attack type is Normal, returns 1
        {
            return 1;
        }
        if (attack_type == Pokemon::Fighting) {   //if attack type is Fighting, then it will go through this branch of code
            if (types[0] == Pokemon::Normal) {  //if defending type is Normal, then it returns 2
                return 2.0;
            }
            if (types[0] == Pokemon::Fighting) {//if defending type is Fighting, then it returns 1
                return 1.0;
            }
            if (types[0] == Pokemon::Flying) { //if defending type is Flying, then it returns 0.5
                return 0.5;
            }
            if (types[0] == Pokemon::Poison) { //if defending type is Poison, then it returns 0.5
                return 0.5;
            }
        }
        if (attack_type == Pokemon::Flying) {     //if attack type is Flying, then it will go through this branch of code
            if (types[0] == Pokemon::Normal) { //if defending type is Normal, then it returns 1.0
                return 1.0;
            }
            if (types[0] == Pokemon::Fighting) {//if defending type is Fighting, then it returns 2.0;
                return 2.0;
            }
            if (types[0] == Pokemon::Flying) {//if defending type is Flying, then it returns 1.0;
                return 1.0;
            }
            if (types[0] == Pokemon::Poison) {//if defending type is Poison, then it returns 1.0;
                return 1.0;
            }
        }
        if (attack_type == Pokemon::Poison) {     //if attack type is Poison, then it will go through this branch of code
            if (types[0] == Pokemon::Normal) {//if defending type is Normal, then it returns 1.0
                return 1.0;
            }
            if (types[0] == Pokemon::Fighting) {//if defending type is Fighting, then it returns 1.0
                return 1.0;
            }
            if (types[0] == Pokemon::Flying) {//if defending type is Flying, then it returns 1.0
                return 1.0;
            }
            if (types[0] == Pokemon::Poison) {//if defending type is Poison, then it returns 0.5
                return 0.5;
            }
        }
    }

    if (is_multitype() == true) {                     //if there is more than one type, then it will go through this branch of code
        if (attack_type == Pokemon::Normal)       //if attack type is Normal, then it will go through this branch of code
        {   /* The code checks the pair of types, and assigns them a multiplier accordingly*/
            if (types[0] == Pokemon::Normal || types[1] == Pokemon::Normal) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Fighting || types[1] == Pokemon::Fighting) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Flying || types[1] == Pokemon::Flying) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Poison || types[1] == Pokemon::Poison) {
                attackMultp *= 1.0;
            }
        }

        if (attack_type == Pokemon::Fighting)
        {
            if (types[0] == Pokemon::Normal || types[1] == Pokemon::Normal) {
                attackMultp *= 2.0;
            }
            if (types[0] == Pokemon::Fighting || types[1] == Pokemon::Fighting) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Flying || types[1] == Pokemon::Flying) {
                attackMultp *= 0.5;
            }
            if (types[0] == Pokemon::Poison || types[1] == Pokemon::Poison) {
                attackMultp *= 0.5;
            }
        }

        if (attack_type == Pokemon::Flying)
        {
            if (types[0] == Pokemon::Normal || types[1] == Pokemon::Normal) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Fighting || types[1] == Pokemon::Fighting) {
                attackMultp *= 2.0;
            }
            if (types[0] == Pokemon::Flying || types[1] == Pokemon::Flying) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Poison || types[1] == Pokemon::Poison) {
                attackMultp *= 1.0;
            }
        }

        if (attack_type == Pokemon::Poison)
        {
            if (types[0] == Pokemon::Normal || types[1] == Pokemon::Normal) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Fighting || types[1] == Pokemon::Fighting) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Flying || types[1] == Pokemon::Flying) {
                attackMultp *= 1.0;
            }
            if (types[0] == Pokemon::Poison || types[1] == Pokemon::Poison) {
                attackMultp *= 0.5;
            }
        }

        return attackMultp; //returns attackMultp
    }

    return 0;
}

Pokemon::Pokemon(string summary)
{
    //erases all the spaces in summary
    summary.erase(remove(summary.begin(), summary.end(), ' '), summary.end()); 
    
    _name = summary.substr(0, summary.find(','));         //initializes the name using information from a summary string
    summary.erase(0, summary.find(',') + 1);              //erases the name section of the summary string so the rest may be processed

    _ndex = stoi(summary.substr(1, 3));                   //initializes the index number by using information from a summary string
    summary.erase(0, summary.find(',') + 1);              //erases the index section of the summary string so the rest may be processed

    string s = summary.substr(0, summary.find(','));      //initializes a string s using information from a summary string, this string is the type
    types[0] = string_to_type(s);                         //initializes the first type by sending the string to a function which will turn it into a type
    summary.erase(0, summary.find(',')+1);                //erases the type section of the summary string so the rest may be processed

    if (summary.size() > 0)                               //if the summary string size is greater than 0, then it means there are more than one types
    {

        types[1] = string_to_type(summary.substr(0, summary.find(','))); //initializes the second type by sending a string to a function where it will be converted to a type
        type_count = 2;                                     //type count is 2 since there is more than one type
    }
    else {                                                //otherwise, there is only one type
        types[1] = types[0];                              //initializes the second type to be equal to the first type
        type_count = 1;                                   //type count is 1 since there is only one type
    }

    
}

string Pokemon::summary()
{
    string summary;                                           //initializes a summary string
    string num = to_string(_ndex);                            //initializes a string num by converting the integer value of _ndex to a string
    string type1, type2;                                      //initializes 2 types

    type1 = type_to_string(types[0]);                         //converts the first type to string
    type2 = type_to_string(types[1]);                         //converts the second type to string

    if (num.size() == 1) {                                    //if the num is a single digit, then a 2 zeroes will be added to make it the size of 3
        num = "00" + num;
    }
    if (num.size() == 2) {                                    //if the num is a double digit, then a zero will be added to make it the size of 3
        num = "0" + num;
    }

    if (type1 == type2)                                       //if types 1 and 2 are the same, then a string with a single type will be produced
    {
        summary = _name + ", #" + num + ", " + type1 + ",";

        return summary;
    } else                                                    //otherwise there is 2 types, so a string with 2 types will be produced
    {
        summary = _name + ", #" + num + ", " + type1 + ", " + type2 + ",";

        return summary;
    }

}

string type_to_string(Pokemon::Type t)                  //this function looks at the value for type and converts it to the right string
{
  string type;
  if (t == Pokemon::Normal)
  {
    type = "Normal";
  }
  if (t == Pokemon::Fighting)
  {
    type = "Fighting";
  }
  if (t == Pokemon::Flying)
  {
    type = "Flying";
  }
  if (t == Pokemon::Poison)
  {
    type = "Poison";
  }

  return type;
}

Pokemon::Type string_to_type(string s)                //this function looks at a string and converts it to the right type
{

    if (s == "Normal")
    {
        return Pokemon::Normal;
    }
    if (s == "Fighting")
    {
        return Pokemon::Fighting;
    }
    if (s == "Flying")
    {
        return Pokemon::Flying;
    }
    if (s == "Poison")
    {
        return Pokemon::Poison;
    }
   
   return Pokemon::Normal;
}