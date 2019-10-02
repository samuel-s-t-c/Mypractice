#ifndef FOLDERH
#define FOLDERH

#include <set>

class Message;
class Folder {
  friend class Message;
  friend void swap(Message &lhs, Message &rhs);
public:
  //constructor
  Folder() = default;
  Folder(const Folder &f);
  //destructor
  ~Folder();

  //
  void add(Message&m);
  void remove(Message&m);
  void print();

private:
  std::set<Message*> set_ptr_msg;

  void add_Messages(const Folder&);
  void remove_Messages();
  void addMsg(Message *msg);
  void remMsg(Message *msg);

};

#endif
