#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

class matr 
{
    private:
        double *array_;
        int n_;
        int m_;
        
    public:
    matr(int n, int m);
    ~matr();
	matr& operator =(const matr &other);
	int get_length () const;
	int get_height () const;
	double get_element (int i, int j) const;
	void change_element (int i, int j, double k);
	void set_element (double C, int i, int j);
	friend matr& operator+(const matr &left, const matr &right);
    friend std::ostream& operator<<(std::ostream &os, const matr& Q);
};

class podmatr 
{
	private:
		int n1;
		int m1;
		int i;
		int j;
		matr *pod;
		
	public:
		podmatr(&matr, i, j, n, m);
		~podmatr();
		double get_element(int n, int m)
};

class Exception 
{
	private:
		int code_;
		std::string message_;
	public:
		Exception(int code, std::string message): code_(code), message_(message){}
		std::string message() const {return message_;}
		int code() const {return code_;}
}

