public class Matrix {
    private int row; //init fields
    private int col;
    private int array[][];

    Matrix(int row, int col){
        this.row = row<=0 ? 3 : row; //if row and col <=0, set it to 3, otherwise set it to the param
        this.col = col<=0 ? 3 : col;
        this.array = new int[this.row][this.col]; //init values in matrix to 0
        for (int i = 0; i < this.array.length; i++) {
            for (int j = 0; j < this.array[i].length; j++) {
                this.array[i][j] = 0;
            }
        }
    }
    Matrix(int Table [][]){
        this.row = Table.length;
        this.col = Table[0].length;
        this.array = new int[this.row][this.col];
        for (int i = 0; i < this.row; i++) { //copy 2d array to array field
            for (int j = 0; j < this.col; j++) {
                this.array[i][j] = Table[i][j];
            }
        }
    }

    public int getElement(int i, int j) throws IndexOutOfBoundsException{
        if(i>this.array.length || i<0 || j>this.array[i].length || j<0){ //throw error is out of range
            throw new IndexOutOfBoundsException("Invalid Indexes");
        }
        return (array[i][j]); //otherwise return element
    }

    public boolean setElement(int x, int i, int j){
        if(i<=this.array.length && i>=0 && j>=0 && j<=this.array[i].length){
            this.array[i][j] = x; //set element if valid
            return true;
        }else{ return false; } //otherwise return false
    }

    public Matrix copy(){
        return new Matrix(this.array);
    } //create new matrix with matrix being called with

    public void addTo(Matrix m) throws ArithmeticException{
        if(m.array.length != this.array.length || m.array[0].length != this.array[0].length){
            throw new ArithmeticException("Invalid Operation"); //if sizes dont match, throw error
        }
        for (int i = 0; i < this.array.length; i++) {
            for (int j = 0; j < this.array[i].length; j++) {
                this.array[i][j] += m.array[i][j]; //otherwise add each value together
            }
        }
    }

    public Matrix subMatrix(int i, int j) throws ArithmeticException{
        if(i<=this.array.length && j<=this.array[0].length){ //if i and j are within range
            Matrix subArr = new Matrix(i,j);
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < j; l++) {
                    subArr.array[k][l] = this.array[k][l]; //create new matrix with that range
                }
            }
            return subArr;
        }else{ //otherwise throw error
            throw new ArithmeticException("Submatrix not deﬁned");
        }
    }

    public boolean isUpperTr(){
        int rows = this.array.length; //go through each value below diagonal
            for (int i = 1; i < rows; i++) {
                for (int j = 0; j < i; j++) {
                    try {
                        if (array[i][j] != 0) { //if any of those value are not 0, it is not uppertr
                            return false; //and return false
                        }
                    }catch(IndexOutOfBoundsException e){ //if size of matrix causes loop to go out of range
                        System.out.print(""); //just ignore it and keep going
                    }
             }
        }
        return true; //otherwise return true
    }

    public static Matrix sum(Matrix[] matArray) throws ArithmeticException{
        Matrix sumMat = new Matrix(matArray[0].array.length, matArray[0].array[0].length);
        //create a sum matrix of the right size
        for(int i = 0; i < matArray.length; i++){
            sumMat.addTo(matArray[i]); //iterate through each matrix and add them to the sum mat
        }
        return sumMat; //return matrix
    }

    public String toString(){
        String str = "";
        for (int i = 0; i < this.array.length; i++) {
            for (int j = 0; j < this.array[i].length; j++) {
                str += String.valueOf(this.array[i][j]) + "  "; //add the value of each index to the string with spaces
            }
            str += "\n"; //add newline
        }
        return str; //return string
    }
    public int getRow(){ return this.array.length; }
    public int getCol(){ return this.array[0].length; }

}
