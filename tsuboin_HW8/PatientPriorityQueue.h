// Narissa Tsuboi
// @file PatientPriorityQueue.h
// purpose: specification and implementation file for the
// PatientPriorirityQueue (PPQ) class

#ifndef HW8_PATIENTPRIORITYQUEUE_H
#define HW8_PATIENTPRIORITYQUEUE_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <vector>

using namespace std;

template<class Patient>
class PatientPriorityQueue
{
private:
    vector<Patient> patients; // heap container of Patient objects
    int nextPatientNumber; // last patient added into the heap

public:
    // Constructors and Overloaded Operators //////////////////////////////////
    PatientPriorityQueue() {
        // default constructor creates an empty triage system with no patients
        nextPatientNumber = 0; // accumulator++
    }

    // Heap Methods ///////////////////////////////////////////////////////////

    void add(Patient &newPatient) {
    // adds the patient to the PPQ while maintaining heap order
        int i, parent;
        Patient tmp;

        // increment nextPatientNumber and assign to patient
        nextPatientNumber++;
        newPatient.setArrivalOrder(nextPatientNumber);

        // enqueue newPatient to the end of the vector
        patients.push_back(newPatient);

        // swap newPatient up until parent greater priority than newPatient
        i = patients.size() - 1;
        while (true) {
            if (i == 0) return;
            parent = (i - 1) / 2;
            if (patients[i] > patients[parent]) {
                tmp = patients[i];
                patients[i] = patients[parent];
                patients[parent] = tmp;
                i = parent;
            } else
                return;
        }
    }

    Patient peek() const {
    // returns the highest priority patient without removing it from the minheap
    // out: patient stored at the root of the heap

        if (patients.empty())
            throw length_error("error: attempted to peak into an empty heap");
        return patients.front(); // patient at root
    }

    Patient remove() {
    // removes the highest priority patient from the queue and returns it '
        Patient root;

        if (patients.empty()) {
            throw (std::length_error) "Called remove() on an empty PQueue";
        }
        root = patients[0];
        patients[0] = patients[patients.size()-1];
        patients.pop_back();
//        if (patients.empty() == 0)
//            return root;
        heapRebuild(0);
        return root;
    }

    int size() const {
    // returns the number of patients still waiting in the PPQ
        return patients.size();
    }

    void heapRebuild(int nodeIndex)
    {
        if(2 * nodeIndex + 1 < int (patients.size())) // the root is not a leaf (that is, it has a left child)
        {
            int largerChildIndex = 2 * nodeIndex + 1; // left child index
            if(largerChildIndex + 1 < int (patients.size())) // the root has a right child
            {
                int rightChildIndex = largerChildIndex + 1;
                if(patients[rightChildIndex].operator>
                (patients[largerChildIndex]))
                    largerChildIndex = rightChildIndex;
            }

            if(patients[nodeIndex].operator< (patients[largerChildIndex]))
            {	// swap
                Patient temp = patients[nodeIndex];
                patients[nodeIndex] = patients[largerChildIndex];
                patients[largerChildIndex] = temp;

                heapRebuild(largerChildIndex);
            }
        }
    }

    // Utility ////////////////////////////////////////////////////////////////

    string to_string() const {
        stringstream sso;
        Patient temp;
        for (size_t i = 0; i < patients.size(); i++) {
            temp = patients[i];
            sso << "\t";
            sso << temp.getArrivalOrder() << "\t ";
            sso << temp.getPriorityDescr() << "\t\t  ";
            sso << temp.getName() << "\n";
        }
        return sso.str();
    }


};

#endif //HW8_PATIENTPRIORITYQUEUE_H
