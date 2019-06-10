class Something : public Bigthing {
	const Otherthing ot;
	static int x;
	Something() {
	}
	Something(int n):Bigthing(n), ot(n){
	}
public:
	~Something(){
	}
	virtual void show() const {
	}
	virtual void show() {
	}
	static Something* create(int n) {
		return new Something(n);
	}
};
int main() {
	Something *st = Something::create(123), *st1 = st->create(321);
	st->show();
	st1->show();
	return 0;
}
