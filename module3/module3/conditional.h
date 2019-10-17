class Conditional : public SubExpression
{
public:
	Conditional(Expression* left, Expression* right, Expression* condition) :
		SubExpression(left, right)
	{
		this -> condition = condition;
	}
	int evaluate()
	{
		if (condition->evaluate() == 0) {
			return right->evaluate();
		}
		else {
			return left->evaluate();
		}
	}
private:
	Expression* condition;
};