#include <iostream>

struct node_t
{
    int val=0;
    node_t *lhs = nullptr;
    node_t *rhs = nullptr;

    static node_t *create(int val_ )
    {
        node_t *tmp = new node_t;
        tmp->val = val_;
        return tmp;
    }
};

class Tree
{
public:
    node_t *&root()
    {
        return m_root;
    }

    void insert( int val, node_t *&node )
    {
        if( node == nullptr )
        {
            node = node_t::create(val);
            return;
        }

        else if( val < node->val )
        {
            insert(val, node->lhs);
        }
        else
        {
            insert(val, node->rhs);
        }
    }
    bool find( int val, node_t *&node )
    {
        if( node == nullptr )
        {
            return false;
        }
        else if( val == node->val )
        {
            return true;
        }
        else if( val <= node->val )
        {
            return find( val, node->lhs );
        }
        else
        {
            return find( val, node->rhs );
        }
    }
    node_t *remove( int val, node_t *&node )
    {
        if( node == nullptr)
        {
            return node;
        }
        else if( val < node->val )
        {
            node->lhs = remove(val, node->lhs );
        }
        else if ( val > node->val )
        {
            node->rhs = remove(val, node->rhs );
        }
        else
        {
            if( !node->lhs )
            {
                node_t *tmp = node->rhs;
                delete node;
                return tmp;
            }
            else if( !node->rhs )
            {
                node_t *tmp = node->lhs;
                delete node;
                return tmp;
            }
            else
            {
                node->val = node->rhs->val;
                node->rhs = nullptr;
                return node;
            }

        }

        return node;
    }
    size_t min_depth(const node_t *node)
    {
        if( nullptr == node ) return 0;

        if( !node->lhs && !node->rhs)
        {
            return 1;
        }
        else if( !node->lhs )
        {
            return min_depth( node->rhs ) + 1;
        }
        else if( !node->rhs )
        {
            return min_depth( node->lhs ) + 1;
        }

        size_t lhs = min_depth(node->lhs);
        size_t rhs = min_depth(node->rhs);

        return (lhs < rhs) ? lhs + 1 : rhs + 1;
    }
    size_t max_depth(const node_t *node)
    {
        if( nullptr == node ) return 0;

 //       std::cout << node->val << std::endl;

        size_t lhs = max_depth(node->lhs);
        size_t rhs = max_depth(node->rhs);

        return (lhs > rhs) ? lhs + 1 : rhs + 1;
    }
    size_t minValue(const node_t *node)
    {
        if( nullptr == node ) return 0;

        const node_t *current = node;

        while( current->lhs != nullptr )
        {
            current = current->lhs;
        }

        return current->val;
    }
    size_t maxValue(const node_t *node)
    {
        if( nullptr == node ) return 0;

        const node_t *current = node;

        while( current->rhs != nullptr )
        {
            current = current->rhs;
        }

        return current->val;
    }
    size_t size(const node_t *node)
    {
        if( node == nullptr ) return 0;

        return size(node->lhs) + 1 + size(node->rhs);
    }
    void inorder(const node_t *node)
    {
        if( node == nullptr ) return;
        inorder(node->lhs);
        std::cout << node->val << std::endl;
        inorder(node->rhs);
    }
    void preorder(const node_t *node)
    {
        if( node == nullptr ) return;
        std::cout << node->val << std::endl;
        preorder(node->lhs);
        preorder(node->rhs);
    }
    void postorder(const node_t *node)
    {
        if( node == nullptr ) return;
        postorder(node->lhs);
        postorder(node->rhs);
        std::cout << node->val << std::endl;
    }
private:
    node_t *m_root= nullptr;
};


void status(Tree &tree, node_t *root)
{
    std::cout << "size=" << tree.size(root) << std::endl;
    std::cout << "min=" << tree.minValue(root) << std::endl;
    std::cout << "max=" << tree.maxValue(root) << std::endl;
    std::cout << "min_depth=" << tree.min_depth(root) << std::endl;
    std::cout << "max_depth=" << tree.max_depth(root) << std::endl;
}

int main()
{
    int vector[] = {4,2,5,1,3};

//    int vector[] = {4,5,1,3};

    Tree tree;

    node_t *&root = tree.root();

    for( auto val : vector )
    {
        tree.insert(val,root);
    }

    for( auto val : vector )
    {
        std::cout << "val=" << val << " find=" << tree.find(val,root) << std::endl;
    }

    //tree.inorder(root);
    //tree.preorder(root);
    //tree.postorder(root);

    std::cout << "remove=" << tree.remove(2,root) << std::endl;
    //std::cout << "remove=" << tree.remove(3,root) << std::endl;


    status(tree,root);
    tree.inorder(root);
   // for( auto val : vector )
    //{
    //    tree.remove(val,root);
   // }

    //status(tree,root);
}
