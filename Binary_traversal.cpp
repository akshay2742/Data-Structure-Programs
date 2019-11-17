#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Node
{
    public:
        int data;
        Node* left_h;
        Node* right_h;
        Node()
        {
            left_h=NULL;
            right_h=NULL;
        }
};
class Binary_search
{
    public:
        Node* root;
        Binary_search()
        {
            root=NULL;
        }

        void add_node(int d)
        {
            Node* new_node= new Node;
            Node* temp;
            temp=root;
            new_node->data=d;
            if(root==NULL)
            {
                root=new_node;
            }
            else
            {
                
                while (temp->left_h!=NULL && temp->right_h!=NULL)
                {
                    if (new_node->data < temp->data)
                    {
                        temp=temp->left_h;
                    }
                    else
                    {
                        temp=temp->right_h;
                    }
                }
                while (temp->left_h!=NULL)
                {
                    if (new_node->data < temp->data)
                    {
                        temp=temp->left_h;
                    }
                    else 
                    {
                        if(temp->right_h!=NULL)
                        {
                            temp=temp->right_h;
                        }
                        else
                            break;
                    }
                   
                }
                while (temp->right_h!=NULL)
                {
                    if (new_node->data > temp->data)
                    {
                        temp=temp->right_h;
                    }
                    else
                    {
                        if(temp->left_h!=NULL)
                        {
                            temp=temp->left_h;
                        }
                        else
                            break;
                    }
                    
                    
                    
                }
                
                if(new_node->data<temp->data)
                {
                    temp->left_h=new_node;
                }
                else
                {
                    temp->right_h=new_node;
                    
                }
                
                
            }
        }
        int tree_height()
        {
            if(root==NULL)
            {
                return 0;
            }
            queue<Node *> q;

            q.push(root);
            int height=0;
            while (1)
            {
                int nodeCount=q.size();
                if(nodeCount==0)
                    return height;

                height++;

                while (nodeCount>0)
                {
                    Node *node=q.front();
                    q.pop();
                    if (node->left_h!=NULL)
                    {
                        q.push(node->left_h);
                    }
                    if (node->right_h!=NULL)
                    {
                        q.push(node->right_h);
                    }
                    nodeCount--;
                    
                }
                
            }
            
        }
        void level_traversal()
        {
            if(root==NULL)
            {
                return;
            }
            queue<Node *> q;

            q.push(root);
            
            while (!q.empty())
            {
                
                Node *node=q.front();
                    
                cout<<node->data<<" ";
                q.pop();
                if (node->left_h!=NULL)
                {
                    q.push(node->left_h);
                }
                if (node->right_h!=NULL)
                {
                    q.push(node->right_h);
                }
            }
            
        }

       void inorder(Node* root)
        {
            if (root==NULL)
            {
                return;
            }

            inorder(root->left_h);
            cout<<root->data<<" ";
            inorder(root->right_h);
        }

        void preorder(Node* root)
        {
            if (root==NULL)
            {
                return;
            }

            
            cout<<root->data<<" ";
            inorder(root->left_h);
            inorder(root->right_h);
        }

        void postorder(Node* root)
        {
            if (root==NULL)
            {
                return;
            }

            inorder(root->left_h);
            
            inorder(root->right_h);
            cout<<root->data<<" ";
        }

        bool search(int n)
        {
            Node* temp=root;
            if (root==NULL)
            {
                return false;
            }
            while (temp!=NULL)
            {
                if (n< temp->data)
                {
                    temp=temp->left_h;
                }
                else if (n> temp->data)
                {
                    temp=temp->right_h;

                }
                else
                {
                    return true;
                }

                
            }   
            return false;
        }

        int leaf_nodes()
        {
            int cnt=0;
            stack <Node* > s;
            s.push(root);
            if (root==NULL)
            {
                return 0;
            }
            else
            {
                while (!s.empty())
                {
                    Node* temp=s.top();
                    s.pop();

                    if (temp->left_h!=NULL)
                    {
                        s.push(temp->left_h);
                    }
                    if (temp->right_h!=NULL)
                    {
                        s.push(temp->right_h);
                    }
                    if (temp->left_h==NULL && temp->right_h==NULL)
                    {
                        cnt++;
                    }
                }
                return cnt;
            }
            
            
        }

