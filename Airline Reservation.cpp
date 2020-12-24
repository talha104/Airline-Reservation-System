#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class seats
{
protected:
	int price;
	int *seat_no;
	int *booked;
	int pos;
	int distance;
public:
	int getprice()
	{
		return price;
	}
	void setprice(int p)
	{
		price = p;
	}
	int *getseat()
	{
		return seat_no;
	}
	void setseat(int *s)
	{
		seat_no = s;
	}
	int getdistance()
	{
		return distance;
	}
	void setdistance(int d)
	{
		distance = d;
	}
	virtual int calculateprice(int n)=0;
};

class first :public seats
{
public:
	first()
	{
		seat_no = new int[20];
		for (int i = 0; i < 20; i++)
		{
			seat_no[i] = i + 1;
		}
		booked = new int[20];
		distance = 0;
		price = 0;
		pos = 0;
	}

	void addseat()
	{
		pos = 0;
		int n;
		bool a = false;
		for (int i = 0; i < 20; i++)
		{
			if (seat_no[i] == 0)
			{
				pos++;
			}
		}

		if (pos == 20)
		{
			a = true;
		}

		if (a == false)
		{
			for (int i = 0; i < 20; i++)
			{
				cout << "\t\t\t" << seat_no[i] << "\t\t";
			}
			do
			{
				cin >> n;
			} while (seat_no[n] == 0 || n < 0 || n>20);

			booked[n - 1] = seat_no[n - 1];
			seat_no[n - 1] = 0;
		}

		if (a == true)
		{
			cout << "Sorry this class is out of seats!\n";
		}
	}

	void cancelseat(int a)
	{
		if (seat_no[a - 1] == 0)
		{
			seat_no[a - 1] = booked[a - 1];
			booked[a - 1] = 0;
			cout << "Seat "<<a<<" Canceled!\n";
		}
		else if (seat_no[a - 1] != 0)
		{
			cout << "This seat has not been booked yet!\n";
		}
	}

	int calculateprice(int n)
	{
		price = n * (getdistance() * 40);
		return price;
	}
};

class business :public seats
{
public:
	business()
	{
		seat_no = new int[30];
		for (int i = 0; i < 30; i++)
		{
			seat_no[i] = i + 1;
		}
		booked = new int[30];
		distance = 0;
		price = 0;
		pos = 0;
	}
	void addseat()
	{
		pos = 0;
		int n;
		bool a = false;
		for (int i = 0; i < 30; i++)
		{
			if (seat_no[i] == 0)
			{
				pos++;
			}
		}

		if (pos == 30)
		{
			a = true;
		}

		if (a == false)
		{
			for (int i = 0; i < 30; i++)
			{
				cout << "\t\t\t" << seat_no[i] << "\t\t";
			}
			do
			{
				cout << endl;
				cin >> n;
			} while (seat_no[n] == 0 || n < 0 || n>30);

			booked[n - 1] = seat_no[n - 1];
			seat_no[n - 1] = 0;
		}

		if (a == true)
		{
			cout << "Sorry this class is out of seats!\n";
		}
	}

	void cancelseat(int a)
	{
		if (seat_no[a - 1] == 0)
		{
			seat_no[a - 1] = booked[a - 1];
			booked[a - 1] = 0;
			cout << "Seat " << a << " Canceled!\n";
		}
		else if (seat_no[a - 1] != 0)
		{
			cout << "This seat has not been booked yet!\n";
		}
	}

	int calculateprice(int n)
	{
		price = n * (getdistance() * 20);
		return price;
	}
};

