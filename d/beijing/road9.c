inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵������Ͼ��Ͽ��������������������ǳ����֡���ʱ��
����������������߷ɳ۶���������һ·���������ϵ��˸������ž�װ��
�¼��������еĻ���������ŵ�������������Щϰ��Ľ����ˡ���·��
������������������֡�
LONG );
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : "/d/cangzhou/nroad3",
	]));
	set("objects",([
		"quest/skills2/wunon/non/nontian" : 2,
		"/d/taishan/npc/tangzi" : 2,
	]));
	set("outdoors", "huabei");
	set("coor/x", 10);
	set("coor/y", 3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
