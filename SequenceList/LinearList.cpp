//Linear List

#include<iostream>
using namespace std;
const int MAXSIZE=20;

template<class DataType>
class LinearList
{
	private:
		DataType data[MAXSIZE];
		int lenght;
		
	public:
		LinearList();
		~LinearList();
		int Length();
		
		DataType Get(int i);
		DataType Delete(int i);
		
		void Insert(int i,DataType &elem);
		int Locate(DataType &elem);
		void show();
							
 };
 
template<class DataType>
LinearList<DataType>::LinearList(){
	lenght = 0;
}
 
 template<class DataType>
 LinearList<DataType>::~LinearList(){
 	delete [] data;
 }
 
 template<class DataType>
 DataType LinearList<DataType>::Get(int i){
 	// get the data[] i-th elem
 	if(i<1||i>lenght) cout<<"the number is illegal!"<<endl;
 	cout<<data[i-1]<<endl;
 	return data[i-1];
 };
 
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
 	
 	if(i<1 || i>lenght+1) cout<<"the number is illegal!"<<endl;
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
 	cout<<"length is"<<lenght<<endl;
 }
 
 int main(){
 	cout<<"begin"<<endl;
 	LinearList<int> data;
 	cout<<"please insert 3 number"<<endl;
 	for(int i=1;i<=3;i++){
 		int temp;
 		cin>>temp;
 		data.Insert(i,temp);
	 }
	 data.show();
	 
 	return 0;
 }
