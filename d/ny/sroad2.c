
// Room: /d/snow/sroad2.c

inherit ROOM;

void create()
{
	set("short", "��Զ�ǽֵ�");
	set("long",
"��������Զ�ǵĽֵ�����ı�����һ�ҿ�ջ��������Ϳ���������ջ����������̸Ц������\n"
"���ֵ�������Զ���и�ת�����������������ֱ�߾�����ɽ��С���ˣ�����������ߵ�����\n"
"�������ﲻ���Ĺٵ���\n"
);
	set("exits", ([ /* sizeof() == 3 */
]));
	set("outdoors", "ny");

	setup();
	replace_program(ROOM);
}
