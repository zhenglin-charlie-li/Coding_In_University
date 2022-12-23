public class Queue {
    private int[] elements = null;
    private int size = 0;

    public Queue() {
        this.elements = new int[8];
    }

    public int enqueue(int toAdd) {
        if (this.empty()) {
            elements[0] = toAdd;
            size++;
            return 0;
        } else {
            if (elements[elements.length - 1] == 0) {
                int i;
                for (i = elements.length - 2; i >= 0; i--) {
                    if (elements[i] != 0) {
                        elements[i + 1] = toAdd;
                        size++;
                        break;
                    }
                }
                return i + 1;
            } else {
                int[] newElements = new int[size * 2];
                for (int i = 0; i < size; i++) {
                    newElements[i] = elements[i];
                }
                elements = newElements;
                elements[size] = toAdd;
                size++;
                return size;
            }
        }

    }

    public int dequeue() {
        int res = elements[0];
        for (int i = 0; i < elements.length-1; i++) {
            elements[i] = elements[i + 1];
        }
        elements[elements.length-1] = 0;
        size--;
        return res;
    }

    public boolean empty() {
        return size == 0;
    }

    public int getSize() {
        return size;
    }

    public void print() {
        for (int i = 0; i < size; i++) {
            System.out.print(elements[i]+" ");
        }
    }
}

