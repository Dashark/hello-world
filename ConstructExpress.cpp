#include <iostream>
using namespace std;

class queue_up{
	public:
		queue_up(int n) {
			this->n = n;
			for(int i = 0; i < n; i++) {
				stu[i].order = i;
			}
		}
		~queue_up() {}
		
		void adjust(int p, int q) { //学号为p的同学向后移动q
			int flag1, flag2, flag;
			if(q == 0) return;
			else {
				if(q < 0) {
					flag1 = stu[p-1].order+q;
					flag2 = stu[p-1].order;
					flag = -1;
				}
				else {
					flag1 = stu[p-1].order;
					flag2 = stu[p-1].order+q;
					flag = 1;
				}
				for(int i = 0; i < n; i++) {
					if(stu[i].order == stu[p-1].order || stu[i].order < flag1 || stu[i].order > flag2) continue;
					else stu[i].order -= flag;
				}
			}
			stu[p-1].order += q;
//			for(int i = 0; i < n; i++) {
//				cout << "stu" << i+1 << " " << stu[i].order << endl;
//			}
//			cout << "*" << endl;
		}
		void final() {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(stu[j].order == i) {
						cout << j+1 << " ";
						break;
					}
				}
			}
			cout << endl;
		}

	private:
		struct student{
			int order; 
		}stu[1000];
		int n;
};

int main() {
	int n, m; //n学生的数量; m调整的次数
	cin >> n >> m;
	queue_up stuqueue(n);
	while(m--) {
		int p, q; //学号为p的同学向后移动q
		cin >> p >> q;
		stuqueue.adjust(p, q);
	}
	stuqueue.final();
	return 0;
}
