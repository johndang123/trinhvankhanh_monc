int countAll(){
		int count=0;
		for(absList* temp=this;temp;temp=temp->subLst){
			count++;
		}
		return count;
	}
