#pragma once
class Settings
{
public:
	const int AMOUNT_OF_OPTIONS = 8;

	enum Solution {
		SimplyBruteForce,
		DivideAndConquer,
		WarndorfsRule

	};

	Solution solution = WarndorfsRule;
	Settings();
	~Settings();
};

