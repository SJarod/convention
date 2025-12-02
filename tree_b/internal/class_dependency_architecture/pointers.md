**Pointers**

**unique_ptr :**
a class depends on another and has the ownership over the other if it is composed using a unique pointer
- has ownership of the object
- manages the object's memory and lifetime

**shared_ptr :**
same but has shared ownership
- shares the object's ownership
- lifetime and memory is automatically destroyed

**raw pointer :**
possible aggregation
a class depends on an "optional" instance, the pointer can be nulled, pointers can be passed in constructors or methods
- should not own the object (~~new~~)
- shoult not delete
- passed for doing something without having **ownership**

**weak_ptr :**
possible aggregation
- similar to the raw pointer

**raw object :**
classical composition, compared to unique pointers, objects can be copied
- allocated on the stack
- "ownership"
- used for composition

**object reference :**
compared to raw pointers, references cannot be nulled, the calss has no ownership
- cannot be null
- lifetime is managed somewhere else