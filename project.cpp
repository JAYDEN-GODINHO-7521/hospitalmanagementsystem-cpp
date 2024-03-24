#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
const int n = 10;
int p = 0;
int patients_no = 0;

class hospital {
protected:
	string h_name;
	int available_bed;
	int doctor_no;
public:
	hospital()
	{
		cout << "\t\t\t\t\tEnter hospital name:";
		cin >> h_name;
		cout << "\t\t\t\t\tEnter number of avaliable beds:";
		cin >> available_bed;
		cout << "\t\t\t\t\tEnter number of doctors in the hospital:";
		cin >> doctor_no;
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
	}
	int putdata0() {
		cout << "\t\t\t\t\tHOSPITAL NAME IS:                       " << h_name << endl;
		cout << "\t\t\t\t\tAVAILABLE BED  IS:                      " << available_bed << endl;
		cout << "\t\t\t\t\tNUMBER OF PATIENT IS:                   " << patients_no << endl;
		cout << "\t\t\t\t\tNUMBER OF DOCTOR IN HOSPITAL:           " << doctor_no << endl;
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
		return 0;
	}
};
class patient
{
public:
	string name;
	float number;
	int age;
	string ID;
	string blood_group;
	string gender;

	int operator++()
	{
		cout << "\t\t\t\t\tEnter Name of Patient\n\t\t\t\t\t";
		cin >> name;
		cout << "\t\t\t\t\tEnter Phone Number of Patient\n\t\t\t\t\t";
		cin >> number;
		cout << "\t\t\t\t\tEnter Age of Patient\n\t\t\t\t\t";
		cin >> age;
		cout << "\t\t\t\t\tEnter Blood group of Patient\n\t\t\t\t\t";
		cin >> blood_group;
		cout << "\t\t\t\t\tEnter the gender of patient\n\t\t\t\t\t";
		cin >> gender;
		cout << "\t\t\t\t\tEnter the ID of patient\n\t\t\t\t\t";
		cin >> ID;
		p++;
		patients_no++;
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
		return 0;
	}

	void putdata1()
	{
		cout << "\t\t\t\t\tName of Patient:                        ";cout << name << endl;
		cout << "\t\t\t\t\tID of patient:                          " << ID << endl;
		cout << "\t\t\t\t\tNumber of Patient:                      " << number << endl;
		cout << "\t\t\t\t\tAge of Patient:                         " << age << endl;
		cout << "\t\t\t\t\tBlood group of Patient:                 " << blood_group << endl;
		cout << "\t\t\t\t\tThe gender of patient:                  " << gender << endl;
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";

	}
	void getname()
	{
		cout << name;
	}
	void discharge()
	{
		name = name + " (Discharged)";
	}
};
template <class t>
t room(t price, t days)
{
	t PRICE;
	PRICE = price*days;
	return PRICE;
}
class bill
{
	int rprice = 500, sevice_charge = 200, doc_charge = 1000, total, days;
	int a, b, c;
public:
	void cal_data4()
	{
		cout << "\t\t\t\t\tEnter number of days:";
		cin >> days;
		a = room(rprice, days);
		cout << "\t\t\t\t\tprice of room in days:" << a << endl;
		b = room(sevice_charge, days);
		cout << "\t\t\t\t\tservice charges of room in days:     RS:" << b << endl;
		c = room(doc_charge, days);
		cout << "\t\t\t\t\tdoctor charges of room in days:      RS:" << c << endl;
		total = a + b + c;
		cout << "\t\t\t\t\tTOTAL PRICE=                         RS:" << total << endl;
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
	}

};
class patient_history :public patient, public bill
{
	int time[10];
	string condition[10];
	string date[10];
	int i = 0, j = 0;
public:
	void get_data2()
	{
		cout << "\t\t\t\t\tEnter date:";
		cin >> time[i];
		cout << "\t\t\t\t\tEnter time:";
		cin >> date[i];
		cout << "\t\t\t\t\tEnter condition:";
		cin >> condition[i];
		i++;
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
	}
	void put_data2()
	{
		if (i == 0)
			cout << "\t\t\t\t\tData not Avaliable\n";
		else
		{
			cout << "\t\t\t\t\tEnter Sr.no\n";
			cout << "\t\t\t\t\tDate" << "\t" << "Time" << "\t" << "condition" << endl;
			for (j = 0;j < i;j++)
			{
				cout << "\t\t\t\t\t" << date[j] << "\t" << time[j] << "\t" << condition[j] << endl;
			}
		}
	}
};






