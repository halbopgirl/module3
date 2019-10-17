class Or : public SubExpression
{
public:
	Or(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		if (left->evaluate() == 0) {
			if (right->evaluate() == 0) {
				return 0;
			}
		return 1;
		}
		else {
			return 1;
		}
	}
};