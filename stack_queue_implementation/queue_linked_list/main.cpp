#include "queue_linked_list.h"
#include "recursive_queue_linked_list.h"

// uncomment below line to use recursive queue
using namespace queue_linked_list;
// uncomment below line to use non-recursive queue
// using namespace recursive_queue_linked_list;


int main() {
	Queue<int> q;
	Queue<int> q1;


	int option = -1;
	do {
		cout << "---------------------QUEUE LINKED LIST---------------------" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Khoi tao Queue" << endl;
		cout << "2. Copy Queue" << endl;
		cout << "3. Giai phong Queue" << endl;
		cout << "4. Kiem tra Queue co rong hay khong" << endl;
		cout << "5. Enqueue vao Queue" << endl;
		cout << "6. Dequeue khoi Queue" << endl;
		cout << "7. Lay gia tri dau Queue" << endl;
		cout << "8. In Queue" << endl;

		cout << "Nhap vao lua chon cua ban: ";
		cin >> option;

		switch (option) {
			case 0:
				cout << "Ket thuc chuong trinh" << endl;
				break;
			case 1: {
				q.init();
				break;
			}
			case 2: {
				q1.init();
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
				cout << "Gia tri bi dequeue: " << q.dequeue() << endl;
				break;
			}
			case 7: {
				cout << "Gia tri dau Queue: " << q.frontValue() << endl;
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