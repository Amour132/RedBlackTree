#include <iostream>

#define Black 1
#define Red 0


class BstTree 
{
private:
  struct BstNode
  {

    BstNode():_data(0),_color(Red),_left(NULL),_right(NULL),_parent(NULL)
    {}

    BstNode* GrandParent()
    {
      if(_parent == NULL)
        return NULL;

      return _parent->_parent;
    }

    BstNode* Uncle()
    {
      if(GrandParent() == NULL)
        return NULL;

      if(_parent == GrandParent()->_left)
        return GrandParent()->_right;
      else
        return GrandParent()->_left;
    }

    BstNode* Brother()
    {
      if(_parent->_left == this)
        return _parent->_right;
      else 
        return _parent->_left;
    }

    int _data;
    bool _color;
    BstNode* _left;
    BstNode* _right;
    BstNode* _parent;
  };

private:
  void  Rotate_right(BstNode* p)
  {
    BstNode* gp = p->GrandParent();
    BstNode* fp = p->_parent;
    BstNode* y = p->_right;

    fp->_left = y;
    if(y != _nil)
    {
      y->_parent = fp;
    }
    p->_right = fp;
    fp->_parent = p;

    if(_root == fp)
    {
      _root = p;
    }
    p->_parent = gp;

    if(gp != NULL)
    {
      if(gp->_left == fp)
        gp->_right = p;
      else 
        gp->_left = p;
    }
  }

  void Rotate_left(BstNode* p)
  {
    if(p->_parent == NULL)
    {
      _root = p;
      return;
    }
    BstNode* gp = p->GrandParent();
    BstNode* fp = p->_parent;
    BstNode* y = p->_left;

    fp->_right = y;

    if(y != _nil)
    {
      y->_parent = fp;
    }
    p->_left = fp;
    fp->_parent = p;

    if(_root == fp)
    {
      _root == p;
    }
    p->_parent = gp;

    if(gp != NULL)
    {
      if(gp->_left == fp)
        gp->_right = p;
      else 
        gp->_left = p;
    }
  }

  void inorder(BstNode* p)
  {
    if(p == _nil)
    {
      return;
    }
    if(p->_left)
      inorder(p->_left);
    std::cout << p->_data << "-";
    if(p->_right)
      inorder(p->_right);
  }

  std::string Output_color(bool color) 
  {
    return color ? "Black" : "Red";
  }

  BstNode* Getsmall_child(BstNode* p)
  {
    if(p->_left == _nil)
      return p; 
    return Getsmall_child(p->_left); 
  }

  bool delete_child(BstNode* p,int data)
  {
    if(p->_data > data) 
    {
      if(p->_left == _nil)
        return false;
    
      return delete_child(p->_left,data);
    }
    else if(p->_data < data)
    {
      if(p->_right == _nil)
        return false;

      return delete_child(p->_right,data);
    }
    else if(p->_data == data) 
    {
      if(p->_right == _nil)
      {
        delete_one_child(p);
        return true;
      }
      BstNode* small = Getsmall_child(p->_right);
      std::swap(p->_data,small->_data);
      delete_ond_child(small);
      return true;
    }
    else 
      return false;
  }

  void delete_one_child(BstNode* p)
  {
    BstNode* child = p->_left == _nil ? p->_left : p->_right;

    if(p->_parent  == NULL && p->_left = _nil && p->_right == _nil)
    {
      p = NULL;
      _root =p;
      return;
    }
    if(p->_parent == NULL)
    {
      delete p;
      child->_parent = NULL;
      _root = child;
      _root->_color = Black;
      return;
    }

    if(p->_parent->_left == p)
      p->_parent->_right = child;
    else 
      p->_parent->_left = child;

    child->_parent = p->_parent;

    if(p->_color == Black)
    {
      if(child->_color = Red)
        child->_color = Black;
      else 
        delete_case(child);
    }
    delete p;
  }

  void delete_case(BstNode* p)
  {}

  void insert(BstNode* p,int data)
  {
    if(p->_data >= data)
    {
      if(p->_left != _nil)
        insert(p->_left,data);
      else 
      {
        BstNode* tmp = new BstNode();
        tmp->_data = data; 
        tmp->_left = tmp->_right = _nil;
        tmp->_parent = p;
        p->_left = tmp;
        insert_case(tmp);
      }
    }
    else 
    {
      if(p->_right != _nil)
        insert(p->_right,data);
      else 
      {
        BstNode* tmp = new BstNode();
        tmp->_data = data;
        tmp->_left = tmp->right = _nil;
        tmp->_parent = p;
        p->_right = tmp;
        insert_case(tmp);
      }
    }
  }

  void insert_case(BstNode* p)
  {}

public:
  BstTree()
  {
    _nil = new BstNode();
    _nil->_color = Black;
    _root = NULL;
  }

  void inorder()
  {
    if(_root == NULL)
    {
      return;
    }
    inorder(_root);
    std::cout << std::endl;
  }

  void insert(int data) 
  {
    if(_root == NULL)
    {
      _root = new Node();
      _root->_color = Black;
      _root->_left = _root->_right = _nil;
      _root->_data = data;
    }
    else 
    {
      insert(_root,data);
    }
  }

  bool delete_data(int data) 
  {
    return delete_child(_root,data);
  }

  ~BstTree()
  {
    if(_root)
      DeleteTree(_root);
    delete _nil;
  }

private:
  BstNode* _root;
  BstNode* _nil;
};
