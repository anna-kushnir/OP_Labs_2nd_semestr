/// Відповідно до виразу, що читається з текстового файлу, 
/// побудувати дерево-формулу та обчислити значення цієї формули.

#include "Functions.h"
#include "Node.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream inFile("text.txt");                         // Вхідний файл з формулою.
	if (!inFile.is_open()) {
		cout << "Не вдалося відкрити файл для зчитування виразу!\n\n";
		return -1;
	}
	vector<string> mass = readFile(inFile);              // Масив зчитаних з виразу символів.
	inFile.close();
	ofstream outFile("result.txt");                      // Результуючий файл.

	if (mass[0] == "") {
		cout << "Неправильне введення формули!\n\n";
		outFile << "Неправильне введення формули!";
		outFile.close();
		return -1;
	}

	outFile << "Введений вираз:\n";
	outputVector(mass, outFile);

	BinaryTree Tree(mass);
	outFile << "\n\nПобудоване дерево-формула:\n\n";
	Tree.printTree(outFile);

	double result = Tree.countValueOfExpression();       // Результат обчислення виразу.
	outFile << "\n\nРезультат обчислення формули: " << result;
	cout << "Побудоване дерево та отриманий результат були успішно виведені у файл.\n\n";

	Tree.clearMemory();
	outFile.close();

	system("pause");
	return 0;
}
