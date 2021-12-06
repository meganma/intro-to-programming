/*
    PIC 10A Homework 7, StudentClub.h
    header file
    Author: Megan Ma
    Date: 11/27/2021
 
 */

#ifndef __STUDENTCLUB_H__
#define __STUDENTCLUB_H__

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class StudentClub{
    public:
        /**
         Constructs a StudentClub with name n and null president pointer, null treasurer pointer, and empty vector of members.
         */
        StudentClub(string n);
        /**
         Constructs a StudentClub with name n and president pointer to student p, treasurer pointer to student t, and member vector with members in student vector m.
         */
        StudentClub(string n, Student* p, Student* t, vector<Student*>m);
    
        /**
         Return the StudentClub's president pointer
         */
        Student* get_president() const;
        /**
         Return the StudentClub's treasurer pointer
         */
        Student* get_treasurer() const;
        /**
         Return the vector of members in the StudentClub
         */
        vector<Student*> get_member() const;
        
        /**
         Set president to point to Student p
         */
        void set_president(Student* p);
        /**
         Set treasurer to point to student t
         */
        void set_treasurer(Student* t);
        /**
         Add student pointer object to the vector member
         */
        void add_member(Student* s);
        /**
         Print club name, president name, treasurer name, and number of current members
         */
        void print() const;
    //private variables
    private:
        string name;
        Student* president;
        Student* treasurer;
        vector<Student*> member;
    
};

vector<string> find_youngest(const vector<Student*> member);
#endif

