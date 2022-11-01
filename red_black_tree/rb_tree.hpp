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

		// Node() {
		// 	left = NULL;
		// 	right = NULL;
		// 	parent = NULL;
		// 	color = BLACK;
		// 	value = T();
		// }
	};

	// template<class T>

	template<class T>
	class rb_tree {
	private:
		Node<T> *root;
		Node<T> *NIL;
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
		public:
			Node<T>*	node;
			rb_tree<T>	tree;

			typedef T																						value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

			RBT_iterator(): node(NULL), tree() {}
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
				Node<T>* p;
				if (node == NULL) {
					node = tree.root;
					// std::cout << tree.NIL;
					while (node->left->left != NULL) {
						node = node->left;
					}
				} else if (node->right != NULL) {
					node = node->right;
					while (node->left->left != NULL) {
						node = node->left;
					}
				} else {
					p = node->parent;
					while (p != NULL && node == p->right) {
						node = p;
						p = p->parent;
					}
					node = p;
				}
				return *this;
			}

			RBT_iterator& operator++(int);
			// RBT_iterator& operator--(void);
			// RBT_iterator& operator--(int);
		};
	};


} // namespace ft

# include "rb_tree.tpp"


#endif