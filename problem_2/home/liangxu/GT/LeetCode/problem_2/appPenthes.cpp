
#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std; 

struct state
{ 
  int l; 
  int l_left; 
  int l_right;
  int m; 
  int m_left; 
  int m_right;
  int n;  
  int n_left; 
  int n_right;  
}; 



void validParentheses(state&          s, 
                      vector<string>& res, 
                      string&         current, 
                      stack<char>&    st,
                      int             level, 
                      int             total)
{
    if (level == total)
    {
      res.push_back(current); 
    }
    cout << "Leven " << current << " stack size "<< st.size() << endl; 
    
    // add left
    if (s.l_left < s.l)
    {
      current.push_back('('); 
      st.push('('); 
      ++s.l_left; 
      validParentheses(s, res, current, st, level + 1, total); 
      current.pop_back();
      --s.l_left; 
    }

    if (s.m_left < s.m)
    {
      current.push_back('<'); 
      st.push('<'); 
      ++s.m_left; 
      validParentheses(s, res, current, st, level + 1, total); 
      current.pop_back(); 
      --s.n_left; 
    }

    if (s.n_left < s.n)
    {
      current.push_back('{'); 
      st.push('{'); 
      ++s.n_left; 
      validParentheses(s, res, current, st, level + 1, total); 
      current.pop_back();
      --s.n_left; 
    }

    // add right
    if (!st.empty())
    {
      if (st.top() == '(')
      {
        current.push_back(')');
      } else if (st.top() == '<')
      {
        current.push_back('>');
      } else if (st.top() == '{')
      {
        current.push_back('}');
      }
      st.pop();
      validParentheses(s, res, current, st, level + 1, total); 
      current.pop_back();  
    }

    
}

vector<string> validParentheses_solve(int l, int m, int n) 
{
  // write your solution here
  vector<string> res; 
  stack<char> st; 
  state s{l,0,0,m,0,0,n,0,0};
  string current; 
  validParentheses(s, res, current, st, 0, (l + m + n) * 2 ); 
  return res; 
}

int main()
{
    vector<string> res =  validParentheses_solve(1,0,2); 
    for (auto& st : res)
    {
        cout << st << endl; 
    }
    return 0; 
}