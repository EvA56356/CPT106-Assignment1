#include <iostream>
using namespace std;





bool same_Array(int a[], int lenA, int b[], int lenB) {
	// Initialize two temperary variables
	int temp1 = 0;
	int temp2 = 0;
	bool result1=true; // result of the first comparison
	bool result2=true; // result of the second comparison
	bool result; // the final returned result

	// the first comparison
	// loop for array a
	for (int i = 0; i < lenA; i++) {
		temp1 = a[i];
			// loop for array b
			for (int k = 0; k < lenB; k++) {
				temp2 = b[k];				
				// If there are two integers are the same, stop comparing and move to the next integer in array a
				if (temp1 == temp2) { break; }	
				// If the comparison times is equal to the length of the array b minus one, it means two arrays are not the same
				if (k == lenB - 1) {  result1 = false; goto FLAG1; }// result of the first comparison is false
			}
	}

	FLAG1:
	// the second comparison
	// loop for array b
	for (int i = 0; i < lenB; i++) {
		temp1 = b[i];
			// loop for array a
			for (int k = 0; k < lenA; k++) {
				temp2 = a[k];
				// If there are two integers are the same, stop comparing and move to the next integer in array b
				if (temp1 == temp2) { break; }
				// If the comparison times is equal to the length of the array a minus one, it means two arrays are not the same
				if (k == lenA - 1) {  result2 = false; goto FLAG2; }// result of the second comparison is false
			}
	}
	FLAG2:

	result = result1 && result2;
	return result;
}


void  main() {
	// Initialize the variables
	int lenA = 0;
	int lenB = 0;

	// Input array a
	cout << "Please input the length of the fisrt array: " << endl;
	cin >>lenA ;
	int* a=new int[lenA];
	cout << "Please input the content of the first array: " << endl;
	for (int i = 0; i < lenA;i++) {
		cin >> a[i];
	}

	//Input array b
	cout << "Please input the length of the second array: " << endl;
	cin >> lenB;
	int* b = new int[lenB];
	cout << "Please input the content of the second array: " << endl;
	for (int i = 0; i < lenB; i++) {
		cin >> b[i];
	}

	// Show the result of the comparison
	bool result = same_Array(a, lenA, b, lenB);
	if (result) {
		cout << "same" << endl;
	}
	else {
		cout << "different" << endl;
	}
	

}

