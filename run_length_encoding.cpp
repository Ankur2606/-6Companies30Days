string encode(string src)
{     
  string s="";
  int cnt=1;
  for(int i=1;i<src.length();i++){
      if(src[i-1]==src[i]){
          cnt++;
      }
      else{
          
          s+=src[i-1];
          string srr = to_string(cnt);
          s+=srr;
          cnt=1;
      }
  }
       s+=src.back();
       s+=to_string(cnt);
  return s;
}     