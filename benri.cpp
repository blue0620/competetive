#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


	string Replace(string String1,string String2, string String3 ){//�����u��
		
    	string::size_type  Pos( String1.find( String2 ) );

    	while( Pos != string::npos )
		{
        		String1.replace( Pos, String2.length(), String3 );
        		Pos = String1.find( String2, Pos + String3.length() );
    	}
    	return String1;
	}
	do{//�S����
	
 	}while(next_permutation(data.begin(), data.end()));
	
	string hoge(n,'-');//�C�Ӓ���string��-�Ŗ��߂Ċm��
	
	string IntToString(int number)//int��string�ɕϊ�
	{
  	stringstream ss;
  	ss << number;
  	return ss.str();
	}
	
	int StringToInt(string str)//string��int�ɕϊ�
	{
  	stringstream ss;
	int number;
	ss<<str;
  	ss >> number;
  	return number;
	}
	
	lower_bound(a,a+n,k);//�\�[�g���ꂽ�v�fn�̗�a����a_i>k �ƂȂ�悤�ȍŏ��̃|�C���^��Ԃ�
	priority_queue<int> que;//�v���C�I���e�B�L���[push�œ����Atop,pop�œ��ꂽ���ň�ԑ傫�������o�Ă���
	
	// v = { 1, 2, 3, 4, 5 }
	// w.size() >= 5 ����Ȃ��ƃ_��
	partial_sum(v.begin(), v.end(), w.begin()); // w = { 1, 3, 6, 10, 15 }
	partial_sum(v.begin(), v.end(), v.begin()); // v�ɏ㏑�����ł��� v = { 1, 3, 6, 10, 15 }

