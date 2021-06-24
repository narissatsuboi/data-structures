// Narissa Tsuboi
// @file Patient.h
// purpose: specification and implementation file for the Patient object

#ifndef HW8_PATIENT_H
#define HW8_PATIENT_H

#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

class Patient {
private:
    string name; // patient's full name
    string priorityDescr;
    int priorityCode{}; // 1, 2, 3, or 4
    int arrivalOrder{}; // patient's number of arrival to ER

public:

    // Constructors and Overloaded Operators //////////////////////////////////

    Patient() = default;

    Patient(const string &name, const string &priorityDescr) {
    // overloaded constructor
    // in: name and priority code (1-4)
    // throws: invalid argument for priority codes out of range

       this->name = name;
       this->priorityDescr = priorityDescr;
       this->priorityCode = convertPriorityDesc(priorityDescr);
       this->arrivalOrder = -99;
    }

    // assignment operator
    Patient& operator= (const Patient &otherPatient) = default;

    bool operator< (const Patient &otherPatient) const {
    // overloaded less than to compare patient's priority
    // in: Patient object
    // out: true if this Patient is higher priority

        if (this->priorityCode == otherPatient.priorityCode) {
            if (this->arrivalOrder > otherPatient.arrivalOrder)
                return true;
        }
        else if (this->priorityCode > otherPatient.priorityCode)
            return true;
        return false;
    }

    bool operator> (const Patient &otherPatient) const {
    // overloaded greater than to compare patient's priority
    // in: Patient object
    // out: true if this Patient is lower priority
        if (this->priorityCode == otherPatient.priorityCode) {
            if (this->arrivalOrder < otherPatient.arrivalOrder)
                return true;
        }
        else if (this->priorityCode < otherPatient.priorityCode)
            return true;
        return false;
    }

    // Mutators and Accessors //////////////////////////////////////////////////

    void setArrivalOrder(const int &order) {
    // for use in PPQ class to set arrival order
    // in: order
    // modify: patient's arrivalorder member

        this->arrivalOrder = order;
    }

    int getArrivalOrder() const {
    // returns arrivalOrder
    // out: arrivalorder
        return arrivalOrder;
    }

    string getName() {
    // returns Patient's full name
    // out: name

        return name;
    }

    string getPriorityDescr() const {
    // returns Patient's priorityDesc
    // out: the written description of the priority code

        return priorityDescr;
    }

    // Utility ////////////////////////////////////////////////////////////////

    string to_string() const{
    // stringifies Patient members per README
    // For example: Jane Smith { pri=urgent, arrive=3 }
        stringstream sso;
        sso << name;
        sso << " { pri=" << priorityDescr << ", ";
        sso << "arrive=" << arrivalOrder << " }\n";
        return sso.str();
    }

    int convertPriorityDesc(const string& descr) {
        // returns code given a description
        if (descr == "immediate")
            priorityCode = 1;
        else if (descr == "emergency")
            priorityCode = 2;
        else if (descr == "urgent")
            priorityCode = 3;
        else // "minimal"
            priorityCode = 4;
        return priorityCode;
    }
};

#endif //HW8_PATIENT_H
