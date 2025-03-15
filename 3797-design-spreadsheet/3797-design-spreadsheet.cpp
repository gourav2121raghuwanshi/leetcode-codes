class Spreadsheet {
public:
    int r;
    vector<vector<int>> v;

    Spreadsheet(int rows) {
        r = rows;
        v.resize(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        v[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        v[row][col] = 0;
    }

    bool isAllDigit(const string &s) {
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    int getValue(string formula) {


        formula = formula.substr(1); 
        size_t pos = formula.find('+');

        string a = formula, b = "";
        if (pos != string::npos) {
            a = formula.substr(0, pos);
            b = formula.substr(pos + 1);
        }

        int value = 0;
        if (isAllDigit(a)) {
            value += stoi(a);
        } else {
            int row = stoi(a.substr(1)) - 1;
            value += v[row][a[0] - 'A'];
        }

        if (!b.empty()) {
            if (isAllDigit(b)) {
                value += stoi(b);
            } else {
                int row = stoi(b.substr(1)) - 1;
                value += v[row][b[0] - 'A'];
            }
        }

        return value;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
