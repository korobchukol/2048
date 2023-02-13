#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

	srand(time(NULL));

	int field[4][4]{};
	int fill = 0;
	int move = 0;
	int exit = 0;
	int win = 0;

	while (true)
	{
		start:

		system("cls");

		cout << "2048\n\n";
		
		exit = 0;

		if (move == 1)
		{
			for (int crow = 0; crow < 4; crow++)
			{
				for (int ccol = 0; ccol < 4; ccol++)
				{
					field[crow][ccol] = 0;
				}
				
			}
			cout << "Поле очищено\n\n";
			move = 0;
		}


		cout << "Управляйте стрелочками на нумпаде!\n\nЧтоб начать заново, введите 1\n\n";

		fill = 0;
		for (int a = 0; a < 4; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				if (field[a][b] != 0)
				{
					fill++;
				}
				if (field[a][b] >= 2048)
				{
					win++;
				}
			}
		}
		if (win >= 0)
		{
			cout << "Вы выиграли!!!\n\nПри желании можете продолжить игру\n\n";
		}

		int not_lose = 0;
		if (fill >= 16)
		{
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					if (field[a][b] == field[a+1][b]|| field[a][b] == field[a][b + 1])
					{
						not_lose++;
					}
				}
			}
			if (field[2][3] == field[3][3] || field[3][2] == field[3][3])
			{
				not_lose++;
			}

			if (not_lose >= 1)
			{
				cout << "У вас есть возможность походить! Присмотритесь!\n\n";
			}
			else
			{
				cout << "Вы проиграли\n\n";
			}
		}
		else
		{
			int arow = rand() % (3 - 0 + 1) + 0, acol = rand() % (3 - 0 + 1) + 0;

			while (field[arow][acol] != 0)
			{
				arow = rand() % (3 - 0 + 1) + 0;
				acol = rand() % (3 - 0 + 1) + 0;
			}
			field[arow][acol] = 2;
		}

		int max_number = 0;
		int score = 0;
		for (int a = 0; a < 4; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				if (field[a][b] > max_number)
				{
					max_number = field[a][b];
				}
				score = score + field[a][b];
			}
		}
		cout << "Счёт:" << score << "\n\n";

		for (int vrow = 0; vrow < 4; vrow++)
		{
			if (max_number >= 0)
			{
				cout << "---------";
			}
			if (max_number >= 10)
			{
				cout << "----";
			}
			if (max_number >= 100)
			{
				cout << "----";
			}
			if (max_number >= 1000)
			{
				cout << "----";
			}
			if (max_number >= 10000)
			{
				cout << "----";
			}
			if (max_number >= 100000)
			{
				cout << "----";
			}

			cout << "\n";
			for (int vcol = 0; vcol < 4; vcol++)
			{
				cout << "|";
				if (field[vrow][vcol] != 0)
				{
					cout << field[vrow][vcol];
				}
				if (field[vrow][vcol] < 100000)
				{
					if (max_number > 100000)
					{
						cout << " ";
					}
						if (field[vrow][vcol] < 10000)
						{
							if (max_number > 10000)
							{
								cout << " ";
							}
							if (field[vrow][vcol] < 1000)
							{
								if (max_number > 1000)
								{
									cout << " ";
								}
								if (field[vrow][vcol] < 100)
								{
									if (max_number > 100)
									{
										cout << " ";
									}
									if (field[vrow][vcol] < 10)
									{
										if (max_number > 10)
										{
											cout << " ";
										}
										if (field[vrow][vcol] == 0)
										{
											if (max_number > 0)
											{
												cout << " ";
											}
										}
									}
								}
							}
						}
				}
				if (vcol == 3)
				{
					cout << "|";
				}
			}
			cout << "\n";
		}
		if (max_number >= 0)
		{
			cout << "---------";
		}
		if (max_number >= 10)
		{
			cout << "----";
		}
		if (max_number >= 100)
		{
			cout << "----";
		}
		if (max_number >= 1000)
		{
			cout << "----";
		}
		if (max_number >= 10000)
		{
			cout << "----";
		}
		if (max_number >= 100000)
		{
			cout << "----";
		}

		cout << "\n\n";

		int moved = 0;
		move:
		cin >> move;
		switch (move)
		{
		case 1:
			if (exit == 1)
			{
				goto start;
			}
			exit++;
			cout << "\nВы уверенны что хотите начать заново?\nНажмите 1 чтоб подтвердить\nСделайте ход чтоб отменить\n\n";
			goto move;
			break;
		case 2:
			for (int times = 0; times < 4; times++)
			{
				for (int wcol = 0; wcol < 4; wcol++)
				{
					for (int wrow = 3; wrow >= 1; wrow--)
					{
						if (field[wrow][wcol] == field[wrow - 1][wcol] && field[wrow][wcol] != 0)
						{
							field[wrow - 1][wcol] = field[wrow - 1][wcol] * 2;
							field[wrow][wcol] = 0;
							moved++;
						}
						if (field[wrow - 1][wcol] != 0 && field[wrow][wcol] == 0)
						{
							field[wrow][wcol] = field[wrow - 1][wcol];
							field[wrow - 1][wcol] = 0;
							moved++;
						}
					}
				}
			}
			break;
		case 4:
			for (int times = 0; times < 4; times++)
			{
				for (int wrow = 0; wrow < 4; wrow++)
				{
					for (int wcol = 0; wcol < 3; wcol++)
					{
						if (field[wrow][wcol + 1] == field[wrow][wcol] && field[wrow][wcol + 1] != 0)
						{
							field[wrow][wcol] = field[wrow][wcol] * 2;
							field[wrow][wcol + 1] = 0;
							moved++;
						}
						if (field[wrow][wcol + 1] != 0 && field[wrow][wcol] == 0)
						{
							field[wrow][wcol] = field[wrow][wcol + 1];
							field[wrow][wcol + 1] = 0;
							moved++;
						}
					}
				}
			}
			break;
		case 6:
			for (int times = 0; times < 4; times++)
			{
				for (int wcol = 3; wcol >= 1; wcol--)
				{
					for (int wrow = 0; wrow < 4; wrow++)
					{
						if (field[wrow][wcol] == field[wrow][wcol - 1] && field[wrow][wcol] != 0)
						{
							field[wrow][wcol] = field[wrow][wcol] * 2;
							field[wrow][wcol - 1] = 0;
							moved++;
						}
						if (field[wrow][wcol - 1] != 0 && field[wrow][wcol] == 0)
						{
							field[wrow][wcol] = field[wrow][wcol - 1];
							field[wrow][wcol - 1] = 0;
							moved++;
						}
					}
				}
			}
			break;
		case 8:
			for (int times = 0; times < 4; times++)
			{
				for (int wcol = 0; wcol < 4; wcol++)
				{
					for (int wrow = 0; wrow < 3; wrow++)
					{
						if (field[wrow][wcol] == field[wrow + 1][wcol] && field[wrow][wcol] != 0)
						{
							field[wrow + 1][wcol] = field[wrow + 1][wcol] * 2;
							field[wrow][wcol] = 0;
							moved++;
						}
						if (field[wrow + 1][wcol] != 0 && field[wrow][wcol] == 0)
						{
							field[wrow][wcol] = field[wrow + 1][wcol];
							field[wrow + 1][wcol] = 0;
							moved++;
						}
					}
				}
			}
			break;
		default:
			cout << "\nВведите число, являющееся стрелкой на нумпаде или единицей\n\n";
			goto move;
		}

			if (moved == 0 && move != 1)
			{
				fill = 0;
				for (int a = 0; a < 4; a++)
				{
					for (int b = 0; b < 4; b++)
					{
						if (field[a][b] != 0)
						{
							fill++;
						}
					}
				}
				if (fill >= 16)
				{
					goto start;
				}
				cout << "\nДействие совершить невозможно. Сделайте ход в другую сторону\n\n";
				goto move;
			}
	}
}