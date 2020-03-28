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

void LZ77::CompressFile(const std::string& strFilePath)
{
  FILE* fIn = fopen(strFilePath.c_str(),"rb");
  if(!fIn)
  {
    std::cout<<"打开带压缩文件失败!"<<std::endl;
    return ;
  }

  fseek(fIn,0,SEEK_END);
  ULL file_size = ftell(fIn);
  fseek(fIn,0,SEEK_SET);

  if(file_size < MIN_MATCH)
  {
    std::cout<<"文件太小，不用压缩!"<<std::endl;
    return ;
  }

  ULL lookAhead = fread(pWin_,1,WSIZE * 2,fIn);

  USH hashaddr = 0;
  for(USH i = 0;i < MIN_MATCH - 1;i++)
  {
    ht_.HashFunc(hashaddr,pWin_[i]);
  }

  FILE* fOut = fopen("2.lz","wb");
  if(!fOut)
  {
    std::cout<<"打开保存压缩数据文件失败!"<<std::endl;
    return ;
  }
  FILE* fOutFlag = fopen("3.txt","wb");
  if(!fOutFlag)
  {
    std::cout<<"打开保存压缩数据标记文件失败!"<<std::endl;
    return ;
  }

  USH matchHead = 0;
  USH curMatchLength = 0;
  USH curMatchDist = 0;

  USH start = 0;

  UCH chFlag = 0;
  UCH bitCount = 0;

  while(lookAhead)
  {
    ht_.Insert(matchHead,pWin_[])
  }
  

}

void LZ77::UNCompressFile(const std::string& strFilePath)
{

}

USH LZ77::LongestMatch(USH matchHead, USH& curMatchDist, USH start)
{

}

void LZ77::WriteFlag(FILE* fOUT, UCH& chFlag, UCH& bitCount, bool isLen) //写标记文件
{

}

//合并压缩数据文件和标记信息文件
void LZ77::MergeFile(FILE* fOut, ULL fileSize)
{

}

//在处理大于64k文件时，需要重新填充缓冲区的右窗口
void LZ77::FillWindow(FILE* fIn, size_t& lookAhead, USH& start)
{

}

//获取文件的后缀
std::string LZ77::GetStr(std::string filename)
{

}

