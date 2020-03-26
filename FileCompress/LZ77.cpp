#include "LZ77.h"

const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1; //要保证最后一次匹配,最大匹配长度258 
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;       //最远的匹配距离，如果距离太远还进行匹配，会大大降低压缩效率

LZ77::LZ77()
  :pWin_(new UCH[WSIZE * 2])
   ,ht_(WSIZE)
{

}

LZ77::~LZ77()
{
  delete[] pWin_;
  pWin_ = nullptr;
}

//该函数的作用是压缩文件
//strFilePath：代表带压缩文件的文件名称
void LZ77::CompressFile(const std::string& strFilePath)
{
  //打开带压缩文件，注意要使用二进制的方式打开
  FILE* fIn = fopen(strFilePath.c_str(),"rb");
  if(!fIn)
  {
    std::cout<<"打开带压缩文件失败!"<<std::endl;
    return ;
  }

  //1.获取文件大小
  fseek(fIn,0,SEEK_END);
  ULL file_size = ftell(fIn);
  fseek(fIn,0,SEEK_SET);

  if(file_size < MIN_MATCH)
  {
    std::cout<<"文件太小，不用压缩!"<<std::endl;
    return ;
  }

  //2.从带压缩文件当中读取一个窗口的数据，并记录真正读取到的字节数
  ULL lookAhead = fread(pWin_,1,WSIZE * 2,fIn);

  //记录哈希地址
  USH hashaddr = 0;

  //因为哈希函数的设计是要拿3个字符计算哈希地址，然后才可以插入字符，进行找匹配，开始压缩，，所以先根据开始两个字符计算哈希地址，为后面的压缩做铺垫
  for(USH i = 0;i < MIN_MATCH - 1;i++)
  {
    ht_.HashFunc(hashaddr,pWin_[i]);
  }

  //打开保存压缩数据的文件，写入原字符和长度距离对信息
  FILE* fOutDate = fopen("2.lz","wb");
  if(!fOutDate)
  {
    std::cout<<"打开保存压缩数据文件失败!"<<std::endl;
    return ;
  }

  //打开标记文件，规定如果是原字符就在chFlag当中的对应比特位上置为0，如果是长度距离对就置为1
  FILE* fOutFlag = fopen("3.txt","wb");
  if(!fOutFlag)
  {
    std::cout<<"打开保存压缩数据标记文件失败!"<<std::endl;
    return ;
  }
  
  //代表匹配头，也就是和发生哈希冲突字符的上一个在pWin中出现的位置
  USH matchHead = 0;

  //代表最长匹配长度
  USH curMatchLength = 0;

  //代表最长匹配距离
  USH curMatchDist = 0;

  //记录当前压缩的位置，每次压缩都是根据start往后走的
  USH start = 0;

  //每次都往chFlag的比特位中写标记，原字符：0，长度距离对：1
  UCH chFlag = 0;

  //记录chFlag中已经使用的比特位的个数
  UCH bitCount = 0;

  //对读取到的数据开始压缩
  while(lookAhead)
  {
    //往哈希表当中插入第一个字符，
    ht_.Insert(matchHead,pWin_[start + 2],start,hashaddr);

    //如果插入后带出的匹配头小于MIN_MATCH，就代表没有找打匹配，就可以写入原字符
    if(matchHead < MIN_MATCH)
    {
      //写入原字符
      fputc(pWin_[start],fOutDate);
      
      //后移压缩指针
      start++;

      //带压缩数据个数--
      lookAhead--;

      //写入标记
      WriteFlag(fOutFlag,chFlag,bitCount,false);
    }
    else //找到匹配
    {
      //因为匹配长度的范围是[0,258]，一个字符存不下，所以需要-3，后面解压缩时对长度+3即可
      UCH length = curMatchLength - 3;
      
      //写入长度信息
      fputc(length,fOutDate);

      //写入标记信息
      WriteFlag(fOutFlag,chFlag,bitCount,true);

      //写入距离信息
      fwrite(&curMatchDist,1,sizeof(USH),fOutDate);
      
      //匹配了多少字符就把缓冲区的字符个数减去
      lookAhead -= curMatchLength;

      //因为如果发生匹配，那么我们还需要把匹配的字符插入到哈希表当中，还哈希函数的设计原因
      //--和++的原因是以当前字符找匹配的，该字符已经别插入到哈希表当中，所以跳过该字符
      curMatchLength--;
      start++;

      //把发生匹配的字符插入到哈希表当中
      while(curMatchLength)
      {
        ht_.Insert(matchHead,pWin_[start + 2],start,hashaddr);
        start++;
        curMatchLength--;
      }
    }

    //如果lookAhead < MIN_LOOKAHEAD就需要向pWin当中填充新数据了，否则匹配率不高
    if(lookAhead < MIN_LOOKAHEAD)
    {
        FillWindow(fIn, lookAhead, start);
    }

  }

  //最后可能出现bitcount ！= 8，而写标记文件时不满8是不会写入到文件当中的，所以在结束时需要判断
  if(bitCount)
  {
    chFlag <<= (8 - bitCount);
    fputc(chFlag,fOutFlag);
  }

  fclose(fOutFlag);

  //把源文件大小传入，并把标记文件合并到压缩数据文件当中
  MergeFile(fOutDate,file_size);

  remove("./3.txt");//删除标记信息文件

  //关闭文件描述符
  fclose(fIn);
  fclose(fOutDate);

}