class economy :public seats
{

public:
	economy()
	{
		seat_no = new int[60];
		for (int i = 0; i < 60; i++)
		{
			seat_no[i] = i + 1;
		}
		booked = new int[60];
		distance = 0;
		price = 0;
		pos = 0;
	}
	void addseat()
	{
		pos = 0;
		int n;
		bool a = false;
		for (int i = 0; i < 60; i++)
		{
			if (seat_no[i] == 0)
			{
				pos++;
			}
		}

		if (pos == 60)
		{
			a = true;
		}

		if (a == false)
		{
			for (int i = 0; i < 60; i += 3)
			{
				cout << "\t\t\t   " << i + 1 << " " << i + 2 << " " << i + 3 << "\t";
			}
			do
			{
				cin >> n;
			} while (seat_no[n] == 0 || n < 0 || n>60);

			booked[n - 1] = seat_no[n - 1];
			seat_no[n - 1] = 0;
		}

		if (a == true)
		{
			cout << "Sorry this class is out of seats!\n";
		}
	}

	void cancelseat(int a)
	{
		if (seat_no[a - 1] == 0)
		{
			seat_no[a - 1] = booked[a - 1];
			booked[a - 1] = 0;
			cout << "Seat " << a << " Canceled!\n";
		}
		else if (seat_no[a - 1] != 0)
		{
			cout << "This seat has not been booked yet!\n";
		}
	}


	int calculateprice(int n)
	{
		price = n * (getdistance() * 10);
		return price;
	}
};

class flight
{
	string airline;
	string departure;
	string destination;
	string date;
public:
	string getair()
	{
		return airline;
	}
	void setair(string f)
	{
		airline = f;
	}
	string getdeparture()
	{
		return departure;
	}
	void setdeparture(string d)
	{
		departure = d;
	}
	string getdestination()
	{
		return destination;
	}
	void setdestination(string d)
	{
		destination = d;
	}
	string getdate()
	{
		return date;
	}
	void setdate(string d)
	{
		date = d;
	}

	void dom_deptenteries()
	{
		int dept;
		cout << "Enter departure:\n";
		cout << "1.Lahore\n";
		cout << "2.Karachi\n";
		cout << "3.Islamabad\n";
		cout << "4.Sialkot\n";
		cout << "5.Multan\n";
		cin >> dept;
		switch (dept)
		{
		case 1:
			departure = "Lahore";
			break;
		case 2:
			departure = "Karachi";
			break;
		case 3:
			departure = "Islamabad";
			break;
		case 4:
			departure = "Sialkot";
			break;
		case 5:
			departure = "Multan";
			break;
		}
	}
	void dom_destenteries()
	{
		int dest;
		cout << "1.Lahore\n";
		cout << "2.Karachi\n";
		cout << "3.Islamabad\n";
		cout << "4.Sialkot\n";
		cout << "5.Multan\n";
		do {
			cout << "Please enter the destination:\n";
			cin >> dest;
			switch (dest)
			{
			case 1:
				destination = "Lahore";
				break;
			case 2:
				destination = "Karachi";
				break;
			case 3:
				destination = "Islamabad";
				break;
			case 4:
				destination = "Sialkot";
				break;
			case 5:
				destination = "Multan";
				break;
			}
		} while (departure == destination || dest > 5 || dest < 1);
	}

	void int_deptenteries()
	{
		int dept;
		cout << "1.Paris\n";
		cout << "2.New York\n";
		cout << "3.Manchester\n";
		cout << "4.Islamabad\n";
		cout << "5.Toronto\n";
		do {
			cout << "Enter the departure:\n";
			cin >> dept;
			switch (dept)
			{
			case 1:
				departure = "Paris";
				break;
			case 2:
				departure = "New-York";
				break;
			case 3:
				departure = "Manchester";
				break;
			case 4:
				departure = "Islamabad";
				break;
			case 5:
				departure = "Toronto";
				break;
			}
		} while (dept > 5 || dept < 1);
	}

	void int_destenteries()
	{
		int dest;
		cout << "1.Paris\n";
		cout << "2.New York\n";
		cout << "3.Manchester\n";
		cout << "4.Islamabad\n";
		cout << "5.Toronto\n";
		do {
			cout << "Please enter the destination:\n";
			cin >> dest;
			switch (dest)
			{
			case 1:
				destination = "Paris";
				break;
			case 2:
				destination = "New-York";
				break;
			case 3:
				destination = "Manchester";
				break;
			case 4:
				destination = "Islamabad";
				break;
			case 5:
				destination = "Toronto";
				break;
			}
		} while (departure == destination || dest > 5 || dest < 1);
	}
};


