#include  <iostream>
using  namespace  std;
//整型向量类 
class  intMyVector{
public:
    //构造函数 
    intMyVector(int  count){
        n=count;  
        p=new  int[count];
    } 
    //复制构造函数      
    intMyVector(intMyVector  &v){    
       n=v.n; 
         p=new int[v.n];
         for(int i=0;i<n;i++)
           p[i]=(v.p)[i];
    }        
       
  friend intMyVector& operator+(intMyVector &v1,intMyVector &v2);
  intMyVector& operator=(intMyVector &v);
  friend ostream& operator << (ostream&,intMyVector&);
 
friend istream& operator>> (istream&,intMyVector&);

  ~intMyVector(){delete[]  p;    }
private:
    int  n;
    int  *p;        
}; 
intMyVector mVector(3); 

int  main()
{
    int  n;
    cin>>n;
    intMyVector a(n),c(n);
    cin>>a;
    cin>>c;
    intMyVector b(a);
    c=a+b+c; 
    cout<<c;
    return  0;
}

intMyVector& operator+(intMyVector &v1,intMyVector &v2)
{
    //补充代码
    
int n=v1.n+v2.n;
intMyVector v(n);
for(int i=0;i<n;i++){
v.p[i]=v1.p[i]+v2.p[i];
}
return v;

    //
}

intMyVector&  intMyVector::operator=(intMyVector  &v){
    //补充代码
        
n=v.n;
p=new int[n];
for(int i=0;i<n;i++)p[i]=v.p[i];
return *this;

    // 
}
//补充代码
ostream&  operator  <<  (ostream&  output,intMyVector&  v)
{output<<"[";
  for(int  i=0;i<(v.n-1);i++)
    output<<v.p[i]<<",";
    output<<v.p[v.n-1]<<"]"<<endl;
  return  output;
}

istream &operator>>(istream *is,intMyVector&v){
for(int i=0;i<v.n;i++)is>>v.p[i];
return is;
}

//

