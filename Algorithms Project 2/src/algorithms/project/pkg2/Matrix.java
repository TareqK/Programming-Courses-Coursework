/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms.project.pkg2;

import java.io.FileInputStream;
import java.io.IOException;
import static java.lang.Math.random;

/**
 *
 * @author haxx
 */
public class Matrix {
    
    protected int n;//y
    protected int m;//x
    protected double[][] vals;

    public Matrix(int n, int m) {
        this.n = (n-1);
        this.m = (m-1);
        this.vals=new double[n][m];
    }

    public int getN() {
        return n;
    }

    public void setN(int n) {
        this.n = n;
    }

    public int getM() {
        return m;
    }

    public void setM(int m) {
        this.m = m;
    }

    public double[][] getVals() {
        return vals;
    }

    public void setVals(double[][] vals) {
        this.vals = vals;
    }
    
    public void initRandom()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                this.vals[i][j]= random();
            }
        }
    }
    
    public void initInOrder()
    {
       int counter =0;
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                this.vals[i][j]= counter ;
                counter++;
            }
        }
        
    }
    
    public void initReverseOrder()
    {
       int counter = n*m;
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                this.vals[i][j]= counter ;
                counter--;
            }
        }
        
    }
    
    public void initFromFile(FileInputStream in) throws IOException,BadDataException
    {
    int c;
    StringBuilder temps = new StringBuilder();
    while ((c = in.read())!=-1) {
        if((char)c!='\n'){
        }
        else{
            temps.append((char)c); 
        }

    }
    String[] tokens= temps.toString().split(",");
        if(tokens.length>m*n)
        {
            throw new BadDataException();
        }
        int counter =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    this.vals[i][j]= Double.parseDouble(tokens[counter]) ;
                    counter++;
            }
        }
        
    }
        
    
}
