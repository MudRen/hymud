// Room: /d/yueyang/xuanyuantai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ԯ̨");
	set("long", @LONG
����һ�������������������������ϸߴ���������̨������̨�ֳ�
��ԯ̨��������ԯ�Ƶ����ڴ�����������ÿ���ؤ���ɽ��ᶼ�ڴ˴�
���У������������Ů֮��ʮ����ִ��ؤ������ڴ�һ������Ⱥؤ��
���ӵ�����˵��޾ٿ�ǰ���Ҳ��٣���Ӣ����Եʢ�٣�����׷������
����ˡ�
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shijie6",
	"north" : __DIR__"madayuanju",
	]));
	set("objects", ([
		__DIR__"npc/ma-dayuan" : 1,
		
	]));
	set("coor/x", -1790);
	set("coor/y", 2270);
	set("coor/z", 30);
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("ma dayuan", environment(me))) && 
		dir == "north")
		return notify_fail("���Ԫ��ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}