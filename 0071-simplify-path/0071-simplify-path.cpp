class Solution {
public:
//     string simplifyPath(string path) {

//         // create a stack
//         stack<char> st;
//         if(path.empty()) return "/";
//         if(path.size() > 0) st.push('/');
        

//         for (int i = 1; i<path.size();) 
//         {
//             // condtions
//             if (path[i] == '/') 
//             {
//                 if (!st.empty() && st.top() != '/') 
//                 {
//                     st.push('/');
                    
//                 }
//                 i++;
//             }

//             else if (path[i] == '.') 
//             {
//                 if (i+1 < path.size() && path[i+1] == '.' && 
//                    (i+2 >= path.size() || path[i+2] == '/'))
//                 {
//                     if(st.size() > 1)
//                     {
//                         st.pop();
//                         while(!st.empty() && st.top() != '/')
//                         {
//                             st.pop();
//                         }
//                     }

//                     i += 2;
                    
//                 }
//                 else //('.')
//                 {
//                     i++;
//                 }
//             }

//             else
//             {
//                 st.push(path[i]);
//                 i++;
//             }

//         }

//         //checking if / at the end
//         if(st.size() > 1 && st.top() == '/') st.pop();

//         string ans = "";

//         while(!st.empty())
//         {
//             auto ch = st.top();
//             st.pop();
//             ans+=ch;
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };


string simplifyPath(string path)
{
    stack<string>st;
    stringstream ss(path);
    string token = "";

    while(getline(ss, token, '/'))
    {
        if(token == "" || token == ".") continue;
        if(token == ".." )
        {
            if(!st.empty()) st.pop();


        }
        else
        {
            st.push(token);
        }
    }

    string ans = "";
    while(!st.empty())
    {
        auto word = st.top();
        st.pop();
        ans = "/" + word + ans;

    }
    

/*reverse(ans.begin(), ans.end());*/
return ans.empty() ? "/" : ans;


}






























/*
string simplifyPath(string path) {
    stack<string> st;
    stringstream ss(path);
    string token;
    
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") continue;
        if (token == "..") {
            if (!st.empty()) st.pop();
        } else {
            st.push(token);
        }
    }
    
        string ans = "";

        while(!st.empty())
        {
            auto ch = st.top();
            st.pop();
            ans = "/" + ch + ans;
        }

        // reverse(ans.begin(), ans.end());
        return ans.empty() ? "/" : ans;
}
*/
};