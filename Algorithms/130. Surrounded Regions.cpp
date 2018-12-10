#define O 'O'
#define X 'X'
typedef struct Coordinate {
	int row;
	int col;
	Coordinate(int row, int col) : row(row), col(col) {}
} *PCoordinate;

class Solution {
public:
	void solve(vector<vector<char>>& board);
private:
	bool **collected;
	bool bfs(vector<vector<char>>& board, vector<PCoordinate>& region, int i, int j);
	bool onBorder(int row, int col, int nRows, int nCols);
	void getCoordinatesAround(vector<vector<char>>& board, vector<PCoordinate>& surroundings, int i, int j);
	bool canAround(vector<vector<char>>& board, int i, int j);
};

void Solution::solve(vector<vector<char>>& board) {
	int nRows = board.size();
	if (nRows == 0) return;
	int nCols = board[0].size();
	if (nCols == 0) return;
	collected = new bool*[nRows];
	for (int i = 0; i < nRows; i++) {
		collected[i] = new bool[nCols];
		fill(collected[i], collected[i] + nCols, false);
	}
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++) //For every (i, j) on board
			if (board[i][j] == O && !collected[i][j]) {
				//Get the region formed by (i, j)
				vector<PCoordinate> region;
				if (!bfs(board, region, i, j)) { //If the region is not on the border
					for (PCoordinate pCoordinate : region) //Change characters in the region to 'X'
						board[pCoordinate->row][pCoordinate->col] = X;
				}
				for (auto it = region.begin(); it != region.end(); it++) //Delete the vector
					if (*it != NULL) {
						delete *it;
						*it = NULL;
					}
				vector<PCoordinate>().swap(region);
			}
	for (int i = 0; i < nRows; i++)
		free(collected[i]);
	free(collected);
}

bool Solution::bfs(vector<vector<char>>& board, vector<PCoordinate>& region, int i, int j) {
	int nRows = board.size();
	int nCols = board[0].size();
	queue<PCoordinate> q;
	bool isOnBorder = false;
	region.push_back(new Coordinate(i, j));
	q.push(region[0]);
	collected[i][j] = true;
	if (onBorder(i, j, nRows, nCols)) isOnBorder = true;
	while (!q.empty()) {
		PCoordinate p = q.front();
		q.pop();
		int row = p->row, col = p->col;
		vector<PCoordinate> surroundings;
		getCoordinatesAround(board, surroundings, row, col); //Get the characters around
		for (PCoordinate pCoordinate : surroundings) {
			region.push_back(pCoordinate);
			q.push(pCoordinate);
			collected[pCoordinate->row][pCoordinate->col] = true;
			if (onBorder(pCoordinate->row, pCoordinate->col, nRows, nCols))
				isOnBorder = true;
		}
	}
	return isOnBorder;
}

bool Solution::onBorder(int row, int col, int nRows, int nCols) {
	return row == 0 || row == nRows - 1 || col == 0 || col == nCols - 1;
}

void Solution::getCoordinatesAround(vector<vector<char>>& board, vector<PCoordinate>& surroundings, int i, int j) {
	if (canAround(board, i - 1, j)) surroundings.push_back(new Coordinate(i - 1, j));
	if (canAround(board, i, j - 1)) surroundings.push_back(new Coordinate(i, j - 1));
	if (canAround(board, i, j + 1)) surroundings.push_back(new Coordinate(i, j + 1));
	if (canAround(board, i + 1, j)) surroundings.push_back(new Coordinate(i + 1, j));
}

bool Solution::canAround(vector<vector<char>>& board, int i, int j) {
	int nRows = board.size();
	int nCols = board[0].size();
	return i >= 0 && i < nRows && j >= 0 && j < nCols && !collected[i][j] && board[i][j] == O;
}
