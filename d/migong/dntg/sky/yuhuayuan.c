// yuhuayuan.c ����԰

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����ǻ����ͻ�������԰. ƽ�������ʱ���������, �͹�������
һ���ͻ�Ʒ��. ����, �����ƽ��̫��, ������������. ����Ĺ�Ů��
����������, ��ͨ������. �����Ĺ�, ��Ŀ�����ƽ�����, ����ϸ�ֱ�, 
��ȻƷĿ��ȫ, ������õ�, �������붼�������, ���ﶼ����. ��
������Щ�ʼ���ʵ��϶���.
LONG
);
	set("outdoors", "dntg");
	set("magicroom",1);set("exits", ([
		"south" : __DIR__"hougong",
    "north" : __DIR__"dong99",
	]) );
	set("objects", ([
		__DIR__"npc/xiannu" : 2,
		"/d/huanggong/obj/panlonghuai" : 1,
		"/d/huanggong/obj/wolongsong" : 1,
		"/d/huanggong/obj/luohanbai" : 1,
	]) );
	set("coor/x", -200);
	set("coor/y", 5330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}