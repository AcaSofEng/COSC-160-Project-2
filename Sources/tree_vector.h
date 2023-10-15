#ifndef TREE_VECTOR_H_INCLUDED
#define TREE_VECTOR_H_INCLUDED

#include<algorithm>
#include<cstddef>
#include<cstdint>
#include<initializer_list>
#include<limits>
#include<memory>
#include<stdexcept>
#include<type_traits>
#include<utility>

template<typename value_type,
         template<typename allocate_type> typename allocator_type=std::allocator>
class tree_vector
{
    struct tree_node
    {
        value_type _value;
        std::size_t _left_subtree_size;
        std::ptrdiff_t _height;
        tree_node* _parent;
        tree_node* _left_child;
        tree_node* _right_child;

        tree_node():_value(),
                    _left_subtree_size(),
                    _height(),
                    _parent(),
                    _left_child(),
                    _right_child(){}

        template<typename... argument_types>
        tree_node(tree_node* const source_parent,
                  argument_types&&... source_arguments):_value(std::forward<argument_types>(source_arguments)...),
                                                        _left_subtree_size(),
                                                        _height(),
                                                        _parent(source_parent),
                                                        _left_child(),
                                                        _right_child(){}

        template<typename... argument_types>
        tree_node(const std::size_t source_left_subtree_size,
                  const std::ptrdiff_t source_height,
                  tree_node* const source_parent,
                  argument_types&&... source_arguments):_value(std::forward<argument_types>(source_arguments)...),
                                                        _left_subtree_size(source_left_subtree_size),
                                                        _height(source_height),
                                                        _parent(source_parent),
                                                        _left_child(),
                                                        _right_child(){}
    };

    class tree_node_iterator
    {
        tree_node* _tree_node;

        tree_node* predecessor_node(tree_node* source_node)
        {
            if(source_node->_left_child)
            {
                source_node=source_node->_left_child;
                while(source_node->_right_child)
                {
                    source_node=source_node->_right_child;
                }

                return source_node;
            }

            tree_node* source_node_parent(source_node->_parent);
            while(source_node_parent
                  &&source_node_parent->_left_child==source_node)
            {
                source_node=source_node_parent;
                source_node_parent=source_node_parent->_parent;
            }

            return source_node_parent;
        }

        tree_node* successor_node(tree_node* source_node)
        {
            if(source_node->_right_child)
            {
                source_node=source_node->_right_child;
                while(source_node->_left_child)
                {
                    source_node=source_node->_left_child;
                }

                return source_node;
            }

            tree_node* source_node_parent(source_node->_parent);
            while(source_node_parent
                  &&source_node_parent->_right_child==source_node)
            {
                source_node=source_node_parent;
                source_node_parent=source_node_parent->_parent;
            }

            return source_node_parent;
        }

        public:
            tree_node_iterator():_tree_node(){}
            tree_node_iterator(tree_node* const source_node):_tree_node(source_node){}

            tree_node_iterator& operator++()
            {
                _tree_node=successor_node(_tree_node);

                return *this;
            }

            tree_node_iterator& operator--()
            {
                _tree_node=predecessor_node(_tree_node);

                return *this;
            }

            tree_node_iterator operator++(int)
            {
                tree_node_iterator previous_iterator(_tree_node);
                _tree_node=successor_node(_tree_node);

                return previous_iterator;
            }

            tree_node_iterator operator--(int)
            {
                tree_node_iterator next_iterator(_tree_node);
                _tree_node=predecessor_node(_tree_node);

                return next_iterator;
            }

            value_type& operator*() const
            {
                return _tree_node->_value;
            }

            value_type* operator->() const
            {
                return std::addressof(_tree_node->_value);
            }

            bool operator==(const tree_node_iterator& source_iterator) const
            {
                return _tree_node==source_iterator._tree_node;
            }

            bool operator!=(const tree_node_iterator& source_iterator) const
            {
                return _tree_node!=source_iterator._tree_node;
            }
    };

    class tree_node_reverse_iterator
    {
        tree_node_iterator _tree_node_iterator;

        public:
            tree_node_reverse_iterator():_tree_node_iterator(){}
            tree_node_reverse_iterator(tree_node* const source_node):_tree_node_iterator(source_node){}

            tree_node_reverse_iterator& operator++()
            {
                --_tree_node_iterator;

                return *this;
            }

            tree_node_reverse_iterator& operator--()
            {
                ++_tree_node_iterator;

                return *this;
            }

