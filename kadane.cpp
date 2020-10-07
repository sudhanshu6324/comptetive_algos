#include <iostream> 
using namespace std;

int main(){
	// i assume the extenstion of the input file is .txt, please change accordingly
	freopen("test1Max.txt", "r", stdin); // redirects standard input 
	
    int n;
    cout << "Please enter the number of elements in array : ";
    cin >> n;

    // since in the given problem array can be real numbers instead of just integers, we need to take
    // an array of double
    double A[n];
    for(int i=0; i < n; i++){
        cin >> A[i];
    }
	// left_idx keeps track of the lower index of the subarray whose value is added into 'sum' currently
	// ans_lower_idx keeps track of the lower index of subarray whose value is added into 'maxi' currently
	// ans_higher_idx keeps track of the lower index of subarray whose value is added into 'maxi' currently
    // these are initialised to -1 beacause all the elements in the subarray may be negative so we want to 
    // detect that scenario
// added maxi and sum
	int maxi = sum;
    double maxi = 0, sum = 0, ans_lower_idx = -1, ans_higher_idx = -1, left_idx = 0 ;
    for(int i = 0; i < n; i++){
        sum += A[i];
        if( maxi <= sum){
        	// update maxi
        	maxi = sum;
        	// update lower index and higher index of the maxi's subarray 
        	ans_lower_idx = left_idx;
        	ans_higher_idx = i;
        }
        if( sum < 0){
            sum = 0;
            left_idx = i + 1;
        }
    }

    if(ans_lower_idx == -1){
    	cout << "All the elements are negative hence sum is 0" << endl;
    } else {
    	cout << "(" << ans_lower_idx <<", " << ans_higher_idx << ")" <<" and the sum is " << maxi << endl;
    }
 
}
