/*
Dado um vetor arr não-ordenado de inteiros, retorne o comprimento da maior sequência de inteiros
consecutivos em arr. Por exemplo, se arr = {1, 9, 3, 10, 4, 20, 2}, então a saída deve ser 4, pois
a maior sequência de inteiros consecutivos é {1, 3, 4, 2}. Note que os elementos desta sequência não
precisam estar um ao lado do outro no vetor arr.

int f(std::vector<int>& nums);

VERIFIQUE A SOLUCAO ABAIXO:
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int f(vector<int> &nums)
{
    unordered_map<int, int> dict;

    for (int num : nums)
    {
        dict[num] = 1;
    }

    int maxCount = 0;

    for (auto &[key, value] : dict)
    {
        if (value == 0) continue;
        value = 0;

        int currentCount = 1;
        while (dict.find(key + currentCount) != dict.end())
        {
            dict[key + 1] = 0;
            currentCount++;
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
        }
    }

    return maxCount;
}


int main()
{
    vector<vector<int>> tests = {
        {1, 9, 3, 10, 4, 20, 2},
        {100, 4, 200, 1, 3, 2},
        {1, 2, 3, 4, 5},
        {10, 30, 20},
        {5},
        {},
        {1, 1, 2, 2, 3, 3},
        {0, -1, -2, 1, 2},
        {10, 5, 12, 11, 13, 14, 15}
    };

    for (int i = 0; i < tests.size(); i++)
    {
        cout << "Teste " << i + 1 << ": ";
        cout << f(tests[i]) << endl;
    }

    return 0;
}
