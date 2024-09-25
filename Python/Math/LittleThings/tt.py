def bnl(n,k,p):
    return p^k*(1-p)^(n-k)
print(1-20*bnl(20,1,0.01)-bnl(20,0,0.01))