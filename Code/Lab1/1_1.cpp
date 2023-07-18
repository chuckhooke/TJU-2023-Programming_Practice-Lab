#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;  //共n行
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;  //每一行的人数
		int *array = new int[num];
		for(int j = 0; j < num; j++) array[j] = 1;
		int cnt = 0;
		int count = 0;
		//当总人数<=3时结束循环
		while(num > 3){
			//2号出列
			for (int j = 0; j < num; j++) {
				if (array[j] == 1) {
					if (cnt == 0) {cnt++; count++;}
					else {
						cnt = 0;
						array[j] = 0;
					}
				}
			}
			if (count <= 3) break; //判断队中人数是否<=3
			count = 0;
			cnt = 0;

			//3号出列
			for (int j = 0; j < num; j++) {
				if (array[j] == 1) {
					if (cnt <= 1) {cnt++; count++;}
					else {
						cnt = 0;
						array[j] = 0;
					}
				}
			}
			if (count <= 3) break; //判断队中人数是否<=3
			count = 0;
			cnt = 0;
		}
		for (int j = 0; j < num; j++){
			if (array[j] == 1) cout << j+1 << " ";
			
		}
		cout << endl;
		delete array;
	}
}

