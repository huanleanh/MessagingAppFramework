#ifndef MESSAGE_H
#define MESSAGE_H

#include <typeindex>
#include <memory>

namespace maf {
namespace messaging {

class MessageBase;
template <typename Msg> using MessagePtr = std::shared_ptr<Msg>;
template <typename Msg> using CMessagePtr = const std::shared_ptr<Msg>;
using MessageBasePtr = MessagePtr<MessageBase>;
using CMessageBasePtr = CMessagePtr<MessageBase>;
template<class Msg, typename... Args>
MessagePtr<Msg> createMessage(Args&&... args) { return std::make_shared<Msg>(std::forward<Args>(args)...); }

class MessageBase
{
public:
    using Type = std::type_index;
    virtual ~MessageBase();
    virtual Type id() const;
    template<typename T> static Type idof() { return typeid (T); }
    template<typename T> static Type idof(const T& obj) { return typeid (obj); }
    int priority() const;
    void setPriority(int p);

    struct PriorityComp
    {
        bool operator()(CMessageBasePtr m1, CMessageBasePtr m2)
        {
            return m1->priority() < m2->priority();
        }
    };

private:
    int _priority = 0;
};



}
}
#endif // MESSAGE_H
