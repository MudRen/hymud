// Room: /open/dt/zhouxierjia.c

inherit ROOM;

void create()
{
	set("short", "��ϲ����");
	set("long", @LONG
������Ի���ϲ���ļҡ���ϲ������һ���������ɳ�������
��������Ϊ��ȴʮ����ʵ������������Լ�����������ó�����
�����ˣ�������ýַ��ھӵ�ϲ�������ﲼ�õúܼ򵥣��ݽ�һ
������������һ����Ƥ����������֧��һֻ���¯��ǽ�Ϲ���Щ
�����޼�֮��Ĳ��Թ��ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu5",
]));

	setup();
	replace_program(ROOM);
}
