#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
class Clock {
	public:
		Clock() {
			this->hour = 0;
			this->minute = 0;
			this->second = 0;
		}
		~Clock() {}
		
		void tick() {
			while(1) {
				Sleep(1000);
				second = (second+1) % 60;
				if(!second) {
					minute = (minute+1) % 60;
					if(!minute) {
						hour = (hour+1) % 24;
					}
				}
				show();
			}
		}
		void show() {
			system("cls");
			int curh = hour; int curm = minute; int curs = second;
			cout << setw(2) << setfill('0') << curh << ": ";  
			cout << setw(2) << setfill('0') << curm << ": ";  
		    cout << setw(2) << setfill('0') << curs << endl; 
		}
		bool islegal(int h, int m, int s) {
			if(h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
				return true;
			}
			else return false;
		} 
		void adjust(int h, int m, int s) {
			if(islegal(h, m, s) == false) {
				cout << "Your setting is illegal." << endl;
			}
			else {
				second = s;
				minute = m;
				hour = h;
			}
		}
	
	private:
		int hour; int minute; int second;
};

int main() {
	Clock ck;
	ck.tick();
	ck.show();
	ck.adjust(16,45,00); //判断输入是否合法 
	ck.show();
	return 0;
}