int choice2, choice3;
int m = 0;

void patmenu(patient_history a[])
{
	int choice3;int choice2;
	cout << "\t\t\t\t\t";
	cin >> choice2;
	choice2 = choice2 - 1;
	cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
	do {
		cout << "\n\t\t\t\t\t1.Excess patient details\n\t\t\t\t\t2.Make an entry in records\n\t\t\t\t\t3.Excess patient Records\n\t\t\t\t\t4.Create bill\n\t\t\t\t\t5.Exit patient menu\n\t\t\t\t\t";
		cin >> choice3;
		switch (choice3)
		{
		case 1:
			a[choice2].putdata1();
			break;
		case 2:
			a[choice2].get_data2();
			break;
		case 3:
			a[choice2].put_data2();
			break;
		case 4:
			a[choice2].cal_data4();
			a[choice2].discharge();
			break;
		case 5:
			cout << "\t\t\t\t\tMenu exited sucessfully\n";
			break;
		default:
			cout << "\t\t\t\t\tWrong input\n";
			break;
		}
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
	} while (choice3 != 5);
}
int exc_pat_list(patient_history a[])
{
	if (p == 0)
	{
		cout << "\t\t\t\t\tData Not Avaliable\n";
	}
	else
	{
		cout << "\t\t\t\t\tEnter Sr.no\n";
		cout << "\t\t\t\t\tSr.no\t\tPatient's name\n";
		for (int g = 0;g < p;g++)
		{
			cout << "\t\t\t\t\t" << g + 1 << "\t\t";
			a[g].getname();
			cout << endl;
		}
		patmenu(a);
	}
	return 0;
}

int main()
{
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t _______________________________________________________________________________________\n";
	cout << "\t\t\t\t\t                                         		                                    ";
	cout << "\t\t\t\t\t                                          		                                    ";
	cout << "\t\t\t\t\t                                           		                                    ";
	cout << "\t\t\t\t\t                                          											";
	cout << "\t\t\t\t\t                                          		                                    ";
	cout << "\t\t\t\t\t                                          		                                     \n";
	cout << "\t\t\t\t\t                                 WELCOME TO                                           \n";
	cout << "\t\t\t\t\t                                                                                      \n";
	cout << "\t\t\t\t\t                          HOSPITAL MANAGEMENT SYSTEM                                  \n";
	cout << "\t\t\t\t\t                                                                                      \n";
	cout << "\t\t\t\t\t                                                                                      \n";
	cout << "\t\t\t\t\t                                                                                      \n";
	cout << "\t\t\t\t\t                                                                                      \n";
	cout << "\t\t\t\t\t                                                                                      \n";
	cout << "\t\t\t\t\t																						 \n";
	cout << "\t\t\t\t\t_______________________________________________________________________________________\n";




	int choice1;
	hospital h;
	patient_history a[n];
	patient b[n];
	do {
		cout << "\t\t\t\t\t1.Excess hospital details\n\t\t\t\t\t2.Excess patient list\n\t\t\t\t\t3.Enter new patient\n\t\t\t\t\t4.Close the program\n\t\t\t\t\t";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			h.putdata0();
			break;
		case 2:
			exc_pat_list(a);
			break;
		case 3:
			if (p<n)
			{
				++a[p];
			}
			else
				cout << "\t\t\t\t\tSORRY! beds full\n";
			break;
		case 4:
			cout << "\t\t\t\t\tProgram exited sucessfully\n";
			break;
		default:
			cout << "\t\t\t\t\tWrong input\n";
			break;
		}
		cout << "\t\t\t\t\t_______________________________________________________________________________________\n";
	} while (choice1 != 4);
}
