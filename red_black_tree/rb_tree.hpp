#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>
# include <iterator>

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

		// Node<T>* operator=(const Node<T>* other) {
		// 	if (this == &other) {
		// 		return *this;
		// 	}
		// 	color = other->color;
		// 	value = other->value;
		// 	left = other->left;
		// 	right = other->right;
		// 	parent = other->parent;
		// 	return *this;
		// }
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

		Node<T>* NIL;

	public:
		rb_tree_header<T>	header;
		Node<T> 			*root;
		std::allocator< Node<T> > alloc;
		
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

		class RBT_iterator: std::iterator<std::bidirectional_iterator_tag, T> {
		private:
			Node<T>*	node;
			rb_tree_header<T>	header;
			Node<T>*			root;

			bool isNIL(Node<T>* x) {
				if (x == NULL) {
					return true;
				}
				if (x->right == NULL && x->left == NULL) {
					return true;
				}
				return false;
			}

			Node<T>* maximum(Node<T>* x) {
				Node<T>* curr = x;
				while (!isNIL(curr->right)) {
					curr = curr->right;
				}
				return curr;
			}

			Node<T>* minimum(Node<T>* x) {
				Node<T>* curr = x;
				while (!isNIL(curr->left)) {
					curr = curr->left;
				}
				return curr;
			}

			Node<T>* next(Node<T>* x) {
				if (!isNIL(x->right)) {
					return minimum(x->right);
				}
				Node<T> *y = x->parent;
				while (!isNIL(y) && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			Node<T>* prev(Node<T>* x) {
				if (!isNIL(x->left))
					return maximum(x->left);
				Node<T> *y = x->parent;
				while (!isNIL(y) && x == y->left) {
					x = y;
					y = y->parent;
				}
				return y;
			}

		public:
			typedef T																						value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

			RBT_iterator() {}
			RBT_iterator(Node<T>* node, Node<T>* root, rb_tree_header<T> header):
				node(node),
				header(header),
				root(root) {}
			RBT_iterator(const RBT_iterator& other):
				node(other.node),
				header(other.header),
				root(other.root) {}
			virtual ~RBT_iterator() {}

			RBT_iterator& operator=(const RBT_iterator& other) {
				if (*this == other) {
					return *this;
				}
				node = other.node;
				root = other.root;
				header = other.header;
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
				if (node->value == maximum(root)->value) {
					node = header.header;
				} else {
					node = next(node);
				}
				return *this;
			}

			RBT_iterator& operator++(int) {
				RBT_iterator tmp(*this);
				operator++();
				return tmp;
			}

			RBT_iterator& operator--(void) {
				if (node == header.header) {
					node = maximum(root);
				} else {
					node = prev(node);
				}
				return *this;
			}

			RBT_iterator& operator--(int) {
				RBT_iterator tmp(*this);
				operator--();
				return tmp;
			}
		};
		typedef RBT_iterator iterator;

		class RBT_const_iterator: std::iterator<std::bidirectional_iterator_tag, T> {
		private:
			Node<T>*	node;
			rb_tree_header<T>	header;
			Node<T>*			root;

			bool isNIL(Node<T>* x) {
				if (x == NULL) {
					return true;
				}
				if (x->right == NULL && x->left == NULL) {
					return true;
				}
				return false;
			}

			Node<T>* maximum(Node<T>* x) {
				Node<T>* curr = x;
				while (!isNIL(curr->right)) {
					curr = curr->right;
				}
				return curr;
			}

			Node<T>* minimum(Node<T>* x) {
				Node<T>* curr = x;
				while (!isNIL(curr->left)) {
					curr = curr->left;
				}
				return curr;
			}

			Node<T>* next(Node<T>* x) {
				if (!isNIL(x->right)) {
					return minimum(x->right);
				}
				Node<T> *y = x->parent;
				while (!isNIL(y) && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			Node<T>* prev(Node<T>* x) {
				if (!isNIL(x->left))
					return maximum(x->left);
				Node<T> *y = x->parent;
				while (!isNIL(y) && x == y->left) {
					x = y;
					y = y->parent;
				}
				return y;
			}

		public:
			typedef T																						value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

			RBT_const_iterator() {}
			RBT_const_iterator(Node<T>* node, Node<T>* root, rb_tree_header<T> header):
				node(node),
				header(header),
				root(root) {}
			RBT_const_iterator(const RBT_const_iterator& other):
				node(other.node),
				header(other.header),
				root(other.root) {}
			virtual ~RBT_const_iterator() {}

			RBT_const_iterator& operator=(const RBT_const_iterator& other) {
				if (*this == other) {
					return *this;
				}
				node = other.node;
				root = other.root;
				header = other.header;
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
				if (node->value == maximum(root)->value) {
					node = header.header;
				} else {
					node = next(node);
				}
				return *this;
			}

			RBT_const_iterator& operator++(int) {
				RBT_const_iterator tmp(*this);
				operator++();
				return tmp;
			}

			RBT_const_iterator& operator--(void) {
				if (node == header.header) {
					node = maximum(root);
				} else {
					node = prev(node);
				}
				return *this;
			}

			RBT_const_iterator& operator--(int) {
				RBT_const_iterator tmp(*this);
				operator--();
				return tmp;
			}
		};
		typedef RBT_const_iterator const_iterator;
	};

} // namespace ft

# include "rb_tree.tpp"


#endif