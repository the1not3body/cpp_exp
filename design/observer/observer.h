#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>
#include <memory>
#include <iostream>
#include <mutex>
#include <unordered_set>
#include <unordered_map>

struct Event {
    std::string topic;
    int value;
    Event(std::string topic, int value) : topic(topic), value(value) {}
};

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(Event* event) = 0;
};

class EventBus {
public:
    virtual ~EventBus() = default;
    virtual void subscribe(const std::string topic, const std::shared_ptr<Observer> o) = 0;
    virtual void unsubcribe(const std::string topic, const std::shared_ptr<Observer> o) = 0;   
    virtual void notify(Event* event) = 0;
};  

class BaseObserver : public Observer {
public:
    BaseObserver(std::string name) : name(name) {}
    void update(Event* event) {
        printf("obsever name %s, event key %s, event val: %d\n", 
            name.c_str(), event->topic.c_str(), event->value); 
    }
private:
   std::string name;
};


class BaseEventBus : public EventBus {
public:
    void subscribe(const std::string topic, const std::shared_ptr<Observer> o) override {
        std::unique_lock<std::mutex> locker(mux);
        obs[topic].insert(o);
    }

    void unsubcribe(const std::string topic, const std::shared_ptr<Observer> o) override {
        std::unique_lock<std::mutex> locker(this->mux);
        if (obs.find(topic) != obs.end()) {
            obs[topic].erase(o);
        }
        if (!obs[topic].empty()) {
            obs.erase(topic);
        }
    }

    void notify(Event *event)override {
        std::unordered_set<std::shared_ptr<Observer>> subscribers;
        {
            std::unique_lock<std::mutex> locker(this->mux);
            if (obs.find(event->topic) == obs.end()) return;
            subscribers = obs[event->topic];
        }
        auto it = subscribers.begin();
        while (it != subscribers.end()) {
            (*it++)->update(event);
        }

    }
protected:
    std::mutex mux;
    std::unordered_map<std::string, std::unordered_set<std::shared_ptr<Observer>> > obs;
};

#endif