#pragma once

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("error : invalid parameter\n");
		return 0;
	}

	char* filePath = argv[1];
	AVFormatContext* m_pFormatCtx = nullptr;
	int ret = avformat_open_input(&m_pFormatCtx, filePath, nullptr, nullptr);
	if (0 < ret)
	{
		printf("error : failed open\n");
		return 0;
	}

	ret = avformat_find_stream_info(m_pFormatCtx, nullptr);
	if (0 < ret)
	{
		printf("error : Stream not found\n");
		return 0;
	}

	avformat_close_input(&m_pFormatCtx);

	return 0;
}