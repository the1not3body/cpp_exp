#include "observer.h"

int main() {
    std::shared_ptr<Observer> o1 = std::make_shared<BaseObserver>("a1");
    std::shared_ptr<Observer> o2 = std::make_shared<BaseObserver>("b2");
    std::shared_ptr<Observer> o3 = std::make_shared<BaseObserver>("c3");
    std::shared_ptr<Observer> o4 = std::make_shared<BaseObserver>("d4");

    std::shared_ptr<EventBus> subs = std::make_shared<BaseEventBus>();
    std::string topic = "why u make urself so hard";
    subs->subscribe(topic, o1);
    subs->subscribe(topic, o2);
    subs->subscribe(topic, o3);
    subs->subscribe(topic, o4);
    Event* e = new Event(topic, 2);
    subs->notify(e);

    return 0;
}