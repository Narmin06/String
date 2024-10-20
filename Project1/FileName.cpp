#include<iostream>
using namespace std;

class String {
	char* array = nullptr;
	size_t capacity = 20;

public:
	String() {
		array = new char[capacity] {};
	}

	String(const char* array) : String(){
		SetArray(array);
	}

	size_t MyStrlen(const char* array) const {
		size_t len = 0;
		for (size_t i = 0; array[i]!='\0'; i++)
		{
			len++;
		}
		return len;
	}


	char* GetArray() const {
		return array;
	}

	void SetArray(const char* array) {
		size_t size = MyStrlen(array);
		Check_Size(size);
		for (size_t i = 0; array[i] != '\0'; i++)
		{
			this->array[i] = array[i];
		}
	}

	int GetCapacity() const {
		return capacity;
	}

	void Check_Size(size_t len) {
		while (capacity <= len) {
			capacity += 10; 
		}
		char* new_array = new char[capacity] {};
		for (size_t i = 0; i < MyStrlen(array); i++)
		{
			new_array[i] = array[i];
		}
		delete[] array; 
		array = new_array;
	}

	void AppendString(const char* array2) {
		size_t len = MyStrlen(array);
		size_t new_len = MyStrlen(this->array) + MyStrlen(array2);
		Check_Size(new_len);
		char* new_array = new char[capacity] {};

		for (size_t i = 0; i < len; i++)
		{
			new_array[i] = this->array[i];
		}

		for (size_t i = 0; array2[i] != '\0'; i++) 
		{
			new_array[len + i] = array2[i];
		}
		new_array[new_len] = '\0'; 

		delete[] array; 
		array = new_array; 
	}

	void Upper() {
		for (size_t i = 0; array[i] != '\0'; i++)
		{
			if (int(array[i]) >= 97 && int(array[i] <= 122)) { 
				array[i] = array[i] - 32; 
			}
		}
	}

	void Lower() {
		for (size_t i = 0; array[i] != '\0'; i++)
		{
			if (int(array[i]) >= 64 && int(array[i] <= 91)) {
				array[i] = array[i] + 32;
			}
		}
	}

	bool Empty() const {
		return MyStrlen(this->array) == 0;
	}

	int Find(const char* array2) const {
		size_t len = MyStrlen(array2);
		size_t str_len = MyStrlen(array);

		for (size_t i = 0; i <= str_len; i++)
		{
			if (array[i] == array2[0]) { 
				size_t k = 1; 
				while (k < len && array[i + k] == array2[k]) {
					k++;
				}
				if (k == len) {
					return i; 
				}
			}
		}
		return -1; 
	}


	friend ostream& operator<<(ostream& out, const String& object) {
		out << object.array << endl;
		return out;
	}

	~String() {
		delete[] array;
	}
};

void main() {
	String* str1 = new String{ "Narmin" };
	String* str2 = new String{ " Alishova" };
	cout << *str1 << endl;

	////Length method
	//cout << str1->MyStrlen(str1->GetArray());

	////Empty method
	//cout << "Is empty? " << str1->Empty();
	
	////Append method
	//str1->AppendString(str2->GetArray());
	//cout << *str1 << endl;

	////Upper method
	//str1->Upper();
	//cout << *str1 << endl;

	////Lower method
	//str1->Lower();
	//cout << *str1 << endl;

	////Find method
	//int index = str1->Find("rm");
	//cout << "Index: " << index << endl;
	//index = str1->Find("xz");
	//cout << "Index: " << index << endl;

}