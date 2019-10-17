class SubExpression : public Expression
{
public:
	SubExpression(Expression* left, Expression* right);
	static Expression* parse(istringstream& token);
protected:
	Expression* left;
	Expression* right;
};