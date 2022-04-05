public static ArrayList<Integer> getDivisors(int n){
        ArrayList<Integer> divisors = new ArrayList<>();
        //without 1 or n, make 1 and N separated worry if 1 == N
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i) divisors.add(n / i);
            }
        return divisors;
    }
