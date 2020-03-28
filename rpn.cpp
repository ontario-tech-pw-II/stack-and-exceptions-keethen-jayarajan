// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")


int main() 
{
    string in;
    stack<string> st;   // stack definition

    int value1, value2, value3;
    cin >> in;
    
    while(in != "q")
    {
        try
        {
            if (is_str_digit(in))
            {
                // add your code here
                st.push(in);
            }
            else if (is_str_operator(in))
            {
                if (st.size() < 2)
                    throw 3;
                
                value1 = stoi(st.top()); 
                st.pop();
                value2 = stoi(st.top()); 
                st.pop();
                
                switch(in[0])
                {
                    case '+':
                        value3 = value2 + value1;
                        break;

                    case '-':
                        value3 = value2 - value1;
                        break;

                    case '*':
                        value3 = value2 * value1;
                        break;

                    case '/':
                        if (value1 == 0)
                            throw 1;
                            
                        value3 = value2 / value1;
                        break;
                }
                // add your code here
                st.push(to_string(value3));
            }
        }

        catch (int i)
        {
            if (i == 1)
                cout << "ERROR: CANNOT DIVIDE BY ZERO" << endl;
            else if (i == 2)
                cout << "ERRORS: INTEGERS REMAIN IN STACK" << endl;
            else if (i == 3)
                cout << "ERROR: NOT ENOUGH VALUES IN STACK" << endl;
            return 0;
        }
        cin >> in;
    }

    if (st.size() != 1)
        throw 2;
    cout << "The answer is: " << st.top() << endl;
    
    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}