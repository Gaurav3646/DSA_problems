class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        if(arr.size()<=2)
        {
            if(arr.size()==1)
                return 0;
            else
               return 1;    
        }
   
   
   int n=arr.size(); //n-1 is the last element index
   
   unordered_map<int ,vector<int>>mp;
   vector<bool>visited(n,false);
   
   for(int i=0;i<n;i++)
   {
       mp[arr[i]].push_back(i);

   }
   
  queue<int>que;
  que.push(0);
  visited[0]=true;
  int steps=0;
  while(!que.empty())
  {
      int size=que.size();
      while(size--)
      {
          int curr=que.front();
          que.pop();


          int right=curr+1;
          int left=curr-1;
          if(curr==n-1)
             return steps;
// for moving in left
        if(left>=0 && !visited[left])
        {
                que.push(left);
                visited[left]=true;
        }   
//for moving in right
        if(right<=n-1 && !visited[right])
        {
                que.push(right);
                visited[right]=true;
        }

 // for jumping to same element   j where: arr[i] == arr[j] and i != j.   
     for(int &idx:mp[arr[curr]])
     {
           if(!visited[idx])
           {
               que.push(idx);
               visited[idx]=true;
           }
     }
     mp.erase(arr[curr]);
      }
steps++;


  } 
  
  return -1;
   }



};