// pomiao.c
// by dicky

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
����һ���������õ�ɽ���������ưܲ�����ɽ����������һ�ԣ�
���ϵ���Ҳ�����˻ҳ���һ����֪���Ѿ��ܾ�û������������ˡ�����
���Ÿ����㰸���������ҵ����ż�����ʣ�����ļ���ͷ��Ҳ��������Ϊ
���ε�ԭ��ɣ�ؤ���һ���ֶ�ͱ����ڴ˴���
LONG);
	set("exits", ([
		"west" : __DIR__"lu16",
		"north" : __DIR__"ygbz/qiao",
		"south" : __DIR__"ygbz/yuanzi",
	]));

	set("objects", ([
		"/clone/npc/npc" : 1,
	]));

        setup();
        replace_program(ROOM);


}