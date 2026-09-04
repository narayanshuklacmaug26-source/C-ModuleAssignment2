//============================================================================
// Name        : HospitalPatientRegistry.cpp
// Author      : Narayan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Paitent{

	int patientId;
	string  name;
	int age;
	string ward;
	const string bloodGroup;

public:

	Paitent():patientId(0), name("Unkown"), age(0), ward("General"), bloodGroup("o+"){ //Default constructor.
	   cout << " Default Constructor." << endl;

   }

	Paitent(int id, const string & name):
		patientId(id),name(name),age(0),ward("Emergency"),bloodGroup("o+"){ // Emergency constructor.


   }


	Paitent(int id,const string& name, 	int age, const string&ward, const string & bg) // Full admission constructor.
	:patientId(id),name(name),age(age),ward(ward),bloodGroup(bg)
	{



	}

	~Paitent(){
		cout<<"[Destructor] Paitent "<<name<<" Discharged "<<endl;
	}


	void displayPaitentRecord() const{
		 cout<<"\n Patient record"<<endl;
		 cout << "ID   : " << patientId << endl;
		 cout<<"Name is :"<< name<<endl;
		 cout<<"Age is "<<age<<endl;
		 cout<<"Ward is "<<ward<<endl;
		 cout<<"BloodGroup "<<bloodGroup<<endl;


	}

	void transferWard(const string & newward){
		cout<<"\n ward transfer "<<name<<"->"<<newward<<endl;
		ward = newward;


	}



};

int main() {

	Paitent p();
	Paitent p1(1,"rahul");
	Paitent p2(2,"Vishal",23,"General ward","A");


   Paitent* paitent = new Paitent[4]; // . Create dynamic array of 4 patients

   for(int i=0; i<4; i++){
	   paitent[i].displayPaitentRecord();

   }

    p2.transferWard("ICU");   // 4. Transfer one patient's ward

    delete[] paitent;

    cout << "\nEnd of main()" << endl;

    // 6. Stack objects will automatically
    // be destroyed when main() ends


	return 0;
}
