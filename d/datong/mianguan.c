// Room: /open/dt/mianguan.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��ݵ��ϰ���һ���ػأ��������￪�������Ѿ��ж���ʮ
���ˣ��ӳ����˳�ȥ��ÿһ���涼���������������ġ������Ĵ�
��ţ������Ƚ���ֱ��ˣ������������䲻���Աߵ���һ����
ô��������ÿ��Ҳ���������������ǡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu4",
]));

	setup();
	replace_program(ROOM);
}
