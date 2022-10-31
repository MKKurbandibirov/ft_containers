#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <memory>

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
	class rb_tree {
	private:
		Node<T> *root;
		Node<T> *NIL;
		std::allocator< Node<T> > alloc;

		void clear_tree();
	
	public:
		rb_tree();
		// rb_tree(T value);
		~rb_tree();

		void rotate_right(Node<T> *x);
		void rotate_left(Node<T> *x);

		Node<T>* insert_node(const T &value);
		void insert_fixup(Node<T> *x);
		
		Node<T>* find_node(const T &value);
		void delete_node(Node<T> *z);
		void delete_fixup(Node<T> *x);

		Node<T>* get_root() const;
	};


} // namespace ft

# include "rb_tree.tpp"


#endif