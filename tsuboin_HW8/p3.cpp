// Narissa Tsuboi
// @file p3.cpp
// purpose: p3 represents the user interface of the Emergency Room that
// patients are triaged and added to the priority queue in. p3 calls
// PatientPriorityQueue functionality to run the ER. includes a help command
// to orient the user.

#include "PatientPriorityQueue.h"
#include "Patient.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const std::string WHITESPACE = " \t\r\n"; // line sequence separators and spaces

void welcome();
// Prints welcome message.

void goodbye();
// Prints goodbye message.

void help();
// Prints help menu.

bool processLine(string, PatientPriorityQueue<Patient> &);
// Process the line entered from the user or read from the file.

void addPatientCmd(string, PatientPriorityQueue<Patient> &);
// Adds the patient to the waiting room.

void peekNextCmd(PatientPriorityQueue<Patient> &);
// Displays the next patient in the waiting room that will be called.

void removePatientCmd(PatientPriorityQueue<Patient> &);
// Removes a patient from the waiting room and displays the name on the screen.

void showPatientListCmd(PatientPriorityQueue<Patient> &);
// Displays the list of patients in the waiting room.

void execCommandsFromFileCmd(const string&, PatientPriorityQueue<Patient> &);
// Reads a text file with each command on a separate line and executes the
// lines as if they were typed into the command prompt.

string delimitBySpace(string &);
// Delimits (by space) the string from user or file input.

string ltrim(const string &s);
// Trims left hand side white space.

string rtrim(const string &s);
// Trims right hand side whitespace.

string trim(const string &s);
// Trims left and right hand site whitespace.


// main represents the emergency room where patients are triaged, added and
// removed from the patient priority queue as they are seen by the doctor
int main() {

    // declare variables
	string line;

	// welcome message
	welcome();

	// process commands
	PatientPriorityQueue<Patient> priQueue;

	do {
		cout << "\ntriage> ";
		getline(cin, line);
	} while (processLine(line, priQueue));

	// goodbye message
	goodbye();

	return 0;
}

bool processLine(string line, PatientPriorityQueue<Patient> &priQueue) {
// Process the line entered from the user or read from the file.
// in: line from file or console, reference to PPQ
// modify: parse the command from the line
// out: true upon process completion

    // get command
	string cmd = delimitBySpace(line);
	if (cmd.length() == 0) {
		cout << "Error: no command given.";
		return false;
	}

	// process user input
	if (cmd == "help")
		help();
	else if (cmd == "add")
		addPatientCmd(line, priQueue);
	else if (cmd == "peek")
		peekNextCmd(priQueue);
	else if (cmd == "next")
		removePatientCmd(priQueue);
	else if (cmd == "list")
		showPatientListCmd(priQueue);
	else if (cmd == "load")
		execCommandsFromFileCmd(line, priQueue);
	else if (cmd == "quit")
		return false;
	else
		cout << "Error: unrecognized command: " << cmd << endl;

	return true;
}

void addPatientCmd(string line, PatientPriorityQueue<Patient> &priQueue) {
// Adds the patient to the waiting room.
// in: line from processLine, reference to PPQ

    string priority, name;

	// get priority and name
	priority = delimitBySpace(line);
	if (priority.length() == 0) {
		cout << "Error: no priority code given.\n";
		return;
	}
	name = line;
	// validate priority is between 1 and 4
	if (!(priority == "immediate" || priority == "emergency" ||
	    priority == "urgent" || priority == "minimal")) {
	    cout << "Error: invalid priority.\n";
	    return;
	}
	if (name.length() == 0) {
		cout << "Error: no patient name given.\n";
		return;
	}

	// remove leading and trailing spaces
	priority = trim(priority);
	name = trim(name);

	// add new Patient to priQueue
	Patient newPatient(name, priority);
	priQueue.add(newPatient);
	cout << "Added patient " << name << " to the priority system\n";
}

