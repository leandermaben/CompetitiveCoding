#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left=nullptr;
        Node* right=nullptr;
};
Node* insert(Node* root,int data){
    if(!root){
        Node* temp=new Node();
        temp->data=data;
        return temp; 
    }
    if(data<=root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
Node* lca(Node* root,int mn,int mx){
    if(root->data<=mx&&root->data>=mn)
        return root;
    else if(root->data>mx)
        return lca(root->left,mn,mx);
    else
        return lca(root->right,mn,mx);
}
int max_in_path(Node* root,int mx){
    if(root->data>=mx)
        return root->data;
    else
        return max_in_path(root->right,mx);
}
int main(){
    Node* root=nullptr;
    int i,n,temp,x,y,mn,mx;
    int height=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>temp;
        root=insert(root,temp);
    }
    cin>>x>>y;
    mn=x<y?x:y;
    mx=x>y?x:y;
    cout<<max_in_path(lca(root,mn,mx),mx);
    
}