

#include <iostream>
#include <string>
#include <iostream>  
#include <fstream>      

using namespace std;


/*10) S->P = E | repeat S until E

P->k1 | k2

E->E + T | T

T->T * F | F

F->P | (E)

*/



enum  TLexema
{
	RP, // )
	LP, // (
	VALUE, // REPEAT , UNTIL
	END, // finish
	ITER1, // *
	ITER2, // +
	EQL,  // =
	COMMA, // ,
	IDEN, // k1 | k2
};
TLexema curr_tok;
string line = "";
string input = "input5.txt";
string result;
string errorMesage = "";
int position = 0;
int lineNumber;
bool flag = true;

TLexema get_token() {

	ofstream file;
	file.open("result.txt", ofstream::out | ofstream::app);
	string s = "";
	int lenght = line.size();
	char c;

	if (position == lenght) {
		file << "< " << lineNumber << "end line" << " END" << " >" << endl;
		return curr_tok = END;
	}

	c = line.at(position);
	while (c == ' ' && line.at(position)) {
		position++;
		if (line.at(position)) {
			file << "< " << lineNumber << " END" << " >";
			return curr_tok = END;
		}
		c = line.at(position);
	}
	if (c == '(') {
		position++;
		if (flag)
			file << "< " << lineNumber << " LP" << " >";
		return curr_tok = LP;
	}
	else	if (c == ')') {
		position++;
		if (flag)
			file << "< " << lineNumber << " RP" << " >";
		return curr_tok = RP;
	}
	else	if (c == '=') {
		position++;
		if (flag)
			file << "< " << lineNumber << " EQL" << " >";
		return curr_tok = EQL;
	}
	else	if (c == ',') {
		position++;
		if (flag)
			file << "< " << lineNumber << " COMMA" << " >";
		return curr_tok = COMMA;
	}
	else    if (c == '+') {
		position++;
		if (flag)
			file << "< " << lineNumber << " ITER2" << " >";
		return curr_tok = ITER2;
	}
	else	if (c == '*') {
		position++;
		if (flag)
			file << "< " << lineNumber << " ITER1" << " >";
		return curr_tok = ITER1;
	}
	else	if (c == 'k') {
		if (line.at(position + 1) && line.at(position + 1) == '1') {
			for (int i = 0; i < 2 && line.at(position); i++) {
				s += line.at(position);
				position++;
			}
			if (s == "k1") {
				if (flag)
					file << "< " << lineNumber << " k1 " << " IDEN" << " >";
				return curr_tok = IDEN;
			}

			else
			{
				file << endl;
				cout << " in line number " << lineNumber << "  iden have mistake" << endl;
				return curr_tok = END;

			}
			{

			}
		}
		else if (line.at(position + 1) && line.at(position + 1) == '2') {
			for (int i = 0; i < 2 && line.at(position); i++) {
				s += line.at(position);
				position++;
			}
			if (s == "k2") {
				if (flag)
					file << "< " << lineNumber << " k2 " << " IDEN" << " >";
				return curr_tok = IDEN;
			}

			else
			{
				file << endl;
				cout << " in line number " << lineNumber << "  iden have mistake" << endl;
				return curr_tok = END;

			}
			{

			}
		}
	}
	else	if (c == 'r') {
		if (line.at(position + 1) && line.at(position + 1) == 'e') {
			for (int i = 0; i < 6 && line.at(position); i++) {

				s += line.at(position);
				position++;
			}
			if (s == "repeat") {
				if (flag)
					file << "< " << lineNumber << "repeat" << "VALUE" << " >";
				return curr_tok = VALUE;
			}
			else
			{
				file << endl;
				cout << " in line number " << lineNumber << " repeat" << " VALUE is incorect " << endl;
				return curr_tok = END;
			}
		}
		else
		{
			file << endl;
			cout << " in line number " << lineNumber << " repeat" << " VALUE is incorect " << endl;
			return curr_tok = END;

		}
	}
	else	if (c == 'u') {
		if (line.at(position + 1) && line.at(position + 1) == 'n') {
			for (int i = 0; i < 5 && line.at(position); i++) {
				s += line.at(position);
				position++;
			}
			if (s == "until") {
				if (flag)
					file << "< " << lineNumber << "until" << "VALUE" << " >";
				return curr_tok = VALUE;
			}
			else
			{
				file << endl;
				cout << " in line number " << lineNumber << " until" << " UNTIL is incorect " << endl;

			}
		}
		else {
			file << endl;
			cout << " in line number " << lineNumber << " until" << " UNTIL is incorect " << endl;

		}
	}
	else {
		file << endl;
		cout << " in line number " << lineNumber << " not identified symbol" << endl;
		return curr_tok = END;
	}

}

int main()
{
	string l;
	ifstream myfile;
	myfile.open(input);
	lineNumber = 0;

	if (!myfile.is_open()) {
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 10; i++) {
		while (getline(myfile, l)) {
			line = l;
			position = 0;
			lineNumber++;
			curr_tok = RP;
			for (int i = 0; i < line.size(); i++) {
				if (curr_tok != END) {
					get_token();
				}
				else
				{
					break;
				}

			}



		}

	}
	system("pause");
	return 0;
}