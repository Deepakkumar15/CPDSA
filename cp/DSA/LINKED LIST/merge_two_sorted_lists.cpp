// MERGE TWO SORTED LINKED LISTS
// O(N+M) ADDITIONAL SPACE USED


Node* SortedMerge(Node* a, Node* b)
{
    if(!a)
        return b ;
    if(!b)
        return a ;
        
    Node *head = NULL ;
    Node *curr = NULL ;
    Node *tmp = NULL ;
    
    while(a && b){
        if(a->data < b->data){
            tmp = a ;
            if(!curr){ // first node
                head = tmp ;
                curr = tmp ;
            }
            else{
                curr->next = tmp ;
                curr = curr->next ;
            }
            
            a = a->next ;
            
        }    
        
        else{
            tmp = b ;
            if(!curr){ // first node
                head = tmp ;
                curr = tmp ;
            }
            else{
                curr->next = tmp ;
                curr = curr->next ;
            }
            
            b = b->next ;
        }
    }
    
    while(a){
        curr->next = a ;
        curr = curr->next ;
        a = a->next ;
        
    }
    
    while(b){
        curr->next = b ;
        curr = curr->next ;
        b = b->next ;
    }
    
    
    return head ;
    
}







// USING O(1) SPACE

Node* SortedMerge(Node* a, Node* b)
{
    if(!a)
        return b ;
    if(!b)
        return a ;
    
    if(a->data > b->data){ // here we have to swap the values
        Node *tmp = a ;
        a = b ;
        b = tmp ;
    }   
    
    Node *head = a ;
    
    while(a && b){
        Node *tmp = NULL ;
        while(a && a->data <= b->data){
            tmp = a ;
            a = a->next ;
        }
        
        tmp->next = b ;
        
        // again swap the nodes
        tmp = a ;
        a = b ;
        b = tmp ;
    }
    return head ;
    
}