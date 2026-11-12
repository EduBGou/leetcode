#include <vector>

using namespace std;

class Solution {
public:

    int encontrarQuebraOrdem(const vector<int>& vec, int inicio, int fim){
        
        if (inicio >= fim) {
            return -1;
        }

        int meio = inicio + (fim - inicio) / 2;

        if (meio > inicio && vec[meio] < vec[meio - 1]) {
            return meio;
        }

        if (meio < fim && vec[meio] > vec[meio + 1]) {
            return meio + 1;
        }

        int resultadoEsquerda = encontrarQuebraOrdem(vec, inicio, meio - 1);
        if (resultadoEsquerda != -1) {
            return resultadoEsquerda;
        }
        int resultadoDireita = encontrarQuebraOrdem(vec, meio+1, fim);
        if (resultadoDireita != -1) {
            return resultadoDireita;
        }
        return -1;
    }

    int binarySearch(const vector<int>& vec, int inicio, int fim, int target){
        if (inicio >= fim){
            if (inicio >= 0 && inicio < vec.size() && vec[inicio] == target)
            return inicio;
            else
            return -1;
        }

        int meio = inicio + (fim - inicio) / 2;

        if (vec[meio] == target) {
            return meio;
        }

        int resultadoEsquerda = binarySearch(vec, inicio, meio - 1, target);
        if (resultadoEsquerda != -1) {
            return resultadoEsquerda;
        }

        int resultadoDireita = binarySearch(vec, meio+1, fim, target);
        if (resultadoDireita != -1) {
            return resultadoDireita;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) 
    {    
        int meio = encontrarQuebraOrdem(nums, 0, nums.size()-1);
        if (meio == -1){
            return binarySearch(nums, 0, nums.size()-1, target);
        }
        if (nums[meio] == target){
            return meio;
        }

        int resultadoEsquerda = binarySearch(nums, 0, meio, target);
        if (resultadoEsquerda != -1) {
            return resultadoEsquerda;
        }
        
        int resultadoDireita = binarySearch(nums, meio+1, nums.size()-1, target);
        if (resultadoDireita != -1) {
            return resultadoDireita;
        }
        return -1;
    }
};