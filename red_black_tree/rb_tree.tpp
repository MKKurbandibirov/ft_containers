namespace ft {

template<class T>
rb_tree<T>::rb_tree() {
	NIL = alloc.allocate(1);
	NIL->parent = NULL;
	NIL->left = NULL;
	NIL->right = NULL;
	NIL->value = T();
	NIL->color = BLACK;
}

template<class T>
rb_tree<T>::rb_tree(T value) {
	NIL = alloc.allocate(1);
	NIL->parent = NULL;
	NIL->left = NULL;
	NIL->right = NULL;
	NIL->value = value;
	NIL->color = BLACK;

	root = alloc.allocate(1);
	root->parent = NIL;
	root->left = NIL;
	root->right = NIL;
	root->value = value;
	root->color = BLACK;
}

template<class T>
void rb_tree<T>::rotate_left(Node<T>* x) {
	Node<T> *y = x->right;

	x->right = y->left;
	if (y->left != NIL) {
		y->left->parent = x;
	}

	if (y != NIL) {
		y->parent = x->parent;
	}

	if (x->parent != NULL) {
		if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
	} else {
		root = y;
	}

	y->left = x;
	if (x != NIL) {
		x->parent = y;
	}
}

template<class T>
void rb_tree<T>::rotate_right(Node<T> *x) {
	Node<T>* y = x->left;

	x->left = y->right;
	if (y->right != NIL) {
		y->right->parent = x;
	}

	if (y != NIL) {
		y->parent = x->parent;
	}

	if (x->parent != NULL) {
		if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
	} else {
		root = y;
	}

	y->right = x;
	if (x != NIL) {
		x->parent = y;
	}
}

template<class T>
void rb_tree<T>::insert_fixup(Node<T> *x) {
	while (x != root && x->parent->color == RED) {
		if (x->parent == x->parent->parent->left) {
			Node<T> *y = x->parent->parent->right;
			if (y->color == RED) {
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			} else {
				if (x == x->parent->right) {
					x = x->parent;
					rotate_left(x);
				}

				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				rotate_right(x->parent->parent);
			} 
		} else {
			Node<T> *y = x->parent->parent->left;
			if (y->color == RED) {
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = BLACK;
				x = x->parent->parent;
			} else {
				if (x == x->parent->left) {
					x = x->parent;
					rotate_right(x);
				}

				x->parent->color = BLACK;
				x->parent->parent->color= RED;
				rotate_left(x->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

template<class T>
Node<T>* rb_tree<T>::insert_node(const T& value) {
	Node<T> *current, *parent, *x;

	current = root;
	parent = NULL;
	while (current != NIL && root != NULL) {
		if (current->value == value) {
			return current;
		}
		parent = current;
		if (value < current->value) {
			current = current->left;
		} else {
			current = current->right;
		}
	}

	x = alloc.allocate(1);
	x->value = value;
	x->parent = parent;
	x->left = NIL;
	x->right = NIL;
	x->color = RED;

	if (parent != NULL) {
		if (value < parent->value) {
			parent->left = x;
		} else {
			parent->right = x;
		}
	} else {
		root = x;
	}

	insert_fixup(x);
	return x;
}


// template<class T>
// void rb_tree<T>::clear_tree() {
	
// }
template<class T>
rb_tree<T>::~rb_tree() {
	std::cout << root->value << std::endl;
}

} // namespace ft
