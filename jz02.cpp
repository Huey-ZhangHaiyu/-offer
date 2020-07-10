class Solution {
public:
	void replaceSpace(char *str,int length) {
        int space_num;
        for(int i=0;i<length;i++){
            if(str[i]==' '){space_num++;}
        }
        for(int i=length-1;i>=0;i--){
            if(str[i]!=' '){
                str[i+2*space_num]=str[i];
            }
            else if(str[i]==' '){
                str[i+2*space_num]='0';
                str[i+2*space_num-1]='2';
                str[i+2*space_num-2]='%';
                space_num--;
            }
        }
	}
};
