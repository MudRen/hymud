//sroom.c.�ͷ�
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","�ͷ�");
    set("long",@LONG
�������м��ջ�Ŀͷ������ڿ���̫�ֻ࣬�ðѿⷿ������������ס�ˡ���
�ڼ������������ڸ�̸���ۣ�����������ʲô�߲��Թ���ϡ���䱦��������
�м��������Ŀ��ˣ����극������Ϣ�ˡ�
LONG);
   
    set("exits",([
        "out"   : __DIR__"kezhan",
    ])); 
    set("sleep_room","inn");
    set("outdoors","lanzhou");
    setup();
}

