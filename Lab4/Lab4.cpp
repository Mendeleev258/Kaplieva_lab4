#include <iostream>
#include <fstream>
#include <iomanip>
#include <functional>


template<typename T, typename Predicat>
void validation(T& x, T& y, Predicat condition, const char* message);
template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message);

void ending(int n);

int task1(int n, std::istream& stream);
int task1(int n, int a, int b);
int task2(int n, std::istream& stream);
int task2(int n, int a, int b);



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	std::ifstream file;
	file.open("data.txt");
	std::cout << task2(13, 0, 10);
}



void ending(int n)
{
	if (n % 10 > 4 and n % 10 <= 9 or n % 10 == 0 or (n % 100 > 10 and n % 100 < 20)) std::cout << n << " элементов\n";
	else if (n % 10 != 1) std::cout << n << " элемента\n";
	else std::cout << n << " элемент\n";
}

int task1(int n, std::istream& stream)
{
	int x{}, cnt{}, lastMin{};
	stream >> lastMin;
	for (int i = 1; i < n; ++i)
	{
		stream >> x;
		if (x <= lastMin)
		{
			lastMin = x;
			cnt = 0;
		}
		else
			if (x % 2 == 0)
				cnt++;
	}
	return cnt;
}

int task1(int n, int a, int b)
{
	std::cout << "Сгенерирована последовательность, содержащая ";
	ending(n);
	
	int x{}, cnt{}, lastMin{};
	lastMin = rand() % (b - a) + a;
	std::cout << lastMin << ' ';
	for (int i = 1; i < n; ++i)
	{
		x = rand() % (b - a) + a;
		std::cout << x << ' ';
		if (x <= lastMin)
		{
			lastMin = x;
			cnt = 0;
		}
		else
			if (x % 2 == 0)
				cnt++;
	}
	std::cout << '\n';
	return cnt;
}

int task2(int n, std::istream& stream)
{
	int x{}, sum{}, res{}, cnt{};
	for (int i = 0; i < n; ++i)
	{
		stream >> x;
		sum += x;
		if (x == 7)
		{
			if (cnt > 0)
				res = sum;
			else
				sum = 0;
			cnt++;
		}
	}
	if (cnt > 1)
		res -= 7;
	return res;
}

int task2(int n, int a, int b)
{
	int x{}, sum{}, res{}, cnt{};
	bool flag = false;
	
	
	std::cout << "Сгенерирована последовательность, содержащая ";
	ending(n);

	for (int i = 0; i < n; ++i)
	{
		x = rand() % (b - a) + a;
		std::cout << x << ' ';
		sum += x;
		if (x == 7)
		{
			if (cnt > 0)
				res = sum;
			else
				sum = 0;
			cnt++;
		}
	}
	std::cout << '\n';
	if (cnt > 1)
		res -= 7;
	return res;
}

template<typename T, typename Predicat>
void validation(T& x, T& y, Predicat condition, const char* message)
{
	std::cout << message << '\n';
	std::cout << ">>> ";
	std::cin >> x;
	std::cout << ">>> ";
	std::cin >> y;
	while (!(condition(x, y)))
	{
		std::cout << "Ошибка ввода!\n";
		std::cout << message << '\n';
		std::cout << ">>> ";
		std::cin >> x;
		std::cout << ">>> ";
		std::cin >> y;
		std::cout << '\n';
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	}
}

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message)
{
	std::cout << message << "\n>>> ";
	while (!(std::cin >> x && condition(x)))
	{
		std::cout << "Ошибка ввода\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << message << "\n>>> ";
	}
}
