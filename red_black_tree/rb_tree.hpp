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

		Node<T>* minimum(Node<T>* x) {
			if (x->left == NULL)
				return x;
			return minimum(x->left);
		}

		Node<T>* maximum(Node<T>* x) {
			if (x->right == NULL)
				return x;
			return maximum(x->right);
		}

		Node<T>* next(Node<T>* x) {
			if (x->right != NULL)
				return minimum(x->right);
			Node<T> *y = x->parent;
			while (y != NULL && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		Node<T>* prev(Node<T>* x) {
			if (x->left != NULL)
				return maximum(x->left);
			Node<T> *y = x->parent;
			while (y != NULL && x == y->left) {
				x = y;
				y = y->parent;
			}
			return y;
		}
	};

	template<class T>
	class rb_tree {
	private:
		Node<T> *root;
		std::allocator< Node<T> > alloc;

		void clear_tree(Node<T> *x);

		void rotate_right(Node<T> *x);
		void rotate_left(Node<T> *x);

		void insert_fixup(Node<T> *x);
		void delete_fixup(Node<T> *x);

	public:
		rb_tree();
		~rb_tree();

		Node<T>* insert_node(const T &value);
		
		Node<T>* find_node(const T &value);

		void delete_node(Node<T> *z);
		
		Node<T>* get_root() const;

		class RBT_iterator: std::iterator<std::bidirectional_iterator_tag, T> {
		private:
			Node<T>*	node;

		public:
			typedef T																						value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

			RBT_iterator() {}
			RBT_iterator(Node<T>* node): node(node) {}
			RBT_iterator(const RBT_iterator& other): node(other.node) {}
			virtual ~RBT_iterator() {}

			RBT_iterator& operator=(const RBT_iterator& other) {
				if (*this == other) {
					return *this;
				}
				node = other.node;
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
				node = node->next(node);
				return *this;
			}

			RBT_iterator& operator++(int) {
				RBT_iterator tmp(*this);
				operator++();
				return tmp;
			}

			RBT_iterator& operator--(void) {
				node = node->prev(node);
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

		public:
			typedef T																						value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

			RBT_const_iterator() {}
			RBT_const_iterator(Node<T>* node): node(node) {}
			RBT_const_iterator(const RBT_const_iterator& other): node(other.node) {}
			virtual ~RBT_const_iterator() {}

			RBT_const_iterator& operator=(const RBT_const_iterator& other) {
				if (*this == other) {
					return *this;
				}
				node = other.node;
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
				node = node->next(node);
				return *this;
			}

			RBT_const_iterator& operator++(int) {
				RBT_const_iterator tmp(*this);
				operator++();
				return tmp;
			}

			RBT_const_iterator& operator--(void) {
				node = node->prev(node);
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