#include<bits/stdc++.h>
using namespace std;
const int NO_OF_STATES = 15;  
int n1,n;
                    
class states{
      public:
      char status;        
      int sno;  
      int gp;   
      int* ts;   
    
      states(){
           sno=gp=0;
           ts=NULL;}
      states(int state_no){
           gp=0;     
           sno=state_no;
           ts = new int[n];
           for(int i=0;i<n;i++)
              ts[i]=-1;} 

     void input(){
           char ch='a';
           cout<<"For state "<<sno<<"\n";
           for(int j=0;j<n;j++,ch++){
                cout<<"Enter output state for input "<<ch<<" : ";
                cin>>ts[j];}
           cout<<"Non-final or final state ? (N/F) : ";
           cin>>status;
           if(status=='n'||status=='N')
           gp=0;
           else
           gp=1;} 
};

void printtm(states dfatotm[]){
    cout<<"\tSTATE/INPUT \n\t";
	char a='a';
    cout<<"  ";
	for(int i=0;i<n;i++){
		cout<<"|\t"<<a++<<"\t";}
        cout<<"|\tB";
        cout<<endl;
    for(int i=0;i<n1;i++){char a='a';
           cout<<"\n\tq"<<i<<"|";
        for(int j=0;j<n+1;j++)
        if(dfatotm[i].ts[j]!=-1){
        if(j!=n){
       cout<<"\t(";
       cout<<dfatotm[i].ts[j]<<","<<a++<<",R";
       cout<<")\t|";}
      else if(j==n){
         if(dfatotm[i].status=='f'||dfatotm[i].status=='F'){
                   cout<<"\t(";
             cout<<"q"<<n1<<",B,R)";}}}}
                  cout<<"\n\tq"<<n1;
         for(int i=0;i<n+1;i++){
            cout<<"|\t-\t";}}

int main(){
    char ch='a';
        cout<<"Enter total number of states in DFA : ";
	    cin>>n1;      
        cout<<"Enter number of elements in alphabet : ";
        cin>>n;
      states dfatotm[NO_OF_STATES]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
      for(int i=0;i<n1;i++)
      dfatotm[i].input();
      printtm(dfatotm);}