        int non_leaf_node()
        {
            stack <Node* > s;
            s.push(root);
            int cnt=0;
            if (root==NULL)
            {
                return 0;
            }
            else
            {
                while (!s.empty())
                {
                    Node* temp=s.top();
                    s.pop();
                    if (temp->left_h!=NULL)
                    {
                        s.push(temp->left_h);
                        cnt++;
                    }
                    else if (temp->right_h!=NULL)
                    {
                        s.push(temp->right_h);
                        cnt++;
                    }
                    else if (temp->left_h!=NULL && temp->right_h!=NULL)
                    {
                        cnt++;
                    }
                    else
                    {
                        
                    }
                    
                    if (temp->left_h!=NULL)
                    {
                        s.push(temp->left_h);
                        
                    }
                    if (temp->right_h!=NULL)
                    {
                        s.push(temp->right_h);
                        
                    }
                }
                return cnt;   
            }
            
            
        }

        Node* minimum(Node *r)
        {
            Node* temp=r;
            while (temp && temp->left_h!=NULL)
            {
                temp=temp->left_h;
            }
            return temp;
            
        }

        Node* delete_copying(Node* r,int d)
        {
            if (r==NULL)
            {
                return root;
            }
            if (d < r->data)
            {
                r->left_h=delete_copying(r->left_h,d);
            }
            else if (d > r->data)
            {
                r->right_h=delete_copying(r->right_h,d);
            }
            else
            {
                if (r->left_h==NULL)
                {
                    Node* p=r->right_h;
                    delete r;
                    return p;
                }
                else if (r->right_h==NULL)
                {
                    Node* q=r->left_h;
                    delete r;
                    return q;
                }
                Node* s=minimum(r->right_h);
                r->data=s->data;
                r->right_h=delete_copying(r->right_h,s->data);

            
                
                
            } 
            return r;
        }

        void mirror_image(Node* root)
        {
            if (root==NULL && root->left_h==NULL && root->right_h==NULL)
            {
                return;
            }
            Node* temp=root;
            stack <Node*> st;
            st.push(root);
            while (!st.empty())
            {
                temp=st.top();
                st.pop();
                Node* swap=temp->right_h;
                temp->right_h=temp->left_h;
                temp->left_h=swap;
                if (temp->left_h!=NULL)
                {
                    st.push(temp->left_h);
                }
                if (temp->right_h!=NULL)
                {
                    st.push(temp->right_h);
                }
            }
            
            
        }

       

        
};


int main()
{
    Node* root=NULL;
    Binary_search list;
    
    list.add_node(34);
    list.add_node(62);
    list.add_node(7);
    list.add_node(55);
    list.add_node(63);
    list.add_node(31);
    list.add_node(6);
    list.add_node(33);
    list.add_node(25);
    list.add_node(47);
    cout<<"Height of the tree is: "<<list.tree_height();
    cout<<"\nInorder: ";
    list.inorder(list.root);
    cout<<"\nPreorder: ";
    list.preorder(list.root);
    cout<<"\nPostorder: ";
    list.postorder(list.root);
    cout<<"\nLevel Traveral: ";
    list.level_traversal();

    if(list.search(25))
    {
        cout<<"\nElement is found";
    }
    else
    {
        cout<<"\nElement is not Found";
    }
    cout<<"\nNo of leaf Nodes are: "<<list.leaf_nodes();
    cout<<"\nNo of Non-leaf Nodes are: "<<list.non_leaf_node();

    list.delete_copying(list.root,34);
    cout<<"\nInorder: ";
    list.inorder(list.root);
    list.mirror_image(list.root);
    cout<<"\nInorder: ";
    list.inorder(list.root);

    
    
   
}