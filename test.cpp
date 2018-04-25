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
