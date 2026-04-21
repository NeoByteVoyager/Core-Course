#ifndef LIST_H
#define LIST_H
struct Term{
	int exp; //项的指数 
	int cof; //项的系数 
};
class List{
	static const int MAXN=200;
	Term data[MAXN+2];
	int len;
	public:
		List();
		bool insert(int cof,int exp);
		int getLen() const;
		Term getTerm(int index); //根据索引来获取项 
}; 
#endif