            tree_node_reverse_iterator operator++(int)
            {
                tree_node_reverse_iterator next_iterator(*this);
                --_tree_node_iterator;

                return next_iterator;
            }

            tree_node_reverse_iterator operator--(int)
            {
                tree_node_reverse_iterator previous_iterator(*this);
                ++_tree_node_iterator;

                return previous_iterator;
            }

            value_type& operator*() const
            {
                return *_tree_node_iterator;
            }

            value_type* operator->() const
            {
                return _tree_node_iterator.operator->();
            }

            bool operator==(const tree_node_reverse_iterator& source_iterator) const
            {
                return _tree_node_iterator==source_iterator._tree_node_iterator;
            }

            bool operator!=(const tree_node_reverse_iterator& source_iterator) const
            {
                return _tree_node_iterator!=source_iterator._tree_node_iterator;
            }
    };

    class tree_node_const_iterator
    {
        const tree_node* _tree_node;

        const tree_node* predecessor_node(const tree_node* source_node)
        {
            if(source_node->_left_child)
            {
                source_node=source_node->_left_child;
                while(source_node->_right_child)
                {
                    source_node=source_node->_right_child;
                }

                return source_node;
            }

            const tree_node* source_node_parent(source_node->_parent);
            while(source_node_parent
                  &&source_node_parent->_left_child==source_node)
            {
                source_node=source_node_parent;
                source_node_parent=source_node_parent->_parent;
            }

            return source_node_parent;
        }

        const tree_node* successor_node(const tree_node* source_node)
        {
            if(source_node->_right_child)
            {
                source_node=source_node->_right_child;
                while(source_node->_left_child)
                {
                    source_node=source_node->_left_child;
                }

                return source_node;
            }

            const tree_node* source_node_parent(source_node->_parent);
            while(source_node_parent
                  &&source_node_parent->_right_child==source_node)
            {
                source_node=source_node_parent;
                source_node_parent=source_node_parent->_parent;
            }

            return source_node_parent;
        }

        public:
            tree_node_const_iterator():_tree_node(){}
            tree_node_const_iterator(const tree_node* const source_node):_tree_node(source_node){}

            tree_node_const_iterator& operator++()
            {
                _tree_node=successor_node(_tree_node);

                return *this;
            }

            tree_node_const_iterator& operator--()
            {
                _tree_node=predecessor_node(_tree_node);

                return *this;
            }

            tree_node_const_iterator operator++(int)
            {
                tree_node_const_iterator previous_iterator(_tree_node);
                _tree_node=successor_node(_tree_node);

                return previous_iterator;
            }

            tree_node_const_iterator operator--(int)
            {
                tree_node_const_iterator next_iterator(_tree_node);
                _tree_node=predecessor_node(_tree_node);

                return next_iterator;
            }

            const value_type& operator*() const
            {
                return _tree_node->_value;
            }

            const value_type* operator->() const
            {
                return std::addressof(_tree_node->_value);
            }

            bool operator==(const tree_node_const_iterator& source_iterator) const
            {
                return _tree_node==source_iterator._tree_node;
            }

            bool operator!=(const tree_node_const_iterator& source_iterator) const
            {
                return _tree_node!=source_iterator._tree_node;
            }
    };

    class tree_node_const_reverse_iterator
    {
        tree_node_const_iterator _tree_node_const_iterator;

        public:
            tree_node_const_reverse_iterator():_tree_node_const_iterator(){}
            tree_node_const_reverse_iterator(const tree_node* const source_node):_tree_node_const_iterator(source_node){}

            tree_node_const_reverse_iterator& operator++()
            {
                --_tree_node_const_iterator;

                return *this;
            }

            tree_node_const_reverse_iterator& operator--()
            {
                ++_tree_node_const_iterator;

                return *this;
            }

            tree_node_const_reverse_iterator operator++(int)
            {
                tree_node_const_reverse_iterator next_iterator(*this);
                --_tree_node_const_iterator;

                return next_iterator;
            }

            tree_node_const_reverse_iterator operator--(int)
            {
                tree_node_const_reverse_iterator previous_iterator(*this);
                ++_tree_node_const_iterator;

                return previous_iterator;
            }

            const value_type& operator*() const
            {
                return *_tree_node_const_iterator;
            }

            const value_type* operator->() const
            {
                return _tree_node_const_iterator.operator->();
            }

            bool operator==(const tree_node_const_reverse_iterator& source_iterator) const
            {
                return _tree_node_const_iterator==source_iterator._tree_node_const_iterator;
            }

            bool operator!=(const tree_node_const_reverse_iterator& source_iterator) const
            {
                return _tree_node_const_iterator!=source_iterator._tree_node_const_iterator;
            }
    };

