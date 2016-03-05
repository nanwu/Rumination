
Expr::Expr(int i):
    p(new int_node(i)) {}

Expr::Expr(const String& op, Expr e):
    p(new unary_node(op, e)) {}

Expr::Expr(const String& op, Expr left, Expr right ):
    p(new binary_node(op, left, right)) {}



