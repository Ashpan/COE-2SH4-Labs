public class UpperTriangularMatrix {
    private int n;  //n storing size of 2d matrix
    private int array[]; //array storing eff matrix
    public UpperTriangularMatrix(int n){
        if(n<1)
            this.n = 1; //set n to 1 if its less than that
        else
            this.n = n; //otherwise set it to param
        array = new int[n*(n+1)/2];
        for (int i = 0; i < array.length; i++) { //set all values to 0
            array[i] = 0;
        }
    }

    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException{
        if(!(upTriM.isUpperTr())) { //throw error if the Matrix is not upper triangular
            throw new IllegalArgumentException("Matrix is not upper triangular");
        }else{
            int counter = 0;
            n = upTriM.getRow();
            array = new int[n*(n+1)/2];
            for (int i = 0; i < array.length; i++) { //first initialize all values to 0
                array[i] = 0;
            }

            for (int i = 0; i < upTriM.getRow(); i++) { //then initialize all values above diagonal to
                for (int j = i; j < upTriM.getRow(); j++) { //the values from the Matrix
                    array[counter] = upTriM.getElement(i,j);
                    counter++;
                }
            }
        }
    }

    public int getDim(){
        return this.n; //return the size of the 2d matrix
    }

    public int getElement(int i, int j) throws IndexOutOfBoundsException{
        Matrix temp = this.fullMatrix();
        if(i >= 0 && i <= this.n && j >= 0 && j <= this.n){ //return the value at index i, j if possible
            return temp.getElement(i, j);
        }else{ //if not, throw an error
            throw new IndexOutOfBoundsException("i and j are not in the range of your matrix");
        }
    }

    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException{
        Matrix temp = this.fullMatrix();
        if(i < 0 || i > this.n || j < 0 || j > this.n){ //if i and j arent appproriate, throw an error
            throw new IndexOutOfBoundsException("i and j are not in the range of your matrix");
        }else if(j<i && x != 0){ //if setting the value makes the matrix non upper triangular, throw an error
            throw new IllegalArgumentException("This entry must be a 0 for an upper triangular matrix");
        }else{
            temp.setElement(x, i, j); //otherwise set it to that value
            int counter = 0;
            for(int p = 0; p < n; p++){
                for(int q = p; q < n; q++){
                    array[counter] = temp.getElement(p,q);
                    counter++;
                }
            }
        }
    }

    public Matrix fullMatrix(){
        Matrix fullMat = new Matrix(n, n); //create a 2d matrix out of the effMat
        int counter = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){ //loop through ignoring the 0's
                fullMat.setElement(this.array[counter],i,j); //and set the values from the effMat
                counter++;
            }
        }
        return fullMat;
    }

    public void print1DArray(){
        for (int i = 0; i < this.array.length; i++) { //prints all the values in the 1d array
            System.out.print(this.array[i] + "  ");
        }
        System.out.println("");
    }

    public String toString(){
        Matrix temp = this.fullMatrix();
        String str = "";
        for (int i = 0; i < this.n; i++) { //prints all the values in the 2d array with a new line
            for (int j = 0; j < n; j++) { //between each row
                str += temp.getElement(i, j) + " ";
            }
            str += '\n';

        }
        return str;
    }
    public int getDet(){
        int det = 1;
        Matrix temp = this.fullMatrix(); //iterates through index i, i and multiplies them together
        for (int i = 0; i < n; i++) { //to get the determinant
            det *= temp.getElement(i, i);
        }
        return det;
    }
    public double[] effSolve(double[] b) throws IllegalArgumentException{
        if(this.getDet() == 0){ //check if determinant is 0
            throw new IllegalArgumentException("Non-Invertable Matrix");
        }else if(this.n != b.length){ //check if the size of the matrices dont match
            throw new IllegalArgumentException("Wrong dimension size");
        }
        double x[] = new double[this.n]; //create the solution array X
        int incrementCount = 0; //sub counter used in for loop
        for (int i = this.array.length-1; i >= 0; i-=(incrementCount)) { //iterate i to go to the last element in each row
            incrementCount++; //increment this counter
            double val = 0; //init val and jRep
            int jRep = 0;
            double rSide = b[this.n-incrementCount]; //set rSide to the value of the corresponding b matrix
            for (int j = i; j > i-incrementCount; j--) { //go in reverse order from the last to first element in each row
                if(jRep+1 != incrementCount){ //if the next iteration of the loop still passes the condition
                    rSide -= this.array[j]*x[this.n-jRep-1]; //subtract the current value in A times the value in X that has already been calculated
                }else{
                    val = rSide/this.array[j]; //if its the last iteration of this for loop
                } //set val to the current b value divided by the current value in A
            jRep++; //increment counter
            }
            x[this.n-incrementCount] = val; //set the val of the solution matrix to val
        }
        return x; //return solution matrix
    }
}
