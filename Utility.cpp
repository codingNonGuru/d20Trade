#include "Utility.hpp"

std::random_device randomDevice;
std::mt19937 twister(randomDevice());

namespace utility
{
	float GetRandom(float minimum, float maximum)
	{
		std::uniform_real_distribution<float> distribution(minimum, maximum);
		return distribution(twister);
	}

	int GetRandom(int minimum, int maximum)
	{
		std::uniform_int_distribution<int> distribution(minimum, maximum);
		return distribution(twister);
	}
}