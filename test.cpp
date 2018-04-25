#define MAX_F 10000

// Remove additional cin/cout statements before submission
int NumberOfIntersections(int a[], int b[], int n)
{
    int i_count =0;
    // Write code here
    
    // METHOD #1
    /*----------------
    lets take
    case 
    5  1
    3  2
    2  2
    1  5


    this will have 6 intersection points
    {(5,1) (3,2)}  --  case 1
    {(5,1) (2,2)}  --
    
    {(1,5) (2,2)}  --
    {(1,5) (3,2)}    |- case 2
    {(1,5) (5,1)}  --
    
    {(3,2),(2,2)}     - case 3
    
    in our calculation this will be counted, which is repetition, so needs to taken case
    {(5,1) (1,5)}  --   case 4 (this is repetition of case {(1,5) (5,1)}  so needs to be taken care of in final count )
    -----------------*/
    
    for (int i =0; i<n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            // case 1: if a[i]< a[j] & b[i]>b[j]: refer above  example 
            // case 2: if a[i]> a[j] & b[i]<b[j]: 
            // case 3: if either a[i]!=a[j] &  and b[i]==b[j]  or a[i]==a[j] &  and a[i]==a[j]
            //      in our example this is intersection point between (3,2) and (2,2)
            if( ((a[i]-a[j])*(b[i]-b[j]))<=0)
            {
                i_count++;
            }
        }
    }
    
    /*
    for case 
    5  1
    3  2
    2  2
    1  5
    
    (5,1) and (1,5) intersection will be counted twice
    */
    int i_count_invert = 0; 
    for (int i =0; i<n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if((a[i]==b[j]) && (a[j]==b[i]) && !(a[i]==a[j]&&b[i]==b[j])  )
            i_count_invert++;
        }
    }
    
    
    i_count = i_count - (i_count_invert);

    // METHOD #2 try with sorting 
    /*
     vector<pair<int, int>> arr;
    for (int i =0; i<n; i++)
    {
        pair <int, int> ai;
        ai.first = a[i];
        ai.second =b[i];
        arr.push_back(ai);
      
    sort(arr.begin(), arr.end() );
    
    for (vector<pair<int,int>>::iterator i= arr.begin(); i!=arr.end()-1; i++)
    {
        for (vector<pair<int,int>>::iterator j= (i+1) ; j!=arr.end(); j++)
        {
            if(i->second>j->second)
               i_count++;
        }
    }
    */
    
    return i_count;
    
}

int main()
{
    int i, n;
    int a[MAX_F], b[MAX_F];

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    cout << NumberOfIntersections(a, b, n) << endl;

    return 0;
}
