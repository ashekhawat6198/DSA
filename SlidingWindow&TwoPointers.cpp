
// 1. Longest Substring Without Repeating Characters

// brute force     TC:- O(N*N)   SC:- O(256)
int lengthOfLongestSubstring(string s)
{
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int hash[256] = {0};
        for (int j = i; j < s.size(); j++)
        {
            if (hash[s[j]] == 1)
                break;
            maxLength = max(maxLength, j - i + 1);
            hash[s[j]] = 1;
        }
    }

    return maxLength;
}

// OPTIMISED APPROACH          TC:- O(N)   SC:- O(256)
int lengthOfLongestSubstring(string s)
{
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n)
    {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

// 2. MAX CONSECUTIVE ONES III

// BRUTE FORCE    O(N*N)

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int zeroes = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 0)
                zeroes++;
            if (zeroes <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

// OPTIMISED      O(N)

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0;
    int r = 0;
    int zeroes = 0;
    int maxLen = 0;
    while (r < n)
    {
        if (nums[r] == 0)
            zeroes++;
        if (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }
        if (zeroes <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }

    return maxLen;
}

// 3.LONGEST REPEATING CHARACTERS REPLACEMENT

// BRUTE FORCE   TC:-O(N*N)   SC:-O(1)

int characterReplacement(string s, int k)
{
    int n = s.size();
    int maxLength = 0;
    int maxFreq = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int hash[26] = {0};
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            int changes = (j - i + 1) - maxFreq;
            if (changes <= k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLength;
}

// OPTIMAL   SC:-O(N)    TC:-O(26)
int characterReplacement(string s, int k)
{
    int maxLen = 0;
    int maxFreq = INT_MIN;
    int l = 0;
    int r = 0;
    int n = s.size();
    int hash[26] = {0};
    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);
        if ((r - l + 1) - maxFreq > k)
        {
            hash[s[l] - 'A']--;

            l++;
        }
        if ((r - l + 1) - maxFreq <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

// 4. Binary Subarrays With Sum

// BRUTE FORCE APPROACH    O(N*N)
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == goal)
                count++;
        }
    }
    return count;
}

