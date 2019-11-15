import javax.net.ssl.SSLServerSocket;

public class SLLSet {
    private int setSize;
    private SLLNode head;
    public SLLSet(){
        this.head = new SLLNode(0, null);
        this.setSize = 0;
    }
    public SLLSet(int[] sortedArray){
        this();
        int i = 0;
        for (SLLNode curr = this.head; i<sortedArray.length; curr = curr.next) {
            curr.value = sortedArray[i];
            if(i+1<sortedArray.length)
                curr.next = new SLLNode(0, null);
            i++; this.setSize++;
        }
    }
    public int getSize(){ return this.setSize; }
    public SLLSet copy() {
        int[] arr = new int[this.setSize];
        SLLNode currentNode = this.head;
        int i = 0;
        for (SLLNode curr = this.head; i<arr.length; curr = curr.next) {
            arr[i] = curr.value;
            i++;
        }
        return new SLLSet(arr);
    }
    public boolean isIn(int v){
        if (head == null) {
            return false;
        }else{
            for (SLLNode curr = this.head; curr != null; curr = curr.next) {
                if (curr.value == v) {
                    return true;
                }
                this.setSize++;
            }
        }
        return false;
    }

    public void add(int v){
        if(!(isIn(v))){
            int i = 0;
            for (SLLNode curr = this.head; i<this.setSize; curr = curr.next) {
                if(v>curr.next.value){
                    curr.next = new SLLNode(v, curr.next);
                }
                i++; this.setSize++;
            }
        }
    }

    public void remove(int v){
        if(!(this.isIn(v))){
            int i = 0;
            for (SLLNode curr = this.head; i<this.setSize; curr = curr.next) {
                if(curr.next.value == v) {
                    curr.next = curr.next.next;
                }
                i++; this.setSize++;
            }
        }
    }

    public SLLSet union(SLLSet s){
        SLLSet newSet = new SLLSet();
        SLLNode firstNode = this.head;
        SLLNode secondNode = s.head;
        SLLNode newNode = newSet.head;
        while(firstNode.next != null && secondNode.next != null) {
            if (firstNode.value == secondNode.value){
                newNode.value = firstNode.value;
                firstNode = firstNode.next;
                secondNode = secondNode.next;
            }else if(firstNode.value < secondNode.value) {
                newNode.value = firstNode.value;
                firstNode = firstNode.next;
            }else{
                newNode.value = secondNode.value;
                secondNode = secondNode.next;
            }
            newSet.setSize++;
            newNode.next = new SLLNode(0, null);
            newNode = newNode.next;

        }
        int temp = secondNode.value;
        while(firstNode.next != null){
            if(temp <= firstNode.value){
                newNode.value = temp;
                temp = Integer.MAX_VALUE;
                newSet.setSize++;
                newNode.next = new SLLNode(0, null);
                newNode = newNode.next;
                firstNode = firstNode.next;
            }else if(firstNode.next != null){
                newNode.value = firstNode.value;
                newSet.setSize++;
                newNode.next = new SLLNode(0, null);
                newNode = newNode.next;
                firstNode = firstNode.next;
            }
            if(firstNode.next == null){
                newNode.value = firstNode.value;
                newSet.setSize++;
                if(temp != Integer.MAX_VALUE)
                    newNode.next = new SLLNode(temp, null);
                    newSet.setSize++;
            }
        }

        temp = firstNode.value;
        while(secondNode.next != null){
            if(temp <= secondNode.value){
                newNode.value = temp;
                temp = Integer.MAX_VALUE;
                newSet.setSize++;
                newNode.next = new SLLNode(0, null);
                newNode = newNode.next;
                secondNode = secondNode.next;
            }else if(secondNode.next != null){
                newNode.value = secondNode.value;
                newSet.setSize++;
                newNode.next = new SLLNode(0, null);
                newNode = newNode.next;
                secondNode = secondNode.next;
            }
            if(secondNode.next == null){
                newNode.value = secondNode.value;
                newSet.setSize++;
            }
        }
        return newSet;
    }
    public SLLSet intersection(SLLSet s){
        SLLSet newSet = new SLLSet();
        SLLNode firstNode = this.head;
        SLLNode secondNode = s.head;
        SLLNode newNode = newSet.head;
        while(firstNode.next != null && secondNode.next != null) {
            if (firstNode.value == secondNode.value){
                newNode.value = firstNode.value;
                newSet.setSize++;
                newNode.next = new SLLNode(0, null);
                newNode = newNode.next;
                firstNode = firstNode.next;
                secondNode = secondNode.next;
            }else if(firstNode.value < secondNode.value)
                firstNode = firstNode.next;
            else
                secondNode = secondNode.next;
        }
        return newSet;
    }

    public SLLSet difference(SLLSet s){
        SLLSet newSet = new SLLSet();
        SLLNode current = this.head;
        SLLNode newCurrent = newSet.head;
        for (int i = 0; i < this.setSize; i++) {
            if(!(s.isIn(current.value))){
                System.out.println("curr " + current.value);
                newCurrent.value = current.value;
                if(current.next != null){
                    newCurrent.next = new SLLNode(0, null);
                    newCurrent = newCurrent.next;
                }
                newSet.setSize++;
            }
            current = current.next;
        }
        return newSet;
    }

    public static SLLSet union( SLLSet[] sArray){
        SLLSet unionSet = sArray[0].union(new SLLSet(new int[]{}));
        for (int i = 0; i < sArray.length-1; i++) {
            unionSet = unionSet.union(sArray[i+1]);
        }
        return unionSet;
    }

    public String toString(){
        String str = "";
        SLLNode curr = this.head;
        for (int i = 0; i < this.setSize; i++) {
            str += curr.value + ", ";
            curr = curr.next;
        }
        str = str.substring(0,str.length()-2);
        return str;
    }
    public static void main(String[] args) {
        SLLSet set1 = new SLLSet(new int[]{1, 2, 4, 11, 13, 14, 16});
        SLLSet set2 = new SLLSet(new int[]{5, 6});
        System.out.println(set1.toString());
        System.out.println(set2.toString());
        System.out.println(set1.intersection(set2).toString());
    }
//    TODO: Check if the empty set works!
}
