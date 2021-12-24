#include <bits/stdc++.h>

using namespace std;

int main() {
   string a;
   string b;
   cin >> a >> b;
   int lena = 0, lenb = 0;
   int it = 0;
   while (it != a.size()) {
       if (a[it] == 'o') {
           it += 3;
       } else {
           it += 4;
       }
       lena += 1;
   }
   it = 0;
   while (it != b.size()) {
       if (b[it] == 'o') {
           it += 3;
       } else {
           it += 4;
       }
       lenb += 1;
   }
   if (lena < lenb) {
       cout << "<" << endl;
   } else if (lena > lenb) {
       cout << ">" << endl;
   } else {
       it = 0;
       while (a[it] == b[it] && it != a.size()) {
           if (a[it] == 'o') {
               it += 3;
           } else {
               it += 4;
           }
       }
       if (it == a.size()) {
           cout << "=" << endl;
       } else if (a[it] == 'o') {
           cout << ">" << endl;
       } else {
           cout << "<" << endl;
       }
    }
}