    allocator_type<tree_node> _tree_node_allocator;
    tree_node _auxiliary;
    tree_node* _root;
    std::size_t _size;

    tree_node* copy_node(const tree_node* const source_node,
                         tree_node* const source_parent)
    {
        tree_node* clone_node(_tree_node_allocator.allocate(static_cast<std::size_t>(1)));
        std::allocator_traits<allocator_type<tree_node>>::construct(_tree_node_allocator,
                                                                    clone_node,
                                                                    source_node->_left_subtree_size,
                                                                    source_node->_height,
                                                                    source_parent,
                                                                    source_node->_value);

        return clone_node;
    }

    tree_node* copy_tree(const tree_node* source_root)
    {
        if(!source_root)
        {
            return nullptr;
        }

        tree_node* copy_root(copy_node(source_root,
                                       nullptr));
        _auxiliary._left_child=copy_root;
        _auxiliary._right_child=copy_root;

        tree_node* traverse_node(copy_root);
        while(source_root)
        {
            while(source_root->_left_child)
            {
                source_root=source_root->_left_child;
                traverse_node->_left_child=copy_node(source_root,
                                                     traverse_node);
                traverse_node=traverse_node->_left_child;

                if(traverse_node->_parent==_auxiliary._left_child)
                {
                    _auxiliary._left_child=traverse_node;
                }
            }

            if(source_root->_right_child)
            {
                source_root=source_root->_right_child;
                traverse_node->_right_child=copy_node(source_root,
                                                      traverse_node);
                traverse_node=traverse_node->_right_child;

                if(traverse_node->_parent==_auxiliary._right_child)
                {
                    _auxiliary._right_child=traverse_node;
                }
            }

            else
            {
                while(source_root->_parent
                      &&source_root->_parent->_right_child==source_root)
                {
                    source_root=source_root->_parent;
                    traverse_node=traverse_node->_parent;
                }

                while(source_root->_parent
                      &&!source_root->_parent->_right_child)
                {
                    source_root=source_root->_parent;
                    traverse_node=traverse_node->_parent;
                }

                if(source_root->_parent)
                {
                    source_root=source_root->_parent->_right_child;
                    traverse_node=traverse_node->_parent;
                    traverse_node->_right_child=copy_node(source_root,
                                                          traverse_node);
                    traverse_node=traverse_node->_right_child;

                    if(traverse_node->_parent==_auxiliary._right_child)
                    {
                        _auxiliary._right_child=traverse_node;
                    }
                }

                else
                {
                    break;
                }
            }
        }

        return copy_root;
    }

    void assign_tree(const tree_node* source_root)
    {
        if(!source_root)
        {
            clear_tree();
            _root=nullptr;
            _auxiliary._left_child=nullptr;
            _auxiliary._right_child=nullptr;
        }

        tree_node* traverse_node(_root);
        while(source_root)
        {
            while(source_root->_left_child)
            {
                traverse_node->_value=source_root->_value;
                source_root=source_root->_left_child;
                if(!traverse_node->_left_child)
                {
                    traverse_node->_left_child=copy_node(source_root,
                                                         traverse_node);
                }

                traverse_node=traverse_node->_left_child;
                if(traverse_node->_parent==_auxiliary._left_child)
                {
                    _auxiliary._left_child=traverse_node;
                }
            }

            if(source_root->_right_child)
            {
                traverse_node->_value=source_root->_value;
                source_root=source_root->_right_child;
                if(!traverse_node->_right_child)
                {
                    traverse_node->_right_child=copy_node(source_root,
                                                          traverse_node);
                }

                traverse_node=traverse_node->_right_child;
                if(traverse_node->_parent==_auxiliary._right_child)
                {
                    _auxiliary._right_child=traverse_node;
                }
            }

            else
            {
                while(source_root->_parent
                      &&source_root->_parent->_right_child==source_root)
                {
                    source_root=source_root->_parent;
                    traverse_node=traverse_node->_parent;
                }

                while(source_root->_parent
                      &&!source_root->_parent->_right_child)
                {
                    source_root=source_root->_parent;
                    traverse_node=traverse_node->_parent;
                }

                if(source_root->_parent)
                {
                    traverse_node->_value=source_root->_value;
                    source_root=source_root->_parent->_right_child;
                    traverse_node=traverse_node->_parent;
                    if(!traverse_node->_right_child)
                    {
                        traverse_node->_right_child=copy_node(source_root,
                                                              traverse_node);
                    }

                    traverse_node=traverse_node->_right_child;
                    traverse_node->_value=source_root->_value;
                    if(traverse_node->_parent==_auxiliary._right_child)
                    {
                        _auxiliary._right_child=traverse_node;
                    }
                }

                else
                {
                    break;
                }
            }
        }
    }

