// Room: /open/dt/bingqipu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ϰ��֮��û�в�ϣ��ӵ��һ�����ֵı����ģ�����������Ҫ
ʲô���ı���������ұ�����������Ե��ҡ�����ǹ������ꪡ�
�йٱʡ��׹���....�������θ���ı����ڼ�����ҫ����ɭ�Ĺ�
â��������һʱ�Ҳ������ֵı�����ֻҪ�������������״����
����������֮�ڵ����˾Ϳ��԰�����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu1",
]));

	set("objects",([
	__DIR__"npc/weaponboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
