#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> var;

// SAFE TRIM
string trim(string s) {
    int start = 0;
    while (start < (int)s.size() && s[start] == ' ') start++;

    int end = (int)s.size() - 1;
    while (end >= start && s[end] == ' ') end--;

    return (start <= end) ? s.substr(start, end - start + 1) : "";
}

bool isNumber(string s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

// ================== ORIGINAL HELPERS ==================
int precedence(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

int applyOp(int a, int b, string op, bool &error) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            cout << "Error: Division by zero\n";
            error = true;
            return 0;
        }
        return a / b;
    }
    return 0;
}

// ================== EXPRESSION ==================
int evaluate(string expr, bool &error) {
    stringstream ss(expr);
    vector<string> tokens;
    string temp;

    while (ss >> temp)
        tokens.push_back(temp);

    vector<int> values;
    vector<string> ops;

    auto getValue = [&](string s) -> int {
        if (isNumber(s)) return stoi(s);
        if (var.count(s)) return var[s];

        cout << "Error: Undefined variable -> " << s << endl;
        error = true;
        return 0;
    };

    for (int i = 0; i < (int)tokens.size(); i++) {
        string t = tokens[i];

        if (isNumber(t) || var.count(t)) {
            values.push_back(getValue(t));
        }
        else if (t == "(") ops.push_back(t);
        else if (t == ")") {
            while (!ops.empty() && ops.back() != "(") {
                int b = values.back(); values.pop_back();
                int a = values.back(); values.pop_back();
                string op = ops.back(); ops.pop_back();
                values.push_back(applyOp(a, b, op, error));
            }
            if (!ops.empty()) ops.pop_back();
        }
        else {
            while (!ops.empty() && precedence(ops.back()) >= precedence(t)) {
                int b = values.back(); values.pop_back();
                int a = values.back(); values.pop_back();
                string op = ops.back(); ops.pop_back();
                values.push_back(applyOp(a, b, op, error));
            }
            ops.push_back(t);
        }

        if (error) return 0;
    }

    while (!ops.empty()) {
        int b = values.back(); values.pop_back();
        int a = values.back(); values.pop_back();
        string op = ops.back(); ops.pop_back();
        values.push_back(applyOp(a, b, op, error));
    }

    return values.back();
}

// ================== CONDITION (ORIGINAL) ==================
bool evaluateCondition(string left, string op, string right) {
    int l, r;

    if (isNumber(left)) l = stoi(left);
    else l = var[left];

    if (isNumber(right)) r = stoi(right);
    else r = var[right];

    if (op == "==") return l == r;
    if (op == "!=") return l != r;
    if (op == ">") return l > r;
    if (op == "<") return l < r;
    if (op == ">=") return l >= r;
    if (op == "<=") return l <= r;

    return false;
}

// ================== 🔥 NEW LOGICAL ENGINE (ADDED ONLY) ==================
bool evaluateLogicalLine(string line) {

    // replace && || ! into tokens
    stringstream ss(line);
    vector<string> t;
    string x;

    while (ss >> x) t.push_back(x);

    bool result = false;
    bool current = false;
    string op = "";

    auto evalSimple = [&](string a, string oper, string b) -> bool {

        int l = isNumber(a) ? stoi(a) : var[a];
        int r = isNumber(b) ? stoi(b) : var[b];

        if (oper == ">") return l > r;
        if (oper == "<") return l < r;
        if (oper == ">=") return l >= r;
        if (oper == "<=") return l <= r;
        if (oper == "==") return l == r;
        if (oper == "!=") return l != r;

        return false;
    };

    for (int i = 0; i < (int)t.size(); i++) {

        if (t[i] == "&&" || t[i] == "||") {
            op = t[i];
            continue;
        }

        if (t[i] == "!") {
            current = !current;
            continue;
        }

        // simple condition: a > b
        if (i + 2 < (int)t.size()) {
            current = evalSimple(t[i], t[i + 1], t[i + 2]);
            i += 2;
        }

        if (op == "") result = current;
        else if (op == "&&") result = result && current;
        else if (op == "||") result = result || current;
    }

    return result;
}

// ================== EXECUTE BLOCK ==================
void executeBlock(vector<string> block) {
    for (string line : block) {
        bool dummy;
        stringstream ss(line);
        string name;
        ss >> name;

        if (name == "print") {
            string v;
            ss >> v;
            cout << var[v] << endl;
        }
        else if (line.find("=") != string::npos) {
            int pos = line.find("=");
            string n = trim(line.substr(0, pos));
            string e = trim(line.substr(pos + 1));
            var[n] = evaluate(e, dummy);
        }
        else if (line.find("++") != string::npos) {
            string n = trim(line.substr(0, line.find("++")));
            var[n]++;
        }
        else if (line.find("--") != string::npos) {
            string n = trim(line.substr(0, line.find("--")));
            var[n]--;
        }
    }
}

// ================== MAIN ==================
int main() {

    string line;

    cout << "==== MINI INTERPRETER ====\n";

    while (getline(cin, line)) {

        line = trim(line);

        if (line == "exit") break;
        if (line.empty()) continue;

        // ================== WHILE LOOP ==================
        if (line.find("while") == 0) {

            string cond = line.substr(5);

            for (char &c : cond)
                if (c == '(' || c == ')')
                    c = ' ';

            vector<string> block;
            string l;

            getline(cin, l);

            while (getline(cin, l) && trim(l) != "}") {
                block.push_back(trim(l));
            }

            while (evaluateLogicalLine(cond)) {
                executeBlock(block);
            }

            continue;
        }

        // ================== FOR LOOP ==================
        if (line.find("for") == 0) {

            string s = line.substr(3);

            for (char &c : s)
                if (c == '(' || c == ')' || c == ';')
                    c = ' ';

            string varName, eq, value;
            string a, op, b, inc;

            stringstream ss(s);
            ss >> varName >> eq >> value >> a >> op >> b >> inc;

            var[trim(varName)] = stoi(value);

            vector<string> block;
            string l;

            getline(cin, l);

            while (getline(cin, l) && trim(l) != "}") {
                block.push_back(trim(l));
            }

            while (evaluateCondition(a, op, b)) {
                executeBlock(block);

                string n = trim(inc.substr(0, inc.find("++")));
                if (inc.find("++") != string::npos) var[n]++;
                if (inc.find("--") != string::npos) var[n]--;
            }

            continue;
        }

        // ================== PRINT ==================
        if (line.find("print") == 0) {
            string name = trim(line.substr(6));
            cout << var[name] << endl;
            continue;
        }

        // ================== SHOW ==================
        if (line == "show") {
            for (auto p : var)
                cout << p.first << " = " << p.second << endl;
            continue;
        }

        // ================== INCREMENT ==================
        if (line.find("++") != string::npos) {
            string name = trim(line.substr(0, line.find("++")));
            var[name]++;
            continue;
        }

        // ================== DECREMENT ==================
        if (line.find("--") != string::npos) {
            string name = trim(line.substr(0, line.find("--")));
            var[name]--;
            continue;
        }

        // ================== ASSIGNMENT ==================
        if (line.find("=") != string::npos) {
            int pos = line.find("=");
            string name = trim(line.substr(0, pos));
            string expr = trim(line.substr(pos + 1));

            bool error = false;
            var[name] = evaluate(expr, error);
            continue;
        }

        cout << "Error: Invalid statement -> " << line << endl;
    }

    cout << "Interpreter exited.\n";
    return 0;
}