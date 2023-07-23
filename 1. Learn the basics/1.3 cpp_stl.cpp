#include <bits/stdc++.h>
using namespace std;

void explainPair() {
	pair <int, int> p = make_pair(4,1);
	cout << p.first << " " << p.second << endl ;
	
	pair <int, pair <int, int> > p1 = make_pair(1, make_pair(8,2));
	cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;
	
	pair <int, int> arr[] = {make_pair(1,2), make_pair(5,4), make_pair(6,7)};
	cout << arr[0].first << arr[0].second << " " << arr[1].first << arr[1].second << " " << arr[2].first << arr[1].second << endl;
}

void explainVector() {
	vector<int> v;
	v.push_back(1);
//	cout v[0];

	vector< pair<int, int> > v1;
	v1.push_back({3,1});
//	cout << v1[0].first << " " << v1[0].second << endl;	
	
	vector<int> v2(4, 10);
//	cout << v2[0] << " " << v2[3] << endl;
	
	vector<int> v3(5) ;
//	cout << v3[4];

	vector<int> v4(5, 20) ;
	vector<int> v5(v4) ;
//	cout << v5[2] ;

	vector<int>	:: iterator it = v4.begin() ;
	it++;
	it += 2;
	//cout << *(it) << " ";
	
	vector <int> :: iterator iti = v5.end();
	//cout << *(iti-1) << " ";

	v4.push_back(43);
	//cout << v4.back() << endl;
	
//	for(vector<int> :: iterator it = v4.begin(); it != v4.end(); it++){
//		cout << *(it) << endl;
//	}
	
//	for(auto it = v4.begin(); it!=v4.end(); it++){
//		cout << *(it) << endl;
//	}

//	for(auto {it;} : v4){
//		cout << it << " " ;
//	}

	v4.erase(v4.begin()+1, v4.begin()+4);
	
//	for(vector<int> :: iterator it = v4.begin(); it != v4.end(); it++){
//		cout << *(it) << endl;
//	}
	
	vector<int> dec(2, 10);
	cout << dec[0] << " " << dec[1] << endl;
	
	dec.insert(dec.begin(), 5);
	cout << dec[0] << " " << dec.size() << endl ;
	
	dec.insert(dec.begin()+2, 2, 9);
	
	for(vector<int>::iterator it=dec.begin(); it!=dec.end(); it++){
		cout << *(it) << " ";
	}
	
	dec.pop_back();
	cout << endl << dec.size() << endl;
	
	vector<int> hec(2,100);
	
	dec.swap(hec);
	cout<< dec.size() << " " << hec.size() << endl;
	
	dec.clear();
	cout << dec.size() << endl;
	
	cout << dec.empty() << " " << true;
	
}

int main() {
	
	freopen("C:\\Users\\DINI\\Documents\\C++\\A2Z_Sheet\\input.txt", "r", stdin);
	freopen("C:\\Users\\DINI\\Documents\\C++\\A2Z_Sheet\\output.txt", "w", stdout);
	
	explainVector() ;
	
	


	
}
