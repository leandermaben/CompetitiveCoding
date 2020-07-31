#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        int height;
        Node* left=nullptr;
        Node* right=nullptr;
};
Node* insert(Node* root,int data,int height,int* m){
    if(!root){
        Node* temp=new Node();
        temp->data=data;
        temp->height=height+1;
        *m=(*m)>temp->height?(*m):temp->height;
        return temp; 
    }
    if(data<=root->data){
        root->left=insert(root->left,data,root->height,m);
    }else if(data>root->data){
        root->right=insert(root->right,data,root->height,m);
    }
    return root;
}
int main(){
    Node* root=nullptr;
    int i,n,temp;
    int height=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>temp;
        root=insert(root,temp,0,&height);
    }
    cout<<height;
    
}