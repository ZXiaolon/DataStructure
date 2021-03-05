//Linear List

#include<iostream>
using namespace std;
const int MAXSIZE=20;

template<class DataType>
class LinearList
{
	private:
		DataType* data;
		int lenght;
		int maxsize; //data max space;it will be change if increase space;
		
	public:
		LinearList();
		~LinearList();
		
		void IncreaseSize(); 
		int Lenght();
		
		DataType Get(int i);
		DataType Delete(int i);
		void Insert(int i,DataType &elem);
		int Locate(DataType &elem);
		void show();
							
 };
 
template<class DataType>
LinearList<DataType>::LinearList(){
	data = new DataType[MAXSIZE];
	lenght = 0;
	maxsize = MAXSIZE;
}
 
 template<class DataType>
 LinearList<DataType>::~LinearList(){
 	delete [] data;
 }
 
 template<class DataType>
 void LinearList<DataType>::IncreaseSize(){
 	//increase space to complete the dynamical memory distribution
 	DataType* temp=NULL;
 	temp = data;
 	data = new DataType[maxsize+MAXSIZE];
 	
 	//copy the values updata to the new data
 	for(int i=0;i<lenght;i++){
 		data[i] = temp[i];
	 }
	 maxsize = maxsize+MAXSIZE;
	 delete[] temp;
 }
 
 template<class DataType>
 int LinearList<DataType>::Lenght(){
 	return lenght;
 }

 
 template<class DataType>
 DataType LinearList<DataType>::Get(int i){
 	//return the i-th elem
 	if(i<1||i>lenght){
 		cout<<"the number is illegal"<<endl;
 		return;
	 }
	 cout<<data[i-1];
 	return data[i-1];
 }
 
 template<class DataType>
 int LinearList<DataType>::Locate(DataType &elem){
 	for(int i=0;i<lenght;i++){
 		if(data[i]==elem) return i+1;
 		return 1;
	 }
 }
 
 
 template<class DataType>
DataType LinearList<DataType>::Delete(int i){
 	// delete the data[] i-th elem
 	DataType dele_temp; //the elem will be deleted!
 	if(i<1||i>lenght) cout<<"the number is illegal!"<<endl;
 	
 	dele_temp = data[i-1];
 	for(int j=i;i<lenght;j++){
 		data[j] = data[j+1];
	 }
	 cout<<dele_temp<<"is deleted"<<endl;
	 return dele_temp;	 
 }
 
template<class DataType>
void LinearList<DataType>::Insert(int i,DataType &elem){
 	// insert elem into the i-th
 	if(lenght>MAXSIZE){
 		cout<<"List is fulled!"<<endl;
 		//the must be handle
	 }
 	
 	if(i<0 || i>lenght+1) 
	 {
	 cout<<"the number is illegal!"<<endl;
	 return;	
	 }
 	for(int j=lenght-1;j>=i-1;j--){
 		data[j+1] = data[j];
	 }
	 data[i-1] = elem;
	 lenght++;
	 cout<<"elem has been inserted successfully!"<<endl;	
 }
 
 template<class DataType>
 void LinearList<DataType>::show(){
 	for(int i=0;i<lenght;i++) cout<<data[i]<<endl;
 }
 
 void home(){
 	cout<<"1.Insert"<<endl;
 	cout<<"2.Get"<<endl;
 	cout<<"3.Delete"<<endl;
 	cout<<"4.Locate"<<endl;
 	cout<<"5.show"<<endl;
 }
 int main(){
 	
 	cout<<"LinearList"<<endl;
 	
 	LinearList<int> data;
 	home();
 	int choose;
 	cout<<"input your choose:";
 	cin>>choose;
 	switch(choose){
	 case 1:
	 	{
	 		int times;
	 		cout<<"input the times of insert:"<<endl;
	 		cin>>times;
	 		for(int i=0;i<times;i++){
	 			int temp;
	 			cout<<"input the value to inset:";
	 			cin>> temp;
	 			data.Insert(i,temp);
			 }
	 		
		 }
	 }
	 data.show();
	 cout<<"lenght of data is:"<<data.Lenght()<<endl;
	 
 	return 0;
 }
