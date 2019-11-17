#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Node{
    public:
        int info;
        Node *left;
        Node *right;

        Node(int info){
          this->info=info;
          left=right=NULL;
        }

};
class BST{
    Node *root;
  public:
      BST(){
        root=NULL;
      }

      Node* insert(int data,Node *root){

         Node *a=root;
         Node* x=NULL;
         while(a!=NULL ){
                x=a;
            if(data > a->info){
                    a=a->right;

            }
            else{
                a=a->left;
            }

         }
         if(x==NULL){
            x=new Node(data);
         }
         else if(data > x->info){
            x->right=new Node(data);

         }
         else{
            x->left=new Node(data);
         }

      }

      int heightoftree(Node *root){
         if(root==NULL){
            return 0;
         }

            stack<Node *>s;
            s.push(root);
             int height=0;
            while(1){

                int cnt=s.size();

                if(cnt==0){
                    return height;
                }
                height++;

                while(cnt>0){
                    Node* a=s.top();
                    s.pop();
                    if(a->left!=NULL){
                        s.push(a->left);
                    }
                    if(a->right!=NULL){
                        s.push(a->right);
                    }
                    cnt--;
                }
            }
         }
         Node* minimum(Node *root){
             Node *curr=root;
            while(curr && curr->left!=NULL){
                curr=curr->left;
            }
            return curr;
         }


         Node* delete_copying(Node *root,int data){
             if(root==NULL){
                return root;
             }
             if(data > root->info){
                root->right=delete_copying(root->right,data);
             }
             else if(data < root->info){
                root->left=delete_copying(root->left,data);
             }
             else{
                if(root->left==NULL){
                    Node *temp=root->right;
                    delete root;
                    return temp;
                }
                else if(root->right==NULL){
                    Node *temp=root->left;
                    delete root;
                    return temp;
                }

                    Node *temp=minimum(root->right);
                    root->info=temp->info;
                    root->right=delete_copying(root->right,temp->info);

             }
             return root;
         }
void deleteByMerging(Node *root,int data) {
    Node* tmp, *node, *p = root, *prev = NULL;
    while (p != NULL && p->info!=data) {
         prev = p;
         if (data<p->info)
              p = p->right;
         else p = p->left;
    }
    node = p;
    if (p != NULL && p->info==data) {
         if (node->right == NULL)
              node = node->left;
         else if (node->left == NULL)
              node = node->right;
         else {
              tmp = node->left;
              while (tmp->right != NULL)
                  tmp = tmp->right;
              tmp->right =
                  node->right;

              node = node->left;
         }
         if (p == root)
              root = node;
         else if (prev->left == p)
              prev->left = node;
         else prev->right = node; // 5.
    }
    else if (root != NULL)
         cout<<"\nData "<<data<<" is not in the tree";
    else cout<<"\nthe tree is empty";
}


    void leveltraversal(Node *root){
         if(root==NULL){
            cout<<"\nThere is no node in the tree";
         }

            queue<Node *>q;
            q.push(root);
            while(!q.empty()){
                Node *temp=q.front();
                cout<<temp->info<<" ";
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }

            }

     }


    int leafnode(Node *root){
           if(root==NULL){
              return 0;
           }

           int cnt=0;
           stack<Node *>s;
           s.push(root);
        while(!s.empty()){

           Node *temp=s.top();
           s.pop();
           if(temp->left!=NULL){
            s.push(temp->left);
           }
           if(temp->right!=NULL){
            s.push(temp->right);
           }
           if(temp->left==NULL && temp->right==NULL){
            cnt++;
           }

        }
           return cnt;

    }

    int non_leafnode(Node *root){
           if(root==NULL){
              return 0;
           }

           int cnt=0;
           stack<Node *>s;
           s.push(root);
        while(!s.empty()){

           Node *temp=s.top();
           s.pop();
           if(temp->left!=NULL){
            cnt++;
           }
           else if(temp->right!=NULL){
            cnt++;
           }
           else if(temp->left!=NULL && temp->right!=NULL){
            cnt++;
           }
           else{

           }
           if(temp->left!=NULL){
            s.push(temp->left);
           }
           if(temp->right!=NULL){
            s.push(temp->right);
           }


        }
           return cnt;

    }

    bool searchi(Node *root, int data){
      if(root==NULL){
        return false;
      }
      while(root!=NULL){
        if(data>root->info){
            root=root->right;
        }
        else if(data<root->info){
            root=root->left;
        }
        else{
            return true;
            }
      }
      return false;

    }



Node* mirrorimage(Node *root){
   if(root==NULL || (root->left==NULL)&&(root->right==NULL)){
    return root;
   }
   Node *parent=root;
   stack<Node *>s;
   s.push(root);
   while(!s.empty()){
    parent=s.top();
    s.pop();
    Node *temp=parent->right;
    parent->right=parent->left;
    parent->left=temp;
    if(parent->left!=NULL){
        s.push(parent->left);
    }
    if(parent->right!=NULL){
        s.push(parent->right);
    }

   }
   return root;



}



      void inorder(Node *root){
         if(root==NULL){
            return;
         }
         else{
            inorder(root->left);
            cout<<root->info<<" ";
            inorder(root->right);
         }

      }
       void preorder(Node *root){
         if(root==NULL){
            return;
         }
         else{

            cout<<root->info<<" ";
            inorder(root->left);
            inorder(root->right);
         }

      }
       void postorder(Node *root){
         if(root==NULL){
            return;
         }
         else{
            inorder(root->left);

            inorder(root->right);
            cout<<root->info<<" ";
         }

      }

};
int main()
{
    BST b;
    Node *root=NULL;

   root=b.insert(5,root);


    b.insert(3,root);
    b.insert(2,root);

    b.insert(4,root);
    b.insert(7,root);
     b.insert(6,root);
     b.insert(9,root);



if (b.searchi(root, 2))
        cout << "Yes";
    else
        cout << "No";


cout<<"\nLevel by level traversal: ";
 b.leveltraversal(root);
 cout<<"\n";
  b.deleteByMerging(root,3);

cout<<"\n";
  b.delete_copying(root,5);
    b.inorder(root);

 cout<<"\n Inorder traversal: ";
   b.inorder(root);
 int c= b.heightoftree(root);
   cout<<"\n Height: "<<c;
   b.mirrorimage(root);
   cout<<"\nMirror image: ";
    b.inorder(root);
    cout<<"\n";


    int a=b.leafnode(root);
    cout<<"\nLeaf nodes are: "<<a;

     int d=b.non_leafnode(root);
    cout<<"\nNon-Leaf nodes are: "<<d;

    b.deleteByMerging(root,5);
    b.inorder(root);

}
