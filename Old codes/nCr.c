//code for nCr
ll ncr(int n, int r) {
  ll ret=1;
  int i;
  if (r>n) return 0;
  for(i=1;i<=r;i++) ret*=(n+1-i),ret/=i;
  return ret;
}
