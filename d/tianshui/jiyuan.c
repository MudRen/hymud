// Room: /u/xiaozhen/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����Ƿ�Բ����Ψһ��һ�Ҽ�Ժ�����ﵽ���ŵƽ�ʣ�����
�˱ǣ���λ��欵Ĺ��������Աߣ���ʱ�ĳ�����Ц��������Ȼû
���Ϸ����ޣ���������֬Ҳ���з��ϣ�¥�ϲ�ʱ�ش����������
���ε�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiyuan2",
  "east" : __DIR__"nroad1",
]));
	set("no_clean_up", 0);

	set("objects",([
	__DIR__"npc/guinu" : 1,
]));

	
	setup();
}

int valid_leave(object ob,string dir)
{
	string day_night;
	int time;


	return ::valid_leave(ob,dir);
}