    void copy_values(const std::size_t source_value_count,
                     const value_type& source_value)
    {
        for(std::size_t source_value_counter{};
            source_value_counter<source_value_count;
            ++source_value_counter)
        {
            push_back(source_value);
        }
    }

    void copy_values(const std::initializer_list<const value_type>& source_initializer_list)
    {
        for(const value_type& source_value:source_initializer_list)
        {
            push_back(source_value);
        }
    }

    template<typename iterator_type,
             typename std::enable_if<!std::is_integral<iterator_type>::value,
                                     bool>::type=true>
    void copy_values(iterator_type source_begin_iterator,
                     iterator_type source_end_iterator)
    {
        for(;
            source_begin_iterator!=source_end_iterator;
            ++source_begin_iterator)
        {
            push_back(*source_begin_iterator);
        }
    }

    void destruct_node(tree_node* const source_node)
    {
        std::allocator_traits<allocator_type<tree_node>>::destroy(_tree_node_allocator,
                                                                  source_node);
        _tree_node_allocator.deallocate(source_node,
                                        static_cast<std::size_t>(1));
    }

    void clear_tree()
    {
        tree_node* clear_node_parent{};
        tree_node* clear_node(_root);
        while(clear_node)
        {
            while(clear_node->_left_child)
            {
                clear_node=clear_node->_left_child;
            }

            if(clear_node->_right_child)
            {
                clear_node=clear_node->_right_child;
            }

            else
            {
                clear_node_parent=clear_node->_parent;
                transfer_node(clear_node,
                              clear_node_parent,
                              nullptr);
                destruct_node(clear_node);
                clear_node=clear_node_parent;
            }
        }
    }

    void transfer_node(const tree_node* const source_node,
                       tree_node* const source_node_parent,
                       tree_node* const source_transfer_node)
    {
        if(!source_node_parent)
        {
            _root=source_transfer_node;
        }

        else if(source_node_parent->_left_child==source_node)
        {
            source_node_parent->_left_child=source_transfer_node;
        }

        else if(source_node_parent->_right_child==source_node)
        {
            source_node_parent->_right_child=source_transfer_node;
        }

        if(source_transfer_node)
        {
            source_transfer_node->_parent=source_node_parent;
        }
    }

    template<typename... argument_types>
    tree_node_iterator forward_insert(const std::size_t source_index,
                                      argument_types&&... source_arguments)
    {
        if(source_index>_size)
        {
            return tree_node_iterator();
        }

        tree_node* insert_node_parent{};
        tree_node* insert_node(_root);
        std::size_t traverse_index{};
        std::size_t tree_node_index{};
        bool left_child_insert{};
        while(insert_node)
        {
            tree_node_index=traverse_index
                            +insert_node->_left_subtree_size;
            insert_node_parent=insert_node;
            if(tree_node_index>=source_index)
            {
                ++insert_node->_left_subtree_size;
                insert_node=insert_node->_left_child;
                left_child_insert=true;
            }

            else
            {
                traverse_index=tree_node_index
                               +static_cast<std::size_t>(1);
                insert_node=insert_node->_right_child;
                left_child_insert=false;
            }
        }

        insert_node=_tree_node_allocator.allocate(static_cast<std::size_t>(1));
        std::allocator_traits<allocator_type<tree_node>>::construct(_tree_node_allocator,
                                                                    insert_node,
                                                                    insert_node_parent,
                                                                    std::forward<argument_types>(source_arguments)...);
        if(!_root)
        {
            _root=insert_node;
            _auxiliary._left_child=_root;
            _auxiliary._right_child=_root;
        }

        else if(left_child_insert)
        {
            insert_node_parent->_left_child=insert_node;
            if(insert_node_parent==_auxiliary._left_child)
            {
                _auxiliary._left_child=insert_node;
            }
        }

        else
        {
            insert_node_parent->_right_child=insert_node;
            if(insert_node_parent==_auxiliary._right_child)
            {
                _auxiliary._right_child=insert_node;
            }
        }

        ++_size;

        rebalance_tree(insert_node);

        return tree_node_iterator(insert_node);
    }

