// Room: some place in ��ţ����
// uphill4.c

inherit ROOM;

void create()
{
  set ("short", "ʨ�ն�");
  set ("long", @LONG
ʨ�ն����������룬�������֡���ͷ���h��ձƬ����Ƥ
�������೾���˽�������ϣ��ɽ����������������ʬɽ
Ѫ������Ȼ�ȳ����š�����С�������������˹��⣻����
��ħ���������������롣
LONG);
        set("exits", ([ /* sizeof() == 4 */
                "northeast" : __DIR__"uphill5",
                "southwest": __DIR__"uphill3",
        ]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/qingshi-laomo" : 1,
                __DIR__"npc/yao" : 2]));

        set("no_clean_up", 0);
        set("outdoors", "xy28");
        setup();
        replace_program(ROOM);
}

