#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
// # include <iterator>

# include "../util/rbt_iterator.hpp"

namespace ft
{

typedef enum{ BLACK, RED } NodeColor;

template<typename T>
struct Node {
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	NodeColor color;
	T value;
};

template<class T>
struct rb_tree_header {
	Node<T>* header;
	std::size_t node_count;

	rb_tree_header() {
		std::allocator<Node<T> > alloc;
		header = alloc.allocate(1);
		header->color = RED;
		header->left = NULL;
		header->right = NULL;
		header->parent = NULL;
		node_count = 0;
	}

	rb_tree_header<T>& operator=(const rb_tree_header<T>& other) {
		if (this == &other) {
			return *this;
		}
		header = other.header;
		node_count = other.node_count;
		return *this;
	}
};

template<class T>
class rb_tree {
private:
	void rotate_right(Node<T> *x);
	void rotate_left(Node<T> *x);

	void insert_fixup(Node<T> *x);
	void delete_fixup(Node<T> *x);

public:
	typedef RBT_iterator<T>		iterator;
	typedef RBT_const_iterator<T>	const_iterator;

	rb_tree_header<T>	header;
	Node<T> 			*root;
	std::allocator< Node<T> > alloc;
	Node<T>* NIL;
	
	rb_tree();
	~rb_tree();
	void clear_tree(Node<T> *x);

	Node<T>* insert_node(const T &value);
	Node<T>* find_node(const T &value) const;
	Node<T>* find_node_by_key(const T &value) const;
	void delete_node(Node<T> *z);

	Node<T>* maximum(Node<T>* x) const;
	Node<T>* minimum(Node<T>* x) const;

	Node<T>* next(Node<T>* x) const;
	Node<T>* prev(Node<T>* x) const;

	void swap(rb_tree& other) {
		Node<T>* tmp = root;
		root = other.root;
		other.root = tmp;

		Node<T>* tmp_n = NIL;
		NIL = other.NIL;
		other.NIL = tmp_n;

		rb_tree_header<T> tmp_h = header;
		header = other.header;
		other.header = tmp_h;
	}
};

} // namespace ft

# include "rb_tree.tpp"
#endif