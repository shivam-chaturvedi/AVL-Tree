#include<iostream>

using namespace std;

class AVLTree{
    private:

    // first make node structure
    struct Node{
        int key,height;
        Node *left,*right;
        Node(int key):key(key),left(nullptr),right(nullptr),height(1){}// initially height of node when created will be one
    };

    Node * root=nullptr; //main tree root node

    int height(Node *node){
        // this method will calculate height of a node
        if(!node){
            // if node is null so height is 0
            return 0;
        }
        int leftSubtreeHeight=0;
        int rightSubtreeHeight=0;

        if(node->left){
            leftSubtreeHeight=node->left->height;
        }
        if(node->right){
            rightSubtreeHeight=node->right->height;
        }
        
        // we dont need to check for node->left null or not because of the base condition !node
        return (1 + std::max(leftSubtreeHeight,rightSubtreeHeight));
    }

    int getBalanceFactor(Node *node){
        if(!node){
            return 0; //tree is null so balanced
        }
        int leftSubtreeHeight=0;
        int rightSubtreeHeight=0;

        if(node->left){
            leftSubtreeHeight=node->left->height;
        }
        if(node->right){
            rightSubtreeHeight=node->right->height;
        }

        // now after calculating height of nodes we  know that balance factor is leftsubtreeheight-rightsubtreeheight
        return leftSubtreeHeight-rightSubtreeHeight;
        
    }

    Node *leftRotate(Node *root){
        if(!root){
            return root;
        }
        // here root is local var so it is not the tree main root 
        Node *y=root->right;//because tree needs left rotate so it must be right skewed so we need to take y as root ->right child
        // now store the left child of root->right to root->right
        root->right=y->left; //so left subtree of root now right subtree of root (local var )
        // now just simply rotate and update heights
        y->left=root; 
        y->height=height(y);
        root->height=height(root); //local var root
        
        return y; //y will be the new root now

    }

    
    Node *rightRotate(Node *root){
        if(!root){
            return root;
        }
        // here root is local var so it is not the tree main root 
        Node *y=root->left;//because tree needs right rotate so it must be left skewed so we need to take y as root ->left child
        // now store the left child of root->right to root->right
        root->left=y->right; //so right subtree of root now left subtree of root (local var )
        // now just simply rotate and update heights
        y->right=root; 
        y->height=height(y);
        root->height=height(root); //local var root
        
        return y; //y will be the new root now

    }

    Node *balance(Node *root){
        // this method suppose to take a tree root and return new balanced root
        // we need to check balance factor of the root first 
        int rootBalanceFactor=getBalanceFactor(root);
        if(rootBalanceFactor>1){
            // tree is left skewed
            int childBalanceFactor=getBalanceFactor(root->left);
            if(childBalanceFactor>0){
                // child is also left so this is left left skewed
                // so need to perform rotations first make these methods
                // now if tree is left left skewed 
                return rightRotate(root); //we just need to rigt rotate root
            }
            else if(childBalanceFactor<0){
                // left right case
                // so first correct the root->left child right subtree 
                root->left=leftRotate(root->left);
                // now tree is left left skewed
                return rightRotate(root);
            }
        }
        else if(rootBalanceFactor<-1){
            // if tree is right skewed
            int childBalanceFactor=getBalanceFactor(root->right);
            if(childBalanceFactor<0){
                // right right case
                // so simply leftrotate root
                return leftRotate(root); //return new root after rotation

            }
            else if(childBalanceFactor>0){
                // right left case
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
        }
        // if tree is already balaned so simply return root
        return root;
    }

    Node *insert(Node *root,int key){
        // This method will take a tree (root pointer) and then insert the key in the tree and then return new root
        if(!root){
            // if root is null so just return new Node()
            return new Node(key);
        }
        else if(key<root->key){
            // key belongs to left side
            root->left=insert(root->left,key);
            // recursively insert the key in left subtree and then store the new subtree in root->left

        }
        else if(key>root->key){
            root->right=insert(root->right,key);
        }
        // after that now we need to update height and balance the tree also
        root->height=height(root);

        // now we need to balance it so lets make a balance method
        // now simply return the balanced root
        return balance(root);
    }

    // lets make a height and inorder method also to visualize
    void inorder(Node *root){
        if(!root){
            return;
        }//base case
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }

    Node * min(Node * root){
        // we know that left part contain always lower value than parent
        if(!root){
            return nullptr;
        }

        while(root->left){
            root=root->left;
        }
        return root;
    }

    // this method should return new tree after removing the key 
    Node * remove(Node *root,int key){
        if(!root){
            // if root is nullptr
            return root;
        }
        else if(key<root->key){
            // key maybe present in left part
            root->left=remove(root->left,key);
        }
        else if(key>root->key){
            // hmm it make sense as we need to updade each parent child 
            root->right=remove(root->right,key);
        }
        else{
            // we found key
            // there are three cases the node to be removed has no child
            if(!root->right && !root->left){
                // if the root has no child 
                delete root; //dont confuse with the member variable root because this is the local variable root 
                return nullptr;
            }
            else if(!root->left){
                // node to be deleted has right child only
                Node *temp=root->right; //right child address now in temp
                delete root;
                return temp; //we just simply return right child after deleting the node
            }
            else if(!root->right){
                Node * temp=root->left;
                delete root;
                return temp;
            }
            else{
                // if node has both left and right child
                // so we need to find inorder successor or inorder predecessor
                // so first make max or min method 
                // first find minChild

                Node *minChild=min(root->right); //inorder successor
                root->key=minChild->key; //root value removed
                // now recursively remove minChild
                root->right=remove(root->right,minChild->key); //we must chnage the right subtree after removing value from it
            }
        }
        return balance(root); //balance the root and return
    }

    Node * search(Node *root,int key){
        if(!root || key==root->key){
            return root;
        }
        else if(key<root->key){
            return search(root->left,key);            
        }
        else if(key>root->key){
            return search(root->right,key);
        }
        return root;
    }

    // now make a height method 
    public:
    int height(){
        return root->height;
    }
    // also make a insert pulic method that is callable from outside the class
    void insert(int key){
        root=insert(root,key);
    }
    void inorder(){
        inorder(root);
    }

    int min(){
        Node * minChild=min(root);
        return minChild?minChild->key:-1;
    }

    void remove(int key){
        root=remove(root,key); //as it will return new tree (root)
    }

    bool search(int key){
        Node *node=search(root,key);
        return node?true:false;
    }

};

int main(){
    AVLTree tree;
    // lets insert 1000 values
    for(int i=0;i<1000000;i++){
        tree.insert(i);
    }
    //super fast searching 
    cout<<tree.search(347867826);
    // so this tree is beast for large data searching an insertion and thats why it mostly used in Machine learning and big data
    // thanks
    // so the bst height in this case will be 10000 beacuse it will like a linked list 
    // but in avl it should be log base 2 n
    cout<<"AVLTree after insert 1000000 node height is :"<<tree.height()<<endl;
    return 0;
}