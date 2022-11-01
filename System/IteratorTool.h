#ifndef ITERATORTOOL_H
#define ITERATORTOOL_H

class IteratorTool
{
	public:
		IteratorTool();
		virtual ~IteratorTool();
		virtual void first() = 0;
		virtual void next() = 0;
		virtual bool isLastEl() = 0;
};
#endif