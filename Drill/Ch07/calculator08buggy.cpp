
/*
	calculator08buggy.cpp
	Helpful comments removed.
	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

	Grammar:
	
	Calculation:
		Statement
		Print
		Quit
		Calculation Statement
	Print:
		;
	Quit:
		exit
	Statement:
		Declaration
		Expression
	Declaration:
		'#' Name "=" Expression
	Name:
		string literal
	Expression:
		Term
		Expression + Term
		Expression – Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
		( Expression )
		– Primary
		+ Primary
	Number:
		floating-point-literal

		Functions:
			Sqrt
			Pow
*/

#include "std_lib_facilities.h" //Include usual header

//Symbolic constants for clarity///
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char result = '=';
const char square_root='@';
const char pow_calc = '$';

const string declkey = "let";
const string quitkey = "exit";
const string sqrtkey = "sqrt";
const string powkey = "pow";

//function declaration///
double expression();
double primary();
double term();
double declaration();
double statement();

//Variable///////
class Variable {
public:	
	string name;
	double value;
	
};

vector<Variable> names;

double get_value(string s)
{
	for (const auto& v: names)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : names)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (const auto& v: names)
		if (v.name == s) return true;
	return false;
}

double define_name(string s, double val)
{
	if(is_declared(s)) error(s," declared twice");
	names.push_back(Variable{s,val});
	return val;
}

//Variable end////

//Token///////

class Token {
public:	
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};

//Token end/////////


//Token stream//////////
class Token_stream {
public:
	Token_stream();
	Token get();
	void unget(Token t);  
	void ignore(char c);

private:
	bool full;
	Token buffer;	
};


Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::unget(Token t)
{
	if(full) error("unget() into full buffer");
	buffer = t;
	full=true;

}

Token Token_stream::get()
{
	if (full) 
	{ 	
		full = false; 
		return buffer; 
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
	case let:
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
	{
		if (isalpha(ch)) 
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.unget();
		 	if(s== quitkey) return Token{quit};
			else if(s==sqrtkey) return Token{square_root};
			else if (s==powkey) return Token{pow_calc};
			else if (is_declared(s))
				return Token(number, get_value(s));
			
			return Token{name,s};
		}
		error("Bad token");
	}
	return 0;
	}
	
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch =0;
	while (cin >> ch)
		if (ch == c) return;
}
// Token_stream end ////////

Token_stream ts;

// Sqrt function//////

double calc_sqrt(){
	char ch;
	if(cin.get(ch) && ch !='(') error("'(' expected");
	cin.unget();
	double d = expression();
	if(d<0)error("sqrt: negative value");
	return sqrt(d);
}
//Sqrt end////

//Pow function//////
double calc_pow(){
	Token t=ts.get();

	if(t.kind!='(') error("'(' expected");
	double d=expression();

	t=ts.get();

	if(t.kind!=',') error("',' expected");
	double d2=expression();
	if(d2!=narrow_cast<int>(d2)) error("info loss");
	t=ts.get();
	if(t.kind!=')')error("')' expected");

	return pow(d,d2);

}
//Pow end///////


//Function mapping grammar rules///////
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		case '(':
		{	
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("'(' expected");
			return d;
		}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case square_root:
		return calc_sqrt();
	case pow_calc:
		return calc_pow();		
	default:
		error("primary expected");
		
	}
	return -1;
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);

	double d = expression();
	define_name(name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

//Function mapping grammar rules end //////////

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";

//Logically seperate calculate() from the usual "boiler plate" of main//
void calculate()
{
	while (cin) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	
	define_name("k",1000);

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

//Program end!