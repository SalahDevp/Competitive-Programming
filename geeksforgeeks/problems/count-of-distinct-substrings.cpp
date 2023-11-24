// problem url: https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
	int t, l, i, j;
	int temp;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << countDistinctSubstring(s) << endl;
	}
}

// } Driver Code Ends
#define ALPHA_SIZE 26
typedef long long ll;

struct tn
{
	tn *children[ALPHA_SIZE];
};

void insert(tn *node, char c)
{
	tn *ptr = new tn();
	for (int i = 0; i < ALPHA_SIZE; i++)
		ptr->children[i] = nullptr;
	node->children[c - 'a'] = ptr;
}
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
	int count = 1;
	tn *root = new tn();
	for (int i = 0; i < ALPHA_SIZE; i++)
		root->children[i] = nullptr;
	tn *ptr;
	for (int i = 0; i < s.length(); i++)
	{
		ptr = root;
		for (int j = i; j < s.length(); j++)
		{
			if (ptr->children[s[j] - 'a'] == nullptr)
			{
				count++;
				insert(ptr, s[j]);
			}
			ptr = ptr->children[s[j] - 'a'];
		}
	}
	return count;
}