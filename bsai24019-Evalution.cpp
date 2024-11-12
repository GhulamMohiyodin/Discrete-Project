#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;
#define CAPACITY 100
void PrintArray(const string &Msg,int Ray[],int &S)
{
	cout << Msg << " = {";
	for (int i = 0;i < S;i++)
		cout << Ray[i] << ",";
	cout << "\b}\n";
}
void LoadSet(ifstream &Rdr,int Ray[],int &S)
{
	int N;
	S = 0;
	while (Rdr >> N && N != -1)
	{
		bool Found = false;
		for (int i = 0; i < S;i++)
		{
			if (Ray[i] == N) {
				Found = true;
				break;
			}
		}
		if (!Found)
			Ray[S++] = N;
	}
	for (int i = 0;i < S - 1;i++)
		for (int j = 0;j < S - i - 1;j++)
			if (Ray[j] > Ray[j + 1])
				swap(Ray[j], Ray[j + 1]);
}
int mainP1()
{
	ifstream Sets("Sets.txt");
	int U[100], A[100], B[100];
	int SU, SA, SB;
	LoadSet(Sets, U, SU);
	LoadSet(Sets, A, SA);
	LoadSet(Sets, B, SB);

	PrintArray("U []", U, SU);
	PrintArray("A []", A, SA);
	PrintArray("B []", B, SB);
	return 0;
}
void UnionOfSets(int A[], int B[], int C[], int SA, int SB, int& SC)
{
	int i = 0, j = 0, k = 0;
	while (i < SA && j < SB)
	{
		if (A[i] < B[j])
			C[k++] = A[i++];
		else if (B[j] < A[i])
			C[k++] = B[j++];
		else {
			C[k++] = A[i++];
			j++;
		}
	}
	while (i < SA)
		C[k++] = A[j++];
	while (j < SB)
		C[k++] = B[j++];
	SC = k;
}
int mainUnion()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 3,4,5,6 };
	int SA = 4, SB = 4;
	int C[100];
	int SC;

	UnionOfSets(A, B, C, SA,SB,SC);

	PrintArray("A []", A, SA);
	PrintArray("B []", B, SB);
	PrintArray("Union :", C, SC);
	return 0;
}
void IntersectionOfSets(int A[], int B[], int C[], int SA, int SB, int& SC)
{
	int i = 0, j = 0, k = 0;
	while (i < SA && j < SB)
	{
		if (A[i] < B[j])
			i++;
		else if (B[j] < A[i])
			j++;
		else 
		{
			C[k++] = A[i++];
			j++;
		}
	}
	SC = k;
}
int mainIntersection()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 3,4,5,6 };
	int SA = 4, SB = 4;
	int C[100];
	int SC;

	IntersectionOfSets(A, B, C, SA, SB, SC);

	PrintArray("A []", A, SA);
	PrintArray("B []", B, SB);
	PrintArray("Intersection ", C, SC);
	return 0;
}
void SubtractionOfSets(int A[], int B[], int C[], int SA, int SB, int& SC)
{
	int i = 0, j = 0, k = 0;
	while (i < SA && j < SB)
	{
		if (A[i] < B[j])
			C[k++] = A[i++];
		else if (B[j] < A[i])
			j++;
		else {
			i++;
			j++;
		}
	}
	while (i < SA)
		C[k++] = A[j++];
	SC = k;
}
int mainSubtraction()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 3,4,5,6 };
	int SA = 4, SB = 4;
	int C[100];
	int SC;

	SubtractionOfSets(A, B, C, SA, SB, SC);

	PrintArray("A []", A, SA);
	PrintArray("B []", B, SB);
	PrintArray("Subtraction ", C, SC);
	return 0;
}
void ComplementOfSets(int U[],int A[], int C[], int SU, int SA, int& SC)
{
	int i = 0, j = 0, k = 0;
	while (i < SU && j < SA)
	{
		if (U[i] < A[j])
			C[k++] = U[i++];
		else if (A[j] < U[i])
			j++;
		else {
			i++;
			j++;
		}
	}
	while (i < SU)
		C[k++] = U[j++];
	SC = k;
}
int mainComplement()
{
	int U[] = { 1,2,3,4,5,6,7,8,9,10 };
	int A[] = { 3,4,5,6 };
	int SU = 10, SA = 4;
	int C[100];
	int SC;

	SubtractionOfSets(U, A, C, SU, SA, SC);

	PrintArray("U []", U, SU);
	PrintArray("A []", A, SA);
	PrintArray("Complement ", C, SC);
	return 0;
}
void CartesianProduct(int A[], int B[], int SA, int SB)
{
	for (int i = 0;i < SA;i++) {
		for (int j = 0;j < SB;j++) {
			cout << "(" << A[i] << ", " << B[j] << ")" << " ";
		}
		cout << "\n";
	}
}
int mainCartesian()
{
	int A[] = { 1,2,3,4 };
	int B[] = { 4,5,6,7 };
	int SA = 4, SB = 4;
	CartesianProduct(A, B, SA, SB);
	return 0;
}
void menu()
{
	cout << "1. Loading of set\n";
	cout << "2. Union of Sets\n";
	cout << "3. Intersection of sets\n";
	cout << "4. Subtraction of Sets\n";
	cout << "5, Complement of Sets\n";
	cout << "6. Cartesian Product of sets\n";
	cout << "0. Quit\n";
}
int main()
{
	int choice;
	while (true)
	{

		menu();
		cout << "Which Problem :";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:
			mainP1();
			break;
		case 2:
			mainUnion();
			break;
		case 3:
			mainIntersection();
			break;
		case 4:
			mainSubtraction();
			break;
		case 5:
			mainComplement();
			break;
		case 6:
			mainCartesian();
			break;
		case 0:
			cout << "Thank You";
			return 0;
		default:
			cout << "Wrong Input\n";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	return 0;
}