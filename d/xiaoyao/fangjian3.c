// fangjian3.c
// by shilling 97.2
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�䲼�ó�����ģ����С���䣬����ʯ�������ϰ��Ÿ�СС��ľͷ
�Ƴɵ�ҡ����ǽ��������һ�������٣����߶��Ѿ����ˡ�
LONG );
	set("exits", ([
		"east" : __DIR__"tongmen",
	]));
	set("objects",([
		"/clone/book/bojuan" : 1,
	]));
//	set("no_clean_up", 0);
	set("book_count",1);
	setup();
}

