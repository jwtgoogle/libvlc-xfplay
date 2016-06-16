#pragma once
#include <vector>
#include "DefineUnicode.h"
using namespace duilib;
using namespace std;

// �����б��ļ�������ֻ֧�ּ򵥵�M3U�����б����ڿ����PLS���б��ʽ��֧��
// ����ֻ�Ǽ�ʾ����VLC�ڲ��Ѿ�ʵ���˲����б��ܣ��������Ķ��ĵ�

#pragma pack(push,1)

typedef struct tagPlayFileInfo
{
	wchar_t szFileName[256];	
	int nPos;
}PlayFileInfo;

class CPlaylist
{
public:
    CPlaylist(void);
    ~CPlaylist(void);

    bool ReadFile (const string_t &strPath);    // ��ȡ�����б��ļ���m_vctPath      
    bool WriteFile(const string_t &strPath);    // ����m_vctPath���ɲ����б�      
    bool ReadFile (const string_t &strPath, vector<PlayFileInfo> &vctPlaylist);      // ��ȡ�����б��ļ���vctPlaylist
	bool WriteFile(const string_t &strPath, vector<PlayFileInfo> &vctPlaylist);      // ����vctPlaylist���ɲ����б�
    void Add(PlayFileInfo strPath);                 // ���·�����б�β��
	void deleteFile(const string_t& strPath);
	vector<PlayFileInfo> GetPlaylist();             // ��ȡ�����б�����·��
    PlayFileInfo GetPlaylist(unsigned uIndex);      // ��ȡ�����б�ָ���±��·��

private:
	vector<PlayFileInfo> m_vctPath;                 // ��Ų����б��·��
};

