#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Morse_code {
protected:
	string name{};
	string code{};
public:
	void setName(const string& newName) { name = newName; }
	string getName() { return name; }
	void setCode(const string& newCode) { code = newCode; }
	string getCode() { return code; }
	void show() { cout << getCode() << endl; }
	Morse_code(const string& newName, const string& newCode) {
		name = newName;
		code = newCode;
	}
};

[[noreturn]]
void doSomething() {
	throw runtime_error("何か問題が発生しました。");
}

int main() {
	vector<Morse_code>vec;

	vec.push_back(*(new Morse_code(".", "010101")));
	vec.push_back(*(new Morse_code(",", "110011")));
	vec.push_back(*(new Morse_code(":", "111000")));
	vec.push_back(*(new Morse_code("?", "001100")));
	vec.push_back(*(new Morse_code("'", "011110")));
	vec.push_back(*(new Morse_code("-", "100001")));
	vec.push_back(*(new Morse_code("(", "10110")));
	vec.push_back(*(new Morse_code(")", "101101")));
	vec.push_back(*(new Morse_code("/", "10010")));
	vec.push_back(*(new Morse_code("=", "10001")));
	vec.push_back(*(new Morse_code("+", "01010")));
	vec.push_back(*(new Morse_code("×", "1001")));
	vec.push_back(*(new Morse_code("＠", "011010")));
	vec.push_back(*(new Morse_code("A", "01")));
	vec.push_back(*(new Morse_code("B", "1000")));
	vec.push_back(*(new Morse_code("C", "1010")));
	vec.push_back(*(new Morse_code("D", "100")));
	vec.push_back(*(new Morse_code("E", "0")));
	vec.push_back(*(new Morse_code("F", "0010")));
	vec.push_back(*(new Morse_code("G", "110")));
	vec.push_back(*(new Morse_code("H", "0000")));
	vec.push_back(*(new Morse_code("I", "00")));
	vec.push_back(*(new Morse_code("J", "0111")));
	vec.push_back(*(new Morse_code("K", "101")));
	vec.push_back(*(new Morse_code("L", "0100")));
	vec.push_back(*(new Morse_code("M", "11")));
	vec.push_back(*(new Morse_code("N", "10")));
	vec.push_back(*(new Morse_code("O", "111")));
	vec.push_back(*(new Morse_code("P", "0110")));
	vec.push_back(*(new Morse_code("Q", "1101")));
	vec.push_back(*(new Morse_code("R", "010")));
	vec.push_back(*(new Morse_code("S", "000")));
	vec.push_back(*(new Morse_code("T", "1")));
	vec.push_back(*(new Morse_code("U", "001")));
	vec.push_back(*(new Morse_code("V", "0001")));
	vec.push_back(*(new Morse_code("W", "011")));
	vec.push_back(*(new Morse_code("X", "1001")));
	vec.push_back(*(new Morse_code("Y", "1011")));
	vec.push_back(*(new Morse_code("Z", "1100")));
	vec.push_back(*(new Morse_code("1", "01111")));
	vec.push_back(*(new Morse_code("2", "00111")));
	vec.push_back(*(new Morse_code("3", "00011")));
	vec.push_back(*(new Morse_code("4", "00001")));
	vec.push_back(*(new Morse_code("5", "00000")));
	vec.push_back(*(new Morse_code("6", "10000")));
	vec.push_back(*(new Morse_code("7", "11000")));
	vec.push_back(*(new Morse_code("8", "11100")));
	vec.push_back(*(new Morse_code("9", "11110")));
	vec.push_back(*(new Morse_code("0", "11111")));
	vec.push_back(*(new Morse_code(" ", " ")));

	auto begin = vec.begin();
	auto end = vec.end();
	for (;;) {
	start:
		cout << " " << endl;
		cout << "アルファベットなどからモールス変換したい場合は1、モールス信号(数字)からアルファベットに変換したい場合は2、終了したい場合は3を入力してください。" << endl;
		int n;
		cin >> n;
		if (n % 3 == 1) {
			cout << "アルファベットなどからモールス変換をするモードです。" << endl;
			cout << " " << endl;
			cout << "変換したい文字列を大文字アルファベットまたは数字、記号を半角にして入力し, Enterキーを押してください。" << endl;
			string Mozi{};
			cin >> Mozi;
			int s = Mozi.size();

			cout << " " << endl;

			for (int x = 0; x < s; ++x) {
				string target1 = ""s + Mozi[x];
				for (auto i = begin; i != end; ++i) {
					auto ip = *i;
					if (ip.getName() == target1) {
						cout << ip.getCode() << " ";
					}
				}
			}
			cout << " " << endl;
		}
		else if (n % 3 == 2) {
			vector<string>v1;
			int x1 = 0;

			cout << "モールス信号(数字)からアルファベットに変換するモードです。（Ctrl+Cで強制終了します。）" << endl;
			cout << " " << endl;
			for (;;) {
				cout << " " << endl;
				cout << "変換したいモールス信号を1句切りずつ入力し、Enterキーを押してください。全部入力が終わった場合はdone、このモードを終了したい場合はescapeと入力してください。" << endl;
				cout << " " << endl;

				string Code{};
				cin >> Code;
				int s2 = Code.size();
				string target2 = Code;

				if (Code == "escape") {
					goto start;
				}
				else if (Code == "done") {
					for (int j = 0; j < x1; ++j) {
						cout << v1[j];
					}
					cout << " " << endl;
				}
				else {
					for (auto i = begin; i != end; ++i) {
						auto ip = *i;
						if (ip.getCode() == target2) {
							v1.push_back(ip.getName());
							x1++;
						}
					}
				} 
			}
		}
		else if (n % 3 == 0) { 
			cout << "任意のボタンを押すと終了します。" << endl; 
			goto endd;
		}
	}
endd:
	;
}