// ���������� ��������: ����, ����� ����, ������, �����, �������, ����, ���������, ������, �����, ��������;
// ����: ���� = 0.9, ��������� = 1.1, ������ = 1.3, ����� = 3.6, ������� = 1.8, 
// ���� = 16, ��������� = 3, ������ = 2.5, ����� = 2.05, �������� = 1.29 ������;
// ����������� ����� �����: 
//	- �������� �������� ������ 33%;
//	- ������ �������� 24%; 
//	- ������������ ���� �� ������� � ������� 50%
// 
// ****������: ���� � ��� � ������� 5 ������� �����, ����� ����� � ��� �������� �������, �� ������� � ������������ 
// ���������� - ���� (5 * 0.9 > 1 * 3.6 > 2 * 1.29).
// 1. ��������� ��������� ������� ��� �����;
// 2. ��������� ��������� ������� � ������ �����;
// ***����� � �������� ����� ����������� ������ ����. 
// ***����� � ����������� ���������� ����� ��������� �� ��������� � ��������� (�.�.� ������� ���� ���� �������� 
// ��� ��� ����� : ������ �������� � ������������ ������� �������������� ����������� ������ ������,
// �� ������������ ������� �� �������)
// ***���� ������������ ���������, �� ������������ ������ ������� � ������ ����� ��������� ������������ �����
// (������ ���� ���-�� ������� ����� ������, �� ��� ����� �������� ������������ ������������ ����� ����� �������,
// ����� � ��������� ������� ��������� ��������� �������.�� ��� �����������).
// ***������ ��� ����� : ������������ ������ ����� ��������� � ������� � �����	������(���� ������� �� �������� �����, �����, �� � �.�.) ��� ������� �������� �� �����������.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Header.h"

int main()
{
	std::vector<double> basket(10, 0);
	const double genDisc = 50, dayryDisc = 33, flourDisc = 24;// ������
	short product = 0; // ����� ��������
	short indicator = -1; // ���������� ������������� ��� ������ ������������
	double prodPrice = 0, basketPrice = 0, basketPriceDis = 0;// ���� ��������, �������, ������� �� �������
	std::string  unit;

	using namespace MyFunctions;

	do
	{
		HelloMessage(basketPrice, basketPriceDis);
		Recomendation(indicator);

		std::cout << "\nPlease select the product you want to buy and press 'ENTER' or '0' to FINISH:\t";
		std::cin >> product;

		if (product > 0 && product <= 10) {
			
			switch (product) {
			case ShopAssortiment::Meat:
				prodPrice = 16;
				unit = "kg.";
				break;
			case ShopAssortiment::Apples:
				prodPrice = 2.5;
				unit = "kg.";
				break;
			case ShopAssortiment::Oranges:
				prodPrice = 3.0;
				unit = "kg.";
				break;
			case ShopAssortiment::Sugar:
				prodPrice = 2.05;
				unit = "kg.";
				break;
			case ShopAssortiment::Milk:
				prodPrice = 1.3;
				unit = "but.";
				break;
			case ShopAssortiment::Butter:
				prodPrice = 3.6;
				unit = "pack.";
				break;
			case ShopAssortiment::Sour_Cream:
				prodPrice = 1.8;
				unit = "pack.";
				break;
			case ShopAssortiment::Bread:
				prodPrice = 0.9;
				unit = "loaf.";
				break;
			case ShopAssortiment::White_Bread:
				prodPrice = 1.1;
				unit = "loaf.";
				break;
			case ShopAssortiment::Pasta:
				prodPrice = 1.29;
				unit = "pack.";
				break;
			}

			int amount;
			std::cout << "Pleas enter amount " << unit << " :\t";
			std::cin >> amount;

			// ���������� �������� � �������(������ ������� ������ ���� ����� � �������)
			basket[static_cast<std::vector<double, std::allocator<double>>::size_type>(product) - 1] += prodPrice * amount;

			
			// ������ ������� (��� ����� ������)
			basketPrice = BasketPrice(basket);

			// ���������� �-�� ������� ������� (� ������ ������)
			basketPriceDis = BasketPrice(basket, genDisc, dayryDisc, flourDisc, indicator, FindeMax(basket));
		}
		else if (product == 0)
				continue;

		//����������� ��� ��������� ������������� ������ ���������� ����������
		system("cls");
	
	} while (product != 0);


	FinishShoping(basketPrice, basketPriceDis);
}