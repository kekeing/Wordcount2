#include<stdio.h>
#include<vector>
#include <iostream>
#include <algorithm>
#include<cstring>
#include <fstream>
using namespace std;
//����ļ�·������iȷ�Եĺ���
int check(char * argcs);
void wordcount(FILE *, int word);
//������������
//���������е�Ԫ����������
void order(vector<struct file_info_>);
//����һ���ṹ�壬������ʾ�ļ����ַ�����Ϣ
struct file_info_
{
	char *name = NULL;
	int num_appear;
};
bool comp(file_info_ a, file_info_ b) { return a.num_appear>b.num_appear; }
//����һ������ַ�������
vector<char> v_char;
//����һ����Žṹ�������
vector<struct file_info_> file_info_cahr;
//����Ҫ����һ���ṹ�����飬������ʾ��Щ����
//����Ҫ����һ���ַ����飬�����洢��ʱ���ַ���
int  main(int argc, char** argcs)
{
	//�����ļ�ָ��
	FILE *file = NULL;
	///����һ���ַ��͵����ݽ����ļ����ַ��Ĵ���
	char charc;
	//�ȼ���������Ƿ�������
	/*if(argc!=2)
	{
	printf("Please input a correct file name\n");
	return 0;
	}

	//Ȼ�����ļ����ļ�������ȷ��

	if(check!=1)
	{
	printf("This is an incorrect file\n");
	return 0;
	}
	*/
	if ((file = fopen("test.txt", "r")) == NULL)
	{
		printf("This is a broken file\n");
		return 0;
	}
	//�����ֽڶ�ȡ���ݣ�Ȼ���������ļ����в���
	//fgetc �������ÿ�δӵ�ǰ�ļ�ָ���ȡһ���ַ���Ȼ���ļ��ַ�ָ���1
	//ѭ����ȡ���ݣ��ڹ����н��м�����������
	//���ü�����
	int word = 0;
	wordcount(file, word);
	//���������
	order(file_info_cahr);
	//�����������
	return 0;
}
//������
//��������Ҫ���ļ����룬Ȼ����ļ����ַ����д�Ƶ����
//���������ļ�����֮������ݼ�¼��һ���ṹ������֮��
//�������ͽ����˹���
void wordcount(FILE *file, int word)
{
	//����һ���ַ��͵����ݽ����ļ����ַ��Ĵ���
	char charc;
	//��ȡ�ļ��еĵ�һ���ַ���ͬʱ�ļ�ָ��ָ����һ���ַ���λ��
	charc = fgetc(file);
	//�ڼ�������ʽ��ʼ����֮ǰ��Ҫ��һЩ׼������
	//����˵��Ҫ�ų���ͷ���ǿո�����
	if (charc == ' ')
	{
		while (charc == ' ')
			charc = fgetc(file);//�����һ���ļ��ַ����ǿո���ô����Ҫ������ֱ����ȡ��һ�����ǿո���ַ�Ϊֹ
	}
	//��ǰ���ļ�ָ��
	while (charc != EOF)
	{
		//����ǰ���ַ���������֮��
		if (charc != ' '&&charc != 10) {
			v_char.push_back(charc);
			//����ļ�����һ���ַ����ǿո񣬾ͼ���ѭ���������Ҫ��1
			charc = fgetc(file);
		}
		if (charc != ' '&&charc != 10)
		{
			v_char.push_back(charc);
			charc = fgetc(file);
			continue;
		}
		else
		{//����һ���ṹ�壬Ȼ������ṹ���������֮��
		 //������Ҫ�������е��ַ�����һ���ַ���
		 //�����ɽṹ��֮ǰ�����ȼ���Ƿ���ַ��Ѿ����ڣ��������ֻ�Ǽ򵥵Ľ�����+1
		 //�������������Ȼ������һ���ַ���
			char *current_char = NULL;
			if (current_char != NULL) current_char = NULL;
			current_char = new char[v_char.size()];
			for (int i = 0; i<v_char.size(); i++)
			{
				//����һ����̬���ַ�����
				current_char[i] = v_char[i];
			}
			//���vector�ڵ�Ԫ�ظ�����Ϊ0������Ҫ���Ԫ�ظ���
			if (v_char.size() != 0)   v_char.clear();
			//�����е�һ�����ͣ���ֱ�Ӽ�1������ʹ���һ���µĽڵ㣬����������е�
			//�Ȳ鿴�Ƿ����Ԫ�أ������ھͲ���Ҫ������
			if (file_info_cahr.size() == 0)
			{
				//ֱ�Ӵ���һ���ṹ���ok��
				file_info_ file_;
				file_.name = new char[sizeof(current_char)];
				//���ַ���������ݿ������ṹ����
				strcpy(file_.name, current_char);
				//�����ִ�������Ϊ1��
				file_.num_appear = 1;
				//Ȼ�����ṹ������
				file_info_cahr.push_back(file_);

			}
			else {
				//�ṹ���е�Ԫ�ز�Ϊ�գ���Ҫ����
				//����һ�������������Ԫ����Ϊ��
				bool exist = false;
				for (int j = 0; j<file_info_cahr.size(); j++)
				{//�������ȣ��ͽ���������Ϊfalse
					if (strcmp(file_info_cahr[j].name, current_char) != 0) exist = false;
					else
					{
						//�����Ҫ����Ӧ�ṹ��ĳ��ִ�����1��ͬʱ����ѭ��
						file_info_cahr[j].num_appear++;
						exist = true;
						break;
					}
				}
				//ѭ������֮�󣬼���û��������ȵľ���Ҫ���´���һ���ṹ�壬����ṹ������
				if (exist == false)
				{
					file_info_ file__;

					file__.name = new char[sizeof(current_char)];
					strcpy(file__.name, current_char);
					//�����ִ�������Ϊ1��
					file__.num_appear = 1;
					file_info_cahr.push_back(file__);
				}
			}


		}//֮����Ҫ����Щ��Ϣ��¼�ڽṹ������֮��
		charc = fgetc(file);
	}
	//��¼���֮��ӵ��һ�ű��ֱ�Ӷ�������������Ȼ�����ʹ��һ�������������д��
	order(file_info_cahr);
}
void order(vector<struct file_info_> file_)
{
	//����Ҫ�ų�������Ԫ��Ϊ�յ����
	if (file_.size() == 0)
	{
		printf("û�м�⵽����\n");
		return;
	}
	//�ȶ�Ԫ������,�������������

	sort(file_info_cahr.begin(), file_info_cahr.end(), comp);
	//Ȼ��Ϳ��������
	for (int i = 0; i<file_info_cahr.size(); i++)
	{

       
       
		printf("%s :: %d \n", file_info_cahr[i].name, file_info_cahr[i].num_appear);
	
	}
	     
}
