/// Відповідно до виразу, що читається з текстового файлу, 
/// побудувати дерево-формулу та обчислити значення цієї формули.

#include "Functions.h"
#include "Node.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file("text.txt");                  // Вхідний файл з виразом.
	if (!file.is_open()) {
		cout << "Не вдалося відкрити файл для зчитування виразу!\n\n";
		return -1;
	}
	vector<string> mass = readFile(file);       // Масив зчитаних з виразу символів.
	file.close();
	ofstream outFile("result.txt");             // Результуючий файл.

	if (mass[0] == "") {
		cout << "Неправильне введення формули!\n\n";
		outFile << "Неправильне введення формули!";
		outFile.close();
		return -1;
	}

	outFile << "Введений вираз:\n";
	outputVector(mass, outFile);

	int i = 0;        // Змінна для визначення індексу поточного елементу вектора mass.
	Node* Tree = makeTree(mass, i);

	outFile << "\n\nПобудоване дерево-формула:\n\n";
	outputTree(Tree, 0, outFile);

	double result = count(Tree);                // Результат обчислення виразу.
	outFile << "\n\nРезультат обчислення формули: " << result;
	cout << "Побудоване дерево та отриманий результат були успішно виведені у файл.\n\n";

	clearMemory(Tree);
	Tree = NULL;
	outFile.close();

	system("pause");
	return 0;
}
