class MyStack {
private:
    queue<int> queue;

public:
    MyStack() {}

    void push(int x) {
        queue.push(x);
        for (int i = 1; i < queue.size(); i++) {
            queue.push(queue.front());
            queue.pop();
        }
    }

    int pop() {
        int top = queue.front();
        queue.pop();
        return top;
    }

    int top() { return queue.front(); }

    bool empty() { return queue.empty(); }
};
