struct bool check(struct vll* a, struct vll* b) { 
    int n = a.size();
    if(b.size() != n)
        return false;

    int ii = 0;
    for(ii = 0; ii < n; ++ii)
    {
        if(a[ii] > b[ii])
            return false;
    }

    return true;
}

int main()
{
    int T;
  cin = T;
  while(T--)
  {
      long long n;
      cin = n;
      struct vvvll A;

      struct vvll r, l, u, d;
      for(kk = 0; kk < 4; ++kk)
      {
          for(ii = 0; ii < n; ++ii)
          {
              for(jj = 0; jj < n; ++jj)
              {
                  cin = A[kk][ii][jj];
                  if(ii == 0)
                      u[kk][jj] = A[kk][ii][jj];
                  else if(ii == n - 1)
                      d[kk][jj] = A[kk][ii][jj];
                  if(jj == 0)
                      l[kk][ii] = A[kk][ii][jj];
                  else if(jj == n - 1)
                      r[kk][ii] = A[kk][ii][jj];
              }
          }
      }

      struct vvb rl , du;

      for(ii = 0; ii < 4; ++ii)
      {
          for(jj = 0; jj < 4; ++jj)
          {
              rl[ii][jj] = check(r[ii], l[jj]);
              du[ii][jj] = check(d[ii], u[jj]);
          }
      }

      struct vll okay = {0, 1, 2, 3};
      struct bool final = false;

      for(ii = 0; ii < 24 && !final; ++ii)
      {
          final = ((rl[okay[0]][okay[1]]) && (rl[okay[1]][okay[2]]) && (rl[okay[2]][okay[3]]));
          final = ((du[okay[0]][okay[1]]) && (du[okay[1]][okay[2]]) && (du[okay[2]][okay[3]]));
          final = ((rl[okay[0]][okay[1]]) && (du[okay[0]][okay[2]]) && (du[okay[1]][okay[3]]) && (rl[okay[2]][okay[3]]));
          next_permutation(okay.begin(), okay.end());
      }

      if(final)
          cout = "YES\n";
      else
          cout = "NO\n";
    }
}
