

#include <iostream>
#include<fstream>
#include<string>
struct book {
	int id;
	char name[30];
	int size;
};
void bookread(book &b) {
	std::cout << "enter id of book" << std::endl;
	std::cin >> b.id;
	std::cout << "enter name of book" << std::endl;
	std::cin >> b.name;
	std::cout << "enter size of book" << std::endl;
	std::cin >> b.size;
}
void update(book b[]) {
	int index;
	std::cout << "enter index of object you want change" << std::endl;
	std::cin >> index;
	std::cout << "enter name" << std::endl;
	std::cin >> b[index].name;
	std::cout << "enter id" << std::endl;
	std::cin >> b[index].id;
	std::cout << "enter size" << std::endl;
	std::cin >> b[index].size;

}
void display(book b[]) {
	std::cout << "ID of Book     " << b->id << std::endl;
	std::cout << "Name of Book     " << b->name << std::endl;
	std::cout << "size  of Book     " << b->size << std::endl;
}

int main(int argc,char *argv[])
{
	book *b1 = new book[5];
	bookread(*b1);
	std::ofstream file("record1.bin", std::ios::binary);
	file.write((const char*)&b1, sizeof(b1));
	std::ofstream f;
	if (f.is_open()) {
		std::cout << "ID of Book     " << b1->id << std::endl;
		std::cout << "Name of Book     " << b1->name << std::endl;
		std::cout << "size  of Book     " << b1->size << std::endl;

	}
	else {
		std::cout << "file was not open now file will be created" << std::endl;
		std::ofstream f("record2.bin", std::ios::binary);
		f.write((const char*)&b1, sizeof(b1));

		std::cout << "ID of Book     " << b1->id << std::endl;
		std::cout << "Name of Book     " << b1->name << std::endl;
		std::cout << "size  of Book     " << b1->size << std::endl;
	}
	file.close();
	f.close();
	std::string check=argv[1];
	
	if (check == "add") {
		update(b1);
	}
	display(b1);
}