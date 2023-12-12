class segmentTree{
 vector<int>arr;
 int n;
 int makeSegmentTree(vector<int>&nums,int in,int i,int j){
     if(i==j){
         return arr[in]=nums[i];
     }
     int mid=(i+j)/2;
     arr[in]+=makeSegmentTree(nums,2*in+1,i,mid);
     arr[in]+=makeSegmentTree(nums,2*in+2,mid+1,j);
     return arr[in];
 }
 int sum(int i,int j,int in, int st,int en){
    
     if(i==st && j==en){
         return arr[in];
     }
     int mid=(st+en)/2;
     if(mid>=j){
         return sum(i,j,2*in+1,st,mid);
     }
     if(i>mid){
         return sum(i,j,2*in+2,mid+1,en);
     }
     
     return sum(i,mid,2*in+1,st,mid)+sum(mid+1,j,2*in+2,mid+1,en);
     
 }
 void update(int i,int ele,int in,int s,int e){
     if(s==e && s==i){
         arr[in]=ele;
         return;
     }
     int mid=(s+e)/2;
      if(mid>=i){
         update(i,ele,2*in+1,s,mid);
     }else{
    update(i,ele,2*in+2,mid+1,e);
     }
     arr[in]=arr[2*in+2]+arr[2*in+1];
 }
 public:
 segmentTree(int n){
     this->n=n;
     arr.resize(4*n,0);
 }
 void construct(vector<int>&nums){
  makeSegmentTree(nums,0,0,nums.size()-1);   
 }
 int getSumOfSubarray(int i,int j){
    return sum(i,j,0,0,n-1); 
 }
 void updateSubArray(int i,int ele){
     update(i,ele,0,0,n-1);
 }
    
};
