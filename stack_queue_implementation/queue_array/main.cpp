#include "queue.h"
#include "recursive_queue.h"

#include <iostream>

using namespace std;

// uncomment below line to use recursive queue
using namespace queue;
// uncomment below line to use non-recursive queue
// using namespace recursive_queue;

int main() {
	int option = -1;
	do {
		cout << "---------------------QUEUE ARRAY---------------------" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Khoi tao Queue" << endl;
		cout << "2. Copy Queue" << endl;
		cout << "3. Giai phong Queue" << endl;
		cout << "4. Kiem tra Queue co rong hay khong" << endl;
		cout << "5. Enqueue vao Queue" << endl;
		cout << "6. Dequeue khoi Queue" << endl;
		cout << "7. Lay gia tri dau Queue" << endl;
		cout << "8. In Queue" << endl;

		Queue<int> q;
		Queue<int> q1;

		cout << "Nhap vao lua chon cua ban: ";
		cin >> option;

		switch (option) {
			case 0:
				cout << "Ket thuc chuong trinh" << endl;
				break;
			case 1: {
				unsigned int queueSize;
				cout << "Nhap vao kich thuoc Queue: ";
				cin >> queueSize;

				q.init(queueSize);
				break;
			}
			case 2: {
				Queue<int> q1;
				q1.init(q.maxSize);
				q1.copyQueue(q);
				break;
			}
			case 3: {
				q.release();
				break;
			}
			case 4: {
				if (q.isEmpty()) {
					cout << "Queue rong" << endl;
				}
				else {
					cout << "Queue khong rong" << endl;
				}
				break;
			}
			case 5: {
				int newItem;
				cout << "Nhap vao gia tri can enqueue: ";
				cin >> newItem;
				q.enqueue(newItem);
				break;
			}
			case 6: {
				int item = q.dequeue();
				cout << "Gia tri dequeue: " << item << endl;
				break;
			}
			case 7: {
				int item = q.frontValue();
				cout << "Gia tri dau Queue: " << item << endl;
				break;
			}
			case 8: {
				q.print();
				break;
			}
			default:
				cout << "Lua chon khong hop le" << endl;
				break;
		}
	} while (option != 0);

	return 0;
}