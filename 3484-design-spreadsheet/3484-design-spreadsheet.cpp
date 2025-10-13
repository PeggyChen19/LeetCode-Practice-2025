class Spreadsheet {
private:
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        for (int i = 0; i < rows; i++) {
            vector<int> row(26, 0);
            sheet.push_back(row);
        }
    }
    
    void setCell(string cell, int value) {
        auto [i, j] = getCell(cell);
        sheet[i][j] = value;
    }
    
    void resetCell(string cell) {
        auto [i, j] = getCell(cell);
        sheet[i][j] = 0;
    }
    
    int getValue(string formula) {
        int i = 1; // skip =
        int x = parseElement(formula, i);
        i++; // skip +
        int y = parseElement(formula, i);
        return x + y;
    }

private:
    pair<int, int> getCell(string& cell) {
        char col = cell[0] - 'A';
        int i = 1;
        int row = 0;
        while (i < cell.size()) {
            row = row * 10 + cell[i] - '0';
            i++;
        }
        return {row - 1, col}; // row - 1 because of 1-indexed
    }

    int parseElement(string& formula, int& i) {
        if (formula[i] >= 'A' && formula[i] <= 'Z') { // cell
            int col = formula[i] - 'A';
            i++;
            int row = 0;
            while (i < formula.size() && isdigit(formula[i])) {
                row = row * 10 + formula[i] - '0';
                i++;
            }
            return sheet[row - 1][col];
        } else { // non-negative integers
            int num = 0;
            while (i < formula.size() && isdigit(formula[i])) {
                num = num * 10 + formula[i] - '0';
                i++;
            }
            return num;
        }
    }
};

/*
datastructure: vector<vector<int>>
cell: the first char is A to Z, the remaining is number
formula: must be =X+Y format
*/