#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {

	void reverse() {
		int num = 0;
		cout << "Enter the number of double values: " << endl;
		cin >> num;
		double* doubles = new double[num];
		for (int i = 0; i < num; i++) {
			cout << i + 1<<" ";
			cin >> doubles[i];
		}
		for (int i = 0; i < num; i++) {
			cout << doubles[num - i - 1] << endl;
		}
		delete[] doubles;
		doubles = nullptr;
	}

    Contact* getContact(){
        Contact* person = nullptr;
        person = new Contact();
        cout << "Name: ";
        cin >> person->m_name;
        cout << "Last Name: ";
        cin >> person->m_lastname;
        cout << "Phone Number: ";
        cin >> person->m_phoneNumber;
        return person;
    }
    void display(const Contact& person){
        cout << person.m_name << " " << person.m_lastname << ", +" << person.m_phoneNumber << endl;
    }
    void dellocate(Contact* person){
        delete person;
        person = nullptr;
    }
    void setEmpty(Contact& person){
        person.m_name[0] = '\0';
        person.m_lastname[0] = '\0';
        person.m_phoneNumber = 0;
    }





}