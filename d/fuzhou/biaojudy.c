// Room: /city/biaojudy.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����ھִ�Ժ");
	set("long", @LONG
��Ժ���Ե���Щ���ң������ֺ���ʦ�ǽ����������ƺ�
����������æµ��ʲô��һ�úܴ����������Ժ�����룬��
�������ĸ��ݴ���һ����ˬ��
LONG );
	set("exits", ([
		"out"   : "/d/fuzhou/biaoju",
		"north" : "/d/fuzhou/biaojuzt",
	]));
	set("objects", ([
		//__DIR__"npc/shi" : 1,
		"/d/jinyong/book8/fuzhou/npc/shi" : 1,
	]));
	set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