void LZ77::UNCompressFile(const std::string& strFilePath)
{

}

//该函数的作用是根据匹配头找出最长匹配
//matchHead：代表当前匹配头，也就是上一次出现同样字符在pWin中的下标
//curMatchDist：出参，带出最长匹配的距离
//start：代表当前在pWin中的位置
//返回值：代表最长匹配的长度
USH LZ77::LongestMatch(USH matchHead, USH& curMatchDist, USH start)
{
  //记录最多匹配的次数，解决&带来的问题
  UCH maxmatchcount = 255;

  //当前一次匹配的长度
  USH curMatchLength = 0;

  //代表最终最长的匹配长度
  USH maxMatchLength = 0;

  //记录每次在查找缓冲区找匹配的开始位置，后面会根据这个值来计算最大匹配距离
  USH curMatchStart = 0;

  //进行限制
  USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

  do 
  {
    //代表先行缓冲区开始匹配的位置
    UCH* pstart = pWin_ + start;

    //代表先行缓冲区一次匹配的结束位置
    UCH* pend = pWin_ + start + MAX_MATCH;

    //代表查找缓冲区的开始位置
    UCH* pcurstart = pWin_ + matchHead;

    //记录每次匹配的长度
    curMatchLength = 0;
    
    //开始找匹配
    while(pstart < pend && *pstart == *pcurstart)
    {
      curMatchLength++;
      pstart++;
      pcurstart++;
    }

    //如果一次匹配的长度超过最长的匹配长度，就要更新最长匹配长度
    if(curMatchLength > maxMatchLength)
    {
      maxMatchLength = curMatchLength;

      //只有在这种情况下才更新最长匹配在查找缓冲区当中的开始位置
      curMatchStart = matchHead;
    }

  }while((matchHead = ht_.GetNext(matchHead)) > limit && maxmatchcount--);

  //最长匹配距离
  curMatchDist = start - curMatchStart;
  return maxMatchLength;
}

//该函数的作用是写标记文件
//fOutFlag：代表标记文件的文件指针
//chFlag：代表每次向其中的比特位填充；如果是原字符就填充0，如果是长度距离对就填充1
//bitCount：是用来记录chFlag当中8个比特位已经使用的位数，如果==8，就代表chFlag已经被写满，可以写入fOutFlag
//isLen：是用来区分是原字符还是长度距离对
void LZ77::WriteFlag(FILE* fOutFlag, UCH& chFlag, UCH& bitCount, bool isLen) //写标记文件
{
  //每次都左移一位，如果isLen是原字符，就要把chFlag的比特位置为0，而刚好就进不去if，满足情况
  chFlag <<= 1;

  //如果isLen是长度距离对，就要把chFlag对应的比特位写为1，直接|=1即可
  if(isLen)
  {
    chFlag |= 1;
  }

  //无论是写1还是写0，都应该把计数器++
  bitCount++;

  //如果满8位，就可以把该字符写入标记文件
  if(bitCount == 8)
  {
    fputc(chFlag,fOutFlag);

    //把相关变量置为0
    bitCount = 0;
    chFlag = 0;
  }
}

//合并压缩数据文件和标记信息文件
//fOut：代表写压缩数据的文件指针
//fileSize：代表源文件的大小
void LZ77::MergeFile(FILE* fOut, ULL fileSize)
{
  //打开标记文件
  FILE* fOutFlag = fopen("3.txt","rb");
  if(!fOutFlag)
  {
    std::cout<<"合并文件时打开标记文件出错"<<std::endl;
  }

  //缓冲区
  UCH* buf[1024] ;

  //用来计算标记文件大小
  size_t file_size = 0;
  while(1)
  {
    size_t cursize = fread(buf,1,1024,fOutFlag);
    if(cursize == 0)
    {
      break;
    }
    file_size += cursize;
    fwrite(buf,1,1024,fOut);
  }

  //写入标记文件的大小方便解压缩
  fwrite(&file_size,1,sizeof(file_size),fOut);

  //写入源文件的大小方便解压缩
  fwrite(&fileSize,1,sizeof(fileSize),fOut);
}


//在处理大于64k文件时，需要重新填充缓冲区的右窗口
//fIn:代表带压缩数据的文件指针
//lookAhead:代表pWin当中剩余字符的个数，是输出输出型参数
//start：代表当前在pWin当中 的位置
void LZ77::FillWindow(FILE* fIn, ULL& lookAhead, USH& start)
{
  //只有当start进行到右窗时才进行填充操作，否则如果文件已经没有数据了，再进行填充就会出错
  if(start >= WSIZE)
  {
    //把右窗中 数据搬移到左窗
    memcpy(pWin_,pWin_ + WSIZE,WSIZE);

    //把右窗中的数据清0，避免不必要的影响
    memset(pWin_ + WSIZE,0,WSIZE);

    //因为数据已经发生了搬移，哈希表当中记录的每个字符的下标发生了改变，所以需要更新哈希表
    ht_.Update();

    //同样更新start再pWin中的位置
    start -= WSIZE;

    //判断是否到文件末尾
    if(!feof(fIn))
    {
      //毒气数据并更新Pwin中数据的个数
      lookAhead += fread(pWin_ + WSIZE,1,WSIZE,fIn);
    }
  }
}

//获取文件的后缀
std::string LZ77::GetStr(std::string filename)
{

}

