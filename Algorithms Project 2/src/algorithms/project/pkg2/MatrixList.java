package algorithms.project.pkg2;


import algorithms.project.pkg2.Matrix;
import java.util.ArrayList;
import java.util.Arrays;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author haxx
 */
public class MatrixList {
    public ArrayList<Matrix> matricies;
    public int minumumMoves;
    public int[][] markers;
    public int[][] scalarCosts;
    public StringBuilder paranthesis;
    public int[] dimensions;
    public char currentName;
    public int normalMoves;
    
    
    
    public MatrixList(int[] dimensions){
        this.dimensions=dimensions;
        this.matricies = new ArrayList<Matrix>();
        int counter=0;
        for(int i=0;i<dimensions.length-1;i++)
        {
            matricies.add(new Matrix(dimensions[i],dimensions[i+1]));
            matricies.get(counter).initRandom();
            counter++;
        }
        this.markers = new int[dimensions.length][dimensions.length];
        this.scalarCosts = new int[dimensions.length][dimensions.length-1];
        this.minumumMoves=Integer.MAX_VALUE;
        this.paranthesis = new StringBuilder(); 
        this.currentName='A';
        this.normalMoves=this.dimensions[0]*this.dimensions[1];
    }
    
    
    /*public void createMatrixList(int[] dimensions)//we do this to make sure that the matricies are Multiplyable
    {
        
    }*/
    
    
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
    public void matrixChainOrder()
    {
        /* For simplicity of the program, one extra row and one
        extra column are allocated in m[][].  0th row and 0th
        column of m[][] are not used */
        int n = this.dimensions.length;
        int m[][] = new int[n][n];
 
        int i, j, k, L, q;
 
        /* m[i,j] = Minimum number of scalar multiplications needed
        to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
        dimension of A[i] is p[i-1] x p[i] */
 
        // cost is zero when multiplying one matrix.
        for (i = 1; i < n; i++)
            m[i][i] = 0;
 
        // L is chain length.
        for (L=2; L<n; L++)
        {
            for (i=1; i<n-L+1; i++)
            {
                j = i+L-1;
                if(j == n) continue;
                m[i][j] = Integer.MAX_VALUE;
                for (k=i; k<=j-1; k++)
                {
                    // q = cost/scalar multiplications
                    q = m[i][k] + m[k+1][j] + this.dimensions[i-1]*this.dimensions[k]*this.dimensions[j];
                    if (q < m[i][j]){
                        m[i][j] = q;
                        this.markers[i][j]=k;
                    }
                }
            }
        }
        this.scalarCosts=m;
        this.minumumMoves = m[1][n-1];
    }
    
public void createParenthesis(int i, int j)
{
    // If only one matrix left in current segment
    if (i == j)
    {
        this.paranthesis.append(this.currentName);
        this.currentName++;
        return;
    }
    

    this.paranthesis.append("(");

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    createParenthesis(i, markers[i][j]);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    createParenthesis(markers[i][j]+1,j);

    this.paranthesis.append(")");
}


    public double[][] multAll(int i, int j) {
        if (i == j)  {      
        double[][] temp = this.matricies.get(i).getVals();            // basis case
        return temp;
        }
        else {
        int k = this.markers[i][j];
        double[][] X = multAll(i, k)   ;                   // X = A[i]...A[k]
        double[][] Y = multAll(k+1, j)   ;                 // Y = A[k+1]...A[j]
        return(multMatrix(X,Y));                // multiply matrices X and Y
        }
}

   public static double[][] multMatrix(double[][] a, double[][] b){//a[m][n], b[n][p]
   if(a.length == 0) return new double[0][0];
   if(a[0].length != b.length) return null; //invalid dims

   int n = a[0].length;
   int m = a.length;
   int p = b[0].length;
   double[][] ans = new double[m][p];

   for(int i = 0;i < m;i++){
      for(int j = 0;j < p;j++){
         for(int k = 0;k < n;k++){
            ans[i][j] += a[i][k] * b[k][j];
         }
      }
   }
   return ans;
   }
   
   public void calculateNormalMoves()
   {
       for(int i=2;i<this.dimensions.length;i++){
       this.normalMoves*=this.dimensions[i];
       }
   }
    @Override
   public String toString(){
   this.paranthesis.delete(0,this.paranthesis.length());
   this.matrixChainOrder();
   this.calculateNormalMoves();
   this.createParenthesis(1,(dimensions.length -1));
   return ("The Normal Number of Moves is: "+this.normalMoves+"\nThe minimum number of moves is: "+this.minumumMoves+"\nIn the order\n"+this.paranthesis.toString());
       
}
}

