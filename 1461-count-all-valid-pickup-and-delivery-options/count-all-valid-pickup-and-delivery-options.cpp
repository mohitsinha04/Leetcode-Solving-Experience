// https://www.youtube.com/watch?v=OpgslsirW8s
class Solution {
public:
    int mod = 1000000007;
    int countOrders(int n) {
        long long res = 1;
        int spaces = 2 * n;
        while (spaces > 0) {
            long long values = ((spaces * (spaces-1)) /2) % mod;
            res = (res * values) % mod;
            spaces -= 2;
        }
        return res % mod;
    }
};