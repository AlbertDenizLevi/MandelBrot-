#ifndef complex_h
#define complex_h

struct c
{
	double i;
	double r;
};

class complex
{
public:
	complex();
	complex(double i,double r);
	~complex();

	//accessors
	double geti() const;
	double getr() const;
	//mutators
	void seti(double);
	void setr(double);

	complex operator + (complex);
	//c operator + (double);
	complex operator - (complex);
	//c operator - (double);
	complex operator * (complex);
	//c operator * (double);
	complex operator / (complex);
	//c operator / (double);
	//c operator ^ (int);//being eble to get its square is enough so I will just use *
	//friend c complex::operator + (double lhs,c rhs);
	//friend c complex::operator - (double lhs,c rhs);
	//friend c complex::operator * (double lhs,c rhs);
	//friend c complex::operator / (double lhs,c rhs);
private:
	c num;
};


#endif // !complex_h
