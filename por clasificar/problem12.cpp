#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
	int row;
	int column;
} tNode;

void solveCase();
void sensors(vector<vector<char>> & garden, int rows, int columns, int rank,
		int row, int column);
void solve(vector<vector<char>> & garden, int rows, int columns, int entryRow,
		int entryColumn, int doorRow, int doorColumn);
tNode walkAdjacents(tNode & node, int counter);

int main() {
	int casesNumber;
	scanf("%d", &casesNumber);
	for (int i = 0; i < casesNumber; i++) {
		solveCase();
	}
	return 0;
}

void solveCase() {
	int rows, columns, entryRow = 0, entryColumn = 0, doorRow = 0, doorColumn =
			0;
	char trash;

	scanf("%d %d\n", &columns, &rows);
	vector<vector<char>> garden(rows, vector<char>(columns));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			scanf("%c", &garden[i][j]);
			if (garden[i][j] == 'E') {
				entryRow = i;
				entryColumn = j;
			} else if (garden[i][j] == 'P') {
				doorRow = i;
				doorColumn = j;
			}
		}
		scanf("%c", &trash);
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int rank = (int) (garden[i][j] - '0');
			if (rank >= 0 && rank <= 9) {
				sensors(garden, rows, columns, rank, i, j);
			}
		}
	}

	solve(garden, rows, columns, entryRow, entryColumn, doorRow, doorColumn);
}

void sensors(vector<vector<char>> & garden, int rows, int columns, int rank,
		int row, int column) {
	int aux;
	garden[row][column] = '!';
	bool wall1 = false, wall2 = false, wall3 = false, wall4 = false;
	for (int i = 1; i <= rank; i++) {
		if (row + i < rows && !wall1) {
			aux = (int) (garden[row + i][column] - '0');
			if (garden[row + i][column] != '#' && (aux < 0 || aux > 9)) {
				garden[row + i][column] = '!';
			} else if (garden[row + i][column] == '#') {
				wall1 = true;
			}
		}
		if (row - i >= 0 && !wall2) {
			aux = (int) (garden[row - i][column] - '0');
			if (garden[row - i][column] != '#' && (aux < 0 || aux > 9)) {
				garden[row - i][column] = '!';
			} else if (garden[row - i][column] == '#') {
				wall2 = true;
			}
		}
		if (column + i < columns && !wall3) {
			aux = (int) (garden[row][column + i] - '0');
			if (garden[row][column + i] != '#' && (aux < 0 || aux > 9)) {
				garden[row][column + i] = '!';
			} else if (garden[row][column + i] == '#') {
				wall3 = true;
			}
		}
		if (column - i >= 0 && !wall4) {
			aux = (int) (garden[row][column - i] - '0');
			if (garden[row][column - i] != '#' && (aux < 0 || aux > 9)) {
				garden[row][column - i] = '!';
			} else if (garden[row][column - i] == '#') {
				wall4 = true;
			}
		}
	}
}

void solve(vector<vector<char>> & garden, int rows, int columns, int entryRow,
		int entryColumn, int doorRow, int doorColumn) {

	if (garden[entryRow][entryColumn] == '!'
			|| garden[doorRow][doorColumn] == '!') {
		printf("NO\n");
		return;
	}

	bool found = false;
	vector<vector<int>> distances(rows, vector<int>(columns, 0));
	vector<vector<bool>> marked(rows, vector<bool>(columns, false));
	queue<tNode> q;

	tNode begining;
	begining.row = entryRow;
	begining.column = entryColumn;
	distances[begining.row][begining.column] = 0;
	marked[begining.row][begining.column] = true;
	q.push(begining);
	while (!q.empty() && !found) {
		tNode current = q.front();
		q.pop();
		for (int i = 0; i < 4 && !found; i++) {
			tNode next = walkAdjacents(current, i);
			if (next.row >= 0 && next.row < rows && next.column >= 0
					&& next.column < columns
					&& garden[next.row][next.column] != '#'
					&& garden[next.row][next.column] != '!') {
				if (!marked[next.row][next.column]) {
					marked[next.row][next.column] = true;
					distances[next.row][next.column] =
							distances[current.row][current.column] + 1;
					if (next.row == doorRow && next.column == doorColumn) {
						found = true;
						printf("%d\n", distances[next.row][next.column]);
					}
					q.push(next);
				}
			}
		}
	}
	if (!found) {
		printf("NO\n");
	}
}

tNode walkAdjacents(tNode & node, int counter) {
	tNode next = node;
	if (counter == 0) {
		next.row--;
	} else if (counter == 1) {
		next.column++;
	} else if (counter == 2) {
		next.row++;
	} else {
		next.column--;
	}
	return next;
}
