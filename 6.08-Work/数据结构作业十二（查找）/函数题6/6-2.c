Position Find( HashTable H, ElementType Key )
{
    Position p,m;
    p=Hash( Key, H->TableSize );
    if(H->Cells[p].Data==Key||H->Cells[p].Info==Empty)
        return p;
    else
    {
        for(int i=1;i<H->TableSize;i++)
        {
            m=(p+i)%H->TableSize;
            if(H->Cells[m].Data==Key||H->Cells[m].Info==Empty)
                return  m;
        }
        return ERROR;
    }
}
