#ifndef _EXPR_H_
#define _EXPR_H_

#include <iostream>

class Expr
{
    friend ostream& operator<<(ostream&, const Expr&);
    expr_node* n;

public:
    Expr(Int);
    Expr(const String&, Expr);
    Expr(const String&, Expr, Expr);
    Expr(const Expr& e) { n = e.n; ++n->use; }
    Expr& operator=(const Expr&);
    ~Expr() { if (--n->use == 0) delete n; }
}

class expr_node
{
    friend ostream& operator<<(ostream&, const expr_node&);
    friend class Expr;
    
    int use;
    
protected:
    expr_node(): use(1) { }
    virtual void print(ostream&) const = 0;
    virtual ~expr_node() { }
};

ostream& operator<<(ostream& o, const expr_node& e)
{
    e.print(o);
    return 0;
}

class int_node: public expr_node {
    friend class expr;

    int n;
    int_node(int k): n(k) {}
    void print(ostream& o) const { o << n;}
};

class unary_node: public expr_node {
    friend class expr;

    string op;
    expr_node* operand;
    unary_node(const string& a, expr_node* b):
        op(a), operand(b) {}
    
    void print(ostream& o) const
    { 
        o << "(" << op << *operand << ")";
    }
};

class binary_node: public expr_node {
    friend class expr;

    string op;
    expr_node* left_side;
    expr_node* right_side;

    binary_node(const string& a, expr_node* l, expr_node* r):
        op(a), left_side(l), right_side(r) {}
    void print(ostream& o) const
    {
        o << "(" << *left << op << *right << ")";
    }
};


class expr
{
    friend ostream& operator<<(ostream&, const expr&);
    expr_node* e;
}
#endif
