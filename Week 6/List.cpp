class List {
    int size;
    int storage=1000;
    int *n =new int [storage];
    List (){
        size = -1;
    }
    void newstorage (){
        int *m = new int [storage *2];
        for (int i=0;i<=size;i++){
            m[i]=n[i];
        }delete [] n;
        n= m ;
        storage *=2;
    }
    void AddLast (const int &val){
        if (size +1 == storage){
            newstorage();
        }size ++;
        n[size]=val;
    }
    void get (const int &index){
        cout <<n[index];
    }
    void AddFirst (const int & value){
        if (size+1 == storage){
            newstorage();
        }for (int i=size;i>=0;i--){
            n[i+1]=n[i];
        }size++;
        n[0]=value;
    }
    void AddIndex (const int &value ,const int &index){
        if (size+1 == storage){
            newstorage();
        }for (int i=size;i>=index;i--){
            n[i+1]=n[i];
        }size++;
        n[index]=value;

    }

    void deleteFirst (){
        for (int i=1;i<=size;i++){
            n[i-1]=n[i];
        }size--;
    }
    void deleteLast (){
        size--;
    }
    void duyetxuoi (){
        for (int i=0;i<=size;i++){
            cout <<n[i]<<" ";
        }
    }
    void duyetnguoc (){
        for (int i=size;i>=0;i--){
            cout <<n[i]<<" ";
        }
    }
};


int main (){
    return 0;
}


