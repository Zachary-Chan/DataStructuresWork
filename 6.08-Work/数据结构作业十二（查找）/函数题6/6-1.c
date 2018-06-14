Position BinarySearch( List Tbl, ElementType K ) 
{     int low=1;
      int hig=Tbl->Last;
      int mid;
      
      while(low<=hig)
      {          
        mid=(low+hig)/2;
        
        if(Tbl->Data[mid]==K) {
          return mid;         
          
        } else if (Tbl->Data[mid]<K) {
          low=mid+1;
          
        } else if (Tbl->Data[mid]>K) {
          hig=mid-1;         
          
        }     
        
      }
      
      return NotFound;
}
