// didao.c
// by dicky

inherit ROOM;

void create()
	{
	set("short","�ص�");
	set("long", @LONG
����һ���쳣�ľ����ص����������һ�ţ������ʲô����������
�ģ��������棬�㲻���뵽���ƺ���ÿ�����䶼��������ɱ����̫�ֲ�
�ˣ����ܺ�����Ϣ���������һ���붼����������
LONG 
);
	set("exits",([
		"east" : __DIR__"midao1",
		"out" : __DIR__"miao",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