void peekNextCmd(PatientPriorityQueue<Patient> &priQueue) {
// Displays the next patient in the waiting room that will be called.
// in: reference PPQ

	Patient nextPatient = priQueue.peek();
	cout << "Highest priority patient to be called next: ";
	cout << nextPatient.getName() << "\n";
}

void removePatientCmd(PatientPriorityQueue<Patient> &priQueue) {
// Removes a patient from the waiting room and displays the name on the screen.
// in: reference PPQ
// modify: PPQ's root is removed and reassigned

	// Removes and shows next patient to be seen
	Patient nextPatient = priQueue.remove();
	cout << "This patient will now be seen: ";
	cout << nextPatient.getName() << "\n";
}

void showPatientListCmd(PatientPriorityQueue<Patient> &priQueue) {
// Displays the list of patients in the waiting room.
// in: reference PPQ

cout << "# patients waiting: " << priQueue.size() << endl;
	cout << "  Arrival #   Priority Code   Patient Name\n"
		  << "+-----------+---------------+--------------+\n";
	cout << priQueue.to_string() << "\n";
}

void execCommandsFromFileCmd(const string& filename,
                             PatientPriorityQueue<Patient>&priQueue) {
// Reads a text file with each command on a separate line and executes the
// lines as if they were typed into the command prompt.
// in: filepath, reference PPQ

	ifstream infile;
	string line;

	// open and read from file
	infile.open(filename);
	if (infile) {
		while (getline(infile, line)) {
		    cout << "\ntriage> " << line;
			cout << "\ntriage> " << line;
			// process file input
			processLine(line, priQueue);
		}
	} else {
		cout << "Error: could not open file.\n";
	}
	// close file
	infile.close();
}

string delimitBySpace(string &s) {
// Delimits (by space) the string from user or file input.
// in: string reference
// modify: deletes and returns next string segment between spaces
	unsigned pos = 0;
	char delimiter = ' ';
	string result = "";

	pos = s.find(delimiter);
	if (pos != string::npos) {
		result = s.substr(0, pos);
		s.erase(0, pos + 1);
	}
	return result;
}

void welcome() {
// Displays welcome to hospital message
    stringstream sso;
    sso << "\n**********************\n";
    sso << "SEATTLE GRACE HOSPITAL\n";
    sso << "**********************\n";

    sso << "Now entering the emergency room...\n";
    sso << "The triage nurse will now ascertain your waiting room priority.."
           ".\n";
    sso << "Type \'help\' for command descriptions\n";
    cout << sso.str();
}

void goodbye() {
// Displays leaving hospital message
    stringstream sso;
    sso << "\n**********************************\n";
    sso << "NOW EXITING SEATTLE GRACE HOSPITAL\n";
    sso << "**********************************\n";
    sso << "Thank you for visit, we hope you feel better soon!\n";
    cout << sso.str();
}

void help() {
// Displays help table
	cout << "add <priority-code> <patient-name>\n"
<< "            Adds the patient to the triage system.\n"
<< "            <priority-code> must be one of the 4 accepted priority codes:\n"
<< "                1. immediate 2. emergency 3. urgent 4. minimal\n"
<< "            <patient-name>: patient's full legal name (may contain spaces)\n"
<< "next        Announces the patient to be seen next. Takes into account the\n"
<< "            type of emergency and the patient's arrival order.\n"
<< "peek        Displays the patient that is next in line, but keeps in queue\n"
<< "list        Displays the list of all patients that are still waiting\n"
<< "            in heap order.\n"
<< "load <file> Reads the file and executes the command on each line\n"
<< "help        Displays this menu\n"
<< "quit        Exits the program\n";
}


std::string ltrim(const std::string &s) {
// Trims left whitespace
// in: string reference
// out: modified string
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s) {
// Trims right whitespace
// in: string reference
// out: modified string
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
// Trims left and right whitespace
// in: string reference
// out: modified string
    return rtrim(ltrim(s));
}