/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <iostream>
#include "student.h"
#include <iomanip> 
#include <string> 
#include <cstring>

using namespace std;


/*
* function_identifier: constructor for student
* parameters: string last,first name, id, majorCode, double gpa, charges aid 
* return value: nothing 
*/ 
student::student(string last, string first, string id, string majorCode, 
                  double GPA, double charge, double aid):finances(charge, aid){
  
  // set 
  lastName = last; 
  firstName = first;

  // error check for student id 
  if(checkID(id)){
    studentID = id;
  }else{
    studentID = "";
    cout << "Error, invalid student ID." << endl;
  }

  // error check for gpa 
  if(GPA >= 0 && GPA <= 4){
    gpa = GPA;
  }else{
    gpa = 0.0;
    cout << "Error, invalid GPA." << endl;
  }
  
  majorsCodeCount = 0;
  // open majors file 
  majorsFile.open("majorsList.txt");
  // read into array 
  for(int k = 0; k < MAX_MAJORS; k++ ){
    // read in line 
    getline(majorsFile, majorCodes[k]);
    // increment 
    majorsCodeCount++;
    // reach end of file 
    if(majorsFile.eof()){
      break;
    }
  }
  
  
  // get full major 
  major = expandMajorCode(majorCode);
  if(major == "Error"){
    cout << "Error, invalid student major." << endl;
  }
  // if empty string 
  if(majorCode == ""){
    major = "Error";
    cout << "Error, invalid student major." << endl;
  }

  // set from money 
  ch = charge;
  finAid = aid;

}

// deconstructor 
student::~student(){
  // close file 
  majorsFile.close();
}
//********************************************************


 /*
* function_identifier: return values 
* parameters: nothing 
* return value: nothing 
*/ 
string student::getLastName() const{
  return lastName;
}

string student::getFirstName() const{
  return firstName;

}

string student::getID() const{
  return studentID;
}

string student::getMajor() const{
  return major;
}

double student::getGPA() const{
  return gpa;
}



/*
* function_identifier: check if ID all good 
* parameters: string id  
* return value: bool true if good, false if bad 
*/
bool student::checkID(string id) const {
  // vars 
  bool answer = false;
  bool nums = true;

  // loop throuh string 
  for(unsigned int i = 1; i < id.size(); i++){
    // check if not only numbers
    if(!(id[i] >= '0' && id[i] <= '9')){
        nums = false;
        break;
    }
  }
  
  // check if start with L & only 10 char
  if(id[0] == 'L' && id.length() == 10 && nums){
    answer = true;  
  }

  return answer;
}




/*
* function_identifier: find major and expand to full word
* parameters: string major 
* return value: major expanded 
*/
string student::expandMajorCode(string major){
  string majorExpand = "Error";
  // loop through array 
  for(int i = 0; i < majorsCodeCount; i++){
    // check if major in array 
    if(majorCodes[i].substr(0, major.size()).find(major) != string::npos){
      // set to found arra 
      majorExpand = majorCodes[i];
      break;
    }
    
  }
  // default return error
  return majorExpand;
}



//********************************************************

/*
* function_identifier: set last, first name 
* parameters: string last, string first name  
* return value: nothing 
*/
void student::setName(string lastN, string firstN){
  lastName = lastN;
  firstName = firstN;
}

/*
* function_identifier: set id 
* parameters: string id
* return value: nothing 
*/
void student::setID(string id){
  // error check 
  if(checkID(id)){
    studentID = id;
  }else{
    studentID = "";
    cout << "Error, invalid student ID." << endl;
  }
}

/*
* function_identifier: set major 
* parameters: string major code
* return value: nothing 
*/
void student::setMajor(string majorCode){
  // get full major
  major = expandMajorCode(majorCode);

  // error check if error & majorCode is not Error
  if(major == "Error" && majorCode != "Error"){
    cout << "Error, invalid student major." << endl;
  }
  // error check if equal 
  if(majorCode == major){
    major = "Error";
    cout << "Error, invalid student major." << endl;
  }
  // if empty string 
  if(majorCode == ""){
    major = "Error"; 
    cout << "Error, invalid student major." << endl;
  }
  
}

/*
* function_identifier: set gpa
* parameters: double gradePointAverage
* return value: nothing 
*/
void student::setGPA(double gradePointAverage){
  // error check for gpa 
  if(gradePointAverage >= 0.0 && gradePointAverage <= 4.0){
    gpa = gradePointAverage;
  }else{
    gpa = 0.0;
    cout << "Error, invalid GPA." << endl;
  }
}

/*
* function_identifier: set charge & aid 
* parameters: double charge, aid 
* return value: nothing 
*/
void student::setCharges(double chrge, double fAid){
  // call to money class function 
  finances.setCharges(chrge, fAid);
}

/*
* function_identifier: set charge & aid 
* parameters: double charge, aid 
* return value: nothing 
*/
void student::getCharges(double &charges, double &financialAid){
  // call to money class func
  finances.getCharges(charges, financialAid);
}



double student::getBalance() const{
  double bal = 0;
  bal = finances.getBalance();
  
  return bal;
}



//********************************************************

 /*
* function_identifier: output student details 
* parameters: nothing 
* return value: nothing 
*/ 
void student::showStudent(){
  finances.getCharges(ch, finAid);
  string indent(5, ' '); 
  string bars; 
  bars.append(70, '-');

  
  cout << endl << bars << endl;
  cout << "Student Summary" << endl;
  cout << indent << "   Name: " << lastName << ", " << firstName << endl;
  cout << indent << "     ID: " << studentID << endl;
  cout << indent << "  Major: " << major << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << indent << "    GPA: " << setw(8) << gpa << endl; 
  cout << indent << "Charges: " << setw(8) << ch;
  cout << indent << indent << indent << "Financial Aid: ";
  cout << setw(8) << finAid << endl;
  cout << indent << "Balance: " << setw(8) << finances.getBalance() << endl;
}

