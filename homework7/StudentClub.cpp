/*
    PIC 10A Homework 7, StudentClub.cpp
    Implementation file
    Author: Megan Ma
    Date: 11/27/2021
 
 */
#include “StudentClub.h”

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;


/************************************************
  methods implementation
 ***********************************************/

StudentClub::StudentClub(string n){
    name = n;
    president = nullptr;
    treasurer = nullptr;
    member.resize(0);
}

StudentClub::StudentClub(string n, Student* p, Student* t, vector<Student*>m){
    name = n;
    president = p;
    treasurer = t;
    member = m;
    
}
Student* StudentClub::get_president() const{
    return president;
    
}
Student* StudentClub::get_treasurer() const{
    return treasurer;
}

vector<Student*> StudentClub::get_member() const{
    return member;
}

void StudentClub::set_president(Student* p){
    president = p;
}
void StudentClub::set_treasurer(Student* t){
    treasurer = t;
}

// add student pointer s to vector of members
void StudentClub::add_member(Student* s){
    member.push_back(s);
}

void StudentClub::print() const{
    cout << setw(20) << "Club Name: " << name << endl;
    cout << setw(20) << "President Name: " << president -> get_name() << endl;
    cout << setw(20) << "Treasurer Name: " << treasurer -> get_name() << endl;
    cout << setw(20) << "Current Members: " << member.size() << endl;
}

vector<string> find_youngest(const vector<Student*> member){
    //create empty string to store youngest member's names
    vector<string> membernames(0);
    //set smallest age to the age of first member initially
    int smallest = (*member[0]).get_age();
    //loop through member and find the youngest age
    for (int i=0; i<member.size(); ++i){
        if((*member[i]).get_age() <= smallest){
            smallest = (*member[i]).get_age();
        }
    }
    //add all the names of all the members with the smallest age to vector membernames
    for(int i = 0; i < member.size(); ++i){
        if((*member[i]).get_age() == smallest){
            membernames.push_back((*member[i]).get_name());
        }
    }
    return membernames;
    
}
