/// Відповідно до виразу, що читається з текстового файлу, 
/// побудувати дерево-формулу та обчислити значення цієї формули.

#include "Functions.h"
#include "Node.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file("text.txt");
	vector<string> mass = readFile(file);
	file.close();
	outputVector(mass);
	int i = 0;
	Node* Tree = makeTree(mass, i);

	system("pause");
	return 0;
}