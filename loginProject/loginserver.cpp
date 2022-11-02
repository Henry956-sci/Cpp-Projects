#include <iostream>
#include "loginserver.h"

using namespace std;

//initializes an empty server by making sure that the set holding the logged in users and the map holding all of the existing accounts are empty
LoginServer::LoginServer()
{
    S.clear();
    M.clear();
}

//searches through to map to try and find an existing account with the given username, if it doesn't find one, then it creates an account with the given username and password and returns true. Otherwise, returns false.
bool LoginServer::create_user(string username, string password)
{
    if(M.find(username) == M.end())
    {
        M[username] = password;
        return true;
    }
    else
        return false;
}

//searches through the map to try and find the given username, if it doesn't, then it immediately returns false. Otherwise, it goes through the entire map until it finds the element with the matching username and password, then it erases the account associated with the username then it returns true. If it fails to find a matching username AND password, it returns false.
bool LoginServer::delete_user(string username, string password)
{
    if(M.find(username) == M.end())
    {
        return false;
    }

    for(unordered_map<string, string>::iterator i = M.begin(); i != M.end(); i++)
    {
        if(i->first == username && i->second == password)
        {
            M.erase(i->first);
            if (is_logged_in(username) == true)
                S.erase(username);
            return true;
        }
    }
    return false;
}

//returns the total amount of accounts in the system by using the size of the map.
int LoginServer::total_user_count()
{
    return M.size();
}

//checks if the map has an account associated with the given nickname, if it doesn't it returns false. Otherwise, it goes through the entire map checking for a matching username and password. If it finds it, it checks if the account is already logged into the server, if it isn't, then it logs the account into the server and returns true. otherwise, returns false.
bool LoginServer::login(string username, string password)
{
    if(M.find(username) == M.end())
    {
        return false;
    }

    for(unordered_map<string, string>::iterator i = M.begin(); i != M.end(); i++)
    {
        if(i->first == username && i->second == password)
        {
            if(S.find(username) == S.end())
            {
                S.insert(username);
                return true;
            }
        }
    }
    return false;
}

//searches through the set, if it finds the given username, then it erases it from the set (logs it out) and returns true. Otherwise, it returns false.
bool LoginServer::logout(string username)
{
    if(is_logged_in(username) == true)
    {
        S.erase(username);
        return true;
    }
    else
        return false;
}

//searches through the set, if it finds the given username, then it returns true. Otherwise, it returns false.
bool LoginServer::is_logged_in(string username)
{
    if(S.find(username) != S.end())
    {
        return true;
    }
    else
        return false;
}

//returns the amount of people signed in by using the size of the set.
int LoginServer::active_user_count()
{
    return S.size();
}

//logs everyone out of the server by clearing the set.
void LoginServer::logout_everyone()
{
    S.clear();
}

//searches to see if the map has an account associated with the given username, if it doesn't then it returns false. Otherwise, it goes through the entire map searching for a matching username and password, if it finds the match, then it sets the account with the new password given to the function. If it can't find a match, then it returns false.
bool LoginServer::change_password(string username, string old_pw, string new_pw)
{
    if(M.find(username) == M.end())
    {
        return false;
    }

    for(unordered_map<string, string>::iterator i = M.begin(); i != M.end(); i++)
    {
        if(i->first == username && i->second == old_pw)
        {
            i->second = new_pw;
            return true;
        }
    }
    return false;
}