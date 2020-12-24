#include <iostream>
#include <vector>
#include <iomanip>


void alg_floid(std::vector<std::vector<int>>& v) {
	for (int k = 0; k < v.size(); k++) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (i != j && v[i][k] != -1 && v[k][j] != -1) {
					if (v[i][j] == -1) {
						v[i][j] = v[i][k] + v[k][j];
					} else {
						v[i][j] = v[i][j] > v[i][k] + v[k][j] ? v[i][j] : v[i][k] + v[k][j];
					}
				}
			}
		}
	}
}

void print(const std::vector<std::vector<int>>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = 0; j < v[i].size(); j++) {
			std::cout << "| " << std::setw(3) << v[i][j] << " |";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	//Заполняем пути до вершин в соотвествии с графом, который приведён в отчёте		
	std::vector<std::vector<int>> graph = {
			{0,   5,   3,   -9,   -9, -9, -9, -9, -9},
			{-9, 0,   -9, 2,   -9, 5, -9, -9, -9},
			{-9, -9, 0,   -9,   1, -9,   3,   -9, -9},
			{-9, -9, -9, 0,   -9,   -9,   -9, -9, 4},
			{-9, -9, -9, -9, 0,   4, -9, -9,   -9},
			{-9, -9, -9, -9, -9, 0,   -9,   -9, 2},
			{-9, -9, -9, -9, -9, -9, 0,   3,   -9},
			{-9, -9, -9, -9, -9, -9, -9, 0,   3},
			{-9,   -9,   -9,  -9,   -9, -9, -9, -9, 0}
	};
	print(graph);
	alg_floid(graph);
	print(graph);

}