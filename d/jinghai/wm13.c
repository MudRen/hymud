// Room: /d/jinghai/wm13.c

inherit ROOM;

void create()
{
	set("short", "ˮկ��¥");
	set("long", @LONG
������������ˮկ����ߵ㣬�������ϣ��Ӹ����£�Զ����
�ﾡ���۵ף�����巿¥�ᣬ���ϴ�ֻ����������Ŀ����������
��ÿ���Ƹߵ㶼�о����ɵĸ��ڣ������������𣬽��õ���ѶϢ
�����������ڡ���¥��������ˮկ���š�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wm11",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
