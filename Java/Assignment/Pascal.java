class Pascal{
    static int fact(int x){
        int fact=1;
        for (int i=2; i<=x; i++){
            fact*=i;
        }
        return fact;
    }
    static int nCm (int n, int m){
        int com = fact(n)/(fact(m)*fact(n-m));
        return com;
    }

    public static void main (String args[]){
        int n=Integer.parseInt(args[0]);
        int arr [][]= new int [n][];
        int x;
        for (int i=0; i<n; i++){
            arr[i]= new int [i+1];
            for (int j=0; j<=i; j++){
                x=nCm(i,j);
                arr[i][j]=x;
            }
        }
        for (int i=0; i<n; i++){
            for (int s=0; s<n-i; s++){
                System.out.print(" ");
            }
            for (int j=0; j<=i; j++){
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }
        }
    }
