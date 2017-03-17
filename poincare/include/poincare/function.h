#ifndef POINCARE_FUNCTION_H
#define POINCARE_FUNCTION_H

#include <poincare/expression.h>
#include <poincare/list_data.h>

namespace Poincare {

/* The Function class represents the built-in math functions such as cos, sin,
 * tan, log, etc... */

class Function : public Expression {
public:
  Function(const char * name);
  ~Function();
  void setArgument(Expression ** args, int numberOfArguments, bool clone = true);
  void setArgument(ListData * listData, bool clone = true);
  virtual bool isValidNumberOfArguments(int numberOfArguments);
  const Expression * operand(int i) const override;
  int numberOfOperands() const override;
  Expression * clone() const override;
protected:
  ExpressionLayout * privateCreateLayout(FloatDisplayMode floatDisplayMode, ComplexFormat complexFormat) const override;
  Expression * privateEvaluate(Context& context, AngleUnit angleUnit) const override;
  Expression ** m_args;
  int m_numberOfArguments;
  const char * m_name;
};

}

#endif