class passenger
{
	string fname;
	string lname;
	string passport;
	string contact;
public:
	string getfname()
	{
		return fname;
	}
	void setfname(string a)
	{
		fname = a;
	}
	string getlname()
	{
		return lname;
	}
	void setlname(string l)
	{
		lname = l;
	}
	string getpassport()
	{
		return passport;
	}
	void setpassport(string p)
	{
		passport = p;
	}
	string getcontact()
	{
		return contact;
	}
	void setcontact(string c)
	{
		contact = c;
	}
	void enteries()
	{
		cout << "Enter passenger detail:\n";
		cout << "First name: ";
		cin >> fname;
		cout << "Last name: ";
		cin >> lname;
		cout << "Passport no: ";
		cin >> passport;
		cout << "Contact no: ";
		cin >> contact;
	}
	void display()
	{
		cout << "Name: " << fname << " " << lname << endl;
		cout << "Passport no: ";
		cout << passport << endl;
	}
};

class airplane
{
	flight f;
	passenger p;
public:
	void cancelseat(first f1, first f2, business b, business b2, economy e, economy e2)
	{
		int option1, option2, option3, number2;
		string date;
		cout << "1.Domestic Flight\n";
		cout << "2.International Flight\n";
		cout << "\nEnter your option:\n";
		do
		{
			cin >> option1;
		} while (option1 > 2 || option1 < 1);

		string pass;
		switch (option1)
		{
		case 1:
			cout << "Enter the date of journey:\n(DDMMYY) ";
			cin >> date;
			f.dom_deptenteries();
			f.dom_destenteries();
			cout << "1.PIA\n";
			cout << "2.Air Blue\n";
			cout << "3.Etihad\n";
			do {
				cout << "Select the flight:\n";
				cin >> option2;
			} while (option2 < 1 || option2>3);
			cout << "1.First class\n";
			cout << "2.Business class\n";
			cout << "3.Economy class\n";
			do {
				cout << "Select the class:\n";
				cin >> option3;
			} while (option3 < 1 || option3>3);
			int n;

			cout << "Enter the passport no:\n";
			cin >> pass;
			switch (option2)
			{
			case 1:
				if (option3 == 1)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;
					ifstream fin;
					fin.open("PIA.txt");
					ofstream fout;
					fout.open("PIA.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						f1.cancelseat(n);
					}
				}
				if (option3 == 2)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("PIA.txt");
					ofstream fout;
					fout.open("PIA.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						b.cancelseat(n);
					}
				}
				if (option3 == 3)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("PIA.txt");
					ofstream fout;
					fout.open("PIA.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						e.cancelseat(n);
					}
				}
				break;

