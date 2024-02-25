//DS ASSIGNMENT NUMBER 03
//AZFAR NAYYAN
//22L-7886 BSE-3C

//QUEUES

//RADIX SORT PROBLEM.

#include<iostream>
#include<string>

using namespace std;

template<class T>
class Queue               //QUEUE CLASS.
{
	struct Node
	{
		T data;
		Node* next;
	public:
		Node()
		{
			next = NULL;
		}
		Node(T const e)
		{
			next = NULL;
			data = e;
		}
	};

	Node* Front;
	Node* Rear;
	int s;

public:
	Queue()
	{
		Front = NULL;
		Rear = NULL;
		s = 0;
	}
	Queue(T const e)
	{
		Front = new Node(e);
		s = 1;
		Rear = Front;
	}
	bool IsEmpty()
	{
		if (s == 0) return true;
		else return false;
	}
	void Top(T& e)
	{
		if (IsEmpty() == true)
		{
			cout << "EMPTY QUEUE !!" << endl;
			return;
		}

		e = Front->data;
	}
	void enqueue(T const e)
	{
		if (IsEmpty() == true)
		{
			Front = new Node(e);
			s++;
			Rear = Front;
			return;
		}

		Node* temp = new Node(e);
		Rear->next = temp;
		Rear = Rear->next;
		s++;
	}
	void dequeue()
	{
		if (IsEmpty() == true)
		{
			cout << "EMPTY QUEUE !! NOTING TO DEQUEUE!!" << endl;
			return;
		}

		Node* temp = Front;
		Front = Front->next;
		s--;
		delete temp;
	}
	void printQueue()
	{
		cout << "THE QUEUE IS: ";
		if (IsEmpty() == true) {
			cout << "Empty Queue :) " << endl;
			return;
		}

		Node* current = Front;
		int i = 0;
		while (i < s) {
			cout << current->data;
			if (i != s - 1)cout << "-";
			current = current->next;
			i++;
		}
		cout << " :)" << endl;
	}
};

void integerRadixSort(int* arr, int k, int s)
{
	Queue<int>* myQueues = new Queue<int>[10];   //10 QUEUE BECAUSE OF 0-9 POSSIBLE DIGITS.

	int modulo = 10;                             //MODULO AND DIVISOR TO FIND DIGITS.
	int divi = 1;

	for (int j = 0; j < k; j++)                  //FIRST LOOP WHICH ENCOUNTERS K TIMES.
	{ 
		for (int i = 0; i < s; i++)                     //LOOP FOR EVERY NUMBER AND DIGIT ENQUEUE IN QUEUE.
		{
			int digit = (arr[i] % modulo) / divi;
			myQueues[digit].enqueue(arr[i]);
		}


		int index = 0;
		for (int x = 0; x < 10; x++)              //FOR EVERY Kth ITERATION IT DEQUEUES AND SORTS INTO SIMPLE ARRAY.
		{
			while (!myQueues[x].IsEmpty())
			{
				int num;
				myQueues[x].Top(num);
				myQueues[x].dequeue();
				arr[index] = num;
				index++;
			}
		}

		cout << "THE DATA AFTER " << j + 1 << " ITERATION: ";
		for (int f = 0; f < s; f++)
			cout << arr[f] << "-";
		cout << endl;

		modulo *= 10;
		divi *= 10;
	}
}

void stringRadixSort(string* arr, int k, int s)
{
	Queue<string>* myQueues = new Queue<string>[26];  //26 ALPHABETS 26 QUEUES

	int index = k - 1;                    //WE COMPARE FROM LAST CHARACTER

	for (int j = 0; j < k; j++)         //UPPER LOOP FOR K TIMES.
	{
		for (int i = 0; i < s; i++)                     
		{
			char temp = arr[i][index];

			int x = int(temp);                                     //INDEX IS BASICALLY FROM 0-25 BASED ON APLHABET.
			int INDEX = 0;
			if (x >= 65 && x <= 90) INDEX = temp - 'A';
			else if (x >= 97 && x <= 122) INDEX = temp - 'a';

			myQueues[INDEX].enqueue(arr[i]);
		}

	
		int arrayIndex = 0;
		for (int x = 0; x < 26; x++)              //FOR EVERY Kth ITERATION IT DEQUEUES AND SORTS INTO SIMPLE ARRAY.
		{
			while (!myQueues[x].IsEmpty())
			{
				string s;
				myQueues[x].Top(s);
				myQueues[x].dequeue();
				arr[arrayIndex] = s;
				arrayIndex++;
			}
		}

		cout << "THE DATA AFTER " << j + 1 << " ITERATION: ";
		for (int f = 0; f < s; f++)
			cout << arr[f] << "-";
		cout << endl;


		index--;
	}


}

int main()
{
	int* arr = new int[7];

	arr[0] = 329;
	arr[1] = 457;
	arr[2] = 657;
	arr[3] = 839;
	arr[4] = 436;
	arr[5] = 720;
	arr[6] = 355;

	cout << "THE UNSORTED DATA IS: ";
	for (int i = 0; i < 7; i++)
		cout << arr[i] << "-";
	cout << endl;

	integerRadixSort(arr, 3, 7);

	cout << "THE SORTED DATA IS: ";
	for (int i = 0; i < 7; i++)
		cout << arr[i] << "-";
	cout << endl << endl;

	string* arr1 = new string[5];

	arr1[0] = "MNO";
	arr1[1] = "DEF";
	arr1[2] = "JKL"; 
	arr1[3] = "GHI";
	arr1[4] = "ABC";

	cout << "THE UNSORTED DATA IS: ";
	for (int i = 0; i < 5; i++)
		cout << arr1[i] << "-";
	cout << endl;

	stringRadixSort(arr1, 3, 5);

	cout << "THE SORTED DATA IS: ";
	for (int i = 0; i < 5; i++)
		cout << arr1[i] << "-";
	cout << endl;


	//USER INPUT.

	cout << "INTEGER RADIX SORT!" << endl;

	int n, k;
	cout << "ENTER K (FIXED DIGITS IN NUMBER): ";
	cin >> k;
	cout << "ENTER NO OF NUMBERS YOU WANT TO ENTER: ";
	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "ENTER " << i + 1 << " NUMBER: ";
		cin >> a[i];
	}

	cout << "THE UNSORTED DATA IS: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << '-';
	cout << endl;

	integerRadixSort(a, k, n);

	cout << "THE SORTED DATA IS: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << '-';
	cout << endl << endl;


	cout << "STRING RADIX SORT!" << endl;

	cout << "ENTER K (FIXED CHARACTERS IN STRING): ";
	cin >> k;
	cout << "ENTER NO OF STRINGS YOU WANT TO ENTER: ";
	cin >> n;

	string* b = new string[n];

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < n; i++)
	{
		cout << "ENTER " << i + 1 << " STRING: ";
		getline(cin, b[i]);
	
	}

	cout << "THE UNSORTED DATA IS: ";
	for (int i = 0; i < n; i++)
		cout << b[i] << '-';
	cout << endl;

	stringRadixSort(b, k, n);

	cout << "THE SORTED DATA IS: ";
	for (int i = 0; i < n; i++)
		cout << b[i] << '-';
	cout << endl << endl;


	//RADIX SORT

	system("pause>0");
	return 0;
}