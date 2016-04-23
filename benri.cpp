#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


	string Replace(string String1,string String2, string String3 ){//文字置換
		
    	string::size_type  Pos( String1.find( String2 ) );

    	while( Pos != string::npos )
		{
        		String1.replace( Pos, String2.length(), String3 );
        		Pos = String1.find( String2, Pos + String3.length() );
    	}
    	return String1;
	}
	do{//全順列
	
 	}while(next_permutation(data.begin(), data.end()));
	
	string hoge(n,'-');//任意長のstringを-で埋めて確保
	
	string IntToString(int number)//intをstringに変換
	{
  	stringstream ss;
  	ss << number;
  	return ss.str();
	}
	
	int StringToInt(string str)//stringをintに変換
	{
  	stringstream ss;
	int number;
	ss<<str;
  	ss >> number;
  	return number;
	}
	
	lower_bound(a,a+n,k);//ソートされた要素n個の列aからa_i>k となるような最小のポインタを返す
	priority_queue<int> que;//プライオリティキューpushで入れる、top,popで入れた中で一番大きい数が出てくる
	
	// v = { 1, 2, 3, 4, 5 }
	// w.size() >= 5 じゃないとダメ
	partial_sum(v.begin(), v.end(), w.begin()); // w = { 1, 3, 6, 10, 15 }
	partial_sum(v.begin(), v.end(), v.begin()); // vに上書きもできる v = { 1, 3, 6, 10, 15 }

