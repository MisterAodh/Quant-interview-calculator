#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int fact(int x){
    if(x>10){
        return -1;
    }
   for(int i =x-1; i >0; i--) {
        x=x*i;
   }
    return x;
}
int greetings(vector<string> vec_op){
    int entry;
    cout<<"Hello and welcome to the SIG interview questions calculator. \nIn this project i will be creating some functions to solve probability and conditional probability questions.\nThis calculator will also use tree style refinement to asnwer secific questions that recur.\nIf unsure how to leave a loop try entering -999\n";
    for(int i = 0; i<vec_op.size(); i++){
        cout<<(i+1)<<" "<<vec_op[i]<<":"<<"\n";
        
    }
    cin>> entry;
    return entry;

}

int choose(int x, int y){
    int z = x-y;
    return fact(x)/(fact(y)*fact(z));
    
}

double bayes(){
double pa, pac, pb, pbga, pbgac, pagb, pbinta;
int comp;
cout<< "what information do we have \n1 for intersect\n2 for conditional\n3 if we are yet to find the probability of B\n";
    
cin >> comp;
    
if (comp == 1){
cout << "To find the probability of A|B then we will need p(B), and p(BintA): \n p(B): "; 
cin >> pb;
cout<<"p(BintA): ";
cin>> pbinta;

pagb = pbinta/pb;
    
return pagb; 
} 
    
if (comp == 2){
cout << "To find the probability of A|B then we will need p(A), p(B), and p(B|A): \n p(B): "; 
cin >> pa;
cout<<"p(B): ";
cin>> pb;
cout<<"p(B|A): ";
cin >> pbga;
pagb = (pbga*pa)/pb;  
return pagb; 
} 

if (comp == 3){
 cout << "To find the probability of A|B then we will need p(A), p(B), and p(B|A)\n first we need to calculate the pb: \n p(A): "; 
 cin >> pa;
 cout<< "p(B|A): ";
 cin>> pbga;
 cout<<"p(Ac): ";
 cin>> pac;
 cout<< "p(B|Ac):";
 cin>> pbgac;
 pb = pa*pbga + pac*pbgac;
 pagb = (pbga*pa)/pb;  
 return pagb; 
}
    
 return -1;   
}
void pattern(){
    //list of potential patterns
    int x,y,z;
    cout<< "These are the solvable pattern problems.\n(1) Number of outcomes from gridable/sum problem.\n(2) Number of adjacent posistions in a set.\n";
    cin >> x;
    if(x == 1){
        cout<<"what is X in the x by x grid: ";
        cin >> x;
        cout<<"which sum are you looking for?: ";
        cin >>y;
        z = abs((x+1)-y);
        double e = (x-z)/x*x;
        cout<< "The number of outcomes/sums at "<<y<<" is "<<x-z<< "\nThe probability of this outcome is "<<x-z<<"/"<<x*x<<" or "<<e;
        
    }

    if (x==2){
        cout<<"How many numbers in the set?: ";
        cin>>y;
        cout<<"How large a grouping to be adjacent: ";
        cin>>z;
        int total = (y+1)-z;
        cout<< "The total number of iterations of the set with "<<z<<" adjacent to one another is "<< total;
    }

    
    
}
double EV(){
    int count = 0;
    double ev;
    double misc;


        do{
        cout << " Enter your value: ";
        cin >> misc;
        if(misc!=-999){
        ev += misc;
        count++;}
    }while(misc != -999);

    return ev/count;
    }
double EV_w(){
    double ev;
    double weight;
    int count =0, total = 0;
    char num_weight;
    double misc;
    cout<<"do you want to do number weighting Y||or||any: ";
    cin>> num_weight;
    if(num_weight == 'Y'){
        do{

            cout << "Enter your "<<count+1<<" value: ";
            cin >> misc;
            if(misc!=-999)  {  cout << "Enter your "<<count+1<<" number: ";
            cin >> weight;
            ev += misc*weight;
            total+=weight;
            count++;}
        }while(misc!=-999);
        return ev/total;   
        
    }
    do{

        cout << "Enter your "<<count+1<<" value: ";
        cin >> misc;
        if(misc!=-999)  {  cout << "Enter your "<<count+1<<" weight: ";
        cin >> weight;
        ev += misc*weight;}

        count++;
    }while(misc!=-999);
    return ev;
}
void couponsCollector(){
  double x;
  cout<<"What is the sample size?: ";  
  cin>>x;
  double total = 0;
  for(int i=1; i<=x; i++){
      total+=x/i;
  }
  cout<<"The number of trials is "<<total;
}

int main() {
  vector <string> options = {"Bayes_theorem","patters", "EV", "nCr", "Coupons collector"};
  int x = greetings(options);

    if (x == 1){
        double Pagb = bayes();
        cout << "The conditional probability of A given B is "<<Pagb; 
    }
    if (x == 2){
        pattern();
    
    }
    if (x == 3){//EV calculation
        char weighted = 'o';

        cout << "\n"<<"Are the EV's weighted? Y||or||N \n";
        cin >> weighted;
        if(weighted == 'Y'){
            double ev = EV_w();
            cout << "Your ev is: "<<ev;
            
        }else if(weighted == 'N'){
            double ev = EV();   
            cout << "Your ev is: "<<ev;
        }
      
    }
    if (x == 4){
     int x, y;
     cout<<"What size is the set: ";
        cin>>x;
     cout<<"How many would you like to choose: ";
        cin>>y;
        int z = choose(x, y);
    cout<<"There are "<<z<<" permutations";
    }
    if (x == 5){
        couponsCollector();
    }

    
}