    tree_node* find(const std::size_t source_index)
    {
        if(source_index>=_size)
        {
            return nullptr;
        }

        tree_node* find_node(_root);
        std::size_t traverse_index{};
        std::size_t tree_node_index{};
        while(find_node)
        {
            tree_node_index=traverse_index
                            +find_node->_left_subtree_size;
            if(tree_node_index>source_index)
            {
                find_node=find_node->_left_child;
            }

            else if(tree_node_index<source_index)
            {
                traverse_index=tree_node_index
                               +static_cast<std::size_t>(1);
                find_node=find_node->_right_child;
            }

            else
            {
                break;
            }
        }

        return find_node;
    }

    const tree_node* find(const std::size_t source_index) const
    {
        if(source_index>=_size)
        {
            return nullptr;
        }

        const tree_node* find_node(_root);
        std::size_t traverse_index{};
        std::size_t tree_node_index{};
        while(find_node)
        {
            tree_node_index=traverse_index
                            +find_node->_left_subtree_size;
            if(tree_node_index>source_index)
            {
                find_node=find_node->_left_child;
            }

            else if(tree_node_index<source_index)
            {
                traverse_index=tree_node_index
                               +static_cast<std::size_t>(1);
                find_node=find_node->_right_child;
            }

            else
            {
                break;
            }
        }

        return find_node;
    }

    void transfer_auxiliary(const tree_node* const source_node,
                            tree_node* const source_node_parent)
    {
        if(source_node==_auxiliary._left_child)
        {
            if(source_node_parent)
            {
                _auxiliary._left_child=source_node_parent->_left_child
                                       ?source_node_parent->_left_child
                                       :source_node_parent;
            }

            else
            {
                _auxiliary._left_child=_root;
            }
        }

        if(source_node==_auxiliary._right_child)
        {
            if(source_node_parent)
            {
                _auxiliary._right_child=source_node_parent->_right_child
                                        ?source_node_parent->_right_child
                                        :source_node_parent;
            }

            else
            {
                _auxiliary._right_child=_root;
            }
        }
    }

    void calculate_height(tree_node* const source_node)
    {
        std::ptrdiff_t left_height(static_cast<std::ptrdiff_t>(-1));
        std::ptrdiff_t right_height(static_cast<std::ptrdiff_t>(-1));

        if(source_node->_left_child)
        {
            left_height=source_node->_left_child->_height;
        }

        if(source_node->_right_child)
        {
            right_height=source_node->_right_child->_height;
        }

        source_node->_height=std::max(left_height,
                                      right_height)
                             +static_cast<std::ptrdiff_t>(1);
    }

    tree_node* left_rotate(tree_node* const source_node)
    {
        tree_node* const rotate_node(source_node->_right_child);
        transfer_node(source_node,
                      source_node->_parent,
                      rotate_node);

        source_node->_right_child=rotate_node->_left_child;
        if(source_node->_right_child)
        {
            source_node->_right_child->_parent=source_node;
        }

        calculate_height(source_node);

        rotate_node->_left_child=source_node;
        rotate_node->_left_child->_parent=rotate_node;
        rotate_node->_left_subtree_size=source_node->_left_subtree_size
                                        +rotate_node->_left_subtree_size
                                        +static_cast<std::size_t>(1);
        calculate_height(rotate_node);

        return rotate_node;
    }

    tree_node* right_rotate(tree_node* const source_node)
    {
        tree_node* const rotate_node(source_node->_left_child);
        transfer_node(source_node,
                      source_node->_parent,
                      rotate_node);

        source_node->_left_child=rotate_node->_right_child;
        if(source_node->_left_child)
        {
            source_node->_left_child->_parent=source_node;
        }

        source_node->_left_subtree_size=source_node->_left_subtree_size
                                        -rotate_node->_left_subtree_size
                                        -static_cast<std::size_t>(1);
        calculate_height(source_node);

        rotate_node->_right_child=source_node;
        rotate_node->_right_child->_parent=rotate_node;
        calculate_height(rotate_node);

        return rotate_node;
    }

