// Room: /d/jinghai/wm11.c

inherit ROOM;

void create()
{
	set("short", "������ˮկ����");
	set("long", @LONG
��������������ˮկ��ֻ��կǰ��һ��ټ��Ŀյأ��Ϸ���
һ����¥�����յ��Ǳ��м���֮����ˮկ���Ÿ����ܲ����䱸ɭ
�ϣ�һ��İ��յ��˽�Ȼֹ��������������Խ���Ӵ���������ȥ
����������ͣ��ս��������ͷ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"wm13",
  "east" : __DIR__"wm10",
    "down" : __DIR__"wm1",
]));
        set("objects",([
        __DIR__"npc/yong6" : 1,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
