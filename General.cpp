class Something : public Bigthing {
	const Otherthing ot;
public:
	Something() {
	}
	Something(int n):Bigthing(n), ot(n){
	}
	~Something(){
	}
	virtual void show() const {
	}
	virtual void show() {
	}
};
int main() {
	Something st(123);
	st.show();
	return 0;
}
