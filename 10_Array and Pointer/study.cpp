#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<list>
#include<cstring>   
#include<sstream>
#include<set>
#include<map>
#include<cmath>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)


int main() {
   fastio;
   

   int x = 20;
   cout << "x: " << x << "&x: " << &x << '\n';

   const int y = 23;
   cout << "y: " << y << "&y: " <<' '<< &y << '\n';

   //여기까지는 쉬우니까 pass
   
   //포인터
   const int* p1 = &x;
   //p1 += 1; //가능  
   // 톡으로 말한거처럼 const int *은 포인터로 (x)값 변경이 불가  int * const p1 으로 바꾸면 p1+=1도 안될거임
   //밑에줄 불가능 이거 주석해제하면 오류뜰꺼임
   //*p1 += 1;
   cout << "const int * p1 : " << p1 << ' ' << "*p1: " << *p1 << '\n';
   //p2 반복
   const int* p2 = &y;
   cout << "const int * p2 : " << p2 << ' ' << "*p2: " << *p2 << '\n';

   //이중 포인터

   const int** pp2 = &p1;
   
   //이중포인터도 마찬가지로 const int** (x)값 변경이 불가 int ** const pp2 로 바꾸면 pp2+=1도 안되겠지... *pp2 +=1은 되고
   //*pp2 += 1;//가능
   //pp2 += 1;//가능
   //**pp2 += 2;// 불가능
   cout << "const int ** pp2 : " << pp2 << ' ' << "*pp2: " << *pp2 <<"**pp2"<< **pp2 <<'\n';

   return 0;
}