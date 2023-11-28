~linearList(){
		while(this){
			LinearList* temp=this;
			this=this->subLst;
			delete temp;
			temp=NULL;
		}
	}