			case 2:
				if (option3 == 1)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;
					ifstream fin;
					fin.open("Air_Blue.txt");
					ofstream fout;
					fout.open("Air_Blue.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						f1.cancelseat(n);
					}
				}
				if (option3 == 2)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Air_Blue.txt");
					ofstream fout;
					fout.open("Air_Blue.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						b.cancelseat(n);
					}
				}
				if (option3 == 3)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Air_Blue.txt");
					ofstream fout;
					fout.open("Air_Blue.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						e.cancelseat(n);
					}
				}
				break;
			case 3:
				if (option3 == 1)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;
					ifstream fin;
					fin.open("Etihad.txt");
					ofstream fout;
					fout.open("Etihad.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						f1.cancelseat(n);
					}
				}
				if (option3 == 2)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Etihad.txt");
					ofstream fout;
					fout.open("Etihad.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						b.cancelseat(n);
					}
				}
				if (option3 == 3)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Etihad.txt");
					ofstream fout;
					fout.open("Etihad.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						e.cancelseat(n);
					}
				}
				break;
			}
			
			break;
		case 2:
			cout << "Enter the date of journey:\n(DDMMYY) ";
			cin >> date;
			f.int_deptenteries();
			f.int_destenteries();
			cout << "Select the flight:\n";
			cout << "1.PIA\n";
			cout << "2.Air Blue\n";
			cout << "3.Etihad\n";
			cin >> option2;
			cout << "Select the class:\n";
			cout << "1.First class\n";
			cout << "2.Business class\n";
			cout << "3.Economy class\n";
			cin >> option3;
			switch (option2)
			{
			case 1:
				if (option3 == 1)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("PIA.txt");
					ofstream fout;
					fout.open("PIA.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						f2.cancelseat(n);
					}
				}
				if (option3 == 2)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("PIA.txt");
					ofstream fout;
					fout.open("PIA.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						b2.cancelseat(n);
					}
				}
				if (option3 == 3)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("PIA.txt");
					ofstream fout;
					fout.open("PIA.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						e2.cancelseat(n);
					}
				}
				break;

			case 2:
				if (option3 == 1)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Air_Blue.txt");
					ofstream fout;
					fout.open("Air_Blue.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						f2.cancelseat(n);
					}
				}
				if (option3 == 2)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Air_Blue.txt");
					ofstream fout;
					fout.open("Air_Blue.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						b2.cancelseat(n);
					}
				}
				if (option3 == 3)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Air_Blue.txt");
					ofstream fout;
					fout.open("Air_Blue.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						e2.cancelseat(n);
					}
				}
				break;

			case 3:
				if (option3 == 1)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Etihad.txt");
					ofstream fout;
					fout.open("Etihad.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						f2.cancelseat(n);
					}
				}
				if (option3 == 2)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Etihad.txt");
					ofstream fout;
					fout.open("Etihad.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						b2.cancelseat(n);
					}
				}
				if (option3 == 3)
				{
					cout << "How many seats do you want to cancel: ";
					cin >> number2;

					ifstream fin;
					fin.open("Etihad.txt");
					ofstream fout;
					fout.open("Etihad.txt");
					if (fin.is_open())
					{
						for (string line; getline(fin, line);)
						{
							if (line.find(pass) != string::npos)
							{
								fout << "SEAT CANCELLED!!";
							}
						}
					}
					fin.close();
					fout.close();

					for (int i = 0; i < number2; i++)
					{
						cout << "Enter the seat no: ";
						cin >> n;
						e2.cancelseat(n);
					}
				}
				break;
			}
			break;
		}
	}
};







