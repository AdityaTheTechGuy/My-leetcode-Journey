/*
# A Craftsman's Guide to Choosing a C++ Container

This guide is a simple mental model. To pick the right tool, you only need to answer one or two questions.

---

## 1. Do you need a simple list of items?

Nine times out of ten, the answer is **`vector`**.

A **`vector`** is your reliable, all-purpose workbench. It's fast, strong, and you can grab any element instantly using `[]`. It should be the first tool you reach for when you need a list.

**Only consider something else if you have a special need:**
* Do you need to add and remove items from the **front** of the list just as often as the back?
    * Use a **`deque`**. It's a vector that's fast at both ends.
* Do you have a massive list and need to constantly insert and delete items from the **middle**?
    * Use a **`list`**. It's slower to find items, but once you find a spot, modifying it is instant.

**Rule of Thumb:** When in doubt, start with a `vector`.

---

## 2. Do you need a dictionary to look things up?

This is for when you need to store pairs of things, a `key` and its `value`. Your default choice should always be **`unordered_map`**.

An **`unordered_map`** is your lightning-fast lookup tool. You give it a key, and it gives you the value in what feels like instant time. The trade-off is that it's messy inside—the keys are not kept in any sorted order.

**Only consider something else if you have a special need:**
* Do you absolutely need your dictionary to be automatically **sorted by its keys**?
    * Use a **`map`**. It's a bit slower, but it keeps everything in perfect order.

**Rule of Thumb:** For pure speed and general dictionary use, always start with `unordered_map`.

---

## 3. Do you just need to store unique items?

This is for when you only care about whether you've "seen" something before, and you don't want duplicates. Your default choice should be **`unordered_set`**.

An **`unordered_set`** is your magical bag for unique items. You can throw things in, but it will never keep a duplicate. It's the fastest way to check if an item already exists in your collection.

**Only consider something else if you have a special need:**
* Do you need your unique items to be automatically **sorted**?
    * Use a **`set`**.

**Rule of Thumb:** For just checking if an item exists, `unordered_set` is your go-to.

---

## 4. Does your list have a special access rule?

If your problem follows a strict pattern of adding and removing, use one of these special-purpose tools.

* **Last one in is the first one out?**
    * Use a **`stack`**. (Analogy: a stack of plates).
* **First one in is the first one out?**
    * Use a **`queue`**. (Analogy: a line for tickets).
* **The most important one is always at the front?**
    * Use a **`priority_queue`**. (Analogy: a VIP line).
*/