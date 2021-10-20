#include "redb_tree.hpp"

int main(void)
{
	ft::Rb_tree<int, std::less<int> > t;
	t.insert(1);
	t.insert(3);
	t.insert(4);

	return(0);
}