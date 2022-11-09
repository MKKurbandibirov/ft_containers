#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include <iterator>
# include "../red_black_tree/rb_tree.hpp"
# include "iterator_traits.hpp"

namespace ft
{

template<class T>
struct Node;

template<class T>
class rb_tree;

template<class T>
class RBT_iterator {
private:
	Node<T>*	node;
	rb_tree<T>	tree;

public:
	typedef T													value_type;
	typedef T*													pointer;
	typedef T&													reference;
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

	RBT_iterator() {}
	RBT_iterator(Node<T>* node, rb_tree<T> tree): node(node), tree(tree) {}
	RBT_iterator(const RBT_iterator& other): node(other.node), tree(other.tree) {}
	virtual ~RBT_iterator() {}

	RBT_iterator& operator=(const RBT_iterator& other) {
		if (*this == other) {
			return *this;
		}
		node = other.node;
		tree = other.tree;
		return *this;
	}

	bool operator==(const RBT_iterator& other) {
		return node == other.node;
	}

	bool operator!=(const RBT_iterator& other) {
		return node != other.node;
	}

	reference operator*() const {
		return node->value;
	}

	RBT_iterator& operator++(void) {
		if (node->value == tree.maximum(tree.root)->value) {
			node = tree.header.header;
		} else {
			node = tree.next(node);
		}
		return *this;
	}

	RBT_iterator& operator++(int) {
		if (node->value == tree.maximum(tree.root)->value) {
			node = tree.header.header;
		} else {
			node = tree.next(node);
		}
		return *this;
	}

	RBT_iterator& operator--(void) {
		if (node == tree.header.header) {
			node = tree.maximum(tree.root);
		} else {
			node = tree.prev(node);
		}
		return *this;
	}

	RBT_iterator& operator--(int) {
		if (node == tree.header.header) {
			node = tree.maximum(tree.root);
		} else {
			node = tree.prev(node);
		}
		return *this;
	}

};

template<class T>
class RBT_const_iterator: std::iterator<std::bidirectional_iterator_tag, T> {
public:
	typedef T													value_type;
	typedef T*													pointer;
	typedef T&													reference;
	typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
	typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

	RBT_const_iterator() {}
	RBT_const_iterator(Node<T>* node, rb_tree<T> tree): node(node), tree(tree) {}
	RBT_const_iterator(const RBT_const_iterator& other): node(other.node), tree(other.tree) {}
	virtual ~RBT_const_iterator() {}

	RBT_const_iterator& operator=(const RBT_const_iterator& other) {
		if (*this == other) {
			return *this;
		}
		node = other.node;
		tree = other.tree;
		return *this;
	}

	bool operator==(const RBT_const_iterator& other) {
		return node == other.node;
	}

	bool operator!=(const RBT_const_iterator& other) {
		return node != other.node;
	}

	reference operator*() const {
		return node->value;
	}

	RBT_const_iterator& operator++(void) {
		if (node->value == tree.maximum(tree.root)->value) {
			node = tree.header.header;
		} else {
			node = tree.next(node);
		}
		return *this;
	}

	RBT_const_iterator& operator++(int) {
		if (node->value == tree.maximum(tree.root)->value) {
			node = tree.header.header;
		} else {
			node = tree.next(node);
		}
		return *this;
	}

	RBT_const_iterator& operator--(void) {
		if (node == tree.header.header) {
			node = tree.maximum(tree.root);
		} else {
			node = tree.prev(node);
		}
		return *this;
	}

	RBT_const_iterator& operator--(int) {
		if (node == tree.header.header) {
			node = tree.maximum(tree.root);
		} else {
			node = tree.prev(node);
		}
		return *this;
	}

private:
	Node<T>*	node;
	rb_tree<T>	tree;
};

} // namespace ft



#endif