int main()
{
	int option, option1, option2, option3, number2, total;
	string date;
	airplane a;
	flight f;
	passenger p;
	first f1, f2;
	business b, b2;
	economy e, e2;

	do
	{
	cout << "1.Book Flight\n";
	cout << "2.Cancel Flight\n";
	cout << "3.Exit\n";

		do
		{
			cout << "\nEnter your choice:\n";
			cin >> option;
		} while (option < 1 || option>4);

	
	switch (option)
	{
	case 1:
		cout << "1.Domestic Flight\n";
		cout << "2.International Flight\n";
		cout << "\nEnter your option:\n";
		cin >> option1;
		switch (option1)
		{
		case 1:
			cout << "Enter the date of journey:\n(DDMMYY) ";
			cin >> date;
			f.dom_deptenteries();
			f.dom_destenteries();
			cout << "Flights found:\n";
			//flights

			if ((f.getdeparture() == "Lahore" && f.getdestination() == "Karachi") || (f.getdeparture() == "Karachi" && f.getdestination() == "Lahore"))//condition
			{
				f1.setdistance(1212);
				b.setdistance(1212);
				e.setdistance(1212);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) - 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) - 2000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");
				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";

				do
				{
					cin >> option3;
				} while (option3 < 0 || option3>3);

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout<<number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() +" "+ c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();

					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air bLue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Lahore" && f.getdestination() == "Islamabad") || (f.getdeparture() == "Islamabad" && f.getdestination() == "Lahore"))//condition
			{
				f1.setdistance(400);
				b.setdistance(400);
				e.setdistance(400);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 1000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) + 1000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 1000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Lahore" && f.getdestination() == "Sialkot") || (f.getdeparture() == "Sialkot" || f.getdestination() == "Lahore"))//condition
			{
				f1.setdistance(250);
				b.setdistance(250);
				e.setdistance(250);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 1000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) + 1000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 1000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}


			else if ((f.getdeparture() == "Lahore" && f.getdestination() == "Multan") || (f.getdeparture() == "Multan" && f.getdestination() == "Lahore"))//condition
			{
				f1.setdistance(360);
				b.setdistance(360);
				e.setdistance(360);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 1000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) + 1000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 1000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Karachi" && f.getdestination() == "Islamabad") || (f.getdeparture() == "Islamabad" && f.getdestination() == "Karachi"))//condition
			{
				f1.setdistance(1500);
				b.setdistance(1500);
				e.setdistance(1500);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) - 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) - 2000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Karachi" && f.getdestination() == "Sialkot") || (f.getdeparture() == "Sialkot" && f.getdestination() == "Karachi"))//condition
			{
				f1.setdistance(1400);
				b.setdistance(1400);
				e.setdistance(1400);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) - 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) - 2000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) +7000 << "\tRefundable\n";
									total += b.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) -7000<< "\tRefundable\n";
									total += b.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1)+7000 << "\tRefundable\n";
									total += e.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) -7000<< "\tRefundable\n";
									total += e.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Karachi" && f.getdestination() == "Multan") || (f.getdeparture() == "Multan" && f.getdestination() == "Karachi"))//condition
			{
				f1.setdistance(1212);
				b.setdistance(1212);
				e.setdistance(1212);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) - 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) - 2000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1)+7000 << "\tRefundable\n";
									total += f1.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) -7000<< "\tRefundable\n";
									total += f1.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) +7000<< "\tRefundable\n";
									total += e.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) -7000<< "\tRefundable\n";
									total += e.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Islamabad" && f.getdestination() == "Sialkot") || (f.getdeparture() == "Sialkot" && f.getdestination() == "Islamabad"))//condition
			{
				f1.setdistance(900);
				b.setdistance(900);
				e.setdistance(900);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) - 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) - 2000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) +7000<< "\tRefundable\n";
									total += f1.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) -7000<< "\tRefundable\n";
									total += f1.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1)+7000 << "\tRefundable\n";
									total += b.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) -7000<< "\tRefundable\n";
									total += b.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) +7000<< "\tRefundable\n";
									total += e.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1)-7000 << "\tRefundable\n";
									total += e.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Islamabad" && f.getdestination() == "Multan") || (f.getdeparture() == "Multan" && f.getdestination() == "Islamabad"))//condition
			{
				f1.setdistance(600);
				b.setdistance(600);
				e.setdistance(600);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 1000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) + 1000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 1000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) +7000<< "\tRefundable\n";
									total += f1.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) -7000<< "\tRefundable\n";
									total += f1.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) +7000<< "\tRefundable\n";
									total += b.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) -7000<< "\tRefundable\n";
									total += b.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air_Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) +7000<< "\tRefundable\n";
									total += e.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) -7000<< "\tRefundable\n";
									total += e.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Sialkot" && f.getdestination() == "Multan") || (f.getdeparture() == "Multan" && f.getdestination() == "Sialkot"))//condition
			{
				f1.setdistance(500);
				b.setdistance(500);
				e.setdistance(500);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 2000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b.calculateprice(1) + 2000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 2000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 1000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b.calculateprice(1) + 1000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e.calculateprice(1) + 1000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f1.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
							total += f1.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) << "\tRefundable\n";
									total += f1.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) +7000<< "\tRefundable\n";
									total += f1.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f1.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f1.calculateprice(1) -7000<< "\tRefundable\n";
									total += f1.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
							total += b.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) << "\tRefundable\n";
									total += b.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) +7000<< "\tRefundable\n";
									total += b.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b.calculateprice(1) - 7000;

							ofstream fout;
							fout.open("Etihad.txt", ios::app);
							if (fout.is_open())
							{
								fout << number2 << " seat(s) booked for:\n";
								for (int i = 0; i < number2; i++)
								{
									string name, passport, contact;
									name = c[i].getfname() + " " + c[i].getlname();
									passport = c[i].getpassport();
									contact = c[i].getcontact();
									fout << "Name: " << name << endl;
									fout << "Passport: " << passport << endl;
									fout << "Contact: " << contact << endl;

									fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
									fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
									total = 0;
									for (int i = 0; i < number2; i++)
									{
										fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b.calculateprice(1) -7000<< "\tRefundable\n";
										total += b.calculateprice(1)-7000;
									}
									fout << "Your total is: Rs." << total << endl;
								}
							}
							else
							{
								cout << "File not open!\n";
							}
							fout.close();
						}
						cout << "Your total is: Rs." << total << endl;
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
							total += e.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) << "\tRefundable\n";
									total += e.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) +7000<< "\tRefundable\n";
									total += e.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e.calculateprice(1) -7000<< "\tRefundable\n";
									total += e.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}
			break;


		case 2:
			cout << "Enter the date of journey:\n(DDMMYY) ";
			cin >> date;
			f.int_deptenteries();
			f.int_destenteries();

			cout << "Flights found:\n";
			//flights

			if ((f.getdeparture() == "Islamabad" && f.getdestination() == "Paris") || (f.getdeparture() == "Paris" && f.getdestination() == "Islamabad"))//condition
			{
				f2.setdistance(7731);
				b2.setdistance(7731);
				e2.setdistance(7731);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) +7000<< "\tRefundable\n";
									total += f2.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) -7000<< "\tRefundable\n";
									total += f2.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) +7000<< "\tRefundable\n";
									total += b2.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) -7000<< "\tRefundable\n";
									total += b2.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) +7000<< "\tRefundable\n";
									total += e2.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) -7000<< "\tRefundable\n";
									total += e2.calculateprice(1)-7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Islamabad" && f.getdestination() == "New York") || (f.getdeparture() == "New York" && f.getdestination() == "Islamabad"))//condition
			{
				f2.setdistance(11073);
				b2.setdistance(11073);
				e2.setdistance(11073);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Islamabad" && f.getdestination() == "Manchester") || (f.getdeparture() == "Manchester" && f.getdestination() == "Islamabad"))//condition
			{
				f2.setdistance(8315);
				b2.setdistance(8315);
				e2.setdistance(8315);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Islamabad" && f.getdestination() == "Toronto") || (f.getdeparture() == "Toronto" && f.getdestination() == "Islamabad"))//condition
			{
				f2.setdistance(10965);
				b2.setdistance(10965);
				e2.setdistance(10965);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Paris" && f.getdestination() == "New-York") || (f.getdeparture() == "New-York" && f.getdestination() == "Paris"))//condition
			{
				f2.setdistance(5834);
				b2.setdistance(5834);
				e2.setdistance(5834);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Paris" && f.getdestination() == "Manchester") || (f.getdeparture() == "Manchester" && f.getdestination() == "Paris"))//condition
			{
				f2.setdistance(3544);
				b2.setdistance(3544);
				e2.setdistance(3544);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Paris" && f.getdestination() == "Toronto") || (f.getdeparture() == "Toronto" && f.getdestination() == "Paris"))//condition
			{
				f2.setdistance(5997);
				b2.setdistance(5997);
				e2.setdistance(5997);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "New-York" && f.getdestination() == "Manchester") || (f.getdeparture() == "Manchester" && f.getdestination() == "New-York"))//condition
			{
				f2.setdistance(5000);
				b2.setdistance(5000);
				e2.setdistance(5000);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}

			else if ((f.getdeparture() == "Manchester" && f.getdestination() == "Toronto") || (f.getdeparture() == "Toronto" && f.getdestination() == "Manchester"))//condition
			{
				f2.setdistance(5491);
				b2.setdistance(5491);
				e2.setdistance(5491);
				cout << "Airline:\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
				cout << "\1.PIA(1)      \t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) << endl;
				cout << "\2.Air Blue(2)\t14:00\t\t18:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusiness\tRs." << b2.calculateprice(1) + 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << endl;
				cout << "\3.Etihad(3) \t18:00\t\t22:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
				cout << "\t\t\t\t\t\tBusines\t\tRs." << b2.calculateprice(1) - 7000 << endl;
				cout << "\t\t\t\t\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << endl;
				cin >> option2;

				if (option2 == 1)
				{
					f.setair("PIA");

				}
				else if (option2 == 2)
				{
					f.setair("Air Blue");
				}
				else if (option2 == 3)
				{
					f.setair("Etihad");
				}


				cout << "Enter flight class:\n";
				cout << "Press 1 for First Class\n";
				cout << "Press 2 for Business Class\n";
				cout << "Press 3 for Economy Class\n";
				cin >> option3;

				cout << "How many seats would you like to book? ";
				cin >> number2;
				passenger *c;
				c = new passenger[number2];
				cout << "\nEnter the passengers details:\n";
				for (int i = 0; i < number2; i++)
				{
					cout << "For Passenger " << i + 1 << ":" << endl;
					c[i].enteries();
				}

				cout << "Booking detail:\n";

				switch (option3)
				{
				case 1:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						f2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
							total += f2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) << "\tRefundable\n";
									total += f2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) +7000<< "\tRefundable\n";
									total += f2.calculateprice(1)+7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += f2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tFirst\t\tRs." << f2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += f2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 2:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						b2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
							total += b2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) << "\tRefundable\n";
									total += b2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += b2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tBusiness\t\tRs." << b2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += b2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				case 3:
					cout << "Select the seats:\n\n";
					for (int i = 0; i < number2; i++)
					{
						e2.addseat();
					}
					cout << number2 << " seat(s) booked for:\n";
					for (int i = 0; i < number2; i++)
					{
						c[i].display();
					}
					cout << "\nYour tickets:\n";
					cout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
					total = 0;
					if (option2 == 1)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
							total += e2.calculateprice(1);
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("PIA.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\1.PIA(1)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) << "\tRefundable\n";
									total += e2.calculateprice(1);
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 2)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) + 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Air_Blue.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\2.Air Blue(2)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) + 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) + 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					if (option2 == 3)
					{
						for (int i = 0; i < number2; i++)
						{
							cout << "\1.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
							total += e2.calculateprice(1) - 7000;
						}
						cout << "Your total is: Rs." << total << endl;

						ofstream fout;
						fout.open("Etihad.txt", ios::app);
						if (fout.is_open())
						{
							fout << number2 << " seat(s) booked for:\n";
							for (int i = 0; i < number2; i++)
							{
								string name, passport, contact;
								name = c[i].getfname() + " " + c[i].getlname();
								passport = c[i].getpassport();
								contact = c[i].getcontact();
								fout << "Name: " << name << endl;
								fout << "Passport: " << passport << endl;
								fout << "Contact: " << contact << endl;

								fout << "\nYour tickets for " << f.getdeparture() << " to " << f.getdestination() << ":\n";
								fout << "Airline:\tDate:\t\tDeparture:\tArrival:\tClass:\t\tPrice:\t\tCategory:\n";
								total = 0;
								for (int i = 0; i < number2; i++)
								{
									fout << "\3.Etihad(3)      \t" << date << "\t\t10:00\t\t14:05\t\tEconomy\t\tRs." << e2.calculateprice(1) - 7000 << "\tRefundable\n";
									total += e2.calculateprice(1) - 7000;
								}
								fout << "Your total is: Rs." << total << endl;
							}
						}
						else
						{
							cout << "File not open!\n";
						}
						fout.close();
					}
					break;
				}
			}
			break;
		}
		break;
	case 2:
		a.cancelseat(f1, f2, b, b2, e, e2);
		break;
	case 3:
		system("pause");
		return 0;		
		break;
	}
	cout << "Press 1 to go back to the main menu:\n";
	cout << "Press 2 to exit:\n";
	cin >> option;
	}while (option == 1);


	system("pause");
}