    void rebalance_tree(tree_node* source_node)
    {
        std::ptrdiff_t left_height{};
        std::ptrdiff_t right_height{};
        std::ptrdiff_t balance_factor{};
        while(source_node)
        {
            calculate_height(source_node);

            left_height=source_node->_left_child
                        ?source_node->_left_child->_height
                        +static_cast<std::ptrdiff_t>(1)
                        :std::ptrdiff_t();
            right_height=source_node->_right_child
                         ?source_node->_right_child->_height
                         +static_cast<std::ptrdiff_t>(1)
                         :std::ptrdiff_t();
            balance_factor=left_height
                           -right_height;

            if(balance_factor>static_cast<std::ptrdiff_t>(1))
            {
                if(source_node->_left_child->_left_child)
                {
                    source_node=right_rotate(source_node);
                }

                else
                {
                    left_rotate(source_node->_left_child);
                    source_node=right_rotate(source_node);
                }
            }

            else if(balance_factor<static_cast<std::ptrdiff_t>(-1))
            {
                if(source_node->_right_child->_right_child)
                {
                    source_node=left_rotate(source_node);
                }

                else
                {
                    right_rotate(source_node->_right_child);
                    source_node=left_rotate(source_node);
                }
            }

            source_node=source_node->_parent;
        }
    }

    public:
        using const_iterator=tree_node_const_iterator;
        using const_reverse_iterator=tree_node_const_reverse_iterator;
        using iterator=tree_node_iterator;
        using reverse_iterator=tree_node_reverse_iterator;

        tree_vector():_tree_node_allocator(),
                      _auxiliary(),
                      _root(),
                      _size(){}

        tree_vector(const tree_vector& source_tree_vector):_tree_node_allocator(source_tree_vector._tree_node_allocator),
                                                           _auxiliary(),
                                                           _root(copy_tree(source_tree_vector._root)),
                                                           _size(source_tree_vector._size){}

        tree_vector(tree_vector&& source_tree_vector):tree_vector()
        {
            swap(source_tree_vector);
        }

        tree_vector(const std::initializer_list<const value_type>& source_initializer_list):tree_vector()
        {
            copy_values(source_initializer_list);
        }

        template<typename iterator_type,
                 typename std::enable_if<!std::is_integral<iterator_type>::value,
                                         bool>::type=true>
        tree_vector(iterator_type source_begin_iterator,
                    iterator_type source_end_iterator):tree_vector()
        {
            copy_values(source_begin_iterator,
                        source_end_iterator);
        }

        tree_vector(const std::size_t source_value_count):tree_vector(source_value_count,
                                                                      value_type()){}

        tree_vector(const std::size_t source_value_count,
                    const value_type& source_value):tree_vector()
        {
            copy_values(source_value_count,
                        source_value);
        }

        ~tree_vector()
        {
            clear_tree();
        }

        tree_vector& operator=(const tree_vector& source_tree_vector)
        {
            _tree_node_allocator=source_tree_vector._tree_node_allocator;
            _size=source_tree_vector._size;

            if(!_root)
            {
                _root=copy_tree(source_tree_vector._root);
            }

            else
            {
                assign_tree(source_tree_vector._root);
            }

            return *this;
        }

        tree_vector& operator=(tree_vector&& source_tree_vector)
        {
            swap(source_tree_vector);

            return *this;
        }

        tree_vector& operator=(const std::initializer_list<const value_type> source_initializer_list)
        {
            clear();
            copy_values(source_initializer_list);

            return *this;
        }

        void assign(const std::size_t source_value_count,
                    const value_type& source_value)
        {
            clear();
            copy_values(source_value_count,
                        source_value);
        }

        template<typename iterator_type,
                 typename std::enable_if<!std::is_integral<iterator_type>::value,
                                         bool>::type=true>
        void assign(iterator_type source_begin_iterator,
                    iterator_type source_end_iterator)
        {
            clear();
            copy_values(source_begin_iterator,
                        source_end_iterator);
        }

        bool operator<(const tree_vector& source_tree_vector) const
        {
            for(const_iterator begin_iterator(cbegin()),
                source_begin_iterator(source_tree_vector.cbegin());
                begin_iterator!=cend()
                &&source_begin_iterator!=source_tree_vector.cend();
                ++begin_iterator,
                ++source_begin_iterator)
            {
                if((*begin_iterator)<(*source_begin_iterator))
                {
                    return true;
                }
            }

            return _size<source_tree_vector._size;
        }

        bool operator>(const tree_vector& source_tree_vector) const
        {
            return source_tree_vector<(*this);
        }

        bool operator<=(const tree_vector& source_tree_vector) const
        {
            return !((*this)>source_tree_vector);
        }

        bool operator>=(const tree_vector& source_tree_vector) const
        {
            return !((*this)<source_tree_vector);
        }

        bool operator==(const tree_vector& source_tree_vector) const
        {
            if(_size!=source_tree_vector._size)
            {
                return false;
            }

            for(const_iterator begin_iterator(cbegin()),
                source_begin_iterator(source_tree_vector.cbegin());
                begin_iterator!=cend();
                ++begin_iterator,
                ++source_begin_iterator)
            {
                if((*begin_iterator)!=(*source_begin_iterator))
                {
                    return false;
                }
            }

            return true;
        }

