class Negate : public SubExpression
{
public:
	Negate(Expression* left, Expression* right) :
		SubExpression(left, right) {
	}
	int evaluate() {
		if (left->evaluate() == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
};