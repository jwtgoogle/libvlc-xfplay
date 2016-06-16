#include "PlayList.h"
#include <tchar.h>
#include <iostream>			
#include <sstream> 		
#include <fstream>	
using namespace std;	

extern std::string UnicodeToANSI(const std::wstring& strWide);

// 播放列表的文件类型，暂时只解析M3U类型
enum enum_PlaylistType   
{
    em_Unknown,  // 未知类型
    em_PLS,      // PLS类型
    em_M3U       // M3U类型
};


CPlaylist::CPlaylist(void)
{
}

CPlaylist::~CPlaylist(void)
{
}
    
void CPlaylist::Add(PlayFileInfo strPath)
{
    m_vctPath.push_back(strPath);
}

void CPlaylist::deleteFile(const string_t& strPath)
{
	vector<PlayFileInfo>::iterator it;
	for (it = m_vctPath.begin(); it != m_vctPath.end();)
	{
		if (strPath == (*it).szFileName)
		{
			it = m_vctPath.erase(it);
		}
		else
		{
			it++;
		}
	}
}

bool CPlaylist::ReadFile(const string_t &strPath)
{
    return ReadFile(strPath, m_vctPath);
}

bool CPlaylist::WriteFile(const string_t &strPath)
{
    return WriteFile(strPath, m_vctPath);
}

bool CPlaylist::ReadFile(const string_t &strPath, vector<PlayFileInfo> &vctPlaylist)
{
    ifstream_t  fin;
    string_t    strInput;
    char_t      ch;
	PlayFileInfo tempPlayFileInfo;
	
	memset(&tempPlayFileInfo, 0, sizeof(PlayFileInfo));

    fin.imbue(locale(""));
    fin.open(strPath.c_str(), ios::in);
    if(!fin.is_open())
    {
        return	false;
    }
	
	wchar_t szBuffer[300];
	memset(szBuffer, 0, 300);
	
    while(fin.getline(szBuffer,300))
    {   
		memcpy(&tempPlayFileInfo,szBuffer,sizeof(PlayFileInfo));
        vctPlaylist.push_back(tempPlayFileInfo);
    }

    fin.close();
    return true;
}

bool CPlaylist::WriteFile(const string_t &strPath, vector<PlayFileInfo> &vctPlaylist)
{

	
    ofstream_t fout;
    fout.imbue(locale(""));
    fout.open(strPath.c_str(), ios::out | ios::trunc);
    if(!fout.is_open())
    {
        return false;
    }

	vector<PlayFileInfo>::iterator it;
    for(it = vctPlaylist.begin();	it !=  vctPlaylist.end();	it++)
    {
        fout << (*it).szFileName /*<< (*it).nPos*/ << endl;
    }

	fout.close();


    return true;
}

vector<PlayFileInfo> CPlaylist::GetPlaylist()
{
    return m_vctPath;
}

PlayFileInfo CPlaylist::GetPlaylist( unsigned uIndex )
{
    if (uIndex < 0 || uIndex >= m_vctPath.size())
    {
       
    }

    return m_vctPath[uIndex];
}