        bool operator!=(const tree_vector& source_tree_vector) const
        {
            return !((*this)==source_tree_vector);
        }

        template<typename forward_value_type>
        iterator insert(const std::size_t source_index,
                        forward_value_type&& source_value)
        {
            return forward_insert(source_index,
                                  std::forward<forward_value_type>(source_value));
        }

        iterator insert(const std::size_t source_index,
                        const std::size_t source_value_count,
                        const value_type& source_value)
        {
            if(!source_value_count)
            {
                return end();
            }

            const iterator insert_iterator(forward_insert(source_index,
                                                          source_value));
            for(std::size_t source_value_counter(static_cast<std::size_t>(1));
                source_value_counter<source_value_count;
                ++source_value_counter)
            {
                forward_insert(source_index,
                               source_value);
            }

            return insert_iterator;
        }

        iterator insert(const std::size_t source_index,
                        const std::initializer_list<const value_type> source_initializer_list)
        {
            typename std::initializer_list<const value_type>::iterator source_begin_iterator(source_initializer_list.begin());
            if(source_begin_iterator==source_initializer_list.end())
            {
                return end();
            }

            const iterator insert_iterator(forward_insert(source_index,
                                                         (*(source_begin_iterator++))));
            for(;
                source_begin_iterator!=source_initializer_list.end();
                ++source_begin_iterator)
            {
                forward_insert(source_index,
                               *source_begin_iterator);
            }

            return insert_iterator;
        }

        template<typename iterator_type,
                 typename std::enable_if<!std::is_integral<iterator_type>::value,
                                         bool>::type=true>
        iterator insert(const std::size_t source_index,
                        iterator_type source_begin_iterator,
                        iterator_type source_end_iterator)
        {
            if(source_begin_iterator==source_end_iterator)
            {
                return end();
            }

            const iterator insert_iterator(forward_insert(source_index,
                                                         (*(source_begin_iterator++))));
            for(;
                source_begin_iterator!=source_end_iterator;
                ++source_begin_iterator)
            {
                forward_insert(source_index,
                               *source_begin_iterator);
            }

            return insert_iterator;
        }

        template<typename forward_value_type>
        void push_front(forward_value_type&& source_value)
        {
            forward_insert(std::size_t(),
                           std::forward<forward_value_type>(source_value));
        }

        template<typename forward_value_type>
        void push_back(forward_value_type&& source_value)
        {
            forward_insert(_size,
                           std::forward<forward_value_type>(source_value));
        }

        template<typename... argument_types>
        iterator emplace(const std::size_t source_index,
                         argument_types&&... source_arguments)
        {
            return forward_insert(source_index,
                                  std::forward<argument_types>(source_arguments)...);
        }

        template<typename... argument_types>
        void emplace_front(argument_types&&... source_arguments)
        {
            forward_insert(std::size_t(),
                           std::forward<argument_types>(source_arguments)...);
        }

        template<typename... argument_types>
        void emplace_back(argument_types&&... source_arguments)
        {
            forward_insert(_size,
                           std::forward<argument_types>(source_arguments)...);
        }

        const value_type& operator[](const std::size_t source_index) const
        {
            return find(source_index)->_value;
        }

        value_type& operator[](const std::size_t source_index)
        {
            return find(source_index)->_value;
        }

        const value_type& at(const std::size_t source_index) const
        {
            if(source_index>=_size)
            {
                throw std::out_of_range("tree_vector::at() const");
            }

            return find(source_index)->_value;
        }

        value_type& at(const std::size_t source_index)
        {
            if(source_index>=_size)
            {
                throw std::out_of_range("tree_vector::at()");
            }

            return find(source_index)->_value;
        }

        bool contains(const std::size_t source_index) const
        {
            return source_index<_size;
        }

        bool empty() const
        {
            return !static_cast<bool>(_root);
        }