// OPTIMISED   O(2*2N)
int funclessThanGoal(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int l = 0;
    int r = 0;
    int sum = 0;
    int n = nums.size();
    int count = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum = sum - nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int funclessThanGoal_1(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int l = 0;
    int r = 0;
    int sum = 0;
    int n = nums.size();
    int count = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum = sum - nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int lessThanGoal = funclessThanGoal(nums, goal);
    int lessThanGoal_1 = funclessThanGoal_1(nums, goal - 1);
    return lessThanGoal - lessThanGoal_1;
}

// 5. Count Number of Nice Subarrays

int funclessThanGoal(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int l = 0;
    int r = 0;
    int sum = 0;
    int n = nums.size();
    int count = 0;
    while (r < n)
    {
        sum += (nums[r] % 2);
        while (sum > goal)
        {
            sum -= (nums[l] % 2);
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int funclessThanGoal_1(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int l = 0;
    int r = 0;
    int sum = 0;
    int n = nums.size();
    int count = 0;
    while (r < n)
    {
        sum += (nums[r] % 2);
        while (sum > goal)
        {
            sum -= (nums[l] % 2);
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int numberOfSubarrays(vector<int> &nums, int goal)
{
    int lessThanGoal = funclessThanGoal(nums, goal);
    int lessThanGoal_1 = funclessThanGoal_1(nums, goal - 1);
    return lessThanGoal - lessThanGoal_1;
}

// 6. Number of Substrings Containing All Three Characters
 
 // BRUTE FORCE  O(N*N)
 int numberOfSubstrings(string s) {
        int n=s.size();
        
         int count=0;
        for(int i=0;i<n;i++){
           int hash[3]={0};
            for(int j=i;j<n;j++){
                hash[s[j]-'a']=1;
                if(hash[0]+hash[1]+hash[2]==3){
                    count=count+(n-j);
                    break;
                }
            }
        }

        return count;
    }

// OPTIMISED      TC:- O(N)  SC:-O(1)

 int numberOfSubstrings(string s) {
        int n=s.size();
        int lastSeen[3]={-1,-1,-1};
        int count=0;
        for(int i=0;i<n;i++){
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1 ){
                count+= (1+min(lastSeen[0],min(lastSeen[1],lastSeen[2])));
            }
        }
         
        return count;
    }


  // or

   int numberOfSubstrings(string s) {
      int count=0;
      int l=0;
      int r=0;
      int map[3]={-1,-1,-1};
      while(r<s.size()){
           map[s[r]-'a']=r;
          
           if(map[0]!=-1 && map[1]!=-1 && map[2]!=-1){
            count+=(1+min(map[0],min(map[1],map[2])));
            l++;
           }
           r++;
        
      }  

      return count;
    }


// 7.  Maximum Points You Can Obtain from Cards    TC:-O(2*K) &&  SC:-O(1)

   int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int lsum=0;
        int rsum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            lsum=lsum+nums[i];

        }   
        maxSum=lsum;
        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--){
         lsum=lsum-nums[i];
         rsum=rsum+nums[rightIndex];
         rightIndex-=1;
         maxSum=max(maxSum,lsum+rsum);
        } 

        return maxSum;

    }

// 8. Longest Substring with At Most K Distinct Characters
  
   // BRUTE FORCE  O(N*N) * (log 256)    
    int longestKSubstr(string s, int k) {
         int n=s.size();
         map<char,int>mp;
         int maxLength=0;
         for(int i=0;i<n;i++){
             mp.clear();
             for(int j=i;j<n;j++){
                 mp[s[j]]++;
                  if(mp.size()<=k){
                     maxLength=max(maxLength,j-i+1);
                  } 
                  
              }
            
         }
         
         return maxLength;
    }

    // OPTIMISED   TC:-O(N)+O(N)+O(LOG 256)   SC:-O(LOG 256)
   int kDistinctChars(int k, string &str)
{
  int n=str.size();
  int l=0;
  int r=0;
  int maxlen=0;
  map<char,int>mp;
  while(r<n){
      mp[str[r]]++;
      while(mp.size()>k){
          mp[str[l]]--;
          if(mp[str[l]]==0){
              mp.erase(str[l]);
          }
          l=l+1;
      }

      if(mp.size()<=k){
          maxlen=max(maxlen,r-l+1);
      }
      r++;
  }
  return maxlen;
}

// BEST   TC:-O(N)+O(LOG 256)   SC:-O(LOG 256)

int kDistinctChars(int k, string &str)
{
  int n=str.size();
  int l=0;
  int r=0;
  int maxlen=0;
  map<char,int>mp;
  while(r<n){
      mp[str[r]]++;
      if(mp.size()>k){
          mp[str[l]]--;
          if(mp[str[l]]==0){
              mp.erase(str[l]);
          }
          l=l+1;
      }

      if(mp.size()<=k){
          maxlen=max(maxlen,r-l+1);
      }
      r++;
  }
  return maxlen;
}

// 9. Subarrays with K Different Integers

  //BRUTE FORCE    O(N*N)   SC:-O(N)
   int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            for(int j=i;j<n;j++){
                  mp[nums[j]]++;
                  if(mp.size()==k) count++;
                  else if(mp.size()>k) break;
            }
        }   
        return count;
    }

// BETTER APPROACH      TC:- 2 * O(2N)   SC:- 2 * O(N)

 int lessThanK(vector<int>& nums, int k){
       int n=nums.size();
        int count=0;
        int l=0;
        int r=0;
        map<int,int>mp;
        while(r<n){
           mp[nums[r]]++;
           while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l=l+1;
           }
           count=count+(r-l+1);
           r++;
        }
        return count;
   }
      int lessThanK_1(vector<int>& nums, int k){
       int n=nums.size();
        int count=0;
        int l=0;
        int r=0;
        map<int,int>mp;
        while(r<n){
           mp[nums[r]]++;
           while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l=l+1;
           }
           count=count+(r-l+1);
           r++;
        }
        return count;
   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessThanK(nums,k)-lessThanK_1(nums,k-1);
    }

// 10. Minimum Window Substring

  // BRUTE FORCE    TC:- O(N*N)   SC:-O(256)

   string minWindow(string s, string t) {
        int minLength=INT_MAX;
        int n=s.size();
        int m=t.size();
        int startIndex=-1;
       
        for(int i=0;i<n;i++){
            int hash[256]={0};
           int count=0;
           for(int j=0;j<m;j++){
            hash[t[j]]++;          // first we put all memebers of string 2 in array
           }
           for(int j=i;j<n;j++){
            if(hash[s[j]]>0) count++;  // if it is pre exist or it is in string 2 and incremenet count to match the size of string 2
            hash[s[j]]--;
            if(count==m){     // if count is equal to size of string 2
                if((j-i+1)<minLength){
                    minLength=j-i+1;
                   startIndex=i;    
                }
                 
                 break;
            }

           }
        }
          
        return startIndex==-1 ? "" : s.substr(startIndex,minLength);
    }

    // OPTIMAL APPROACH        TC:-  O(2N)+O(M)    SC:-O(256)

    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int l=0;
        int r=0;
        int map[256]={0};
        int count=0;
        int minLength=INT_MAX;
        int startIndex=-1;
        for(int i=0;i<m;i++){
            map[t[i]]++;
        }

        while(r<n){
          if(map[s[r]]>0) count++;
          map[s[r]]--;
          while(count==m){
            if(r-l+1<minLength){
                minLength=r-l+1;
                startIndex=l;

            }

            map[s[l]]++;    // count badha rhe hai agar 0 se bada ho gya toh ek element kam ho gya toh count ki vallue kam ho gyi toh ham aage traverse krenge ki abhi saare element ni hai 
            if(map[s[l]]>0) count--;
            l++;
          }
          r++;
        }
        return startIndex==-1 ? "" : s.substr(startIndex,minLength); 
    }



  
