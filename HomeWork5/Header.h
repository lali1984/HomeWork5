#pragma once
namespace MyFunctions
{
	namespace ShopAssortiment
	{
		enum Other_Products : short
		{
			Meat = 1,
			Apples,
			Oranges,
			Sugar,
			Milk,
			Butter,
			Sour_Cream,
			Bread,
			White_Bread,
			Pasta
		};
	}

	//�����������
	void HelloMessage(const double& basketPrice, const double& bp_disount);

	//���� �������
	const double BasketPrice(std::vector<double>& basket);

	//���� ������� �� �������
	const double BasketPrice(std::vector<double>& basket, const double& discount1, const double& discount2,
		const double& discount3, short& recomendation, const double max);

	//���������� ������������ ���� � �������
	const double FindeMax(std::vector<double>& basket);

	//������������
	void Recomendation(const short& recomend);

	//���������� �������
	void FinishShoping(const double& basketPrice, const double& basketPriceDis);


}