        iterator erase(const std::size_t source_index)
        {
            if(!_root
               ||source_index>=_size)
            {
                return end();
            }

            tree_node* erase_node_parent{};
            tree_node* erase_node(_root);
            std::size_t traverse_index{};
            std::size_t tree_node_index(erase_node->_left_subtree_size);
            while(tree_node_index!=source_index)
            {
                erase_node_parent=erase_node;
                if(tree_node_index>source_index)
                {
                    --erase_node->_left_subtree_size;
                    erase_node=erase_node->_left_child;
                }

                else
                {
                    traverse_index=tree_node_index
                                   +static_cast<std::size_t>(1);
                    erase_node=erase_node->_right_child;
                }

                tree_node_index=traverse_index
                                +erase_node->_left_subtree_size;
            }

            iterator erase_iterator(erase_node);
            ++erase_iterator;

            tree_node* rebalance_node{};
            if(!erase_node->_left_child)
            {
                rebalance_node=erase_node->_right_child
                               ?erase_node->_right_child
                               :erase_node_parent;

                transfer_node(erase_node,
                              erase_node_parent,
                              erase_node->_right_child);
                transfer_auxiliary(erase_node,
                                   erase_node_parent);
            }

            else if(!erase_node->_right_child)
            {
                rebalance_node=erase_node->_left_child
                               ?erase_node->_left_child
                               :erase_node_parent;

                transfer_node(erase_node,
                              erase_node_parent,
                              erase_node->_left_child);
                transfer_auxiliary(erase_node,
                                   erase_node_parent);
            }

            else
            {
                tree_node* successor_node(erase_node->_right_child);
                while(successor_node->_left_child)
                {
                    --successor_node->_left_subtree_size;
                    successor_node=successor_node->_left_child;
                }

                rebalance_node=successor_node;
                if(successor_node!=erase_node->_right_child)
                {
                    rebalance_node=successor_node->_right_child
                                   ?successor_node->_right_child
                                   :successor_node->_parent;

                    transfer_node(successor_node,
                                  successor_node->_parent,
                                  successor_node->_right_child);
                    successor_node->_right_child=erase_node->_right_child;
                    successor_node->_right_child->_parent=successor_node;
                }

                transfer_node(erase_node,
                              erase_node_parent,
                              successor_node);
                successor_node->_left_child=erase_node->_left_child;
                successor_node->_left_child->_parent=successor_node;
                successor_node->_left_subtree_size=erase_node->_left_subtree_size;
            }

            destruct_node(erase_node);

            --_size;

            rebalance_tree(rebalance_node);

            return erase_iterator;
        }

        iterator erase(const std::size_t source_begin_index,
                       const std::size_t source_end_index)
        {
            if(source_begin_index>=source_end_index)
            {
                return end();
            }

            for(std::size_t source_traverse_index(source_end_index
                                                  -static_cast<std::size_t>(1));
                source_traverse_index>source_begin_index;
                --source_traverse_index)
            {
                erase(source_traverse_index);
            }

            return erase(source_begin_index);
        }

        void pop_front()
        {
            erase(std::size_t());
        }

        void pop_back()
        {
            erase(_size
                  -static_cast<std::size_t>(1));
        }

        void clear()
        {
            clear_tree();
            _tree_node_allocator=allocator_type<tree_node>();
            _auxiliary._left_child=nullptr;
            _auxiliary._right_child=nullptr;
            _root=nullptr;
            _size=std::size_t();
        }

        std::size_t size() const
        {
            return _size;
        }

        std::size_t max_size() const
        {
            return std::numeric_limits<std::size_t>::max()
                   /sizeof(tree_node);
        }

        const value_type& front() const
        {
            return _auxiliary._left_child->_value;
        }

        value_type& front()
        {
            return _auxiliary._left_child->_value;
        }

        const value_type& back() const
        {
            return _auxiliary._right_child->_value;
        }

        value_type& back()
        {
            return _auxiliary._right_child->_value;
        }

        const_iterator cbegin() const
        {
            return const_iterator(_auxiliary._left_child);
        }

        const_iterator begin() const
        {
            return const_iterator(_auxiliary._left_child);
        }

        iterator begin()
        {
            return iterator(_auxiliary._left_child);
        }

        const_iterator cend() const
        {
            return const_iterator();
        }

        const_iterator end() const
        {
            return const_iterator();
        }

        iterator end()
        {
            return iterator();
        }

        const_reverse_iterator crbegin() const
        {
            return const_reverse_iterator(_auxiliary._right_child);
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(_auxiliary._right_child);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(_auxiliary._right_child);
        }

        const_reverse_iterator crend() const
        {
            return const_reverse_iterator();
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator();
        }

        reverse_iterator rend()
        {
            return reverse_iterator();
        }

        void swap(tree_vector& source_tree_vector)
        {
            std::swap(_tree_node_allocator,
                      source_tree_vector._tree_node_allocator);
            std::swap(_auxiliary,
                      source_tree_vector._auxiliary);
            std::swap(_root,
                      source_tree_vector._root);
            std::swap(_size,
                      source_tree_vector._size);
        }
};

#endif
