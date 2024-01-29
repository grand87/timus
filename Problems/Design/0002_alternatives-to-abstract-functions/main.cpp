#include <iostream>
#include <functional>
#include <queue>
#include <map>

using namespace std;

class Packet;

int defaultPriorityCalculator(const Packet& aPacket);

class Packet {
public:
    typedef function<int (const Packet& )> PacketProcessor;

private:
    int id;
    int callCount;
    PacketProcessor& callCounter;
    PacketProcessor priorityProvider;

protected:
    Packet& operator=(const Packet& aShape);

public:
    explicit Packet(int aId, PacketProcessor &counter, PacketProcessor aPriorityProvider = defaultPriorityCalculator)
        : id{ aId }
        , callCount{ 0 }
        , callCounter{ counter }
        , priorityProvider{ aPriorityProvider } {

    }

    int getId() const {
        return id;
    }

    int getPriority() const {
        callCounter(*this);
        return priorityProvider(*this);
    }

    void setPriorityProvider(PacketProcessor& aPriorityProvider) {
        priorityProvider = aPriorityProvider;
    }

    virtual ~Packet() = 0 {

    }
};

int defaultPriorityCalculator(const Packet& aPacket) {
    return aPacket.getId() + 15;
}

class RectPacket : public Packet {

public:
    RectPacket(int aId, PacketProcessor &counter, PacketProcessor aPriorityProvider = defaultPriorityCalculator)
        : Packet(aId, counter, aPriorityProvider) {

    }

    RectPacket& operator=(const RectPacket& aRect) {
        RectPacket::operator=(aRect);
        //cusotm fields assignment

        return *this;
    }

    virtual ~RectPacket() {

    }
};

class CirclePacket : public Packet {

public:
    CirclePacket(int aId, PacketProcessor &counter, PacketProcessor aPriorityProvider = defaultPriorityCalculator)
        : Packet(aId, counter, aPriorityProvider) {

    }

    CirclePacket& operator=(const CirclePacket& aRect) {
        CirclePacket::operator=(aRect);
        //cusotm fields assignment

        return *this;
    }

    virtual ~CirclePacket() {

    }
};

class PacketComparatror {
public:
    bool operator() (const Packet* l, const Packet* r) {
        return l->getPriority() < r->getPriority();
    }
};

class PacketSubmitter {
    priority_queue<Packet*, vector<Packet*>, PacketComparatror> packetsQueue;

public:
    void add(Packet* packet) {
        packetsQueue.push(packet);
    }

    void submit() {
        if (!packetsQueue.empty()) {
            Packet* p = packetsQueue.top();
            packetsQueue.pop();
            cout << "submited packet " << p->getId() << " wiht priority " << p->getPriority() << endl;
        }
    }
};

class PacketQueriesCounter {
    map<int, int> queries;
public:

    int operator()(const Packet& packet) {
        queries[packet.getId()]++;
        return queries[packet.getId()];
    }

    int count (const Packet& packet) {
        queries[packet.getId()]++;
        return queries[packet.getId()];
    }

    void dump(ostream& stream) {
        stream << queries.size() << endl;
    }

};

int calcPriority(const Packet& packet) {
    return (packet.getId() % 8) * 6;
}

int calcPriority2(const Packet& packet) {
    return (packet.getId() % 17) * 3;
}

int test(const Packet& p) {
    return 50;
}

class Application {
public:
    typedef function<int(const Packet&)> PacketProcessor;

    void add(Packet* p) {

    }

    void submit(Packet* p) {

    }
};


void main() {
    PacketQueriesCounter counter;
    std::function<int(const Packet&)> countCallsFunctor2 = counter;

    Packet* packets[100];
    for (int i = 0; i < 100; i++) {
        if(i % 2 == 0) {
            packets[i] = new RectPacket(i * 10 + 50, countCallsFunctor2, calcPriority);
        } else {
            packets[i] = new CirclePacket(i * 10 + i, countCallsFunctor2, calcPriority2);
        }
    }

    PacketSubmitter s;

    for (int i = 0; i < 100; i++) {
        s.add(packets[i]);
        if (i % 20 == 0) {
            s.submit();
        }
    }

    for (int i = 0; i < 100; i++) {
        s.submit();
    }

    counter.dump(cout);
}
