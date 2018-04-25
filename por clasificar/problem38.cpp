#include <iostream>
#include <vector>
#include <map>

using namespace std;

const unsigned long long int LARGE = 1000000007;

bool solveCase();

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	/*Reading stuff*/
	int N;
	scanf("%d", &N);
	if (N == 0) {
		return false;
	}
	char trash;
	scanf("%c", &trash);
	map<vector<char>, bool> codes;
	for (int i = 0; i < N; i++) {
		vector<char> code;
		scanf("%c", &trash);
		while (trash != ' ' && trash != '\n') {
			code.push_back(trash);
			scanf("%c", &trash);
		}
		codes.insert(pair<vector<char>, bool>(code, false));
	}
	codes.insert(pair<vector<char>, bool>(vector<char>(1, '0'), false));
	vector<char> message;
	scanf("%c", &trash);
	while (trash != '\n') {
		message.push_back(trash);
		scanf("%c", &trash);
	}
	/*Filling table*/
	unsigned long long int exceptThree = 1;
	unsigned long long int exceptTwo =
			(codes.find(vector<char>(1, message[0])) != codes.end()) ? 1 : 0;
	if ((int) message.size() == 1) {
		printf("%llu\n", exceptTwo);
		return true;
	}
	unsigned long long int exceptOne;
	bool isCodeFirst = exceptTwo == 1 ? 1 : 0;
	bool isCodeSecond =
			(codes.find(vector<char>(1, message[1])) != codes.end()) ? 1 : 0;
	bool isCodeBoth =
			(codes.find(vector<char>(message.begin(), message.begin() + 2))
					!= codes.end()) ? 1 : 0;
	if (isCodeFirst && isCodeSecond && isCodeBoth) {
		exceptOne = 2;
	} else if ((!isCodeFirst || !isCodeSecond) && !isCodeBoth) {
		exceptOne = 0;
	} else {
		exceptOne = 1;
	}
	for (int i = 2; i < (int) message.size(); i++) {
		int exceptThreeMult =
				(codes.find(
						vector<char>(message.begin() + i - 2,
								message.begin() + i + 1)) != codes.end()) ?
						1 : 0;
		int exceptTwoMult =
				(codes.find(
						vector<char>(message.begin() + i - 1,
								message.begin() + i + 1)) != codes.end()) ?
						1 : 0;
		int exceptOneMult =
				(codes.find(vector<char>(1, message[i])) != codes.end()) ?
						1 : 0;
		unsigned long long int aux = (((exceptThreeMult * exceptThree
				+ exceptTwoMult * exceptTwo) % LARGE)
				+ exceptOneMult * exceptOne) % LARGE;
		exceptThree = exceptTwo;
		exceptTwo = exceptOne;
		exceptOne = aux;
	}
	printf("%llu\n", exceptOne);
	return true;
}
