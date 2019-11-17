public class SLLSet {
    private int setSize;
    private SLLNode head;
    public SLLSet(){
        this.head = new SLLNode(0, null);
        this.setSize = 0;
    }
    public SLLSet(int[] sortedArray){ //runs first constructor to init the set
        this(); //then adds values from the array to the set, iterating each node and element in array
        int i = 0;
        for (SLLNode curr = this.head; i<sortedArray.length; curr = curr.next) {
            curr.next = new SLLNode(sortedArray[i], null);
            i++; this.setSize++;
        }
    }
    public int getSize(){ return this.setSize; } //returns the setSize int
    public SLLSet copy() { //iterates through each node in a set and copies this to a new set, copying each value to
        SLLSet newSet = new SLLSet(); //another node
        SLLNode currentNode = this.head;
        SLLNode newNode = newSet.head;
        while(currentNode.next != null){
            newNode.next = new SLLNode(currentNode.next.value, null);
            currentNode = currentNode.next;
            newNode = newNode.next;
            newSet.setSize++;
        }
        return newSet;
    }
    public boolean isIn(int v){ //iterates through each node in a set checking if the value property is equal to v
        if (this.head == null) { //if its empty or not equal at the end, it returns false, otherwise it returns true
            return false;
        }else{
            for (SLLNode curr = this.head; curr.next != null; curr = curr.next) {
                if (curr.next.value == v) {
                    return true;
                }
            }
        }
        return false;
    } //

    public void add(int v){ //only runs if the element isnt in the set
        if(!(isIn(v))){
            SLLNode curr;
            for (curr = this.head; curr.next != null; curr = curr.next) {
                if(v<curr.next.value){ //it check the next value of the node, if v is less than the next value
                    curr.next = new SLLNode(v, curr.next); //add in v as the next of the current node and its next will
                    this.setSize++; //be the old next of the current node. increment size by 1 and then end the function
                    return;
                }
            }
            curr.next = new SLLNode(v, null); //if it goes at the end, set the next to null instead
            this.setSize++; // increment size.
        }
    }

    public void remove(int v){
        for (SLLNode curr = this.head; curr.next != null; curr = curr.next) {
            if(curr.next.value == v) { //if the node value = v
                curr.next = curr.next.next; //set the next value of the current node, to the 2nd next value
                this.setSize--; //reduce size by 1
                return; //end method
            }
        }
    }

    public SLLSet union(SLLSet s){
        SLLSet newSet = new SLLSet();
        SLLNode firstNode = this.head;
        SLLNode secondNode = s.head;
        SLLNode newNode = newSet.head;
        //run until either set reaches the last element
        //if firstNode < secondNode -> add firstNode value to newNode and move newNode and firstNode to their next value
        //if firstNode > secondNode -> add secondNode value to newNode and move newNode and secondNode to their next value
        //if both are equal -> add either value to newNode and move every node to their next node

        //after this iterate through whatever set we havent run through completely yet
        //add all those elements to the rest of the newSet
        while(firstNode.next != null && secondNode.next != null){

            if(firstNode.next.value < secondNode.next.value){
                newNode.next = new SLLNode(firstNode.next.value, null);
                firstNode = firstNode.next;
                newNode = newNode.next;
                newSet.setSize++;
            }else if(firstNode.next.value > secondNode.next.value){
                newNode.next = new SLLNode(secondNode.next.value, null);
                secondNode = secondNode.next;
                newNode = newNode.next;
                newSet.setSize++;
            }else{
                newNode.next = new SLLNode(firstNode.next.value, null);
                firstNode = firstNode.next;
                secondNode = secondNode.next;
                newNode = newNode.next;
                newSet.setSize++;
            }
        }
        while(firstNode.next != null){
            newNode.next = new SLLNode(firstNode.next.value, null);
            firstNode = firstNode.next;
            newNode = newNode.next;
            newSet.setSize++;
        }
        while(secondNode.next != null){
            newNode.next = new SLLNode(secondNode.next.value, null);
            secondNode = secondNode.next;
            newNode = newNode.next;
            newSet.setSize++;
        }
        return newSet; //return newSet
    }
    public SLLSet intersect(SLLSet s){
        SLLSet newSet = new SLLSet();
        SLLNode firstNode = this.head;
        SLLNode secondNode = s.head;
        SLLNode newNode = newSet.head;

        while(firstNode.next != null && secondNode.next != null){ //run while neither set is on last node

            if(firstNode.next.value < secondNode.next.value){ //if firstnode < second
                firstNode = firstNode.next; //change firstnode to its next value
            }else if(firstNode.next.value > secondNode.next.value){ //if firstnode > second
                secondNode = secondNode.next; //change secondnode to its next value
            }else{
                newNode.next = new SLLNode(firstNode.next.value, null); //if they're equal, add the value of
                firstNode = firstNode.next; //either node to the newNode and create the next mode
                secondNode = secondNode.next; //move all the nodes to the next node
                newNode = newNode.next;
                newSet.setSize++;
            }
        }
        return newSet; //return the new set
    }

    public SLLSet difference(SLLSet s){
        SLLSet newSet = new SLLSet();
        SLLNode firstNode = this.head;
        SLLNode newNode = newSet.head;
        while(firstNode.next != null){ //run until you reach last node of firstSet
            if(!s.isIn(firstNode.next.value)){ //if the element of this set is not in the s set
                newNode.next = new SLLNode(firstNode.next.value, null); //then add it to the newSet node
                newNode = newNode.next; //move new node to next value
                newSet.setSize++;
            }
            firstNode = firstNode.next; //move this node to next value
        }
        return newSet; //return the new set
    }
    public static SLLSet union( SLLSet[] sArray){
        SLLSet unionSet = new SLLSet(); //create a empty union set
        for (int i = 0; i < sArray.length; i++) {
            unionSet = unionSet.union(sArray[i]); //set it to the union of itself and the ith set in the array
        }
        return unionSet; //return that new set
    }

    public String toString(){
        String str = ""; //initialize string
        SLLNode curr = this.head;
        for (int i = 0; i < this.setSize; i++) {
            if(curr.next.next != null) //if the next value is the last value, dont run this next part
                str += curr.next.value + ", "; //concatenate the value plus a comma to str
            else{
                str += curr.next.value; //concatenate just the value to str
            }
            curr = curr.next; //iterate the node
        }
        return str; //return str
    }
    public static void main(String[] args) {
        SLLSet set1 = new SLLSet(new int[]{1, 2, 4, 11, 13, 14, 16});
        SLLSet set2 = new SLLSet(new int[]{4, 5, 9});
        SLLSet[] setArr = new SLLSet[]{new SLLSet(new int[] {1,2,3}), new SLLSet(new int[] {1,2,7}), new SLLSet(new int[] {3,5,6})};
        System.out.println(set1.toString());
        System.out.println(set2.toString());
        System.out.println(set1.difference(set2).toString());
        System.out.println(union(setArr).toString());
        set2.remove(9);
        System.out.println(set2.toString());
    }
}
