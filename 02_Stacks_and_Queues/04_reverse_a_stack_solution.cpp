void reverseStack(stack<int> &input, stack<int> &extra) {
    int n = input.size();

    int pop_count = n;

    while (pop_count--) {
        int temp = input.top();
        input.pop();
        int count = pop_count;
        while (count--) {
            int temp1 = input.top();
            input.pop();
            extra.push(temp1);
        }
        input.push(temp);
        while (!extra.empty()) {
            int temp2 = extra.top();
            extra.pop();
            input.push(temp2);
        }
    } 
}