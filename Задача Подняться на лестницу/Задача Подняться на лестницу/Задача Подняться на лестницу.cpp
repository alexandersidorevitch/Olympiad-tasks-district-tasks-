#include <iostream>
#include <vector>
#include <fstream>
#define ui int
using namespace std;
ui letGoMin(ui currentStep, ui maxFootStep, vector<bool> steps) {
	ui sec = 1, i;
	while (currentStep - maxFootStep > -1)
	{
		for (i = maxFootStep; i > 0; i--)
		{
			if (steps[currentStep - i])
			{
				currentStep -= i;
				break;
			}
		}
		++sec;
	}
	return sec;
}
ui letGoMax(ui currentStep, ui maxFootStep, vector<bool> steps) {
	ui sec = 1;
	while (true)
	{
		for (int i = 1; i <= maxFootStep; i++)
		{
			if (currentStep - i <= -1)
			{
				return sec;
			}
			if (steps[currentStep - i])
			{
				currentStep -= i;
				++sec;
				break;
			}
		}
	}
}
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	ui N, maxFootStep, badSteps, badStep;
	input >> N >> badSteps >> maxFootStep;
	vector<bool> steps(N, true);
	for (size_t i = 0; i < badSteps; i++)
	{
		input >> badStep;
		steps[badStep - 1] = false;
	}
	input.close();
	output << letGoMin(N - 1, maxFootStep, steps) << ' ' << letGoMax(N - 1, maxFootStep, steps);
}
