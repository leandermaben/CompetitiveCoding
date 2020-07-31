#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        int height;
        Node* left=nullptr;
        Node* right=nullptr;
        /*~node(){
        	cout<<"destroyed"<<endl;
        }*/
};
void temp(){

}
int main(){
	Node a,b;
	a.data=5;
	b=a;
	cout<<b.data<<endl;
	b.data=7;
	cout<<a.data<<endl;
	cout<<b.data<<endl;

}