#include<queue>
void reverseQueue(queue<int> &input) {
	if (input.size() == 0) {
		return;
	}
	int temp = input.front();
	input.pop();
	reverseQueue(input);
	input.push(temp);
}