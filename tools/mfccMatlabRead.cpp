/*
Khalid Ashraf 2014
Program to obtain the file path and MFCC start and 
end location from the text file containing file names.

//next extension: do it for multiple files
*/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdint.h>
#include <string.h>
#include <stdint.h>
int main()

{
int i,j,mfccID,labelSize,numSamples,startTime[300],endTime[300],labelN[300],mfccLabel[500],label[300];
char output[200],path[100],first[10],last[10];
	//open the file
float mfccTime[500],labelTime[500];

std::string outputS;
std::ifstream labelFile("timitTNET.lab", std::ios::in);
//labelFile.seekg(2);
if(labelFile.is_open()){
i=0;
while(!labelFile.eof())
{
//read one line at a time
//mfccFile>>output;

if((i)%3==0)
{std::getline(labelFile,outputS,' ');
std::cout<<"out"<<outputS<<'\n';
startTime[i/3]=::atoi(outputS.c_str());
std::cout<<startTime[i/3]<<'\n';
i++;
}
else if((i)%3==1)
{std::getline(labelFile,outputS,' ');
std::cout<<"out"<<outputS<<'\n';
endTime[i/3]=::atoi(outputS.c_str());
std::cout<<endTime[i/3]<<'\n';
i++;
}
else
{std::getline(labelFile,outputS,'\n');
std::cout<<"out"<<outputS<<'\n';

if(outputS=="h#") labelN[i/3]=0;
else if(outputS=="aa") labelN[i/3]=1;
else if(outputS=="ae") labelN[i/3]=2;
else if(outputS=="ah") labelN[i/3]=3;
else if(outputS=="aw") labelN[i/3]=4;
else if(outputS=="ay") labelN[i/3]=5;
else if(outputS=="b") labelN[i/3]=6;
else if(outputS=="ch") labelN[i/3]=7;
else if(outputS=="d") labelN[i/3]=8;
else if(outputS=="dh") labelN[i/3]=9;
else if(outputS=="dx") labelN[i/3]=10;
else if(outputS=="eh") labelN[i/3]=11;
else if(outputS=="er") labelN[i/3]=12;
else if(outputS=="ey") labelN[i/3]=13;
else if(outputS=="f") labelN[i/3]=14;
else if(outputS=="g") labelN[i/3]=15;
else if(outputS=="hh") labelN[i/3]=16;
else if(outputS=="ih") labelN[i/3]=17;
else if(outputS=="iy") labelN[i/3]=18;
else if(outputS=="jh") labelN[i/3]=19;
else if(outputS=="k") labelN[i/3]=20;
else if(outputS=="l") labelN[i/3]=21;
else if(outputS=="m") labelN[i/3]=22;
else if(outputS=="n") labelN[i/3]=23;
else if(outputS=="ng") labelN[i/3]=24;
else if(outputS=="ow") labelN[i/3]=25;
else if(outputS=="oy") labelN[i/3]=26;
else if(outputS=="p") labelN[i/3]=27;
else if(outputS=="pau") labelN[i/3]=28;
else if(outputS=="r") labelN[i/3]=29;
else if(outputS=="s") labelN[i/3]=30;
else if(outputS=="sh") labelN[i/3]=31;
else if(outputS=="t") labelN[i/3]=32;
else if(outputS=="th") labelN[i/3]=33;
else if(outputS=="uh") labelN[i/3]=34;
else if(outputS=="uw") labelN[i/3]=35;
else if(outputS=="v") labelN[i/3]=36;
else if(outputS=="w") labelN[i/3]=37;
else if(outputS=="y") labelN[i/3]=38;
else if(outputS=="z") labelN[i/3]=39;


//labelN[i/3]=::atoi(outputS.c_str());
std::cout<<labelN[i/3]<<'\n';
i++;
}

}

}
	//close it
labelFile.close();
labelSize=i/3;  //number of lines in the label file

/*finished creating the label arrays.
Now determine label corresponding to each sample*/

//first read the number of coefficients in a mfcc file
numSamples=219;
j=0;  //index that iterates through the lines of the label file
for (i=0;i<numSamples;i++)
{
//real time corresponding to mfccID 
mfccID=i;
mfccTime[i]=12.5+(mfccID+1)*10; //real time in ms, i is the mfccID here
std::cout<<"mfccTime"<<mfccTime[i]<<'\n';

//real time corresponding to mfccID 
labelTime[j]=endTime[j]*10^(-4); //real time in ms
if(mfccTime[i]<endTime[j]) {}
else {j++;}
mfccLabel[i]=labelN[j];
std::cout<<"mfccLabel"<<mfccLabel[i]<<'\n';

}
}
