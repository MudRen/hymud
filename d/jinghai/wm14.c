// Room: /d/jinghai/wm14.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ׯ�����£��Ŵ���������ľ��ɣ�ǽ����һ��������
ͼ���������м����һ�����¯����¯�ﴫ��һ�������㡣����
��һ�߼��������������Ρ������Ҷ�վ�����ԡ�Ҳ������Ϊû��
��˵�������ϵ����ո������ࡣ��������ǿ���ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"wm18",
  "eastup" : __DIR__"wm17",
  "northup" : __DIR__"wm16",
  "south" : __DIR__"wm9",
]));
        set("objects",([
        __DIR__"npc/master6" : 1,
        __DIR__"npc/guan4.c" : 1 ,
]));


	setup();

}

int valid_leave(object me,string dir)
{
	if(dir == "eastup" && me->query("class") != "jinghai" && !wizardp(me))
		return notify_fail("�Ա�һ��������ס��˵�����Ǳ��ɵ��Ӳ������ڣ�\n");
	return ::valid_leave(me,dir);
}
