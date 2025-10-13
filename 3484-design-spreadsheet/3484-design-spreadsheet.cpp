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
        formula = formula.substr(1);
        istringstream iss(formula);
        string element;
        int result = 0;
        while (getline(iss, element, '+')) {
            if (element[0] >= 'A' && element[0] <= 'Z') { // cell
                auto [i, j] = getCell(element);
                result += sheet[i][j];
            } else { // non-negative integers
                int i = 0;
                int num = 0;
                while (i < element.size()) {
                    num = num * 10 + element[i] - '0';
                    i++;    
                }
                result += num;
            }
        }
        return result;
    }

private:
    pair<int, int> getCell(string cell) {
        char alphabet = cell[0];
        int i = 1;
        int row = 0;
        while (i < cell.size()) {
            row = row * 10 + cell[i] - '0';
            i++;
        }
        return {row - 1, alphabet - 'A'}; // row - 1 because of 1-indexed
    }
};

/*
datastructure: vector<vector<int>>
cell: the first char is A to Z, the remaining is number
formula: must be =X+Y format
*/