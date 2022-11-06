namespace ft {

template<class T>
rb_tree<T>::rb_tree() {
	NIL = alloc.allocate(1);
	NIL->left = NULL;
	NIL->right = NULL;
	NIL->parent = NULL;
	NIL->value = T();
	NIL->color = BLACK;
	root = NULL;
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

	if (x->parent) {
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

	if (x->parent) {
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
			if (y && y->color == RED) {
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
			if (y && y->color == RED) {
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
	header.node_count++;
	return x;
}

template<class T>
void rb_tree<T>::delete_fixup(Node<T>* x) {
	while(x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			Node<T> *w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rotate_left(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rotate_right(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rotate_left(x->parent);
				x = root;
			}
		} else {
			Node<T> *w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rotate_right(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					rotate_left(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rotate_right(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

template<class T>
void rb_tree<T>::delete_node(Node<T>* z) {
	Node<T> *x, *y;

	if (z == NULL || z == NIL) {
		return;
	}

	if (z->left == NIL || z->right == NIL) {
		y = z;
	} else {
		y = z->right;
		while (y->left != NIL) {
			y = y->left;
		}
	}

	if (y->left != NIL) {
		x = y->left;
	} else {
		x = y->right;
	}

	x->parent = y->parent;
	if (y->parent != NULL) {
		if (y == y->parent->left) {
			y->parent->left = x;
		} else {
			y->parent->right = x;
		}
	} else {
		root = x;
	}
	
	if (y != z) {
		z->value = y->value;
	}

	if (y->color == BLACK) {
		delete_fixup(x);
	}
	alloc.deallocate(y, 1);
	header.node_count--;
}

template<class T>
Node<T>* rb_tree<T>::find_node(const T& value) {
	Node<T> *current = root;
	while (current != NIL && current != NULL) {
		if (current->value == value) {
			return current;
		} else if (current->value > value) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
	return NULL;
}

template<class T>
void rb_tree<T>::clear_tree(Node<T>* x) {
	if (x == NULL || x == NIL) {
		return;
	}
	clear_tree(x->left);
	clear_tree(x->right);
	alloc.deallocate(x, 1);

}

template<class T>
rb_tree<T>::~rb_tree() {
	if (root != NULL) {
		clear_tree(root);
	}
}

template<class T>
Node<T>* rb_tree<T>::maximum(Node<T>* x) const {
	Node<T>* curr = x;
	while (curr->right != NIL) {
		curr = curr->right;
	}
	return curr;
}

template<class T>
Node<T>* rb_tree<T>::minimum(Node<T>* x) const {
	Node<T>* curr = x;
	while (curr->left != NIL) {
		curr = curr->left;
	}
	return curr;
}

template<class T>
Node<T>* rb_tree<T>::next(Node<T>* x) const {
	if (x->right != NIL) {
		return minimum(x->right);
	}
	Node<T> *y = x->parent;
	while (y != NIL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

template<class T>
Node<T>* rb_tree<T>::prev(Node<T>* x) const {
	if (x->left != NIL)
		return maximum(x->left);
	Node<T> *y = x->parent;
	while (y != NIL && x == y->left) {
		x = y;
		y = y->parent;
	}
	return y;
}

} // namespace ft
