// Room: /d/fuzhou/biaojuzt.c
// Date: may.12 1998 Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ����ھֵ���������ֻ̫ʦ��һ���ſ���������
��������ͷ���ֳ��̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ�
��һ�ѱ�����
LONG );
	set("exits", ([
		"north" : __DIR__"biaojuhy",
		"south" : __DIR__"biaojudy",
		"west"  : __DIR__"biaojunz",
	]));

	
	set("roomif","$botten#��������|��������:ask lin about job|ask lin about over$#");
	
	set("objects", ([
		"/quest/biao/linzhennan" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

